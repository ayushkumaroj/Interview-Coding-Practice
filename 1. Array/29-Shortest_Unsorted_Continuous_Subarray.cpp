#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
#include<stack>

//Brute Force (TC: O(N^2, SC: O(1)))
int shortest_unsorted_Array(vector<int>arr){
  int start = arr.size();
  int end = 0;
  for(int i=0; i<arr.size()-1; i++){
    for(int j=i+1; j<arr.size(); j++){
      if(arr[i] > arr[j]){
        start = min(start, i);
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

  //copy elem into newArray
  vector<int>newArray;
  for(int i=0; i<arr.size(); i++){
    newArray.push_back(arr[i]);
  }

  //sort the new Array
  sort(newArray.begin(), newArray.end());

  //Traverse both the array
  for(int i=0; i<arr.size(); i++){
    if(newArray[i] != arr[i]){
      start = min(start, i);
      end = max(end, i);
    }
  }

  if(end-start >= 0){
    return end-start+1;
  }
  else{
    return 0;
  }
}

/* USING STACK (TC: O(N), SC: O(N))
1. Here will take one data structure called stack
     - Main purpose of this Stack to find the position
      of minimum and maximum elem of unsorted array
     - If elem is in ascending order, push elem index
       it in stack, if not then then pop top index
2. Here will trverse array two times
      - in 1st traversal will find min position 
        of unsorted array
      - In second traversal will find max position of
        unsorted array
*/
int Using_Stack(vector<int>arr){
  int start = arr.size();
  int end = 0;
  stack<int>st;
    // Traverse array from left to right and get left boundary
    for (int i = 0; i < arr.size(); i++) {
        while (!st.empty() && arr[st.top()] > arr[i]) {
            start = min(start, st.top());
            st.pop();
        }
        st.push(i); // Push only once after clearing larger elements
    }

  //Clear the stack for next use
  while(!st.empty()){
    st.pop();
  }

   // Traverse array from right to left and get right boundary
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