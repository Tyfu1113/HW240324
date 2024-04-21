#include<iostream>

using namespace std;

class HotDogStand{
    private:
        int id, numberSoldOfDay;
        static int totalIncrement;
    public:
        //constructor
        HotDogStand(int id, int numberSoldOfDay){
            this->id=id;
            this->numberSoldOfDay=numberSoldOfDay;
        };
        void justSold(){
            numberSoldOfDay+=1;
            totalIncrement+=1; //invoke when hot dogt gott sell
        }
        int getTotalSold(){
            return numberSoldOfDay;
        }
        static int getTotalIncrement(){
            return totalIncrement;
        }
};
int HotDogStand::totalIncrement=0;

int main(){
    //initialize three hot dogs stands
    HotDogStand stand1(402001, 7);
    HotDogStand stand2(402002, 13);
    HotDogStand stand3(402003, 0);
    //simulate stands sell hot dogs
    stand1.justSold();
    stand2.justSold();
    stand2.justSold();
    stand1.justSold();
    stand3.justSold();
    //get the total number of hot dogs sold by the stand
    cout << "The stand 1 has sold " << stand1.getTotalSold() << " hot dog(s) today.\n";
    cout << "The stand 2 has sold " << stand2.getTotalSold() << " hot dog(s) today.\n";
    cout << "The stand 3 has sold " << stand3.getTotalSold() << " hot dog(s) today.\n";
    cout << "The total increment of the day is " << HotDogStand::getTotalIncrement() << endl;
}