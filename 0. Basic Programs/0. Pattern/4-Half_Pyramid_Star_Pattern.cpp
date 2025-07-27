/*
*
* *
* * *
* * * *
* * * * *
*/

#include<iostream>
using namespace std;

int main(){
  int row;
  cout<<"Enter number of row: ";
  cin>>row;

  //Loop through each row
  for(int i=0; i<row; i++){
    //Inner loop to print star in each row
    // In row 'i' print (i+1) star
    for(int j=0; j<i+1; j++){
      cout<<"*"<<" ";
    }
    //Move to next line after printing one row
    cout<<endl;
  }
}
