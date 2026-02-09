#include <iostream>
#include <string>
#include <vector>
bool isRunning = true;

enum class OrderBookType
{
    bid,
    ask
};

OrderBookType orderType = OrderBookType::bid;

class OrderBookEntry
{
     public:
        OrderBookEntry(double price
                    , double amount
                    , std::string timeStamp
                    , std::string product
                    , OrderBookType orderType)
        : price(price)
        , amount(amount)
        , timeStamp(timeStamp)
        , product(product)
        , orderType(orderType)
        {
            
        }

        double price;
        double amount;
        std::string timeStamp;
        std::string product;
        OrderBookType orderType;
        
};

void printMenu()
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

void printHelp()
{
    std::cout << "Help - your aim is to make money. Analyse the market and makes bids and offers" << std::endl;
}
void printMarketStats()
{
   std::cout << "Markets looks good" << std::endl;
}
void enterOffer()
{
    std::cout << "Make an offer - enter the amount" << std::endl;
}
void enterBid()
{
    std::cout << "Make a bid - enter the amount" << std::endl;
}
void printWallet()
{
    std::cout << "Your wallet is empty" << std::endl;
}
void goToNextTimeFrame()
{
    std::cout << "Going to next time frame" << std::endl;
}
int getUserOption(){
    int userInput;
    std::cout << "Type in 1-7" << std::endl;
    std::cin >> userInput;
    std:: cout << "You chose: " << userInput << std::endl;
    return userInput;
}
void processUserOption(int option){
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

int main(){

    //while(isRunning)
    //{
    //    printMenu();
    //    int userOption = getUserOption();
    //    processUserOption(userOption);
    //}

    OrderBookEntry order1 {
        10000,
        0.001,
        "2020/03/17 17:01:24.884492",
        "BTC/USD",
        OrderBookType::bid
    };

    std::cout << "Order details: " << std::endl;
    std::cout << "Price: " << order1.price << std::endl;
    std::cout << "Amount: " << order1.amount << std::endl;
    std::cout << "Timestamp: " << order1.timeStamp << std::endl;
    std::cout << "Product: " << order1.product << std::endl;

    return 0;
}