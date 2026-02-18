#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include "OrderBookEntry.h"

std::vector<std::string> tokenise(std::string csvLine, char separator)
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

int test()
{
	//std::vector<std::string> tokens;
	//std::string s = "2020/03/17 17:01:24.884492,ETH/BTC,bid,0.023,4000";
	//tokens = tokenise(s, ',');
	//for (std::string& token : tokens)
	//{
	//	std::cout << token << std::endl;
	//}

	std::ifstream csvFile{ "20200317.csv" }; //Input file stream
	std::string line;
	std::vector<std::string> tokens;

	if (csvFile.is_open())
	{
		while(std::getline(csvFile, line))
		{
			tokens = tokenise(line, ',');
			if(tokens.size()!= 5)
			{
				std::cout << "Invalid line: " << line << std::endl;
				continue;
			}
			std::string timestamp = tokens[0];
			std::string product = tokens[1];
			OrderBookType orderType = tokens[2] == "bid" ? OrderBookType::bid : OrderBookType::ask;


			try {
				double price = std::stod(tokens[3]);
				double amount = std::stod(tokens[4]);
				std::cout << "Price: " << price << std::endl;

			} 
			catch(const std::exception& e)
			{
				std::cout << "Bad float!: " << tokens[3] << std::endl;
				std::cout << "Bad float!: " << tokens[4] << std::endl;
				break;
			}
		}

		csvFile.close();
	}
	else
	{
		std::cout << "Cant open the file" << std::endl;
	}
	return 0;
}