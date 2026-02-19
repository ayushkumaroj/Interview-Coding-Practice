#include<iostream>
using namespace std;
#include<vector>

int main(){
    int decimal;
    cin>>decimal;

    int binary[50];
    int idx = 0;

    while(decimal > 0){
        binary[idx] = decimal % 2;
        decimal = decimal / 10;
        idx++;
    }
    
}