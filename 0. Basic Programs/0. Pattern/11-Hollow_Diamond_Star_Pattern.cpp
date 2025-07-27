#include<iostream>
using namespace std;

int main(){
  int row;
  cout<<"Enter number of row: ";
  cin>>row;

  for(int i=0; i<row; i++){
    //print space
    for(int j=0; j<row-i-1; j++){
      cout<<" ";
    }
    //print star
    for(int j=0; j<i-1; j++){
      cout<<"* ";
    }
    //print space
    for(int j=0; j<i; j++){
      cout<<" ";
    }
    //print star
    cout<<"*";
    cout<<endl;
  }
}

