#include <string>
#include <vector>
#include <iostream>

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

	} while (end > 0); // loop until no more separators
	return tokens;
}

int main()
{
	return 0;
}