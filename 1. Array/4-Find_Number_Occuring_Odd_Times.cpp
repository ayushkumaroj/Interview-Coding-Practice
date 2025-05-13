// ------------------------------------------------------------------
// 🔍 Problem Title: [Your Problem Name Here]
// 📌 Problem Statement:
//     Brief explanation of the problem.
//     Input: ...
//     Output: ...
// ------------------------------------------------------------------

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
  for(int i=0; i<arr.size()-1; i++){
    int count = 0;
    for(int j=0; j<arr.size()-1; j++){
      if(arr[i] == arr[j]){
        count++;
      }
    }
    if(count % 2 != 0){
      int result = arr[i];
      return result;
    }
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
// Using HashMap, T.C: O(n^2), S.C: O(1)
int usingMap(vector<int>arr){
  unordered_map<int,int>count;
  int ans;
  for(int i=0; i<arr.size(); i++){
    count[arr[i]]++;
  }

  for(auto x:count){
    if(x.second == 1){
      ans = x.first;
      break;
    }
  }
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
  int ans = 0;
  for(int i=0; i<arr.size(); i++){
    ans = ans ^ arr[i];
  }
  return ans;
}



// ------------------------------------------------------------------
// 🔁 Main Function – Test All Approaches
// ------------------------------------------------------------------

int main() {
  vector<int>arr{4,1,2,1,2};
  
  cout<<usingLoop(arr)<<endl;
  cout<<usingMap(arr)<<endl;
  cout<<UsingXor(arr)<<endl;
  return 0;
}
