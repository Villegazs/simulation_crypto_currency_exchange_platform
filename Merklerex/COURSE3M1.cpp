#include <iostream>
#include "BitcoinMain.h"
int main()
{
    BitcoinMain app("2023-01-01", 45000.0, 85000000000.0, 250000000.0);
    app.Init();
    return 0;
}