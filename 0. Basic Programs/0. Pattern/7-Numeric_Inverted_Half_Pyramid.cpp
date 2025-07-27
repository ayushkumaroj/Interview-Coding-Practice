#include<iostream>
using namespace std;

int main(){
  int row;
  cout<<"Enter number of row: ";
  cin>>row;

  //Outer loop to print number of row
  for(int i=0; i<row; i++){
    //Inner loop to print number from 1 to (row-i)
    // So each next row has one less number
    for(int j=0; j<row-i; j++){
      cout<<j+1<<" ";
    }
    //Move to the next row after printing current row
    cout<<endl;
  }
}
