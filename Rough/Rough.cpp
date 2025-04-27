#include<iostream>
using namespace std;
#include<vector>

int rotate_Once(vector<int>&arr){
  //take out last element of array
  int size = arr.size();
  int temp = arr[size-1];
  for(int i= size-2; i>=0; i--){
    arr[i+1] = arr[i];
  }
  arr[0] = temp;
}se

int main(){
  vector<int>arr{1,2,3,4,5,6,7};
  int k = 3;

  for(int i=0; i<k; i++){
    rotate_Once(arr);
  }

  cout<<"Rotated array is: ";
  for(int i=0; i<arr.size(); i++){
    cout<<arr[i]<<" ";
  }
 

}