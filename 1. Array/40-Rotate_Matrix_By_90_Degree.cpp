#include<iostream>
using namespace std;

//TC: O(row*col) , SC: O(row*col)
int rotate_matrix(int arr[][3], int row, int col){
  // Step 1: Create a new matrix 'ans' to store the rotated result
  int ans[row][col];

  // Step 2: Perform the rotation
  // Traverse through each element of the original matrix
  for(int i=0; i<col; i++){
    for(int j=0; j<col; j++){
      // Step 3: Apply the rotation formula
      // In a 90-degree clockwise rotation:
      // Element at position (i, j) in original matrix moves to (j, col - 1 - i) in the rotated matrix
      ans[j][col-1-i] = arr[i][j];
    }
  }

  // Step 4: Print the rotated matrix
  // Loop through the new matrix and print each element
  for(int i=0; i<3; i++){
    for(int j=0; j<3; j++){
      cout<<ans[i][j]<<" ";
    }
    cout<<endl; // Move to the next row
  }
}

// TC: O(n^2) , In Constant Space SC: O(1)
void rotate_matrixx(int arr[][3], int row, int col){

  // Step 1: Transpose the matrix
  // Transpose means converting rows to columns.
  // We swap elements across the diagonal so that element at (i, j) moves to (j, i).
  for(int i=0; i<row; i++){
    for(int j=i+1; j<col; j++){
      swap(arr[i][j], arr[j][i]); // Swap only upper triangular elements to avoid double swap
    }
  }

  // Step 2: Reverse each row
  // After transpose, to complete the 90° clockwise rotation, reverse every row.
  for(int i=0; i<col; i++){
    int start = 0;
    int end = col-1;

    // Swap elements from left to right in each row
    while(start <= end){
      swap(arr[i][start], arr[i][end]);
      start++;
      end--;
    }
  }

  // Step 3: Print the rotated matrix
  for(int i=0; i<col; i++){
    for(int j=0; j<col; j++){
      cout<<arr[i][j]<<" ";
    }
    cout<<endl;// Move to next row
  }
}



int main(){
  int arr[3][3] = {{1,2,3}, {4,5,6}, {7,8,9}};

  rotate_matrixx(arr, 3, 3);
}