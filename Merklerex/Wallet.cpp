#include "Wallet.h"
#include <iostream>
#include "CSVReader.h"

Wallet::Wallet()
{
	// constructor
}

void Wallet::insertCurrency(std::string currency, double amount)
{
	double balance = 0.0;
	if(amount < 0)
	{
		throw std::exception("Amount must be positive");
	}
	if (currencies.count(currency) == 0) // not there yet
	{
		balance = 0;
	}
	else // is there
	{
		balance = currencies[currency];
	}
	balance += amount;
	currencies[currency] = balance;

}
bool Wallet::removeCurrency(std::string currency, double amount)
{
	if(amount < 0)
	{
		return false;
	}
	if (currencies.count(currency) == 0) // not there yet
	{
		std::cout << "Currency " << currency << " not found in wallet" << std::endl;
		return false;
	}
	else // is there - do we have enough to remove?
	{
		if (containsCurrency(currency, amount)) // we have enough to remove
		{
			std::cout << "Removing " << amount << " of " << currency << std::endl;
			currencies[currency] -= amount;
			return true;
		}
		else // we don't have enough to remove
		{
			return false;
		}
	}
}
bool Wallet::containsCurrency(std::string currency, double amount)
{
	if (currencies.count(currency) == 0) // not there yet
		return false;
	else // is there
	{
		return currencies[currency] >= amount;
	}
}

std::string Wallet::toString()
{
	std::string message;
	for(std::pair<const std::string, double> pair : currencies)
	{
		std::string currency = pair.first;
		double amount = pair.second;
		message += currency + ": " + std::to_string(amount) + "\n";
	}
	return message;
}

bool Wallet::canFulfillOrder(OrderBookEntry order)
{
	std::vector<std::string> currs = CSVReader::tokenise(order.product, '/');
	if (order.orderType == OrderBookType::ask)
	{
		double amount = order.amount;
		std::string currency = currs[0];
		std::cout << "Wallet::canFulfillOrder: " << currency << " : " << amount << std::endl;
		return containsCurrency(currency, amount);
	}
	else if(order.orderType == OrderBookType::bid)
	{
		double amount = order.amount * order.price;
		std::string currency = currs[1];
		std::cout << "Wallet::canFulfillOrder: " << currency << " : " << amount << std::endl;
		return containsCurrency(currency, amount);
	}
}
