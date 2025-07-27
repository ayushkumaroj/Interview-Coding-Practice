#include<iostream>
using namespace std;

int main(){
  int row;
  cout<<"Enter number of row: ";
  cin>>row;

  //Outer loop for each row
  for(int i=0; i<row; i++){
    // Inner loop 1: Print spaces before the stars
    // This aligns the stars to form a centered pyramid
    for(int j=0; j<row-i; j++){
      cout<<" ";
    }
    // Inner loop 2: Print stars with spaces after each
    // Number of stars in row i is (2 * i + 1) when you count both stars and spaces
    for(int j=0; j<i+1; j++){
      cout<<"*"<<" ";
    }
    // Move to the next line after each row
    cout<<endl;
  }
}

