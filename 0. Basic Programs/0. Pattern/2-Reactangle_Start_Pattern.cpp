/*
* * * * *
* * * * *
* * * * *
*/

#include<iostream>
using namespace std;

int main(){
  int row;
  cout<<"Enter number of row: ";
  cin>>row;

  int col;
  cout<<"Enter number of column: ";
  cin>>col;

  for(int i=0; i<row; i++){
    for(int j=0; j<col; j++){
      cout<<"*"<<" ";
    }
    cout<<endl;
  }
}