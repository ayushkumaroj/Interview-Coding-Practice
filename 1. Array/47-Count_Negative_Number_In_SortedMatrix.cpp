#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

//Brute Frce: TC: O(m*n), SC: O(1)
int countNegative(vector<vector<int>>&grid){
  // Step 1: Get the number of rows (m) and columns (n) in the matrix
  int m = grid.size();
  int n = grid[0].size();
  // Step 2: Initialize a counter to store the total negative numbers
  int result = 0;
  // Step 3: Loop through every element in the matrix
  for(int i=0; i<m; i++){ // Loop through rows
    for(int j=0; j<n; j++){ // Loop through columns
      // Step 4: If the current element is negative, increment the counter
      if(grid[i][j] < 0){
        result++;
      }
    }
  }
  // Step 5: Return the total count of negative numbers
  return result;
}

// TC: O(m * logn) , SC: O(1)
int STLImplementation_OfBinarySearch(vector<vector<int>>&grid){
  // Step 1: Get the number of rows(m) and Get the number of columns(n)
  int m = grid.size();
  int n = grid[0].size();

  // Step 2: Initialize result to 0. This will store the final count of negative numbers
  int result = 0;

  // Step 3: Loop through each row of the grid
  for(int i=0; i<m; i++){
    // Step 4: Get a reference to the current row to make code cleaner and faster
    vector<int>&row = grid[i];
    // Step 6: Use upper_bound(Also called binary search) to Find the first position(index) where element becomes negative
    // In simple words: It finds where negative numbers start in a decreasingly sorted row
    // greater<int>() means we are searching in descending order
    int index = upper_bound(row.begin(), row.end(), 0, greater<int>()) - row.begin(); 
    // Step 7: Count how many numbers are negative in this row
    // (n - index) gives us the count of negative numbers in the current row
    result = result + (n-index);
  }
  // Step 8: After going through all rows, return the total number of negative numbers
  return result;
}

//TC: O(m*logn) , SC: O(1)
int UsingBinarySearch(vector<vector<int>>& grid){
  // Step 1: Find total number of rows
  int m = grid.size();

  // Step 2: Find total number of columns
  int n = grid[0].size();

  // Step 3: Initialize the result to 0 (to store the total count of negatives)
  int result = 0;

  // Step 4: Loop through every row in the grid
  for(int i=0; i<m; i++){
    // Step 5: Get reference to the current row
    vector<int>& row = grid[i];

    // Step 6: Apply binary search in this row to find first negative number
    int start = 0;       // Leftmost index
    int end = n - 1;     // Rightmost index
    int firstNegativeIndex = n;  // Default value: assume no negatives

    while(start <= end){
      int mid = start + (end-start)/2;

      // Step 7: If the mid element is negative
      if(row[mid] < 0){
        // Update firstNegativeIndex because we found a negative
        firstNegativeIndex = mid;
        // Move left to find an earlier negative
        end = mid-1;
      }
      else{
        // If element is not negative, go right
        start = mid + 1;
      }
    }
    // Step 8: Count how many negatives in this row
    // All elements after 'firstNegativeIndex' are negative
    result += (n - firstNegativeIndex);
  }
  // Step 9: Return the total count of negatives
  return result;
}

// Two-Pointer Technique (Also called Staircase / Z-Pattern Search)
//TC: O(M+N) , Bcz we eliminate row col, SC: O(1)
int usingStartFromCornerApproch(vector<vector<int>>& grid){
  // Step 1: Get the total number of rows(m) and Column(n) in the grid
  int m = grid.size();
  int n = grid[0].size();

  // Step 3: Start from the bottom-left corner of the grid
  // row = last row, col = first column
  int row = m-1;
  int col = 0;

  // Step 4: Initialize result to 0 (will store total count of negative numbers)
  int result = 0;

  // Step 5: Move in the grid while row is valid and column is valid
  while(row>=0 && col<n){
    // Step 6: Check the current element
    if(grid[row][col] >= 0){
      // If current element is positive or zero:
      // Since the grid is sorted (each row and column), 
      // all elements ABOVE this element in this column are also positive.
      // So we move to the NEXT column. or skip this column
      col++;
    }
    else if(grid[row][col] <= 0){
      // If current element is negative:
      // All elements to the RIGHT in this row are also negative
      // because the row is sorted in decreasing order.
      // So count all negatives in this row: (n - col)
      result = result + (n-col);
      // Move one row UP to check more negatives
      row--;
    }
  }
  // Step 7: Return the total count of negative numbers
  return result;
}


int main() {
    vector<vector<int>> grid = {
        {4, 3, 2, -1},
        {3, 2, 1, -1},
        {1, 1, -1, -2},
        {-1, -1, -2, -3}
    };

    // Step 2: Call the countNegative function
    int negativeCount = countNegative(grid);

    // Step 3: Print the result
    cout << "Total negative numbers in the matrix: " << negativeCount << endl;

    return 0;
}