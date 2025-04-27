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
// ✅ Approach 1: BRUTE FORCE
// ------------------------------------------------------------------
/*
🔸 Idea:
    - Explain the core logic or steps.
🔸 Time Complexity: ...
🔸 Space Complexity: ...
*/
int UsingLoop(vector<int>arr, int size){
  for(int i=0; i<size; i++){
    int count = 1;
    for(int j=i+1; j<size; j++){
      if(arr[i] == arr[j]){
        count++;
      }
    }
    if(count > size/2){
      return arr[i];
    }
  }
  return -1;
}

// ------------------------------------------------------------------
// ✅ Approach 2: USING HASHMAP
// ------------------------------------------------------------------
/*
🔸 Idea:
    - Explain the core logic or steps.
🔸 Time Complexity: O(N)
🔸 Space Complexity: O(N)- in worst case when all eleme distinct
*/

int UsingMap(vector<int>arr, int size){
  unordered_map<int,int>freq;
  //count freq of each element
  for(int i=0; i<size; i++){
    int element = arr[i];
    freq[element] = freq[element]+1; //or -> freq[arr[i]]++;
    if(freq[element] > size/2){
      return arr[i];
    }
  }
  //if no majority element is found
  return -1;
}

// ------------------------------------------------------------------
// ✅ Approach 2: USING Boyer-Moore Algorithm(A,n)
// ------------------------------------------------------------------
/*
🔸 Idea:
    - Explain the core logic or steps.
🔸 Time Complexity: O(N)
🔸 Space Complexity:
*/
int UsingBoyerMooreAlgo(vector<int> arr, int size) {
  int maj = -1;
  int count = 0;

  for(int i=0; i<size; i++){
    if(count == 0){
      maj = arr[i];
      count = 1;
    }
    else if(arr[i] == maj){
      count = count+1;
    }
    else if(arr[i] != maj){
      count = count -1;
    }
  }

  //verification
  count = 0;
  for(int i=0; i<size; i++){
    if(maj == arr[i]){
      count = count+1;
    }
  }

  //check
  if(count > size/2){
    return maj;
  }else{
    return -1;
  }
}





// ------------------------------------------------------------------
// 🔁 Main Function – Test All Approaches
// ------------------------------------------------------------------

int main() {
  vector<int>arr{2,2,1,1,1,1,1,2,2};
  int size = arr.size();

  // int ans = UsingLoop(arr, size);
  // int ans = UsingMap(arr, size);
  int ans = UsingBoyerMooreAlgo(arr, size);

  if(ans){
    cout<<"Majority element is present: "<<ans<<endl;
  }else{
    cout<<"Majority element is not present"<<endl;
  }

  return 0;
}
