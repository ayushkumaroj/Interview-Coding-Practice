#include<iostream>
using namespace std;
#include<vector>
#include<limits.h>

//TC: O(N) , SC: O(1)
int Brute_Force(vector<int>arr){
  for(int i=0; i<arr.size()-1; i++){
    bool isLeader = true;
    for(int j=i+1; j<arr.size()-1; j++){
      if(arr[i] < arr[j]){
        isLeader = false;
        break;
      }
    }
    if(isLeader){
      cout<<arr[i]<<" ";
    }
  }
  //If it says to include last elem
  // cout<<arr[arr.size()-1];
}

// TC: O(N), SC:O(1)
int Optimized_way(vector<int>arr){
  int Curr_Max = INT_MIN;

  //Traverse array from right to left
  for(int i= arr.size()-1; i>=0; i--){
    if(arr[i] > Curr_Max){
      cout<<arr[i]<<" ";
      Curr_Max = arr[i];
    }
  }
}



int main(){
  vector<int>arr{8,4,2,3,1,5,4,2};

  // Brute_Force(arr);
  Optimized_way(arr);
}