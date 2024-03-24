#include<iostream>
#include<ctime>

using namespace std;

int random1to3(){
    int num;
    num=(rand()%3)+1;
    return num;
}
bool compare(int pin[5], int input[5],int numArr[10]){
    for(int i=0; i<5; i++){
        if(numArr[pin[i]]!=input[i]){
            return false;
        }
    }
    return true;
}
int main(){
    int pin[5] = {7, 8, 7, 6, 3};
    int numArr[10], pinArr[5];
    srand(time(0));

    //create random number array
    cout << "PIN: 0 1 2 3 4 5 6 7 8 9" << endl;
    cout << "NUM: ";
    for(int i=0; i<10; i++){
        numArr[i]=random1to3();
        cout << numArr[i] << " ";
    }
    //user prompt his pin number
    cout << "\nEnter your pin number> ";
    for(int i=0; i<5; i++){
        cin >> pinArr[i];
    }
    //compare input with actual pin number
    if(compare(pin, pinArr, numArr)){
        cout << "User's response is correct !" << endl;
    }else{
        cout << "PIN you input is wrong." << endl;
    }


}