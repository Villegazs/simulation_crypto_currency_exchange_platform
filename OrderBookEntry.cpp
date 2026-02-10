#include "OrderBookEntry.h"

OrderBookEntry::OrderBookEntry(double price
                            , double amount
                            , std::string timeStamp
                            , std::string product
                            , OrderBookType orderType)
        : price(price)
        , amount(amount)
        , timeStamp(timeStamp)
        , product(product)
        , orderType(orderType)
        {
            
        }