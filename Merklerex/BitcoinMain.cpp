#include "BitcoinMain.h"
#include <iostream>
#include <string>
#include <fstream>

BitcoinMain::BitcoinMain(std::string snappedtAt, double price, double marketCap, double total_volume)
    : snappedtAt(snappedtAt), price(price), marketCap(marketCap), total_volume(total_volume)
{
}

void BitcoinMain::Init()
{
    std::ifstream csvFile{ "btc-usd-max.csv" }; //Input file stream

    if(csvFile.is_open())
    {
        std::string line;
        std::getline(csvFile, line);
        std::getline(csvFile, line);
        std::cout << line << std::endl;
    }
    else
    {
        std::cout << "Failed to open file." << std::endl;
    }
}

