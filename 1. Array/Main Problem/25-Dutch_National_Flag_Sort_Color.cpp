#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

//Note: In header include #include<algorithm>

//TC: O(NlogN), SC: O(nlogn)
int Sort_Color(vector<int>arr){
  // Step 1: Sort the array using the built-in sort function.
  // This will arrange all 0s, then 1s, then 2s in ascending order.
  sort(arr.begin(), arr.end());

  // Step 2: Print the sorted array.
  for(int i=0; i<arr.size(); i++){
    cout<<arr[i]<<" ";
  }
}

//TC: O(N), SC: O(1)
int usingCounting(vector<int>arr){
  // Step 1: Initialize counters for 0s, 1s, and 2s.
  int countZero = 0;
  int countOne = 0;
  int countTwo = 0;

  // Step 2: Count the frequency of each element.
  for(int i=0; i<arr.size(); i++){
    if(arr[i] == 0){
      countZero++;
    }
    else if(arr[i] == 1){
      countOne++;
    }
    else if(arr[i] == 2){
      countTwo++;
    }
  }

  // Step 3: Reconstruct the array using the counts.
  int index = 0;
  // Insert all 0s first
  while (countZero > 0) {
    arr[index++] = 0;
    countZero--;
  }
  // Insert all 1s
  while (countOne > 0) {
    arr[index++] = 1;
    countOne--;
  }
  // Insert all 2s
  while (countTwo > 0) {
    arr[index++] = 2;
    countTwo--;
  }
  
  // Step 4: Print the sorted array.
  for(int i=0; i<arr.size(); i++){
    cout<<arr[i]<<" ";
  }
}

//Using Three Pointer (TC: O(N), SC: O(N))
void usingTwoPointer(vector<int>& arr) {
  // Step 1: Initialize three pointers:
  // - 'low' for the next position of 0,
  // - 'mid' for the current element under consideration,
  // - 'high' for the next position of 2.
  int low = 0,
  mid = 0, 
  high = arr.size() - 1;

  // Step 2: Traverse the array while mid <= high.
  // This ensures all elements are processed once.
  while (mid <= high) {
    // Case 1: If current element is 0,
    // swap it with the element at 'low', and move both low and mid forward.
    if(arr[mid] == 0) {
      swap(arr[low], arr[mid]);
      low++;
      mid++;
    }
    // Case 2: If current element is 1, it's already in the correct section.
    // Just move mid forward.
    else if (arr[mid] == 1) {
      mid++;
    }
    // Case 3: If current element is 2,
    // swap it with the element at 'high', and move high backward.
    // Do NOT increment mid because the swapped element at mid needs to be checked.
    else{ // arr[mid] == 2
      swap(arr[mid], arr[high]);
          high--;
      }
    }
}


int main(){
  vector<int>arr{0,1,0,1,2,1,2,1};
  Sort_Color(arr);

  usingTwoPointer(arr);
}