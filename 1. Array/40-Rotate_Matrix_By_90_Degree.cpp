#include<iostream>
using namespace std;

//TC: O(row*col) , SC: O(row*col)
int rotate_matrix(int arr[][3], int row, int col){
  //Create matrix to store the rotated result
  int ans[row][col];

  //Rotate matrix by 90 deg clock wise
  for(int i=0; i<col; i++){
    for(int j=0; j<col; j++){
      //Formula to rotate: (i,j) becomes (j, col-1-i)
      ans[j][col-1-i] = arr[i][j];
    }
  }

  //Print the matrix
  for(int i=0; i<3; i++){
    for(int j=0; j<3; j++){
      cout<<ans[i][j]<<" ";
    }
  }
}

// In Constant Space SC: O(1)
void rotate_matrixx(int arr[][3], int row, int col){

  //STEP 1: Transpose the matrix (swap element across diagonal)
  for(int i=0; i<row; i++){
    for(int j=i+1; j<col; j++){
      swap(arr[i][j], arr[j][i]);
    }
  }

  //STEP 2: Reverse each row
  for(int i=0; i<col; i++){
    int start = 0;
    int end = col-1;

    while(start <= end){
      swap(arr[i][start], arr[i][end]);
      start++;
      end--;
    }
  }

  //Print the rotated Matrix
  for(int i=0; i<col; i++){
    for(int j=0; j<col; j++){
      cout<<arr[i][j]<<" ";
    }
  }
}


int main(){
  int arr[3][3] = {{1,2,3}, {4,5,6}, {7,8,9}};

  rotate_matrixx(arr, 3, 3);
}