#pragma once 

#include <string>
#include <vector>
class BitcoinEntry
{
private:
    std::string snappedtAt;
    double price;
    double marketCap;
    double total_volume;

public:
    BitcoinEntry(std::string snappedtAt, double price, double marketCap, double total_volume);
    void displayEntry();
};