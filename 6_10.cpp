#include<iostream>

using namespace std;

class Temperature{
    public:
        void setTempKelvin(double temp){
            tempK=temp;
        }
        //convert from Celsius to Kelvin
        void setTempCelsius(double temp){
            tempK=temp+273.15;
        }
        //convert from Fahrenheit to Kelvin
        void setTempFahrenheit(double temp){
            temp= (5.0/9)*(temp-32)+273.15;
        }
        double getTempKelvin(){
            return tempK;
        }
        //convert from Kelvin to Celsius
        double getTempCelsius(){
            double result=tempK;
            result-=273.15;
            return result;
        }
        //convert from Kelvin to Fahrenheit
        double getTempFahrenheit(){
            double result=tempK;
            result=(result-273.15)*(9.0/5)+32;
            return result;
        }
    private:
        double tempK;
};

int main(){
    Temperature temp;
    //input with scale Kelvin
    temp.setTempKelvin(97);
    cout << "\nThe origin degree is 97 in scale Kevin." 
        << "\nThe degree in scale Celsius is " << temp.getTempCelsius()
        << "\nThe degree in scale Fahrenheit is " << temp.getTempFahrenheit() << endl;
    //input with Celsius
    temp.setTempCelsius(23);
    cout << "\nThe origin degree is 23 in scale Celsius." 
        << "\nThe degree in scale Kelvin is " << temp.getTempKelvin()
        << "\nThe degree in scale Fahrenheit is " << temp.getTempFahrenheit() << endl;
    //input with scale Fahrenheit
    temp.setTempFahrenheit(57);
    cout << "\nThe origin degree is 57 in scale Fahrenheit." 
        << "\nThe degree in scale Kelvin is " << temp.getTempKelvin()
        << "\nThe degree in scale Celsius is " << temp.getTempCelsius() << endl;

}