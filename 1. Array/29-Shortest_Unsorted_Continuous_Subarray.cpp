#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
#include<stack>

//Brute Force (TC: O(N^2, SC: O(1)))
int shortest_unsorted_Array(vector<int>arr){
  int start = arr.size();
  int end = 0;

  //compare every element with all next element
  for(int i=0; i<arr.size()-1; i++){
    for(int j=i+1; j<arr.size(); j++){
      if(arr[i] > arr[j]){
        //update starting index
        start = min(start, i);
        //update ending index
        end = max(end, j);
      }
    }
  }
  int length = end-start+1;
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
  int start = arr.size();
  int end = 0;

  //Step 1: Copy array to new array
  vector<int>newArray;
  for(int i=0; i<arr.size(); i++){
    newArray.push_back(arr[i]);
  }

  //Step 2: Sort the new array
  sort(newArray.begin(), newArray.end());

  //Step 3: Compare original and sorted arrays to find mismatch positions
  for(int i=0; i<arr.size(); i++){
    if(newArray[i] != arr[i]){
      start = min(start, i);
      end = max(end, i);
    }
  }

  // If the array was already sorted, return 0
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
  int start = arr.size();
  int end = 0;
  stack<int>st;

  //Step 1: Traverse array from left to right and get left boundary
  for (int i = 0; i < arr.size(); i++) {
      while (!st.empty() && arr[st.top()] > arr[i]) {
          start = min(start, st.top());
          st.pop();
      }
      st.push(i); // Push only once after clearing larger elements
  }

  //Clear the stack for second traversal
  while(!st.empty()){
    st.pop();
  }

  //Step 2: Traverse array from right to left and get right boundary
   for (int i = arr.size() - 1; i >= 0; i--) {
       while (!st.empty() && arr[st.top()] < arr[i]) {
           end = max(end, st.top());
           st.pop();
       }
       st.push(i); // Push only once after clearing smaller elements
   }

  if(end-start > 0){
    return end-start+1;
  }
  else{
    return 0;
  }
}


int main(){
  vector<int>arr{2,6,4,8,10,9,15};

  // shortest_unsorted_Array(arr);
  // using_Sorting_AndExtraSpace(arr);
  cout<<"The lenght of shortest unsorted subarray is: "<<Using_Stack(arr);
}