#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
#include<stack>

//Brute Force (TC: O(N^2, SC: O(1)))
int shortest_unsorted_Array(vector<int>arr){
  int start = arr.size(); // Initialize start as maximum possible index
  int end = 0; // Initialize end as minimum possible index

  // Step 1: Compare every element with every other element to its right.
  for(int i=0; i<arr.size()-1; i++){
    for(int j=i+1; j<arr.size(); j++){
      // If we find a pair where arr[i] > arr[j], it means the array is unsorted here.
      if(arr[i] > arr[j]){
        // Step 2: Update start to the smallest index where the disorder begins.
        start = min(start, i);
        // Step 3: Update end to the largest index where disorder is detected.
        end = max(end, j);
      }
    }
  }
  // Step 4: Calculate the length of the unsorted subarray
  int length;
  // If 'end' > 'start', it means we found an unsorted region, so calculate length as (end - start + 1).
  if(end > start){
    length = end-start+1;
  }else{
    length = 0; // The array is already sorted
  }

  // Step 5: Print the result.
  cout<<"The Size of Size of shortest SubArray is: "<<length;
}

//Using Sorting And Extra Space (TC: O(nlogn), SC: O(N))
/*
STEPS
  1. Copy input array into new array
  2. Sort New array
  3. Traverse both array, if elem are same then skip otherwise
     calculete start = min(start, i) and end = max(end, j)
*/

//Using Sorting And Extra Space (TC: O(nlogn), SC: O(N))
int using_Sorting_AndExtraSpace(vector<int>arr){
  // Step 1: Store the size of the array in a variable for convenience.
  int n = arr.size();

  // Step 2: Initialize two variables:
  // - 'start' as the maximum possible index (n) to store the first mismatch index.
  // - 'end' as 0 to store the last mismatch index.
  int start = n; 
  int end = 0;  

  // Step 3: Create a new array (copy of the original array) to perform sorting
  // without modifying the original input.
  vector<int>newArray;
  for(int i=0; i<n; i++){
    newArray.push_back(arr[i]);
  }

  // Step 4: Sort the new array so that it becomes the fully sorted version of the original array.
  sort(newArray.begin(), newArray.end());

  // Step 5: Compare the original array with the sorted array.
  // Find the first and last positions where the two arrays differ.
  for(int i=0; i<n; i++){
    if(newArray[i] != arr[i]){
      // Step 6: Update 'start' to the smallest mismatch index.
      start = min(start, i);
      // Step 7: Update 'end' to the largest mismatch index.
      end = max(end, i);
    }
  }

  // Step 8: If end-start >= 0, it means there was an unsorted portion in the array.
  // Calculate and return the length as (end - start + 1).
  // Otherwise, the array was already sorted, so return 0.
  if(end-start >= 0){
    return end-start+1;
  }
  else{
    return 0;
  }
}

/* 
Purpose: To find the left and right boundaries of the unsorted subarray
Steps:
1. Traverse from left to right to find the left boundary (smallest out-of-order index)
2. Traverse from right to left to find the right boundary (largest out-of-order index)
*/

// Using Stack (TC: O(N), SC: O(N))
int Using_Stack(vector<int>arr){
  // Step 1: Store the size of the array in a variable for convenience.
  int n = arr.size();
  // Step 2: Initialize 'start' with n (max index) and 'end' with 0 (min index).
  // These will store the first and last mismatch positions.
  int start = n;
  int end = 0;
  // Step 3: Create a stack to keep track of indices for detecting boundaries.
  stack<int>st;

  // Step 4: Traverse the array from left to right to find the left boundary (start).
  for (int i = 0; i < n; i++) {
      // While stack is not empty and the element at stack top is greater than current element,
      // it means the current element should appear earlier, so update 'start'.
      while (!st.empty() && arr[st.top()] > arr[i]) {
          start = min(start, st.top());
          st.pop();
      }
      // Push the current index to the stack after processing.
      st.push(i); 
  }

  // Step 5: Clear the stack for reuse in the next traversal.
  while(!st.empty()){
    st.pop();
  }

  // Step 6: Traverse the array from right to left to find the right boundary (end).
   for (int i = n-1; i >= 0; i--) {
       // While stack is not empty and the element at stack top is less than current element,
       // it means the current element should appear later, so update 'end'.
       while (!st.empty() && arr[st.top()] < arr[i]) {
           end = max(end, st.top());
           st.pop();
       }
       // Push the current index to the stack after processing.
       st.push(i); 
   }
  // Step 7: Calculate the length of the subarray.
  // If end > start, return (end - start + 1), otherwise return 0 (array is already sorted).
  if(end-start > 0){
    return end-start+1;
  }else{
    return 0;
  }
}


int main(){
  vector<int>arr{2,6,4,8,10,9,15};

  // shortest_unsorted_Array(arr);
  // using_Sorting_AndExtraSpace(arr);
  cout<<"The lenght of shortest unsorted subarray is: "<<Using_Stack(arr);
}