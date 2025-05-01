#include<iostream>
using namespace std;
#include<vector>

//Approch 1: Counting Approach (TC: O(n), SC:O(1)-Extra space for count)
void SortZeroOne1(vector<int>arr){
  int countZero = 0;
  int countOne = 0;

  //Count Number of Zero and One
  for(int i=0; i<arr.size(); i++){
    if(arr[i] == 0){
      countZero++;
    }
    else{
      countOne++;
    }
  }
  //Fill array with zeroes up to countZero
  for(int i=0; i<countZero; i++){
    arr[i] = 0;
  }

  //// Fill the rest with ones
  for(int i= countZero; i<arr.size(); i++){
    arr[i] = 1;
  }
  
  //Finally print the array
  for(int i=0; i<arr.size(); i++){
    cout<<arr[i] <<" ";
  }
  cout<<endl;
}

//Approch 2: Using Two pointer (T.C: O(n), S.C: O(n))
void SortZeroOne2(vector<int>&arr){
  int start = 0;
  int end = arr.size()-1;

  while(start <= end){
    //if first element is 0, then
    if(arr[start] == 0){
      //just increment the start
      start++;
    }
    //if last element is 1 , then
    else if(arr[end] == 1){
      //just decrment the end
      end--;
    }
    //If first elem is 1 and last elemn is 0, thne
    else if(arr[start] == 1 && arr[end] == 0){
      swap(arr[start], arr[end]);
      start++;
      end--;
    }
    cout<<endl;
  }

  //Just print the array
  for(int i=0; i<arr.size(); i++){
    cout<<arr[i]<<" ";
  }
}


int main(){
  vector<int>arr{1,0,1,0,1,0,1,0,1};

  SortZeroOne1(arr);
  SortZeroOne2(arr);

  return 0;
}