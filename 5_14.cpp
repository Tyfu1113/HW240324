#include<iostream>
#include<cmath>
#include<ctime>

using namespace std;
int random1to5(){
    int num;
    num=(rand()%5)+1;
    return num;
}
//Get user's rating score
void input(int &num, int &rating, int (&userInput)[6]){
    //return array to zero
    for(int i=0; i<6; i++){
        userInput[i]=0;
    }
    //get user input
    for(int i=0; i<3; i++){
        cout << "Enter " << i+1 << " movie number and rating> ";
        cin >> num >> rating;
        userInput[num%100]=rating;
    }
}
//Calculate Cartesian distance
void cartDistance(int table[4][6], int userInput[6],int (&result)[4]){
    int nearest;
    //return result to zero
    for(int i=0; i<4; i++){
        result[i]=0;
    }
    //calculate distance
    for(int i=0; i<4; i++){
        for(int j=0; j<6; j++){
            if(userInput[j]!=0){
                result[i]+=pow(table[i][j]-userInput[j], 2);
            }
        }
    }
    nearest = std::min({result[0], result[1], result[2], result[3]});
    //show the closest reviewer number and predict rating
    for(int i=0; i<4; i++){
        if(result[i]==nearest){
            cout << "The closest match is reviewer " << i << endl;
            for(int j=0; j<6; j++){
                if(userInput[j]==0){
                    cout << "Program predict the rating of " << j << " is " << table[i][j] << endl;
                }
            }
        }
    }

}
int main(){
    int table[4][6]={   {3, 1, 5, 2, 1, 5},
                        {4, 2, 1, 4, 2, 4},
                        {3, 1, 2, 4, 4, 1},
                        {5, 1, 4, 2, 4, 2}};
    int userInput[6], result[4], num, rating;
    srand(time(0));

    //creating an random rating table
    cout << "\t100\t101\t102\t103\t104\t105";
    for(int i=0; i<4; i++){
        cout << "\n" << i;
        for(int j=0; j<6; j++){
            cout << "\t" << table[i][j];
        }
    }
    cout << endl;
    input(num, rating, userInput);
    cartDistance(table, userInput, result);
}