
#include<iostream>
using namespace std;
#include<vector>

// Approach 1: BRUTE FORCE (TC: O(N^2 SC: O(N)))
int  UsingLoop(vector<int>arr, int n){
  for(int i=1; i<n; i++){
    int flag = 0;
    for(int j=0; j<n-1; j++){
      if(arr[j] == i){
        flag = 1;
        break;
      }
    }
    if(flag == 0){
      return i;
    }
  }
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
  int sumofN = n*(n+1)/2;
  int sum = 0;
  for(int i=0; i<n-1; i++){
    sum = sum+arr[i];
  }
  int result = sumofN-sum;
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
  // XOR all numbers from 1 to n-1 (x1)
  int x1 = 0;
  for (int i = 1; i <= n; i++) {
    x1 = x1 ^ i;
  }
  // XOR all elements of the array (x2)
  int x2 = 0;
  for (int i = 0; i < n-1; i++) {
    x2 = x2 ^ arr[i];
  }
  // XOR of x1 and x2 gives the missing number
  int result = x1 ^ x2;
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
  int result = UsingXoR(arr,n);

  cout<<"The missing Number is: "<<result;

  return 0;
}
