#include<iostream>
using namespace std;
#include<vector>

//TC: O(N), SC: O(1)
int Search_In_Sorted_Array(vector<int>arr, int sum){
  // Step 1: Get the size of the array.
  int n = arr.size();
  int i;

  // Step 2: Find the pivot point (index where arr[i] > arr[i+1]).
  // This point separates the largest element and the smallest element in the rotated array.
  for(i=0; i<n-1; i++){
    if(arr[i] > arr[i+1]){
      break; // Found pivot at index 'i'.
    }
  }

  // Step 3: Set two pointers:
  // - 'start' to the index of the smallest element (pivot + 1).
  // - 'end' to the index of the largest element (pivot).
  int start = (i+1) % n; // Index of smallest element.
  int end = i;           // Index of largest element.

  // Step 4: Use the two-pointer approach in a circular manner.
  while(start != end){
    // Step 5: If the sum of elements at 'start' and 'end' equals the target, return true.
    if(arr[start] + arr[end] == sum){
      return true;
    }
    // Step 6: If the sum is smaller than the target, move 'start' forward circularly.
    else if(arr[start] + arr[end] < sum){
      //move forward in circular manner
      start = (start + 1)%n;
    }
    // Step 7: If the sum is greater than the target, move 'end' backward circularly.
    else if(arr[start] + arr[end] > sum){
      //Move backward in circular manner
      end = (n + end -1) % n;
    }
  }
  // Step 8: If no pair is found after full traversal, return false.
  return false;
}


int main(){
  vector<int>arr{11,15,26,38,9,10};
  int sum = 206;

  cout<<Search_In_Sorted_Array(arr, sum);
}