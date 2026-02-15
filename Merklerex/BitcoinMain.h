#pragma once 

#include <string>
#include <vector>
class BitcoinMain
{
private:
    std::string snappedtAt;
    double price;
    double marketCap;
    double total_volume;

public:
    BitcoinMain(std::string snappedtAt, double price, double marketCap, double total_volume);
    void Init();
    std::vector<std::string> tokenise(std::string csvLine, char separator);
};