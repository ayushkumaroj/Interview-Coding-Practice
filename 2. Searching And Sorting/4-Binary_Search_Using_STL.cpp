#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

/*
- If key is found then it return 1. If not found then 0.
- TC: O(logn)
- SC: O(1)
*/
int main(){
  vector<int>arr{1,2,3,4,5,6};
  int key = 95;

  // Returns true (1) if found, else false (0)
  int ans = binary_search(arr.begin(), arr.end(), key);

  if(ans){
    cout<<"Key is found in the array";
  }else{
    cout<<"Key is not found in the array";
  }

  return 0;
}



