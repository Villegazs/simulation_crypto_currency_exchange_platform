#include "MerkelMain.h"
#include <iostream>
#include <string>

MerkelMain::MerkelMain()
{
    
}

void MerkelMain::Init()
{
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
    std::cout << "3. Make an Offer" << std::endl;
    // 4 make a bid
    std::cout << "4. Make a Bid" << std::endl;
    // 5 print wallet
    std::cout << "5. Print Wallet" << std::endl;
    // 6 continue
    std::cout << "6. Continue" << std::endl;
    std::cout << "7.Exit Program" << std::endl;

    std::cout << "Select an option: " << std::endl;
    std::cout << "====================" << std::endl;

}

void MerkelMain::printHelp()
{
    std::cout << "Help - your aim is to make money. Analyse the market and makes bids and offers" << std::endl;
}
void MerkelMain::printMarketStats()
{
   std::cout << "Markets looks good" << std::endl;
}
void MerkelMain::enterOffer()
{
    std::cout << "Make an offer - enter the amount" << std::endl;
}
void MerkelMain::enterBid()
{
    std::cout << "Make a bid - enter the amount" << std::endl;
}
void MerkelMain::printWallet()
{
    std::cout << "Your wallet is empty" << std::endl;
}
void MerkelMain::goToNextTimeFrame()
{
    std::cout << "Going to next time frame" << std::endl;
}
int MerkelMain::getUserOption(){
    int userInput;
    std::cout << "Type in 1-7" << std::endl;
    std::cin >> userInput;
    std:: cout << "You chose: " << userInput << std::endl;
    return userInput;
}
void MerkelMain::processUserOption(int option){
    switch (option)
    {
        case 1:
            printHelp();
            break;
        case 2:
            printMarketStats();
            break;
        case 3:
            enterOffer();
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