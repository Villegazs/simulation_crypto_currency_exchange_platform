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

		/* Returns the earliest time in the orderbook*/
		std::string getEarliestTime();
		/* Returns the next time in the orderbook after the given timestamp.
		If there is no next timestamp, wrap around to the start*/
		std::string getNextTime(std::string timestamp);

		void insertOrder(OrderBookEntry& order);

		std::vector<OrderBookEntry> matchAsksToBids(std::string product, std::string timeStamp);

		static double getHighPrice(std::vector<OrderBookEntry>& orders);
		static double getLowPrice(std::vector<OrderBookEntry>& orders);
		/* Returns the mean price of the orders in the vector. 
		The mean price is calculated as the sum of the prices of the 
		orders divided by the number of orders. */
		static double getMeanPrice(std::vector<OrderBookEntry>& orders);
		/* Returns the percentage price value change between the mean price of the 
		orders in the vector and the mean price of the orders at the previous timestamp. 
		The percentage price value change is calculated as 
		((priceAtTime - priceAtPreviousTime) / priceAtPreviousTime) * 100.0. 
		If there is no previous timestamp, return 0.0. */ //
		double getPercentagePriceValueChange(std::vector<OrderBookEntry>& orders);

	private:
		std::vector<OrderBookEntry> orders;
		std::string previousTime = "";
};