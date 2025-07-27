#include<iostream>
using namespace std;

void rotate_matrix(int arr[][3], int row, int col){
  //take transpose of the matrix
  for(int i=0; i<row; i++){
    for(int j=i+1; j<col; j++){
      swap(arr[i][j], arr[j][i]);
    }
  }

  //Now reverse each row
  for(int i=0; i<col; i++){
    int start = 0;
    int end = col-1;
    while(start <= end){
      swap(arr[i][start], arr[i][end]);
      start++;
      end--;
    }
  }

  //Print the matrix
  for(int i=0; i<row; i++){
    for(int j=0; j<col; j++){
      cout<<arr[i][j]<<" ";
    }
  }

}

int main(){
  int arr[3][3] = {{1,2,3}, {4,5,6}, {7,8,9}};

  rotate_matrix(arr, 3, 3);
}