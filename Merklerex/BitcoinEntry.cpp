#include "BitcoinEntry.h"
#include <iostream>

BitcoinEntry::BitcoinEntry(std::string snappedtAt, double price, double marketCap, double total_volume)
    : snappedtAt(snappedtAt), price(price), marketCap(marketCap), total_volume(total_volume)
{
}

void BitcoinEntry::displayEntry()
{
    std::cout << "Timestamp: " << snappedtAt << std::endl;
    std::cout << "Price: " << price << std::endl;
    std::cout << "Market Cap: " << marketCap << std::endl;
    std::cout << "Total Volume: " << total_volume << std::endl;
}