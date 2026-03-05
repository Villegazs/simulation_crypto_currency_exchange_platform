#include "OrderBookEntry.h"
#include <iostream>

OrderBookEntry::OrderBookEntry(
      std::string timeStamp
    , std::string product
    , OrderBookType orderType
    , double price
    , double amount
    , std::string username)
    : timeStamp(timeStamp)
    , product(product)
    , orderType(orderType)
    , price(price)
    , amount(amount)
	, username(username)

{

}

OrderBookType OrderBookEntry::stringToOrderBookType(std::string type)
{
    if (type == "bid")
    {
        return OrderBookType::bid;
    }
    else if (type == "ask")
    {
        return OrderBookType::ask;
    }
    else
    {
        std::cout << "Invalid order book type: " << type << std::endl;
        throw std::exception{};
    }
}

bool OrderBookEntry::compareByTimestamp(OrderBookEntry& e1, OrderBookEntry& e2)
{
	return e1.timeStamp < e2.timeStamp;
}

bool OrderBookEntry::compareByPriceAsc(OrderBookEntry& e1, OrderBookEntry& e2)
{
    return e1.price < e2.price;
}

bool OrderBookEntry::compareByPriceDesc(OrderBookEntry& e1, OrderBookEntry& e2)
{
    return e1.price > e2.price;
}
