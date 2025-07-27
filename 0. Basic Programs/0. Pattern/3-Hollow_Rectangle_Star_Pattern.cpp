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

  //Loop through each row
  for(int i=0; i<row; i++){
    //Loop through each col in current row
    for(int j=0; j<col; j++){
      //Print star if it is first row or last row
      if(i==0 || i==row-1){
        cout<<"*"<<" ";
      }
      //Print star if it is first or last column
      else if(j==0 || j==col-1){
        cout<<"*"<<" ";
      }
      //Otherwise print space (for hollow part)
      else{
        cout<<" "<<" ";
      }
    }
    //Move to the next line after each row
    cout<<endl;
  }
}

