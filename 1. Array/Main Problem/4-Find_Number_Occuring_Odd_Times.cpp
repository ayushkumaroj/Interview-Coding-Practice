
#include<iostream>
using namespace std;
#include<vector>
#include<unordered_map>

// ------------------------------------------------------------------
// ✅ Approach 1: Brute Force (Using Loop)
// ------------------------------------------------------------------
/*
🔸 Idea:
    - Explain the core logic or steps.
🔸 Time Complexity: O(n^2)
🔸 Space Complexity: O(1)
*/

// Brute Force (Using Loop), T.C: O(n^2), S.C: O(1)
int usingLoop(vector<int>&arr){
  int n = arr.size();
  // Step 1: Loop through each element in the array.
  for(int i=0; i<n; i++){
    // Step 2: Initialize count for the current element.
    int count = 0;
    // Step 3: Compare arr[i] with every element in the array to count its frequency.
    for(int j=0; j<n; j++){
      if(arr[i] == arr[j]){
        count++;
      }
    }
    // Step 4: If the count of this element is 1, it's the single number. Return it.
    if(count == 1){
      return arr[i];
    }
    // Step 5: If no such number is found (theoretically shouldn't happen), return -1.
    else{
      return -1;
    }
  }
}



// ------------------------------------------------------------------
// ✅ Approach 2: Using HashMap
// ------------------------------------------------------------------
/*
🔸 Idea:
    - Explain the core logic or steps.
🔸 Time Complexity: O(n^2)
🔸 Space Complexity: O(1)
*/

// Using HashMap, T.C: O(n), S.C: O(n)
int usingMap(vector<int>arr){
  // Step 1: Create a HashMap to store the frequency of each element.
  unordered_map<int,int>count;
  // Step 2: Initialize ans variable to store the result.
  int ans = -1; // Default value, updated later if found.

  // Step 3: Traverse through the array and count occurrences.
  for(int i=0; i<arr.size(); i++){
    count[arr[i]]++;
  }
  // Step 4: Traverse the map to find the element that appears only once.
  for(auto x:count){
    if(x.second == 1){ // If frequency is 1
      ans = x.first; // Update ans with the element
      break; // No need to continue since only one such number exists
    }
  }
  // Step 5: Return the result (single number or -1 if not found).
  return ans;
}

// ------------------------------------------------------------------
// ✅ Approach 3: Using XOR
// ------------------------------------------------------------------
/*

🔸 Idea:
    - Explain the core logic or steps.
🔸 Time Complexity: O(n)
🔸 Space Complexity: O(1)
*/


// Using XOR, T.C: O(N), S.C: O(1)
int UsingXor(vector<int>arr){
  // Step 1: Initialize 'ans' as 0 because XOR with 0 has no effect.
  int ans = 0;
  // Step 2: Traverse through the array and XOR each element with ans.
  for(int i=0; i<arr.size(); i++){
    ans = ans ^ arr[i]; // This cancels out elements appearing twice.
  }
  // Step 3: After the loop, 'ans' will hold the number that appears only once.
  return ans;
}


// ------------------------------------------------------------------
// 🔁 Main Function – Test All Approaches
// ------------------------------------------------------------------

int main() {
  vector<int>arr{4,1,2,1,2};
  
  cout<<usingLoop(arr)<<endl;
  // cout<<usingMap(arr)<<endl;
  // cout<<UsingXor(arr)<<endl;
  return 0;

}


