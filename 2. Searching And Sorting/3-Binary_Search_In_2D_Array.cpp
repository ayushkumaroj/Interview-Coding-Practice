#include<iostream>
using namespace std;

// TC: O(log(m * n)) , SC: O(1)
int Binary_Search_in_2D(int arr[3][4], int row, int col, int target){

  int start = 0;             // Starting index (as if its a 1D array)
  int end = row*col-1;       // Ending index
  int mid = (start + end)/2; // Middle index

  while(start <= end){
    int row_Index = mid/col;   //Convert 1D index to row index
    int col_Index = mid % col; //Convert 1D index to column index

    if(target == arr[row_Index][col_Index]){
      return true; //Target Found
    }
    else if( target > arr[row_Index][col_Index]){
      start = mid+1; //Search in right half
    }
    else if(target < arr[row_Index][col_Index]){
      end = mid-1; //Search in left half
    }

    mid = (start+end)/2; //Update mid
  }
  return false; //Target not found
}

int main(){
  int arr[3][4] = {
                   {1, 2, 3, 4},
                   {5, 6, 7, 8},
                  {9, 10, 11, 12}
                  };

  int target = 111;

  int ans = Binary_Search_in_2D(arr, 3, 4, target);

  if(ans){
    cout<<"Element found";
  }
  else{
    cout<<"Element not found";
  }

}