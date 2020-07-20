//Creates a checkboard pattern

#include <iostream>
using namespace std;

const int width = 100;
const int length = 100;

int main(){
    bool alt = false;   //for alternating 
    
    for(int row = 0; row < length; row++){
        for(int col = 0; col < width; col++){
            if(alt){
                cout << "X" << "O";
            }else{
                cout << "O" << "X";
            }
        }
        alt = !alt;
        cout << endl;
    }
}