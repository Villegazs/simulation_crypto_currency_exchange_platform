#include "CSVReader.h"
#include <iostream>
#include <fstream>

CSVReader::CSVReader()
{
}

std::vector<OrderBookEntry> CSVReader::readCSV(std::string csvFileName)
{
	std::vector<OrderBookEntry> entries;
	
	std::ifstream csvFile{csvFileName};
	std::string line;

	if (csvFile.is_open())
	{
		while (std::getline(csvFile, line))
		{
			if(line.empty())
			{
				continue; // Skip empty lines
			}
			try
			{
				OrderBookEntry obe = stringsToOBE(tokenise(line, ','));
				entries.push_back(obe);
			}
			catch (const std::exception& e)
			{
				std::cout << "Error processing line: " << line << std::endl;
				std::cout << "Exception message: " << e.what() << std::endl;
				// Continue to the next line without adding an entry for this line
			}

		}// End of While loop

		csvFile.close();
	}
	else
	{
		std::cout << "Error: Could not open file " << csvFileName << std::endl;
		throw std::exception{};
	}

	std::cout << "CSVReader::readCSV read " << entries.size() << " entries from file " << csvFileName << std::endl;
	return entries;
}

std::vector<std::string> CSVReader::tokenise(std::string csvLine, char separator)
{
	std::vector<std::string> tokens;

	signed int start, end;
	std::string token;


	start = csvLine.find_first_not_of(separator, 0);

	do
	{
		end = csvLine.find_first_of(separator, start);
		if (start == csvLine.length() || start == end) // no more tokens or empty token
		{
			break;
		}

		if (end >= 0) // found a separator, get the token
		{
			token = csvLine.substr(start, end - start);
		}
		else // no more separators, get the rest of the string
		{
			token = csvLine.substr(start, csvLine.length() - start);
		}

		tokens.push_back(token);

		start = end + 1;

	} while (end != std::string::npos); // loop until no more separators
	return tokens;
}
OrderBookEntry CSVReader::stringsToOBE(std::vector<std::string> tokens)
{
	std::string timestamp, product;
	OrderBookType orderType;
	double price, amount;


	if (tokens.size() != 5)
	{
		std::cout << "Error: Invalid number of tokens" << std::endl;
		throw std::exception{};
	}
	timestamp = tokens.at(0);
	product = tokens.at(1);
	orderType = OrderBookEntry::stringToOrderBookType(tokens.at(2));
	try {
		price = std::stod(tokens.at(3));
		amount = std::stod(tokens.at(4));
	}
	catch (const std::exception& e)
	{
		std::cout << "Bad float!: " << tokens.at(3) << " or " << tokens.at(4) << std::endl;
		throw; // rethrow the exception to be handled by the caller
	}
	OrderBookEntry entry(timestamp,product,
		orderType,price, amount);

	return entry;

}