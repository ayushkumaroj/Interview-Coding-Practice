#include<iostream>
using namespace std;
#include<vector>

//Brute Force(TC: O(N2), SC:O(N))
int BruteForce(vector<int>arr){
  // Step 1: Create a new vector to store the result.
  vector<int>ans;
  
  // Step 2: Traverse the original array and push all even numbers into ans.
  for(int i=0; i<arr.size(); i++){
    if(arr[i] % 2 == 0){ // Check if the number is even
      ans.push_back(arr[i]);
    }
  }

  // Step 3: Traverse the original array again and push all odd numbers into ans.
  for(int j= 0; j<arr.size(); j++){
    if(arr[j] % 2 != 0){ // Check if the number is odd
      ans.push_back(arr[j]);
    }
  }

  // Step 4: Print the rearranged array.
  for(int i=0; i<ans.size(); i++){
    cout<<ans[i]<<" ";
  }
}

//Using Two pointer (TC: O(N), SC:O(1))
int Using_Two_Pointer(vector<int>arr){
  // Step 1: Initialize two pointers: start (beginning) and end (last index).
  int start = 0;
  int end = arr.size()-1;

  // Step 2: Process elements until start crosses end.
  while(start <= end){
    // Case 1: If the element at 'start' is even, it's already in correct position → move start forward.
    if(arr[start] % 2 == 0){
      start++;
    }
    // Case 2: If the element at 'end' is odd, it's in correct position → move end backward.
    else if(arr[end] % 2 != 0){
      end--;
    }
    // Case 3: If 'start' has an odd number and 'end' has an even number → swap them.
    else if(arr[end] % 2 == 0){
      swap(arr[start], arr[end]);
      start++;
      end--;
    }
  }
  
  // Step 3: Print the array after rearrangement.
  for(int i=0; i<arr.size(); i++){
    cout<<arr[i]<<" ";
  }
}

int main(){
  vector<int>arr{3,1,2,4};

  // Using_Two_Pointer(arr);
  BruteForce(arr);
}