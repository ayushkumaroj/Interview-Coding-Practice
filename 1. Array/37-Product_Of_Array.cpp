#include<iostream>
using namespace std;
#include<vector>

// TC: O(N^2), SC: O(N)
int Brute_Force(vector<int>arr){
  int n = arr.size();
  // Step 1: Create an answer array of size n and initialize it with 1
  vector<int>ans(n, 1);

  // Step 2: Loop through each element in the array using index i.
  // For each element, we will calculate the product of all other elements.
  for(int i=0; i<n; i++){
    // Step 3: Initialize a variable 'prod' as 1.
    int prod = 1; 
    // Step 4: Loop through the array again with index j.
    // Multiply all elements except when j == i (skip the current element).
    for(int j=0; j<n; j++){
      if(i != j){
        prod = prod * arr[j]; // Multiply current element into product
      }
    }
    // Step 5: After the inner loop, assign the calculated product to ans[i].
    ans[i] = prod;
  }

  //Print the answer
  for(int i=0; i<ans.size(); i++){
    cout<<ans[i]<<" ";
  }
}


//TC: O(N) , SC: O(N)
int ProductOfArray(vector<int>arr){
  int n = arr.size();

  // Step 1: Create two helper arrays:
  // 'left' will store the product of all elements to the LEFT of the current index.
  // 'right' will store the product of all elements to the RIGHT of the current index.
  vector<int>left(n);
  vector<int>right(n);

  // Step 2: Initialize the first value of 'left' as 1 because there are no elements to the left of the first element.
  left[0] = 1;

  // Step 3: Fill the 'left' array:
  // For each position i, left[i] = product of all elements from index 0 to i-1.
  for(int i=1; i<n; i++){
    left[i] = left[i-1] * arr[i-1];
  }

   // Step 4: Initialize the last value of 'right' as 1 because there are no elements to the right of the last element.
  right[n-1] = 1;

  // Step 5: Fill the 'right' array:
  // For each position i, right[i] = product of all elements from index i+1 to n-1.
  for(int i=n-2; i>=0; i--){
    right[i] = right[i+1] * arr[i+1];
  }

  // Step 6: Create an answer array 'ans' of size n.
  // Multiply left[i] and right[i] to get the product of all elements except arr[i].
  vector<int>ans(n);
  for(int i=0; i<n; i++){
    ans[i] = left[i] * right[i];
  }

  // Step 7: Print the final result array.
  for(int i=0; i<ans.size(); i++){
    cout<<ans[i]<<" ";
  }
}


int main(){
  vector<int>arr{1,2,3,4};

  // Brute_Force(arr);
  // Optimized(arr);
  ProductOfArray(arr);
}