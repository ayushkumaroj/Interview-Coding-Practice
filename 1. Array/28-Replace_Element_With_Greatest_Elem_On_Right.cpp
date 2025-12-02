#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

//Using Brute Force: TC: O(N^2), SC: O(1)
void Replace_Element(vector<int>& arr) {
  // Step 1: Loop through each element in the array.
  for(int i=0; i<arr.size(); i++){
    int maxElem = INT_MIN; // To track the greatest element on the right.

    // Step 2: Scan the elements to the right of arr[i] to find the maximum.
    for(int j=i+1; j<arr.size(); j++){
      if(arr[j] > maxElem){
        maxElem = arr[j];
      }
    }
    // Step 3: Replace arr[i] with the greatest element found. 
    arr[i] = maxElem;
  }
  // Step 4: Replace the last element with -1 (as per problem statement).
  arr[arr.size()-1] = -1;

  // Step 5: Print the updated array.
  for(int i=0; i<arr.size(); i++){
    cout<<arr[i]<<" ";
  }
}

/*
- TC: O(N), SC: O(1)
- Traverse from right to left
- Initially assign last elem to -1
- will take one variable that will store max Element seen so far , initially it will store 1 (bcz last elem is 1)
*/
void Traverse_Right_to_Left(vector<int> arr) {
  int n = arr.size();

  // Step 1: Initialize max_elem_seen_so_far with the last element of the array.
  int max_elem_seen_so_far = arr[n - 1];

  // Step 2: Replace the last element with -1 since there is no element to its right.
  arr[n - 1] = -1;

  // Step 3: Traverse the array from the second last element to the first.
  for (int i = n - 2; i >= 0; i--) {
    // Step 4: Store the current element before overwriting it.
    int curr = arr[i]; 
    // Step 5: Replace the current element with the maximum seen so far.               
    arr[i] = max_elem_seen_so_far;    
    // Step 6: Update max_elem_seen_so_far if the current element is greater.
    if (curr > max_elem_seen_so_far) {
      max_elem_seen_so_far = curr;
    }
  }
  // Step 7: Print the modified array.
  for(int i=0; i<arr.size(); i++){
    cout<<arr[i]<<" ";
  }
}

 

int main() {
    vector<int> arr{17, 18, 5, 4, 6, 1};
    // Replace_Element(arr);

    Traverse_Right_to_Left(arr);
}
