#include<iostream>
using namespace std;
#include<vector>

int main(){
  int row;
  cout<<"Enter number of row: ";
  cin>>row;

  //Outer loop to print number of row
  for(int i=0; i<row; i++){
    //Inner loop to print number from 1 to (i+1) in each row
    for(int j=0; j<i+1; j++){
      cout<<j+1<<" ";
    }
    //Move to the next line after printing each row
    cout<<endl;
  }
  
}
