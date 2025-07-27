#include<iostream>
using namespace std;

//TC: O(m*n), SC: O(1)
int Binary_Search_2D(int arr[][4],int row, int col, int target){
  //variable to tract wheather the target is found
  int found = 0;

  //Traverse each row
  for(int i=0; i<row; i++){
    //Traverse each column within current row
    for(int j=0; j<col; j++){
      //check if current element matches row
      if(arr[i][j] == target){
        //mark we found the target
        found = 1;
        cout<<"Target Found in array at row index"<<" "<<i<<" "<<"And col index"<<" "<<j<<endl;
        //Exit the inner loop since target is found
        break;
      }
    }
  }
  //If target is not found in the entire matrix
  if(found == 0){
    cout<<"Target Not found in the array";
  }
}


int main(){
  int arr[3][4] = {{1,2,3,4}, {5,6,7,8}, {9,10,11,12}};
  int target = 141;

  Binary_Search_2D(arr,3,4, target);
}