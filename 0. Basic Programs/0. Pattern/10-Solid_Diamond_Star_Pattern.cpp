#include<iostream>
using namespace std;

int main(){
  int row;
  cout<<"Enter numbe of row: ";
  cin>>row;

  //STEP 1: TOP HALF OF THE DIAMOND
  for(int i=0; i<row; i++){
    //print space before start to center-align the pyramid
    for(int j=0; j<row-i-1; j++){
      cout<<" ";
    }
    //print star with space after each(Increasing count)
    for(int j=0; j<i+1; j++){
      cout<<"* ";
    }
    //move to the next line after each row
    cout<<endl;
  }

  //STEP 2: BOTTOM HALF OF THE DIAMOND
  for(int i=0; i<row-1; i++){
    //print first space for alignment (increasing each count)
    for(int j=0; j<i+1; j++){
      cout<<" ";
    }
    //print decresing number of star with space
    for(int j=0; j<row-i-1; j++){
      cout<<"* ";
    }
    //move to the next line after each row
    cout<<endl;
  }

  return 0;
}

