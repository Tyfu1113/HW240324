#include<iostream>

using namespace std;

int main(){
    int gradeArray[6], temp;
    char next='n';
    //set all arry value to zero
    for(int i=0; i<6; i++){
        gradeArray[i]=0;
    }
    //user enter grades
    do{
        cout << "Enter grade from 0 to 5> ";
        cin >> temp;
        //using switch to calculate each grade's value
        switch (temp){
            case 0:
                gradeArray[0]+=1;
                break;
            case 1:
                gradeArray[1]+=1;
                break;
            case 2:
                gradeArray[2]+=1;
                break;
            case 3:
                gradeArray[3]+=1;
                break;
            case 4:
                gradeArray[4]+=1;
                break;
            case 5:
                gradeArray[5]+=1;
                break;
        }
        // cout << "Enter next grade?(y/n): ";
        // cin >> next;
    }while(cin);
    //show result on screen
    cout << endl;
    for(int i=0; i<6; i++){
        cout << gradeArray[i] << " grade(s) of " << i << endl;
    }
}