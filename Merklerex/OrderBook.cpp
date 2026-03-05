#include "OrderBook.h"
#include <map>
#include <algorithm>
#include <iostream>


OrderBook::OrderBook(std::string csvFileName) {
	orders = CSVReader::readCSV(csvFileName);
}

std::vector<std::string> OrderBook::getKnownProducts()
{
	std::vector<std::string> products;

	std::map<std::string, bool> productMap; // boolean value is not used, we just want to track unique products

	for (OrderBookEntry& order : orders)
	{
		productMap[order.product] = true; // this will add the product to the map if it's not already there
	}

	for (auto const& pair : productMap) // iterate over the map to extract the unique products
	{
		products.push_back(pair.first); // add the unique product to the products vector
	}

	return products;
}

std::vector<OrderBookEntry> OrderBook::getOrders(OrderBookType type,
	std::string product,
	std::string timestamp)
{
	std::vector<OrderBookEntry> orders_sub;

	for (OrderBookEntry& order : orders)
	{
		if (order.orderType == type &&
			order.product == product &&
			order.timeStamp == timestamp)
		{
			orders_sub.push_back(order);
		}
	}
	return orders_sub;
}

double OrderBook::getHighPrice(std::vector<OrderBookEntry>& orders) 
{
	double max = orders[0].price;

	for(OrderBookEntry& order : orders)
	{
		if (order.price > max)
		{
			max = order.price;
		}
	}

	return max;
}

double OrderBook::getLowPrice(std::vector<OrderBookEntry>& orders)
{
	double min = orders[0].price;

	for (OrderBookEntry& order : orders)
	{
		if (order.price < min)
		{
			min = order.price;
		}
	}

	return min;
}

double OrderBook::getMeanPrice(std::vector<OrderBookEntry>& orders)
{
	double total = 0.0;
	for (OrderBookEntry order : orders)
	{
		total += order.price;
	}

	return total / orders.size();
}

double OrderBook::getPercentagePriceValueChange(std::vector<OrderBookEntry>& orders)
{
	if(previousTime == "")
	{
		return 0.0; // no previous timestamp, so we cannot calculate a price change
	}
	double priceChange = 0.0;
	double priceAtTime = 0.0;
	double priceAtPreviousTime = 0.0;

	priceAtTime = OrderBook::getMeanPrice(orders);

	std::vector<OrderBookEntry> previousOrders;
	previousOrders = this->OrderBook::getOrders(orders[0].orderType, orders[0].product, previousTime);
	priceAtPreviousTime = OrderBook::getMeanPrice(previousOrders);

	priceChange = (priceAtTime - priceAtPreviousTime);
	double priceChangePercentage = (priceChange / priceAtPreviousTime) * 100.0;

	return priceChangePercentage;

}

std::string OrderBook::getEarliestTime()
{
	return orders[0].timeStamp;
}

std::string OrderBook::getNextTime(std::string timestamp)
{
	previousTime = timestamp; // store the current timestamp as the previous timestamp for the next time we calculate the price change
	std::string nextTimestamp = "";
	for(OrderBookEntry& order : orders)
	{
		if (order.timeStamp > timestamp)
		{
			nextTimestamp = order.timeStamp;
			break;
		}
	}
	if(nextTimestamp == "")
	{
		previousTime = ""; // reset the previous time when we loop back to the start of the order book
		nextTimestamp = orders[0].timeStamp; // loop back to the start of the order book if we have reached the end
	}
	return nextTimestamp;
}

void OrderBook::insertOrder(OrderBookEntry& order)
{
	orders.push_back(order);
	std::sort(orders.begin(), orders.end(), OrderBookEntry::compareByTimestamp);
}

std::vector<OrderBookEntry> OrderBook::matchAsksToBids(std::string product, std::string timeStamp)
{
	std::vector<OrderBookEntry> asks = getOrders(OrderBookType::ask, product, timeStamp);

	std::vector<OrderBookEntry> bids = getOrders(OrderBookType::bid, product, timeStamp);

	std::vector<OrderBookEntry> sales; // we will store the sales that we create in this vector and return it at the end of the function

	std::sort(asks.begin(), asks.end(), OrderBookEntry::compareByPriceAsc); // sort the asks in ascending order of price, so that we match the lowest ask price first
	std::sort(bids.begin(), bids.end(), OrderBookEntry::compareByPriceDesc); // sort the bids in descending order of price, so that we match the highest bid price first

	for (OrderBookEntry& ask : asks)
	{
		for (OrderBookEntry& bid : bids)
		{
			if (bid.price >= ask.price)
			{
				OrderBookEntry sale{
						timeStamp,
						product,
						OrderBookType::asksale, // we can use either bid or ask here, as the order type is not relevant for a sale
						ask.price, // the sale price is the ask price
						0.0 // we will calculate the sale amount below
				};
				if(bid.username == "simuser")
				{
					sale.username = "simuser";
					sale.orderType = OrderBookType::bidsale;
				}
				if(ask.username == "simuser")
				{
					sale.username = "simuser";
					sale.orderType = OrderBookType::asksale;
				}
				
				std::cout << "Bid amount: " << bid.amount << " Ask amount: " << ask.amount << std::endl;

				if (bid.amount == ask.amount)
				{
					sale.amount = ask.amount; // the sale amount is the same as the ask amount (or the bid amount, since they are the same)
					sales.push_back(sale); // add the sale to the sales vector
					bid.amount = 0.0; // set the bid amount to 0, as it has been fully matched
					break; // move on to the next ask, as this ask has been fully matched
				}

				if (bid.amount > ask.amount)
				{
					sale.amount = ask.amount; // the sale amount is the same as the ask amount, as the bid has more than enough to fully match the ask
					sales.push_back(sale); // add the sale to the sales vector
					bid.amount -= ask.amount; // reduce the bid amount by the amount that was matched with the ask
					std::cout << "Bid amount after matching: " << bid.amount << std::endl;
					break; // move on to the next ask, as this ask has been fully matched
				}

				if (bid.amount < ask.amount && bid.amount > 0)
				{
					sale.amount = bid.amount; // the sale amount is the same as the bid amount, as the ask has more than enough to fully match the bid
					sales.push_back(sale); // add the sale to the sales vector
					ask.amount -= bid.amount; // reduce the ask amount by the amount that was matched with the bid
					std::cout << "Ask amount after matching: " << ask.amount << std::endl;
					bid.amount = 0.0; // set the bid amount to 0, as it has been fully matched
					continue; // continue trying to match the remaining amount of the ask with the next bid

				}
			}
		}
	}

	return sales;
}
