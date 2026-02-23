#include "OrderBook.h"
#include <map>


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


