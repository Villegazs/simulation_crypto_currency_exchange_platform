#include "GoldEntry.h"
#include <iostream>

GoldEntry::GoldEntry(std::string date, double close, double high, double low, double open, double volume)
    : date(date), close(close), high(high), low(low), open(open), volume(volume)
{
}

void GoldEntry::displayEntry()
{
    std::cout << "Timestamp: " << date << std::endl;
    std::cout << "Close: " << close << std::endl;
    std::cout << "High: " << high << std::endl;
    std::cout << "Low: " << low << std::endl;
    std::cout << "Open: " << open << std::endl;
    std::cout << "Volume: " << volume << std::endl;
}
double GoldEntry::getClose()
{
    return close;
}
double GoldEntry::getHigh()
{
    return high;
}
double GoldEntry::getLow()
{
    return low;
}
double GoldEntry::getOpen()
{
    return open;
}
double GoldEntry::getVolume()
{
    return volume;
}