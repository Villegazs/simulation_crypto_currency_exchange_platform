#pragma once
#include <string>
#include <map>

class Wallet
{
	public:
		Wallet();
		/*Insert currency on the wallet*/
		void insertCurrency(std::string currency, double amount);
		/*Check if the wallet contains this much currency or more*/
		bool containsCurrency(std::string currency, double amount);
		/*Generate a string representation of the wallet*/
		std::string toString();
	private:
		std::map<std::string, double> currencies; // map of currency to amount

};
