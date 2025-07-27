#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

//Using Brute Force: TC: O(N^2), SC: O(1)
void Replace_Element(vector<int>& arr) {
  for(int i=0; i<arr.size(); i++){
    int maxElem = INT_MIN;
    for(int j=i+1; j<arr.size(); j++){
      if(arr[j] > maxElem){
        maxElem = arr[j];
      }
    }
    //update the array with max 
    arr[i] = maxElem;
  }
  //Put -1 at last of the array
  arr[arr.size()-1] = -1;

  //Print the array
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

  // Initialize max_elem_seen_so_far with the last element
  int max_elem_seen_so_far = arr[n - 1];

  // Replace last element with -1 as there is no element to its right
  arr[n - 1] = -1;

  // Traverse the array from second last element to the first
  for (int i = n - 2; i >= 0; i--) {
    // Store current element
    int curr = arr[i]; 
    // Replace current element with the max seen so far               
    arr[i] = max_elem_seen_so_far;    
    // Update max_elem_seen_so_far if current element is greater
    if (curr > max_elem_seen_so_far) {
      max_elem_seen_so_far = curr;
    }
  }
  // Print the modified array (arr)
  for(int i=0; i<arr.size(); i++){
    cout<<arr[i]<<" ";
  }
}
 

int main() {
    vector<int> arr{17, 18, 5, 4, 6, 1};
    // Replace_Element(arr);

    Traverse_Right_to_Left(arr);
}
