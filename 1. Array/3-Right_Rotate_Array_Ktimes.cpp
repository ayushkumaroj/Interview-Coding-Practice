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
  //store last elem in temp variable
  int temp = arr[size - 1];
  for (int i = size - 2; i >= 0; i--) {
    //shift all element one position to right,
    // starting from second last to first
    arr[i + 1] = arr[i];
  }
  //place last elem at first
  arr[0] = temp;
}
// Note: call rotate_one function k time using loop
// (i=0; i<k; i++) in main function


// ------------------------------------------------------------------
// ✅ Approach 2: Linear Time(O(n)) with Additional Space(temp array)
// ------------------------------------------------------------------
/*
🔸 Idea:
    - Explain the core logic or steps.
🔸 Time Complexity: o(n*k)
🔸 Space Complexity: o(1)
*/
// Using Linear Time(O(n)) with Additional Space(temp array)
void UsingTempArray(vector<int>&arr, int k){
  int n = arr.size();
  //step 1: Copy last k element
  vector<int>temp;
  for(int i=n-k; i<n; i++){
    temp.push_back(arr[i]);
  }
  //step 2: Shift remaining element to right
  for(int i=n-k-1; i>=0; i--){
    arr[i+k] = arr[i];
  }
  //step 3: Copy temp to the front
  for(int i=0; i<k; i++){
    arr[i] = temp[i];
  }
}

// ------------------------------------------------------------------
// ✅ Approach 2: Linear Time(O(n))+ O(1) Space (Using Reverse approch)
// ------------------------------------------------------------------
/*
🔸 Idea:
    - Explain the core logic or steps.
🔸 Time Complexity: o(n)
🔸 Space Complexity: o(1)
*/
// Using Reverse approch ,Linear Time(O(n))+ O(1) Space
void reverse(vector<int>&arr, int start, int end){
  while(start < end){
    swap(arr[start], arr[end]);
    start++;
    end--;
  }
}
int UsingReverse(vector<int>&arr, int k){
  int n = arr.size();
  reverse(arr, n-k, n-1);
  reverse(arr, 0, n-k-1);
  reverse(arr, 0, n-1);
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

  // UsingTempArray(arr,k);
  UsingReverse(arr, k);
  for(int i=0; i<size; i++){
    cout<<arr[i]<<" ";
  }

  
  
  return 0;
}
