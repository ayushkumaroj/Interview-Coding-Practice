#include<iostream>
using namespace std;
#include<vector>
#include<limits.h>

//TC: O(N) , SC: O(1)
int Brute_Force(vector<int>arr){
  for(int i=0; i<arr.size()-1; i++){
    bool isLeader = true;
    
    //Check if any element on right is greater
    for(int j=i+1; j<arr.size()-1; j++){
      if(arr[i] < arr[j]){
        isLeader = false;
        //Not a leader, no need to check further
        break;
      }
    }

    //If no greater elem found on right, its a leader
    if(isLeader){
      cout<<arr[i]<<" ";
    }
  }
  //Alway include the last element (as its always a leader)
  cout<<arr[arr.size()-1];
}

// TC: O(N), SC:O(1)
int Optimized_way(vector<int>arr){
  int Curr_Max = INT_MIN;

  //Traverse array from right to left
  for(int i= arr.size()-1; i>=0; i--){
    if(arr[i] > Curr_Max){
      cout<<arr[i]<<" ";
      // Update max so far
      Curr_Max = arr[i];
    }
  }
}



int main(){
  vector<int>arr{8,4,2,3,1,5,4,2};

  // Brute_Force(arr);
  Optimized_way(arr);
}