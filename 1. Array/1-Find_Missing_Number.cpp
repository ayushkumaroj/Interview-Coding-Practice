
#include<iostream>
using namespace std;
#include<vector>

// Approach 1: BRUTE FORCE (TC: O(N^2 SC: O(N)))
int  UsingLoop(vector<int>arr, int n){
  // Step 1: Loop through all numbers from 1 to (n-1).
  for(int i=1; i<n; i++){
    // Step 2: Initialize a flag to check if the current number 'i' is present in the array.
    int flag = 0;
    // Step 3: Traverse the entire array to see if 'i' exists.
    for(int j=0; j<n-1; j++){
      // Step 4: If the current element in the array matches 'i',
     // set flag = 1 (found) and break the inner loop.
      if(arr[j] == i){
        flag = 1;
        break;
      }
    }
    // Step 5: After scanning the entire array, if flag is still 0,
    // it means 'i' is missing. Return 'i' as the answer.
    if(flag == 0){
      return i;
    }
  }
  // Step 6: If no number is missing (theoretically shouldn't happen),
  // function returns nothing (could return -1 for safety).
}

// ------------------------------------------------------------------
// ✅ Approach 2: USING SUM OF N Number
// ------------------------------------------------------------------
/*
🔸 Idea:
    - Explain the core logic or steps.
🔸 Time Complexity: O(n^2)
🔸 Space Complexity: O(1)
*/

// Approach 2: TC: O(N^2), SC: O(1)
int UsingSumOfN(vector<int>arr, int n){
  // Step 1: Compute the sum of the first 'n' natural numbers using the formula.
  // This represents the sum if no number were missing.
  int sumofN = n*(n+1)/2;
  // Step 2: Initialize a variable to store the sum of all elements in the given array.
  int sum = 0;
  // Step 3: Traverse through the array and calculate the sum of its elements.
  for(int i=0; i<n-1; i++){
    sum = sum+arr[i];
  }
  // Step 4: The missing number will be the difference between
  // the expected sum (sumofN) and the actual sum (sum).
  int result = sumofN-sum;
  // Step 5: Return the missing number.
  return result;
}

// ------------------------------------------------------------------
// ✅ Approach 2: USING XOR
// ------------------------------------------------------------------
/*
🔸 Idea:
    - Explain the core logic or steps.
🔸 Time Complexity: O(n^2)
🔸 Space Complexity: O(1)
*/

//Approach 2: TC: O(N), SC:O(1)
int UsingXoR(vector<int>arr, int n){
  // Step 1: Initialize x1 to store XOR of all numbers from 1 to n.
  int x1 = 0;
  // Step 2: XOR all numbers from 1 to n.
  // After this loop, x1 = 1 ^ 2 ^ 3 ^ ... ^ n
  for (int i = 1; i <= n; i++) {
    x1 = x1 ^ i;
  }
  // Step 3: Initialize x2 to store XOR of all elements in the given array.
  int x2 = 0;
  // Step 4: XOR all elements of the array.
  // After this loop, x2 = arr[0] ^ arr[1] ^ ... ^ arr[n-2]
  for (int i = 0; i < n-1; i++) {
    x2 = x2 ^ arr[i];
  }
  // Step 5: The missing number will be x1 ^ x2.
  // Reason: XOR cancels out all numbers that appear twice.
  int result = x1 ^ x2;
  // Step 6: Return the missing number.
  return result;
}


// ------------------------------------------------------------------
// 🔁 Main Function – Test All Approaches
// ------------------------------------------------------------------

int main() {
  vector<int>arr{1,2,4,3,6,7,9,8,10};
  int n = 10;
  // int result = UsingLoop(arr,n);
  // int result = UsingSumOfN(arr, n);
  int result = UsingLoop(arr,n);

  cout<<"The missing Number is: "<<result;

  return 0;
}
