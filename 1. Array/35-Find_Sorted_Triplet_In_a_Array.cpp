#include<iostream>
using namespace std;
#include<vector>

//TC: O(N^3) SC: O(N)
int sorted_Increasing_Triplet(vector<int>arr){
  int n = arr.size();
  int found = 0; // Flag to track if any triplet is found

  // Step 1: Fix the first element of the triplet using index i
  for(int i=0; i<n; i++){
    // Step 2: Fix the second element using index j (must be after i)
    for(int j=i+1; j<n; j++){
      // Step 3: Check if arr[i] < arr[j], as required for an increasing triplet
      if(arr[i] < arr[j]){
        // Step 4: Fix the third element using index k (must be after j)
        for(int k = j+1; k<n; k++){
          // Step 5: Check if arr[j] < arr[k], completing the increasing triplet condition
          if(arr[j] < arr[k]){
            // Step 6: Print the triplet
            cout<<"Triplet: ("<<arr[i]<<","<<arr[j]<<","<<arr[k]<<")"<<endl;
            // return true;
            found = 1; // Set flag to indicate at least one triplet is found
          }
        }
      }
    }
  }
  // Step 7: If no triplet found, display message
  if(found == 0){
    cout<<"No sorted triplet found"<<endl;
  }
}

//TC: O(N), SC: O(1)
int sorted_Increasing_Triplet2(vector<int>arr){
  int n = arr.size();
  // Step 1: If size is less than 3, a triplet cannot exist
  if(n < 3){
    return false;
  }

  // Step 2: Initialize variables:
  // min_index → index of the smallest element seen so far
  int min_index = 0;
  // low → index of the first element of potential triplet
  int low = -1;
  // mid → index of the second element of potential triplet
  int mid = -1;

  // Step 3: Traverse the array starting from index 1
  for(int i=1; i<n; i++){
    // Case 1: Found a new minimum element → update min_index
    if(arr[i] < arr[min_index]){
      // Found new minimum → update min_index
      min_index = i;
    }
    // Case 2: Found a better middle candidate:
    // arr[i] is greater than the smallest element so far (min_index) but smaller than previous mid
    else if(mid == -1 || arr[i] <= arr[mid]){
      // Found a better mid value → current is greater than min but less than previous mid
      low = min_index;
      mid = i;
    }
    // Case 3: Found an element greater than mid → triplet exists
    else if(arr[i] > arr[mid]){
      // Found the 3rd element → arr[low] < arr[mid] < arr[i]
      cout << "Sorted Triplet Found: (" << arr[low] << ", " << arr[mid] << ", " << arr[i] << ")" << endl;
           // return true;
       }
    }
    // Step 4: If loop completes, no triplet exists
   cout << "No sorted triplet found in the array." << endl;
   return false;
}

int main(){
  vector<int>arr{5,4,3,7,6,1,9};

  int ans = sorted_Increasing_Triplet2(arr);
  cout<<"Is Increasing Triplet Exists: "<<ans;
}