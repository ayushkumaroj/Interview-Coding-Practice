/*
* * * * * *
*         *
*         *
* * * * * *
*/

#include<iostream>
using namespace std;
#include<vector>

int main(){
  int row;
  cout<<"Enter number of row: ";
  cin>>row;

  int col;
  cout<<"Enter number of column: ";
  cin>>col;

  for(int i=0; i<row; i++){
    for(int j=0; j<col; j++){
      if(i==0 || i==row-1){
        cout<<"*"<<" ";
      }
      else if(j==0 || j==col-1){
        cout<<"*"<<" ";
      }
      else{
        cout<<" "<<" ";
      }
    }
    cout<<endl;
  }
}