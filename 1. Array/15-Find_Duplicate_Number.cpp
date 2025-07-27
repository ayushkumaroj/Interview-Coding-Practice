#include<iostream>
#include<vector>
using namespace std;


// Brute Force (TC: O(N^2), SC:O(N))
int usingBruteForce(vector<int>arr){
  int ans = -1;
  for(int i=0; i<arr.size(); i++){
    for(int j=i+1; j<arr.size(); j++){
      if(arr[i] == arr[j]){
        return arr[i];
      }
    }
  }
  return -1;
}


int findDuplicate(vector<int>arr){
  int size = arr.size();
  int ans = 0;
  for(int i=0; i<size; i++){
    ans = ans^arr[i];
  }
  return ans;
}


//Using Slow and Fast pointer (TC: O(N), SC: O(1))
int UsingSlowAndFast(vector<int>arr){
  // declare two pointers slow and fast at starting index
  int slow = arr[0];
  int fast = arr[0];
  // move slow by 1 step and fast by 2 steps to find meeting point
  slow = arr[slow];
  fast = arr[arr[fast]];
  // loop until slow and fast meet (cycle detected)
  while(slow != fast){
    slow = arr[slow];             // move slow by 1 step
    fast = arr[arr[fast]];       // move fast by 2 steps
  }
  // move both one step at a time to find start of cycle (duplicate)
  while(slow != fast){
    slow = arr[slow];
    fast = arr[fast];
  }
  return slow;  // return the duplicate number
}


int main(){
  vector<int>arr{1,3,4,2,2};

  // int ans = usingBruteForce(arr);
  int ans2 = findDuplicate(arr);
  cout<<"The Duplicate number is: "<<ans2;
}