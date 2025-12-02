#include<iostream>
using namespace std;
#include<vector>
#include<limits.h>

//TC: O(N^2) , SC: O(1)
int Brute_Force(vector<int>arr){
  // Step 1: Start the first loop to pick every element in the array (except the last one).
  // The last element will always be a leader, so we handle it later.
  for(int i=0; i<arr.size()-1; i++){
    // Step 2: Assume the current element is a leader initially.
    bool isLeader = true;
    
    // Step 3: Check every element to the right of the current element.
    // If we find any element greater than the current element, then it is NOT a leader.
    for(int j=i+1; j<arr.size()-1; j++){
      if(arr[i] < arr[j]){
        // Step 4: Current element is smaller than some element on its right.
       // So, mark it as not a leader and break out of the loop.
        isLeader = false;
        break;
      }
    }

    // Step 5: If isLeader is still true after checking all elements to the right,
    // then print the current element as a leader.
    if(isLeader){
      cout<<arr[i]<<" ";
    }
  }
  // Step 6: The last element is always a leader by definition,
  // so print it explicitly.
  cout<<arr[arr.size()-1];
}

// TC: O(N), SC:O(1)
int Optimized_way(vector<int>arr){
  // Step 1: Initialize a variable to keep track of the maximum element seen so far from the right.
  // We start with INT_MIN so that the rightmost element is always considered a leader.
  int Curr_Max = INT_MIN;

  // Step 2: Traverse the array from right to left (reverse order),
  // because the last element is always a leader and this direction makes it easy to track leaders.
  for(int i= arr.size()-1; i>=0; i--){
    // Step 3: If the current element is greater than Curr_Max,
    // then it is a leader because nothing to its right is greater.
    if(arr[i] > Curr_Max){
      // Step 4: Print the leader element.
      cout<<arr[i]<<" ";
      // Step 5: Update Curr_Max to the current element,
      // because this is now the greatest element encountered so far from the right.
      Curr_Max = arr[i];
    }
  }
}



int main(){
  vector<int>arr{8,4,2,3,1,5,4,2};

  // Brute_Force(arr);
  Optimized_way(arr);
}