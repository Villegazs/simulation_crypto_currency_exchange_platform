#include "MerkelMain.h"
#include <iostream>
#include <string>
#include "CSVReader.h"

MerkelMain::MerkelMain()
{

}

void MerkelMain::Init()
{
	currentTime = orderBook.getEarliestTime();

	wallet.insertCurrency("BTC", 10);

    while (MerkelMain::isRunning)
    {
        printMenu();
        int userOption = getUserOption();
        processUserOption(userOption);
    }

}

void MerkelMain::printMenu()
{

    // 1 print help
    std::cout << "1. Print Help" << std::endl;
    // 2 print exchange stats
    std::cout << "2. Print Exchange Stats" << std::endl;
    // 3 make an offer
    std::cout << "3. Make an Ask" << std::endl;
    // 4 make a bid
    std::cout << "4. Make a Bid" << std::endl;
    // 5 print wallet
    std::cout << "5. Print Wallet" << std::endl;
    // 6 continue
    std::cout << "6. Continue" << std::endl;
    std::cout << "7.Exit Program" << std::endl;

    std::cout << "Select an option: " << std::endl;
    std::cout << "====================" << std::endl;

	std::cout << "Current time: " << currentTime << std::endl;

}

void MerkelMain::printHelp()
{
    std::cout << "Help - your aim is to make money. Analyse the market and makes bids and offers" << std::endl;
}
void MerkelMain::printMarketStats()
{
    for(std::string const p: orderBook.getKnownProducts())
    {
        std::cout << "Product: " << p << std::endl;

		std::vector<OrderBookEntry> asks = orderBook.getOrders
        (OrderBookType::ask, 
            p, 
            currentTime);

		std::cout << "Asks: " << asks.size() << std::endl;
        if (asks.size() > 0)
        {
            calculateStatsForProduct(asks);
        }
        
        std::vector<OrderBookEntry> bids = orderBook.getOrders
        (OrderBookType::bid,
            p,
            currentTime);

		std::cout << "Bids: " << bids.size() << std::endl;
        if (bids.size() > 0)
        {
            calculateStatsForProduct(bids);
        }
	}
   /* std::cout << "Order Book contains " << orders.size() << " entries" << std::endl;

	unsigned int asksCount = 0;
	unsigned int bidsCount = 0;

    for(OrderBookEntry& order : orders)
    {
        if (order.orderType == OrderBookType::ask)
        {
            ++asksCount;
        }
        else if (order.orderType == OrderBookType::bid)
        {
            ++bidsCount;
        }
	}

	std::cout << "Orderbook Asks: " << asksCount << " bids: " << bidsCount << std::endl;
    */
}

void MerkelMain::calculateStatsForProduct(std::vector<OrderBookEntry> orders)
{
    const std::string RESET = "\033[0m";
    const std::string RED = "\033[31m";
    const std::string GREEN = "\033[32m";

    std::string typeStr = (orders[0].orderType == OrderBookType::ask) ? "ask" : "bid";

    std::cout << "Highest " << typeStr << ":" << OrderBook::getHighPrice(orders) << std::endl;
    std::cout << "Lowest " << typeStr << ":" << OrderBook::getLowPrice(orders) << std::endl;
    std::cout << "Mean " << typeStr << ":" << OrderBook::getMeanPrice(orders) << std::endl;
    std::string priceChangeColour = GREEN;
    if (orderBook.getPercentagePriceValueChange(orders) == 0)
    {
        std::cout << priceChangeColour << "No "<< typeStr << " price change" << RESET << std::endl;
    }
    else if (orderBook.getPercentagePriceValueChange(orders) < 0)
    {
        priceChangeColour = RED;
    }
	else if (orderBook.getPercentagePriceValueChange(orders) > 0)
    {
        std::cout << typeStr << " price change: " << priceChangeColour << orderBook.getPercentagePriceValueChange(orders) << "%" << RESET << std::endl;
    }
}
void MerkelMain::enterAsk()
{
    std::cout << "Make an ask - enter the amount: product, price, amount. eg ETH/BTC,200,0.5" << std::endl;
	std::string input;
	std::getline(std::cin, input);
	std::vector<std::string> tokens = CSVReader::tokenise(input, ',');
    if(tokens.size() != 3)
    {
        std::cout << "Invalid input. Please enter in the format: product, price, amount" << std::endl;
        return;
	}
    else
    {
        try
        {
            OrderBookEntry order = CSVReader::stringsToOBE(
                currentTime,
                tokens[0],
                OrderBookType::ask,
                tokens[1],
                tokens[2]);
			orderBook.insertOrder(order);
        }
        catch (const std::exception& e)
        {
            std::cout << "MerkelMain::enterAsk: Invalid input." << std::endl;
        }
    }

	std::cout << "You entered: " << input << std::endl;
}
void MerkelMain::enterBid()
{
    std::cout << "Make a bid - enter the amount: product, price, amount. eg ETH/BTC,200,0.5" << std::endl;
	std::string input;
	std::getline(std::cin, input);
    std::vector<std::string> tokens = CSVReader::tokenise(input, ',');
    if(tokens.size() != 3)
    {
        std::cout << "Invalid input. Please enter in the format: product, price, amount" << std::endl;
        return;
    }
    else
    {
        try
        {
            OrderBookEntry order = CSVReader::stringsToOBE(
                currentTime,
                tokens[0],
                OrderBookType::bid,
                tokens[1],
                tokens[2]);
            orderBook.insertOrder(order);
        }
        catch (const std::exception& e)
        {
            std::cout << "MerkelMain::enterBid: Invalid input." << std::endl;
        }
	}
}
void MerkelMain::printWallet()
{
    std::cout << "Your wallet is empty" << std::endl;
	std::cout << wallet.toString() << std::endl;
}
void MerkelMain::goToNextTimeFrame()
{
    std::cout << "Going to next time frame" << std::endl;
    for(std::string const product: orderBook.getKnownProducts())
    {
        std::cout << "matching" << product << std::endl;
        std::vector<OrderBookEntry> sales = orderBook.matchAsksToBids(product, currentTime);
        std::cout << "Sales: " << sales.size() << std::endl;
        for (OrderBookEntry sale : sales)
        {
            std::cout << "Sale: " << sale.product << " price: " << sale.price << " amount: " << sale.amount << std::endl;
        }
	}
	currentTime = orderBook.getNextTime(currentTime);
}
int MerkelMain::getUserOption() {
    int userInput = 0;
    std::string line;
    std::cout << "Type in 1-7" << std::endl;
	std::getline(std::cin, line);
    try {
        userInput = std::stoi(line);

    }
    catch (const std::exception& e)
    {

	}
    std::cout << "You chose: " << userInput << std::endl;
    return userInput;
}
void MerkelMain::processUserOption(int option) {
    switch (option)
    {
    case 1:
        printHelp();
        break;
    case 2:
        printMarketStats();
        break;
    case 3:
        enterAsk();
        break;
    case 4:
        enterBid();
        break;
    case 5:
        printWallet();
        break;
    case 6:
        goToNextTimeFrame();
        break;
    case 7:
        std::cout << "Exiting program." << std::endl;
        isRunning = false;
        break;
    default:
        std::cout << "Invalid choice. Choose 1-7." << std::endl;
        break;
    }
}