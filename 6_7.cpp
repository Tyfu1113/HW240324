#include<iostream>
#include<string>

using namespace std;

class Pizza{
public:
    string getType(){
        return type;
    }
    char getSize(){
        return size;
    }
    int getTopping(){
        return topping;
    }
    void setPizza(string pizzaType, char pizzeSize, int pizzaToppings){
        type=pizzaType;
        size=pizzeSize;
        topping=pizzaToppings;
    }
private:
    string type;
    char size;
    int topping;
};
//the function to describe the pizza
void outputDescription(Pizza pizza){
    cout << "This is a " << pizza.getSize() << " " << pizza.getType() << " pizza with "
    << pizza.getTopping() << " toppings on it." << endl;
}
//the function to compute the price of pizza
double computePrice(Pizza pizza){
    //switch to different size
    switch(pizza.getSize()){
        case 's':
            return 10.0+2*pizza.getTopping();
            break;
        case 'm':
            return 14.0+2*pizza.getTopping();
            break;
        case 'l':
            return 17+.02*pizza.getTopping();
            break;
    }
}
int main(){
    Pizza pizza1, pizza2;
    pizza1.setPizza("hand toss", 'm', 3);
    pizza2.setPizza("", 'l', 1);

    //test function
    outputDescription(pizza1);
    cout << "The price of pizza1 is $" << computePrice(pizza1) << endl;
    outputDescription(pizza2);
    cout << "The price of pizza2 is $" << computePrice(pizza2) << endl;
    
}
