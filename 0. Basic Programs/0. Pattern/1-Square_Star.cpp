/*
* * * *
* * * *
* * * *
* * * *
*/

#include<iostream>
using namespace std;

int main(){
  
  //Loop through each row (total 4 rows)
  for(int row=0; row<4; row++){
    //Loop through each column in current row (print 4 star in each row)
    for(int col=0; col<4; col++){
      cout<<"*"<<" ";
    }
    //Move to the next line after printing on row
    cout<<endl;
  }
}

