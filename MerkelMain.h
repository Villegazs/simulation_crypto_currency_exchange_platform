
class MerkelMain
{
    public:
        MerkelMain();
        void Init();
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
};