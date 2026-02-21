#pragma once

#include "OrderBookEntry.h"
#include "CSVReader.h"
#include <string>
#include <vector>

class OrderBook
{
	public:
		/*Construct reading a csv data file*/
		OrderBook(std::string csvFileName);
		/*Return vector of all known products in dataset*/
		std::vector<std::string> getKnownProducts();
		/*Return vector of all orders for a given product and timestamp*/
		std::vector<OrderBookEntry> getOrders(OrderBookType type, 
											std::string product, 
											std::string timestamp);
		static double getHighPrice(std::vector<OrderBookEntry>& orders);
		static double getLowPrice(std::vector<OrderBookEntry>& orders);

	private:
		std::vector<OrderBookEntry> orders;
};