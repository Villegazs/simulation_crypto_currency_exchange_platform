#pragma once 

#include <string>
#include <vector>
class GoldEntry
{
private:
    std::string date;
    double close;
    double high;
    double low;
    double open;
    double volume;

public:
    GoldEntry(std::string date, double close, double high, double low, double open, double volume);
    void displayEntry();
    double getClose();
    double getHigh();
    double getLow();
    double getOpen();
    double getVolume();
};