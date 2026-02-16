#include "BitcoinMain.h"
#include "BitcoinEntry.h"
#include <iostream>
#include <string>
#include <fstream>


BitcoinMain::BitcoinMain()
{

}
void BitcoinMain::Init()
{
    std::ifstream csvFile{ "btc-usd-max.csv" }; //Input file stream
    std::string line;
    std::vector<std::string> tokens;
    std::vector<BitcoinEntry> entries;


    if(csvFile.is_open())
    {

        std::getline(csvFile, line); // Skip header line
        while(std::getline(csvFile, line))
        {
            tokens = tokenise(line, ',');
            if(tokens.size()!= 4)
			{
				std::cout << "Invalid line: " << line << std::endl;
				continue;
			}   
            std::string snappedtAt = tokens.at(0);
            try
            {
                double price = std::stod(tokens.at(1));
                double marketCap = std::stod(tokens.at(2));
                double total_volume = std::stod(tokens.at(3));
            }
            catch(const std::exception& e)
            {
                std::cerr << e.what() << std::endl;
                std::cout << line << std::endl;
                std::cout << "Bad float!: " << tokens.at(1) << std::endl;
                std::cout << "Bad float!: " << tokens.at(2) << std::endl;
                std::cout << "Bad float!: " << tokens.at(3) << std::endl;
                break;
            }
            entries.push_back(BitcoinEntry(snappedtAt, price, marketCap, total_volume));
        }
        
        for(BitcoinEntry& entry : entries)
        {
            entry.displayEntry();
        }
        
        csvFile.close();

    }
    else
    {
        std::cout << "Failed to open file." << std::endl;
    }
}

std::vector<std::string> BitcoinMain::tokenise(std::string csvLine, char separator)
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

