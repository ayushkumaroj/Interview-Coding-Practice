#include<iostream>
using namespace std;
#include<algorithm>
#include<vector>

void MoveNegative(vector<int>arr){
  int start = 0;
  int end = arr.size()-1;

  for(int i=0; i<arr.size(); i++){
    //if first elem is less then zero, simply incr start
    if(arr[start] < 0){
      start++;
    }
    //if last elem is less then zero , swap it
    else if(arr[end] < 0){
      swap(arr[start], arr[end]);
      start++;
      end--;
    }
    //if last elem is greater then zero , just decrement it
    else if(arr[end] > 0){
      end--;
    }
  }

  //sort the entire array
  sort(arr.begin(),arr.end());

  //Finally print the array
  for(int i=0; i<arr.size(); i++){
    cout<<arr[i]<<" ";
  }
}

int main(){
  vector<int>arr{-2,1,0,-6,12,90,65,-3};

  MoveNegative(arr);
}