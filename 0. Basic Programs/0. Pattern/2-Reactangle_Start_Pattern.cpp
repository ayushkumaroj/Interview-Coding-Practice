/*
* * * * *
* * * * *
* * * * *
*/

#include<iostream>
using namespace std;

int main(){
  //Ask user to enter number of row
  int row;
  cout<<"Enter number of row: ";
  cin>>row;

  //Ask user to enter number of column
  int col;
  cout<<"Enter number of column: ";
  cin>>col;

  //Outer loop for each row
  for(int i=0; i<row; i++){
    //Inner loop for each column (Print start in each row)
    for(int j=0; j<col; j++){
      cout<<"*"<<" ";
    }
    //Move to next line after printing one row
    cout<<endl;
  }
}

