#include <iostream>
#include <string>
#include <vector>
#include "MerkelMain.h"
#include "CSVReader.h"



int main() {


    //MerkelMain app{};
    //app.Init();

	CSVReader::readCSV("20200317.csv");
    return 0;
}


// The following code is for testing purposes only. It is not part of the main program. It is used to test the functions that compute the average price, low price, high price and price spread. It is also used to test the iteration over a vector of OrderBookEntry objects. It is commented out because it is not part of the main program. It can be uncommented for testing purposes only.

/*double computeAveragePrice(std::vector<OrderBookEntry>& orders)
{
    double totalPrice = 0.0;
    for (OrderBookEntry order : orders)
    {
        totalPrice += order.price;
    }
    return totalPrice / orders.size();
}
double computeLowPrice(std::vector<OrderBookEntry>& orders)
{
    double lowPrice = orders[0].price;
    for (OrderBookEntry order : orders)
    {
        if (order.price < lowPrice)
        {
            lowPrice = order.price;
        }
    }
    return lowPrice;
}

double computeHighPrice(std::vector<OrderBookEntry>& orders)
{
    double highPrice = orders[0].price;
    for (OrderBookEntry order : orders)
    {
        if (order.price > highPrice)
        {
            highPrice = order.price;
        }
    }
    return highPrice;
}

double computePriceSpread(std::vector<OrderBookEntry>& orders)
{
    double lowPrice = computeLowPrice(orders);
    double highPrice = computeHighPrice(orders);
    return highPrice - lowPrice;
}
*/

/*std::vector<OrderBookEntry> orders;



    orders.push_back(OrderBookEntry{
        10000,
        0.001,
        "2020/03/17 17:01:24.884492",
        "BTC/USD",
        OrderBookType::bid
    });

        orders.push_back(OrderBookEntry{
        20000,
        0.002,
        "2020/03/17 17:01:24.884492",
        "BTC/USD",
        OrderBookType::bid
    });

    std::cout << "Average price: " << computeAveragePrice(orders) << std::endl;
    std::cout << "Low price: " << computeLowPrice(orders) << std::endl;
    std::cout << "High price: " << computeHighPrice(orders) << std ::endl;
    std::cout << "Price spread: " << computePriceSpread(orders) << std::endl;

    // Iterate over a vector

    for (OrderBookEntry order : orders) //Works on the copy of the order, not the original order. If we want to change the original order, we need to use a reference.
    {
        std::cout << "Order details: " << std::endl;
        std::cout << "Price: " << order.price << std::endl;
        std::cout << "Amount: " << order.amount << std::endl;
        std::cout << "Timestamp: " << order.timeStamp << std::endl;
        std::cout << "Product: " << order.product << std::endl;
    }

    //Iterating by reference
    for (OrderBookEntry& order : orders) //Works on the original order, not the copy of the order. If we want to change the original order, we need to use a reference.
    {
        std::cout << "Order details: " << std::endl;
        std::cout << "Price: " << order.price << std::endl;
        std::cout << "Amount: " << order.amount << std::endl;
        std::cout << "Timestamp: " << order.timeStamp << std::endl;
        std::cout << "Product: " << order.product << std::endl;
    }

    for (unsigned int  i = 0; i < orders.size(); ++i) //Works on the original order, not the copy of the order. If we want to change the original order, we need to use a reference.
    {
        std::cout << "Order details: " << std::endl;
        std::cout << "Price: " << orders[i].price << std::endl;
        std::cout << "Amount: " << orders[i].amount << std::endl;
        std::cout << "Timestamp: " << orders[i].timeStamp << std::endl;
        std::cout << "Product: " << orders[i].product << std::endl;
    }

    //++i is more efficient than i++ because it does not require a temporary variable to hold the value of i before incrementing it. In this case, since we are not using the value of i after incrementing it, we can use ++i to avoid unnecessary overhead.

    for(unsigned int i = 0; i < orders.size(); ++i) //Works on the original order, not the copy of the order. If we want to change the original order, we need to use a reference.
    {
        std::cout << "Order details: " << std::endl;
        std::cout << "Price: " << orders.at(i).price << std::endl;
        std::cout << "Amount: " << orders.at(i).amount << std::endl;
        std::cout << "Timestamp: " << orders.at(i).timeStamp << std::endl;
        std::cout << "Product: " << orders.at(i).product << std::endl;
    } */