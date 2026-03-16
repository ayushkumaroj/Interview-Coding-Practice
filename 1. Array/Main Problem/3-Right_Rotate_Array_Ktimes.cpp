// ------------------------------------------------------------------
// 🔍 Problem Title: Rotate An Array k Times
// 📌 Problem Statement:
//     Brief explanation of the problem.
//     Input: ...
//     Output: ...
// ------------------------------------------------------------------

#include<iostream>
using namespace std;
#include<vector>

// ------------------------------------------------------------------
// ✅ Approach 1: Calling Rotate 3 times
// ------------------------------------------------------------------
/*
🔸 Idea:
    - Explain the core logic or steps.
🔸 Time Complexity: o(n*k)
🔸 Space Complexity: o(1)
*/

// Calling Rotate 3 times (T.C: O(n*k), S.C: O(1))
void rotate_Once(vector<int> &arr, int size) {
  // Step 1: Store the last element in a temporary variable.
  // Because when we start shifting, the last element will be lost.
  int temp = arr[size - 1];
  // Step 2: Shift all elements one position to the right.
  // Start from the second last element (index size-2) and move towards index 0.
  for (int i = size - 2; i >= 0; i--) {
    //shift all element one position to right,
    // starting from second last to first
    arr[i + 1] = arr[i]; // Move current element to the next index.
  }
  // Step 3: Place the last element (stored in temp) at the first position (index 0).
  arr[0] = temp;
}
/*
Step 4: Call rotate_Once() function k times in the main program.
for (int i = 0; i < k; i++) {
    rotate_Once(arr, size);
}
*/



// ------------------------------------------------------------------
// ✅ Approach 2: Linear Time(O(n)) with Additional Space(temp array)
// ------------------------------------------------------------------
/*
🔸 Idea:
    - Explain the core logic or steps.
🔸 Time Complexity: o(n*k)
🔸 Space Complexity: o(1)
*/
// Using Linear Time(O(n)) + TC: O(N)
void UsingTempArray(vector<int>&arr, int k){
  int n = arr.size();
  // Step 1: Create a temporary array and copy the last 'k' elements of the original array.
  // These will be placed at the beginning after rotation.
  vector<int>temp;
  for(int i=n-k; i<n; i++){
    temp.push_back(arr[i]);
  }
  // Step 2: Shift the remaining elements (first n-k elements) to the right by 'k' positions.
  // Start from index n-k-1 and move backward to avoid overwriting elements.
  for(int i=n-k-1; i>=0; i--){
    arr[i+k] = arr[i];
  }
  // Step 3: Copy the elements from the temporary array back to the beginning of the original array.
  for(int i=0; i<k; i++){
    arr[i] = temp[i];
  }

  //Step 4: Print the Array using lOOP
}


// Using Reverse approch ,Linear Time(O(n))+ O(1) Space
// Reverse Function: Reverse elements in the array between indices 'start' and 'end'.
void reverse(vector<int>&arr, int start, int end){
  // Step 1: Swap elements from both ends and move towards the center.
  while(start < end){
    swap(arr[start], arr[end]);
    start++;
    end--;
  }
}

// Function to Rotate the array to the right by 'k' steps using the reversal algorithm.
int UsingReverse(vector<int>&arr, int k){
  int n = arr.size();
  // Step 1: Normalize k because rotating by n or multiples of n results in the same array.
  k = k % n;
  // Step 2: Reverse the entire array.
  reverse(arr, 0, n-1);
  // Step 3: Reverse the first k elements (which were originally the last k elements).
  reverse(arr, 0, n-k-1);
  // Step 4: Reverse the remaining n-k elements.
  reverse(arr, n-k, n-1);
}


// ------------------------------------------------------------------
// 🔁 Main Function – Test All Approaches
// ------------------------------------------------------------------

int main() {
  vector<int>arr{1,2,3,4,5,6,7};
  int size = arr.size();
  int k = 3;

  //Rotate k times
  // for(int i=0; i<k; i++){
  //   rotate_Once(arr,size);
  // }

  UsingTempArray(arr,k);
  // UsingReverse(arr, k);
  // for(int i=0; i<size; i++){
  //   cout<<arr[i]<<" ";
  // }

  
  
  return 0;
}
