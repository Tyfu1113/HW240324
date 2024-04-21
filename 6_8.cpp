#include<iostream>
#include<iomanip>

using namespace std;

class Money{
    public:
        int getDollars(){
            return dollars;
        }
        int getCents(){
            return cents;
        }
        void setMoney(int dollar, int cent){
            dollars=dollar;
            cents=cent;
        }
    private:
        int dollars;
        int cents;
};
//calculate monetary amount
double monetaryAmount(Money money){
    double amount=money.getDollars()+money.getCents()/100.0;
    return amount;
}

int main(){
    Money account1, account2;
    //test first Money object
    account1.setMoney(20, 17);
    cout << fixed << setprecision(2);
    cout << "The monetary amout of account 1 is " << monetaryAmount(account1) << endl;
    //tes second Money object
    account2.setMoney(233, 03);
    cout << fixed << setprecision(2);
    cout << "The monetary amout of account 2 is " << monetaryAmount(account2) << endl;
}