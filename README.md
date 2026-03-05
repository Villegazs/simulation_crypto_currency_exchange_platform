# Merklerex - Cryptocurrency Exchange Simulation Platform

A C++ console-based simulation of a cryptocurrency exchange trading platform that allows users to analyze market data, place bids and asks, and track their wallet balance.

## Table of Contents

- [Overview](#overview)
- [Features](#features)
- [Project Structure](#project-structure)
- [Technologies](#technologies)
- [Getting Started](#getting-started)
- [Usage](#usage)
- [Implementation Details](#implementation-details)
- [Key Components](#key-components)
- [Data Format](#data-format)
- [Future Enhancements](#future-enhancements)

##  Overview

Merklerex is a cryptocurrency exchange simulator that processes historical market data from CSV files and provides an interactive command-line interface for users to:
- View real-time market statistics
- Place buy (bid) and sell (ask) orders
- Track price changes across different cryptocurrency pairs
- Manage a virtual wallet
- Simulate order matching between buyers and sellers

##  Features

- **Market Analysis**
  - Real-time statistics for multiple cryptocurrency pairs
  - Highest, lowest, and mean price calculations
  - Percentage price change tracking with color-coded output (green/red)
  - Separate statistics for bids and asks

- **Order Management**
  - Place ask orders (sell orders)
  - Place bid orders (buy orders)
  - Automatic order matching engine
  - Order validation and error handling

- **Wallet System**
  - Multi-currency wallet support
  - Currency insertion and removal
  - Order fulfillment validation
  - Automatic wallet updates on successful trades

- **Time Simulation**
  - Step through historical market data timestamp by timestamp
  - View market state at each time frame
  - Automatic wrapping to beginning when reaching the end

##  Project Structure

```
Merklerex/
??? MerkelMain.cpp/h          # Main application controller
??? OrderBook.cpp/h           # Order book management and matching engine
??? OrderBookEntry.cpp/h      # Individual order entry structure
??? Wallet.cpp/h              # Wallet management system
??? CSVReader.cpp/h           # CSV file parsing utilities
??? Merklerex.cpp             # Program entry point
??? test.csv                  # Sample market data file
```

### Class Descriptions

#### `MerkelMain`
The main application controller that handles:
- User interface and menu system
- User input processing
- Coordination between OrderBook and Wallet
- Market statistics display

#### `OrderBook`
Core trading engine that manages:
- Loading and storing market orders
- Product/currency pair tracking
- Order matching algorithm (asks to bids)
- Statistical analysis (high/low/mean prices, price changes)
- Time-based order filtering

#### `OrderBookEntry`
Data structure representing a single market order with:
- Timestamp
- Product (currency pair, e.g., "ETH/BTC")
- Order type (ask/bid)
- Price
- Amount

#### `Wallet`
User's virtual wallet that handles:
- Multi-currency balance tracking
- Currency deposits and withdrawals
- Order fulfillment validation
- Automatic balance updates on trades

#### `CSVReader`
Utility class for:
- Parsing CSV market data files
- Tokenizing CSV lines
- Converting string data to OrderBookEntry objects
- Input validation

##  Technologies

- **Language:** C++14
- **Build System:** Visual Studio 2022 (MSVC 14.44)
- **Standard Library Features:**
  - STL containers (vector, map, string)
  - File I/O (ifstream)
  - Exception handling
  - ANSI color codes for terminal output

##  Getting Started

### Prerequisites

- Visual Studio 2022 or compatible C++14 compiler
- Windows operating system (for ANSI color codes)

### Building the Project

1. Clone the repository:
```bash
git clone https://github.com/Villegazs/simulation_crypto_currency_exchange_platform
cd Merklerex
```

2. Open the solution in Visual Studio:
   - Open `Merklerex.sln` in Visual Studio 2022

3. Build the project:
   - Press `Ctrl + Shift + B` or select `Build > Build Solution`

4. Ensure your CSV data file is in the correct location:
   - Place your market data CSV file (e.g., `20200317.csv`) in the project directory
   - Update the filename in `OrderBook` constructor if using a different file

### Running the Application

1. Run from Visual Studio:
   - Press `F5` or select `Debug > Start Debugging`

2. Or run the compiled executable:
```bash
.\x64\Debug\Merklerex.exe
```

##  Usage

### Main Menu Options

```
1. Print Help          - Display help information
2. Print Exchange Stats - View market statistics for all products
3. Make an Ask         - Place a sell order
4. Make a Bid          - Place a buy order
5. Print Wallet        - Display wallet contents
6. Continue            - Advance to next time frame
7. Exit Program        - Quit the application
```

### Placing Orders

**Format:** `product,price,amount`

**Example Ask (Sell):**
```
Make an ask - enter the amount: product, price, amount
ETH/BTC,0.023,4000
```

**Example Bid (Buy):**
```
Make a bid - enter the amount: product, price, amount
ETH/BTC,0.022,5000
```

### Reading Market Statistics

The application displays:
- Product name (e.g., ETH/BTC, DOGE/BTC)
- Number of asks and bids
- Highest, lowest, and mean prices
- Price change percentage (color-coded)
  - ?? Green: Positive price change
  - ?? Red: Negative price change

##  Implementation Details

### Order Matching Algorithm

The matching engine pairs asks (sell orders) with bids (buy orders):

1. **Filtering:** Retrieves all asks and bids for a specific product at the current timestamp
2. **Sorting:** Orders asks by price (ascending) and bids by price (descending)
3. **Matching:** Iterates through sorted orders, matching compatible prices
4. **Execution:** Creates sale entries when matches occur
5. **Quantity Handling:** Supports partial fills when order amounts differ

### CSV Data Format

Expected CSV format:
```
timestamp,product,orderType,price,amount
2020/03/17 17:01:24.884492,ETH/BTC,bid,0.023,4000
2020/03/17 17:01:24.884492,ETH/BTC,ask,0.024,3500
```

### Price Change Calculation

```cpp
percentageChange = ((currentMeanPrice - previousMeanPrice) / previousMeanPrice) * 100.0
```

### Tokenization

The CSV tokenizer:
- Splits strings by a specified separator (default: comma)
- Handles empty tokens
- Supports custom separators for flexible parsing

## ?? Key Components

### Order Book Management

```cpp
OrderBook orderBook{"market_data.csv"};
std::vector<OrderBookEntry> orders = orderBook.getOrders(
    OrderBookType::ask, 
    "ETH/BTC", 
    currentTime
);
```

### Statistical Analysis

```cpp
double highPrice = OrderBook::getHighPrice(orders);
double lowPrice = OrderBook::getLowPrice(orders);
double meanPrice = OrderBook::getMeanPrice(orders);
double priceChange = orderBook.getPercentagePriceValueChange(orders);
```

### Wallet Operations

```cpp
Wallet wallet;
wallet.insertCurrency("USDT", 10000);
bool canTrade = wallet.containsCurrency("USDT", 100);
wallet.removeCurrency("USDT", 50);
```

##  Data Format

### OrderBookEntry Structure

| Field | Type | Description |
|-------|------|-------------|
| timestamp | string | Order creation time |
| product | string | Currency pair (e.g., "BTC/USDT") |
| orderType | OrderBookType | "ask" or "bid" |
| price | double | Order price |
| amount | double | Order quantity |

##  Future Enhancements

- [ ] Persistent wallet state across sessions
- [ ] Advanced order types (limit, stop-loss, market)
- [ ] Chart visualization of price history
- [ ] Multi-user simulation
- [ ] Trading bot integration
- [ ] Portfolio performance analytics
- [ ] Real-time data feed integration
- [ ] Web-based UI
- [ ] Transaction history logging
- [ ] Risk management features

##  Notes

- The application uses ANSI escape codes for colored terminal output
- Order matching occurs only when advancing the time frame
- The simulation wraps around to the beginning when reaching the last timestamp
- All monetary values are stored as double precision floating-point numbers

##  Contributing

Contributions are welcome! Please feel free to submit a Pull Request.

##  License

This project is part of a Coursera C++ programming course assignment.

##  Author

**Villegazs**
- GitHub: [@Villegazs](https://github.com/Villegazs)
- Repository: [simulation_crypto_currency_exchange_platform](https://github.com/Villegazs/simulation_crypto_currency_exchange_platform)

##  Acknowledgments

- Coursera C++ Programming Course
- Object-Oriented Programming principles
- Modern C++ best practices (C++14)

---

**Note:** This is a simulation for educational purposes and should not be used for actual cryptocurrency trading.
