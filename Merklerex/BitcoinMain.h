#pragma once 

#include <vector>
class BitcoinMain
{
private:
    std::string snappedtAt;
    double price;
    double marketCap;
    double total_volume;

public:
    BitcoinMain();
    void Init();
    std::vector<std::string> tokenise(std::string csvLine, char separator);
};