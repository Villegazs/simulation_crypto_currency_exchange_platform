#include <iostream>
bool isRunning = true;
int main(){

    while(isRunning)
    {
        std:: cout << "0.Exit Program" << std::endl;
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

        std::cout << "Select an option: " << std::endl;
        std::cout << "====================" << std::endl;
        std::cout << "Type in 0-6" << std::endl;
        
        int userOption;
        std::cin >> userOption;
        std:: cout << "You chose: " << userOption << std::endl;


        if(userOption < 0 || userOption > 6) //Bad input
        {
            std::cout << "Invalid choice. Choose 0-6." << std::endl;
        }
        if(userOption == 0)
        {
            isRunning = false;
            std::cout << "Exiting program." << std::endl;
        }
            if(userOption == 1) 
        {
            std::cout << "Help - your aim is to make money. Analyse the market and makes bids and offers" << std::endl;
        }
            if(userOption == 2) 
        {
            std::cout << "Markets looks good" << std::endl;
        }
            if(userOption == 3) 
        {
            std::cout << "Make an offer - enter the amount" << std::endl;
        }
            if(userOption == 4) 
        {
            std::cout << "Make a bid - enter the amount" << std::endl;
        }
            if(userOption == 5) 
        {
            std::cout << "Your wallet is empty" << std::endl;
        }
            if(userOption == 6) 
        {
            std::cout << "Going to next time frame" << std::endl;
        }
    }

    return 0;
}