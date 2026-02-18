#include "OrderBookEntry.h"
#include <iostream>

OrderBookEntry::OrderBookEntry(
      std::string timeStamp
    , std::string product
    , OrderBookType orderType
    , double price
    , double amount)
    : timeStamp(timeStamp)
    , product(product)
    , orderType(orderType)
    , price(price)
    , amount(amount)

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