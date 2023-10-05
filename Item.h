#include <string>
using namespace std;

class Item{
    protected: 
        string name;
        double sellPrice;
        double purchasePrice;
        bool hasExpiry;
    public:
        virtual string getName(){return name;}
        virtual double getsellPrice(){return sellPrice;}
        virtual double getpurchasePrice(){return purchasePrice;}
        virtual bool gethasExpiry(){return hasExpiry;}
};                                                                                                                                 