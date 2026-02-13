#include "OrderBookEntry.h"

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