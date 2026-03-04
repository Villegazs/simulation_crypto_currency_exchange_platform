#pragma once
#include <string>
#include <map>
#include "OrderBookEntry.h"

class Wallet
{
	public:
		Wallet();
		/*Insert currency on the wallet*/
		void insertCurrency(std::string currency, double amount);
		/*remove currency of the wallet*/
		bool removeCurrency(std::string currency, double amount);
		/*Check if the wallet contains this much currency or more*/
		bool containsCurrency(std::string currency, double amount);
		/*Check if the wallet can cope with this ask or bid*/
		bool canFulfillOrder(OrderBookEntry order);
		/*Generate a string representation of the wallet*/
		std::string toString();
		/*Overload the << operator to print the wallet*/
		friend std::ostream& operator<<(std::ostream& os, Wallet& wallet);
	private:
		std::map<std::string, double> currencies; // map of currency to amount

};
