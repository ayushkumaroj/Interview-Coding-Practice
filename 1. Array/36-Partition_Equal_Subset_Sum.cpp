#include<iostream>
using namespace std;
#include<vector>

// TC: O(N^2), SC: O(1)
int Brute_force(vector<int>arr){
  int n = arr.size();

  // Step 1: Traverse the array to check each index as a possible partition point
  for(int i=0; i<n-1; i++){
    int leftSum = 0;
    int rightSum = 0;

   // Step 2: Calculate sum of elements from 0 to i (left part)
    for(int j=0; j<=i; j++){
      leftSum = leftSum + arr[j];
    }

    // Step 3: Calculate sum of elements from i+1 to n-1 (right part)
    for(int j=i+1; j<n; j++){
      rightSum = rightSum + arr[j];
    }

    // Step 4: Check if both sums are equal
    if(leftSum == rightSum){
      // Partition point found at index i
      return i;
    }
  }
  // Step 5: If no partition point found, return -1
  return -1;
}

//TC: O(N) , SC: O(1)
int Find_Split_Index(vector<int>arr){
  int sum = 0;

  // Step 1: Calculate the total sum of all elements in the array
  for(int i=0; i<arr.size(); i++){
    sum = sum + arr[i];
  }

  // Initialize two sums:
  // leftSum: Starts as the total sum and will decrease as we move left to right
  // rightSum: Starts as 0 and will increase as we move left to right
  int leftSum = sum;
  int rightSum = 0;

  // Step 2: Traverse the array from right to left
  for(int i = arr.size()-1; i>=0; i--){
    // Add the current element to rightSum
    rightSum = rightSum + arr[i];

    // Subtract the current element from leftSum
    leftSum = leftSum - arr[i];

    // Step 3: Check if leftSum and rightSum are equal at this point
    if(leftSum == rightSum){
      // Found a split point at index i
      return i;
    }
  }
  // Step 4: If no split point found, return -1
  return -1;
}

int main(){
  vector<int>arr{1, 2, 3, 4, 5, 5};

  // int ans = Brute_force(arr);
  int ans2 = Find_Split_Index(arr);
  cout<<"Answer is"<<" "<<ans2;
}