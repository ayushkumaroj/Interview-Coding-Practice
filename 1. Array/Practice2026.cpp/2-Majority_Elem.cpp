#include<iostream>
using namespace std;
#include<vector>
#include<unordered_map>

// Approch 1: BRUTE FORCE (TC: O(N), SC:O(1))
int UsingLoop(vector<int>arr, int size){
  // Step 1: Traverse each element because we must check every number as a possible majority element
  for(int i = 0; i < size; i++){
    // Step 2: Initialize count = 1 because current element itself is counted once initially
    int count = 1;

    // Step 3: Compare current element with remaining elements because we need total frequency of this element
    for(int j = i + 1; j < size; j++){
      // Step 4: If same element is found then increment count because frequency of current element increases
      if(arr[i] == arr[j]){
        count++;
      }
    }

    // Step 5: Check if count is greater than size/2 because majority element must appear more than half of array size
    if(count > size / 2){
      return arr[i];   // Return immediately because problem guarantees only one majority element
    }
  }

  // Step 6: Return -1 for safety because this executes only when no majority element is found
  return -1;
}

// Approch 2: Hash Map (TC: O(N), SC: O(N))
int UsingMap(vector<int>arr, int size){
  // Step 1: Create unordered_map to store frequency because we need fast counting of each element
  unordered_map<int,int> freq;

  // Step 2: Traverse the array because we must process every element to build frequency count
  for(int i = 0; i < size; i++){
    // Step 3: Store current element in variable for clarity and repeated use in map operations
    int element = arr[i];
    // Step 4: Increase frequency of current element because each occurrence must be counted
    freq[element] = freq[element] + 1;
    // Step 5: Check if frequency becomes greater than size/2 because majority element appears more than half times
    if(freq[element] > size / 2){
      return arr[i];   // Return immediately because problem guarantees only one majority element
    }
  }

  // Step 6: Return -1 for safety because this runs only if no majority element exists
  return -1;
}

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

  count = 0;
  for(int i=0; i<size; i++){
    if(maj == arr[i]){
      count = count+1;
    }
  }

  if(count > size/2){
    return maj;
  }
  else{
    return -1;
  }
}

int main() {
  vector<int>arr{2,2,1,1,1,1,1,2,2};
  int size = arr.size();

  int ans = UsingBoyerMooreAlgo(arr, size);

  if(ans){
    cout<<"Majority element is present: "<<ans<<endl;
  }else{
    cout<<"Majority element is not present"<<endl;
  }

  return 0;
}