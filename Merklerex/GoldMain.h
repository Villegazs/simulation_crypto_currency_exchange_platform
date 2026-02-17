#pragma once 

#include <vector>
#include <string>
#include <functional>
#include "GoldEntry.h"

// Enum para especificar qué tipo de precio evaluar
enum class PriceType {
    CLOSE,
    HIGH,
    LOW,
    OPEN,
    VOLUME
};

class GoldMain
{
private:

public:
    GoldMain();
    void Init();
    std::vector<std::string> tokenise(std::string csvLine, char separator);
    double highestPrice(std::vector<GoldEntry>& entries, PriceType priceType);
    double lowestPrice(std::vector<GoldEntry>& entries, PriceType priceType);
    double averagePrice(std::vector<GoldEntry>& entries, PriceType priceType);
};