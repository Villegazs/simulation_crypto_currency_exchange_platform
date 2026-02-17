#include "GoldMain.h"
#include <iostream>
#include <fstream>




GoldMain::GoldMain()
{

}
void GoldMain::Init()
{
    std::ifstream csvFile{ "GOLD.csv" }; //Input file stream
    std::string line;
    std::vector<std::string> tokens;
    std::vector<GoldEntry> entries;


    if(csvFile.is_open())
    {

        std::getline(csvFile, line); // Skip header line
        while(std::getline(csvFile, line))
        {
            tokens = tokenise(line, ',');
            if(tokens.size()!= 6)
			{
				std::cout << "Invalid line: " << line << std::endl;
				continue;
			}   
            std::string date = tokens.at(0);
            try
            {
                double close = std::stod(tokens.at(1));
                double high = std::stod(tokens.at(2));
                double low = std::stod(tokens.at(3));
                double open = std::stod(tokens.at(4));
                double volume = std::stod(tokens.at(5));
                GoldEntry entry(date, close, high, low, open, volume);
                entries.push_back(entry);
            }
            catch(const std::exception& e)
            {
                std::cerr << e.what() << std::endl;
                std::cout << line << std::endl;
                std::cout << "Bad float!: " << tokens.at(1) << std::endl;
                std::cout << "Bad float!: " << tokens.at(2) << std::endl;
                std::cout << "Bad float!: " << tokens.at(3) << std::endl;
                std::cout << "Bad float!: " << tokens.at(4) << std::endl;
                std::cout << "Bad float!: " << tokens.at(5) << std::endl;
                break;
            }
        }

        int totalEntries = entries.size();
        std::cout << "Total entries: " << totalEntries << std::endl;
        
        double highestClose = highestPrice(entries, PriceType::CLOSE);
        double highestHigh = highestPrice(entries, PriceType::HIGH);
        double highestLow = highestPrice(entries, PriceType::LOW);
        
        std::cout << "Highest Close Price: " << highestClose << std::endl;
        std::cout << "Highest High Price: " << highestHigh << std::endl;
        std::cout << "Highest Low Price: " << highestLow << std::endl;

        double lowestClose = lowestPrice(entries, PriceType::CLOSE);
        double lowestHigh = lowestPrice(entries, PriceType::HIGH);
        double lowestLow = lowestPrice(entries, PriceType::LOW);

        std::cout << "Lowest Close Price: " << lowestClose << std::endl;
        std::cout << "Lowest High Price: " << lowestHigh << std::endl;
        std::cout << "Lowest Low Price: " << lowestLow << std::endl;

        double averageClose = averagePrice(entries, PriceType::CLOSE);
        double averageHigh = averagePrice(entries, PriceType::HIGH);
        double averageLow = averagePrice(entries, PriceType::LOW);

        std::cout << "Average Close Price: " << averageClose << std::endl;
        std::cout << "Average High Price: " << averageHigh << std::endl;
        std::cout << "Average Low Price: " << averageLow << std::endl;

        csvFile.close();

    }
    else
    {
        std::cout << "Failed to open file." << std::endl;
    }
}

std::vector<std::string> GoldMain::tokenise(std::string csvLine, char separator)
{
    std::vector<std::string> tokens;
    signed int start, end;
    std::string token;

    start = csvLine.find_first_not_of(separator, 0);
    do
    {
        end = csvLine.find_first_of(separator, start);
        if(start == csvLine.length() || start == end) // no more tokens or empty token
        {
           break;
        }
        if(end >= 0)
        {
            token = csvLine.substr(start, end - start);
        }
        else
        {
            token = csvLine.substr(start, csvLine.length() - start);
        }
        tokens.push_back(token);
        start = end + 1;
    }
    while(end != std::string::npos);
    return tokens;
}

double GoldMain::highestPrice(std::vector<GoldEntry>& entries, PriceType priceType)
{
    double highest = 0.0;

    for(GoldEntry& entry : entries)
    {
        double currentValue = 0.0;
        
        // Seleccionar el valor según el tipo de precio especificado
        switch(priceType)
        {
            case PriceType::CLOSE:
                currentValue = entry.getClose();
                break;
            case PriceType::HIGH:
                currentValue = entry.getHigh();
                break;
            case PriceType::LOW:
                currentValue = entry.getLow();
                break;
            case PriceType::OPEN:
                currentValue = entry.getOpen();
                break;
            case PriceType::VOLUME:
                currentValue = entry.getVolume();
                break;
        }
        
        if(currentValue > highest)
        {
            highest = currentValue;
        }
    }
    return highest;
}

double GoldMain::lowestPrice(std::vector<GoldEntry>& entries, PriceType priceType)
{
    double lowest = entries[0].getClose(); // Inicializar con el primer valor de cierre como referencia

    for(GoldEntry& entry : entries)
    {
        double currentValue = 0.0;
        
        // Seleccionar el valor según el tipo de precio especificado
        switch(priceType)
        {
            case PriceType::CLOSE:
                currentValue = entry.getClose();
                break;
            case PriceType::HIGH:
                currentValue = entry.getHigh();
                break;
            case PriceType::LOW:
                currentValue = entry.getLow();
                break;
            case PriceType::OPEN:
                currentValue = entry.getOpen();
                break;
            case PriceType::VOLUME:
                currentValue = entry.getVolume();
                break;
        }
        
        if(currentValue < lowest)
        {
            lowest = currentValue;
        }
    }
    return lowest;
}

double GoldMain::averagePrice(std::vector<GoldEntry>& entries, PriceType priceType)
{
    double total = 0.0;

    for(GoldEntry& entry : entries)
    {
        double currentValue = 0.0;
        
        // Seleccionar el valor según el tipo de precio especificado
        switch(priceType)
        {
            case PriceType::CLOSE:
                currentValue = entry.getClose();
                break;
            case PriceType::HIGH:
                currentValue = entry.getHigh();
                break;
            case PriceType::LOW:
                currentValue = entry.getLow();
                break;
            case PriceType::OPEN:
                currentValue = entry.getOpen();
                break;
            case PriceType::VOLUME:
                currentValue = entry.getVolume();
                break;
        }
        
        total += currentValue;
    }
    return total / entries.size();
}

