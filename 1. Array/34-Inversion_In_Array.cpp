#include<iostream>
using namespace std;
#include<vector>

/*
Arr[] = [2, 5, 1, 7, 9]
suppose i=0 , and j=2  || arr[i] = 2 , arr[j] = 1
Inversion : Inversion means if index i< j and a[i] > a[j] then it will count as 1 inversion
*/ 


// Brute Force: TC: O(N^2) , SC: O(1)
int Count_Inversion(vector<int>arr){
  int count = 0; // To store the number of inversions
  // Step 1: Traverse each element using the outer loop
  for(int i=0; i<arr.size(); i++){
    // Step 2: For each element arr[i], check all elements to its right
    for(int j=0; j<arr.size(); j++){
      // Step 3: If i < j AND arr[i] > arr[j], it means (i, j) is an inversion pair
      if(i<j && arr[i]>arr[j]){
        count++; // Step 4: Increment the inversion count
      }
    }
  }

  cout<<"The Number of Inversion are: "<<count<<endl;
}

//Using Merge Sort (TC: O(nlogn), SC: O(N))
// Function to merge two sorted halves and count inversions
int merge(vector<int>&arr, int st, int mid, int end){
  int len1 = mid-st+1; // Length of left subarray
  int len2 = end-mid;  // Length of right subarray
  int invCount = 0;    // To count inversions during merge

  // Step 1: Create temporary arrays for left and right halves
  int* left = new int[len1];
  int* right = new int[len2];

  // Step 2: Copy values from arr into left subarray
  int k=st;
  for(int i=0; i<len1; i++){
    left[i] = arr[k];
    k++;
  }
  // Step 3: Copy values from arr into right subarray
  k=mid+1;
  for(int i=0; i<len2; i++){
    right[i] = arr[k];
    k++;
  }

  // Step 4: Merge two sorted subarrays while counting inversions
  int leftIndx = 0; // Pointer for left array
  int rightIndx = 0; // Pointer for right array
  int startInx = st; // Pointer for original array
  int mainArrayIndx = startInx;

  // Step 5: Compare elements from left and right arrays
  while(leftIndx < len1 && rightIndx<len2){
    // If left element is smaller, no inversion, place it in array
    if(left[leftIndx] < right[rightIndx]){
      arr[mainArrayIndx] = left[leftIndx];
      mainArrayIndx++;
      leftIndx++;
    }
    // If right element is smaller, it's an inversion
    else if(right[rightIndx] < left[leftIndx]){
      arr[mainArrayIndx] = right[rightIndx];
      mainArrayIndx++;
      rightIndx++;
      // Count inversions: all remaining elements in left array
      invCount = invCount + (len1-leftIndx);
    }
  }

  // Step 6: Copy remaining elements from left subarray (if any)
  while(leftIndx < len1){
    arr[mainArrayIndx] = left[leftIndx];
    mainArrayIndx++;
    leftIndx++;
  }
  // Step 7: Copy remaining elements from right subarray (if any)
  while(rightIndx < len2){
    arr[mainArrayIndx] = right[rightIndx];
    mainArrayIndx++;
    rightIndx++;
  }
  // Step 8: Return the inversion count for this merge step
  return invCount;
}

// Recursive Merge Sort function to divide array and count inversions
int mergeSort(vector<int>&arr, int st, int end){
  // Base case: If the segment has 1 or 0 elements, no inversions
  if(st < end){
    // Step 1: Find the midpoint to divide the array
    int mid = st + (end-st)/2;
    // Step 2: Recursively count inversions in left half
    int leftInvCount = mergeSort(arr, st, mid);
    // Step 3: Recursively count inversions in right half
    int rightInvCount = mergeSort(arr, mid+1, end);
    // Step 4: Merge the two halves and count cross inversions
    int invCount = merge(arr, st, mid, end);
    // Step 5: Total inversions = left + right + cross inversions
    int totalInvCount = leftInvCount + rightInvCount + invCount;
    return totalInvCount;
  }

  //If invalid index is present
  return 0;
}

int main(){
  vector<int>arr{6, 3, 5, 2, 7};
  
  // Count_Inversion(arr);
  int ans = mergeSort(arr, 0, arr.size()-1);
  cout<<"Total Inv count is: "<<" "<<ans;
}