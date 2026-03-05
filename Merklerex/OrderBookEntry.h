#pragma once

#include <string>

enum class OrderBookType
{
    bid,
    ask,
    bidsale,
	asksale
};


class OrderBookEntry
{
public:
    OrderBookEntry(std::string timestamp
        , std::string product
        , OrderBookType orderType
        , double price
        , double amount
        , std::string username = "dataset");

	static OrderBookType stringToOrderBookType(std::string type);

	static bool compareByTimestamp(OrderBookEntry& e1, OrderBookEntry& e2);
    static bool compareByPriceAsc(OrderBookEntry& e1, OrderBookEntry& e2);
    static bool compareByPriceDesc(OrderBookEntry& e1, OrderBookEntry& e2);

    std::string timeStamp;
    std::string product;
    OrderBookType orderType;
    double price;
    double amount;
    std::string username;
};