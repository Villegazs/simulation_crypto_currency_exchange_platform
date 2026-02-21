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
	return orders_sub;
}