#pragma once

#include <string>

enum class OrderBookType
{
    bid,
    ask
};


class OrderBookEntry
{
public:
    OrderBookEntry(std::string timestamp
        , std::string product
        , OrderBookType orderType
        , double price
        , double amount
        );

	static OrderBookType stringToOrderBookType(std::string type);

    std::string timeStamp;
    std::string product;
    OrderBookType orderType;
    double price;
    double amount;
};