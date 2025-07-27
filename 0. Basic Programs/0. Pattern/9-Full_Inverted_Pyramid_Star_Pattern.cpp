#include<iostream>
using namespace std;

int main(){
  int row;
  cout<<"Enter number of row: ";
  cin>>row;

  //outer loop to print number of row
  for(int i=0; i<row; i++){
    //first print space to center the star
    for(int j=0; j<i; j++){
      cout<<" ";
    }

    //print star followed by space
    //Number of star in each row = row-i
    for(int j=0; j<row-i; j++){
      cout<<"*"<<" ";
    }

    //move to next line after printing each row
    cout<<endl;
  }
}

