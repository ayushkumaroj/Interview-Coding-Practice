#include <iostream>
using namespace std;
#include<vector>

//Brute Force: TC: O(N^2), SC: O(1)
int firstMissingPositive(int nums[], int n) {
  // Step 1: Loop through all numbers starting from 1 up to (n + 1)
  // Why (n + 1)? Because in the worst case, all numbers from 1 to n exist,
  // then the first missing positive will be (n + 1).
  for (int i = 1; i <= n + 1; i++) {
    // Step 2: Create a flag 'found' to check if current number i exists in the array.
    bool found = false;
    // Step 2: Create a flag 'found' to check if current number i exists in the array.
    for (int j = 0; j < n; j++) {
      // Step 4: If current element matches i, mark 'found' as true and stop checking.
      if (nums[j] == i) {
          found = true;
            break; // No need to check further for this i.
       }
    }
      // Step 5: After checking the whole array, if i was NOT found, 
      // then i is the smallest missing positive. So, return i.
      if (!found) {
        return i; // First missing positive
      }
  }
  // Step 6: As a fallback (though we will usually return inside the loop),
  // return (n + 1). This means all numbers from 1 to n were present.
  return n + 1; // Just in case
}

//Using  Index Marking Approch , TC: O(n), SC: O(1)
int firstMissingPositive(vector<int>& nums){
  int n = nums.size();

  // Step 1: Check if 1 is present in the array
  // Reason: If 1 is missing, it's the smallest positive number → Answer = 1.
  bool contains1 = false;

  // Step 2: Clean the array
  // Reason: Numbers ≤ 0 or > n do not help us, because:
  //    - Negative numbers and zero cannot be the answer.
  //    - Numbers bigger than n cannot be the first missing positive (answer ≤ n+1).
  // So we replace them with 1 (safe value because 1 is already handled).
  for(int i=0; i<n; i++){
    if(nums[i] == 1){
      contains1 = true; // Found 1, mark it.
    }
    if(nums[i]<= 0 || nums[i]>n){ //[1,n]
      nums[i] = 1; // Replace invalid numbers with 1.

    }
  }

  // Step 3: If 1 is missing, return 1
  // Reason: 1 is the smallest positive number, so if it's not there, answer is 1.
  if(contains1 == false){
    return 1;
  }

  // Step 4: Mark all numbers that exist
  // Reason: If we see a number 'num', we go to index num-1 and make that value negative.
  // Why negative? So later, positive values mean "this number was missing".
  for(int i=0; i<n; i++){
    int num = abs(nums[i]); // Use absolute value because some may already be negative.
    int idx = num-1; // Find correct index for this number.

    // If nums[idx] is already negative, it means we already marked it → skip.
    if(nums[idx] < 0){
      continue;
    }

    // Make nums[idx] negative to mark that num exists in the array.
    nums[idx] = nums[idx] * (-1);
  }

  // Step 5: Find the first positive index
  // Reason: If nums[i] > 0, then (i+1) was never marked, so it's missing.
  for(int i=0; i<n; i++){
    if(nums[i] > 0){
      return i+1;
    }
  }

  // Step 6: If everything is marked negative, then all numbers 1..n are present.
  // So the answer is n+1.
  return n+1;
}

int main() {
    int nums[] = {3, 4, -1, 1};
    int n = sizeof(nums) / sizeof(nums[0]);
    cout << firstMissingPositive(nums, n) << endl; // Output: 2
    return 0;
}
