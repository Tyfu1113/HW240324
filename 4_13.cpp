#include<iostream>
#include<iomanip>

using namespace std;
//input is minute and second
double convertToMPH(int minute, int second){
    double total_sec, mph;
    total_sec+=minute*60+second;
    mph=(1/total_sec)*3600;
    return mph;
}
//input is kph
double convertToMPH(double kph){
    kph/=1.6;
    return kph;
}
int main(){
    std::cout << std::fixed;
    std::cout << setprecision(2);
    cout << "Giving function two variable(minute, second)" << endl;
    cout << "The MPH of 5:30 mile is " << convertToMPH(5, 30) << endl;
    cout << "Giving function kph to convert to mph" << endl;
    cout << "The MPH of 170 kph is " << convertToMPH(170) << endl;

}