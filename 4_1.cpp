#include<iostream>
#include<iomanip>

using namespace std;

//convert 24 to 12
void Convertion(int &hour, int &minute, char &notation){
    hour-=12;
    notation = 'p';
}
//user input function
void Userinput(int &hour, int &minute){
    cout << "Enter the hour and minute separate with space> ";
    cin >>  hour >> minute;
}
//show convert result on screen
void Output(int &hour, int &minute, char &notation){
    //make sure time is in reasonable range
    if(hour<0 || minute<0){
        cout << "Time should be postive" << endl;
    }else if(hour>23 || minute>59){
        cout << "check your input if hour<23 and minute<59 or not" << endl;
    }else{
        //if it is, doing the convertion
        Convertion(hour, minute, notation);
        switch(notation){
            case 'a':
                cout << hour << ":" << minute << "A.M." << endl;
                break;
            case 'p':
                cout << hour << ":" << minute << "P.M." << endl;
        }  
    }
    
    
}

int main(){
    int hour, minute;
    char notation='a', again='n';
    bool loop=true;
    do{
        Userinput(hour, minute);
        Output(hour, minute, notation);
        cout << "Do you want to convert next time?(y/n): ";
        cin >> again;
        if(again=='n'){loop=false;}
        else{loop=true;}
    }while(loop);

}
