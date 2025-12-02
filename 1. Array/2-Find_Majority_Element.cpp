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


//Brute Force Majority Elem (T.C: O(n^2), S.C: O(n))
int UsingLoop(vector<int>arr, int size){
  // Step 1: Loop through each element of the array one by one.
  // This will treat each element as a candidate for the majority element.
  for(int i=0; i<size; i++){
    // Step 2: Initialize a counter to 1 (counting arr[i] itself).
    int count = 1;
    // Step 3: Compare the current element (arr[i]) with all elements that come after it.
    // If a match is found, increment the count.
    for(int j=i+1; j<size; j++){
      if(arr[i] == arr[j]){
        count++;
      }
    }
    // Step 4: After checking all elements for arr[i], 
    // check if its frequency is greater than size/2 (majority condition).
    if(count > size/2){
      // Step 5: If yes, return arr[i] because it's the majority element.
      return arr[i];
    }
  }
  // Step 6: If no element satisfies the majority condition, return -1.
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

//USING HASHMAP(T.C: O(N), S.C: O(N))
int UsingMap(vector<int>arr, int size){
  // Step 1: Create an unordered_map to store frequency of each element.
  unordered_map<int,int>freq;
  // Step 2: Traverse the array and update frequency for each element.
  for(int i=0; i<size; i++){
    int element = arr[i]; // Current element.
    // Step 3: Increase the frequency count of the current element.
    // (Alternatively, we can directly write freq[arr[i]]++).
    freq[element] = freq[element]+1;
    // Step 4: If the frequency of the current element exceeds size/2,
    // it means this element is the majority element, so return it immediately.
    if(freq[element] > size/2){
      return arr[i];
    }
  }
  // Step 5: If no element satisfies the majority condition, return -1.
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

// USING Boyer-Moore Algorithm(A,n) , T.C: O(N), S.C: O(1)
int UsingBoyerMooreAlgo(vector<int> arr, int size) {
  // Step 1: Initialize two variables:
  // 'maj' will store the candidate for majority element, initially -1.
  // 'count' will track the "vote balance" for the current candidate.
  int maj = -1;
  // Step 2: Traverse through the array to find a majority candidate.
  int count = 0;
  for(int i=0; i<size; i++){
    // Step 3: If count becomes 0, select the current element as the new candidate.
    if(count == 0){
      maj = arr[i];
      count = 1;
    }
    // Step 4: If current element equals the candidate, increase the vote count.
    else if(arr[i] == maj){
      count = count+1;
    }
    // Step 5: If current element is different, decrease the vote count.
    else if(arr[i] != maj){
      count = count -1;
    }
  }
  // At this point, 'maj' is our potential majority element,
  // but we need to verify it because the algorithm guarantees
  // a correct candidate only if a majority element exists
  //verification

  // Step 6: Reset count to 0 for verification.
  count = 0;
  // Step 7: Count how many times 'maj' actually appears in the array.
  for(int i=0; i<size; i++){
    if(maj == arr[i]){
      count = count+1;
    }
  }
  // Step 8: If the candidate appears more than size/2 times, return it.
  if(count > size/2){
    return maj;
  }
  // Step 9: Otherwise, return -1 (no majority element found).
  else{
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
