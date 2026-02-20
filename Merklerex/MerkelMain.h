#pragma once

#include <vector>
#include "OrderBookEntry.h"
#include "OrderBook.h"

class MerkelMain
{
public:
    MerkelMain();
    /** Call this to start the simulation */
    void Init();
private:
    void loadOrderBook();
    void printMenu();
    void printHelp();
    void printMarketStats();
    void enterOffer();
    void enterBid();
    void printWallet();
    void goToNextTimeFrame();
    int getUserOption();
    void processUserOption(int option);
    bool isRunning = true;

    OrderBook orderBook{"20200317.csv"};

};