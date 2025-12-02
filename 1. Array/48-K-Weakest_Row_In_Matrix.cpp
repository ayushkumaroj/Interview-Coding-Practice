#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
#include<queue>


//Step 2: Function to count number of 1's in a row using Binary Search(This funt is same for sorting method + heap method)
int binarySearch(vector<int>& arr, int start, int end){
  //Step 1: Initialize result as -1 to store index of last 1
  int result = -1;

  // Step 2: Perform binary search on the row
  while(start <= end){
    int mid = start+(end-start)/2;

    // Step 3: If mid element is 1, move right to find last 1
    // In sorted row (1's followed by 0's), last 1 gives total count
    if(arr[mid] == 1){
      result = mid;
      start = mid+1;
    }
    // Step 4: If mid is 0, move left because all elements to the right are also 0
    else{
      end = mid-1;
    }
  }
  // Step 5: Return count of 1's
  // If last 1 is at index result, count = result + 1
  return result+1;
}

//USING Sorting + Binary Search
// TC: O(m * log n + m log m) -> o(mlogn) for binary search in each row + O(mlogn) for sorting
// SC: O(m) for sotoring pairs of (Count of 1's, row index)
//Step 1: Function To find K weakest row index (Sorting Method)
vector<int> kWeakestRows(vector<vector<int>>& mat, int k){
  //Step 1: Get the number of row(m) and column(n)
  int m = mat.size();
  int n = mat[0].size();

  //Step 2: Create a vector to store {number of soldiers, row index}
  // We need to know the strength of each row (how many soldiers) along with its index
  vector<pair<int, int>>countOne;

  //Step 3: Loop through each row of matrix
  for(int row=0; row<m; row++){
    //step 4: Count soldier's (1s) in this row using binary search
    // Each row is sorted (1's then 0's), so binary search is efficient
    int num_of_ones = binarySearch(mat[row], 0, n-1);

    //Step 5: Store the count along with the row index
    // We will sort later based on strength (count of 1's)
    countOne.push_back({num_of_ones, row});
  }

  //Step 6: Sort all row based on:
  // - First: count of 1's (ascending)
  // - Second: row index (Ascending).
  // The weakest row is the one with fewer soldiers(1's); in case of tie, smaller index wins
  sort(countOne.begin(), countOne.end());

  // Step 6: Create result vector with first k row indices,  We only need the k weakest rows
  vector<int>result(k);
  for(int i=0; i<k; i++){
    result[i] = countOne[i].second;
  }
  // Step 7: Return the final result
  return result;
}

//Using Heap Method + Binary Search
//TC: O(mlogn+mlogk) (When k << m, this is much faster than O(m log m))
//SC: O(k)
vector<int> kWeakestRowsUsingHeap(vector<vector<int>>& mat, int k){
  int m = mat.size(); // Number of rows
  int n = mat[0].size(); // Number of columns

  // Step 1: Create a max heap (stores strongest rows at top)
  // We will store pairs: (soldier(1) count, row index)
  priority_queue<pair<int,int>>pq;

  int left = 0, right = n - 1; // For binary search

  // Step 2: Check each row one by one
  for(int row=0; row<m; row++){
    // Step 2.1: Count soldiers(1) in this row using binary search (Same binary search code like prev approch)
    int num_of_ones = binarySearch(mat[row], left, right);

    // Step 2.2: Add the row info to the heap
    // Heap keeps strongest row at the top so we can remove it easily
    pq.push({num_of_ones, row});

    // Step 2.3: If heap size is bigger than k, remove top element
    // We only need k weakest rows, so discard strongest one
    if(pq.size() > k){
      pq.pop();
    }
  }
  // Step 3: // Create a vector of size k to store the weakest row indices
  vector<int>result(k);
  // Start filling the result from the last index, bcz We will get the strongest rows first from the heap, so they should go at the end.
  int j = k - 1; 
  while (!pq.empty()) {
    // Step 3.1: Take the top element from the heap (strongest among remaining), pq.top() gives us a pair {soldier count, row index}
    result[j] = pq.top().second; // Store the row index in the result at position j

    pq.pop(); // Remove this row from the heap
    j--; // Move to the next position from the end
  }
  // Step 4: Return the result, Now the result array contains k weakest rows in correct order (weakest first)
  return result;
}


int main() {
    // Example input
    vector<vector<int>> mat = {
        {1, 1, 0, 0, 0},
        {1, 1, 1, 1, 0},
        {1, 0, 0, 0, 0},
        {1, 1, 0, 0, 0},
        {1, 1, 1, 1, 1}
    };

    int k = 3;

    vector<int> ans = kWeakestRowsUsingHeap(mat, k);

    cout << "The " << k << " weakest rows are: ";
    for (int index : ans) {
        cout << index << " ";
    }
    cout << endl;

    return 0;
}