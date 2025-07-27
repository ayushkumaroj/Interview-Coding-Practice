#include<iostream>
using namespace std;
#include<vector>

void Selection_sort(vector<int>arr){
 int size = arr.size();

 for(int i=0; i<size-1; i++){
  int swapped = 0;
  for(int j=1; j<size; j++){
    if(arr[j-1] > arr[j]){
      swapped = 1;
      swap(arr[j-1], arr[j]);
    }
  }

  if(swapped == 0){
    break;
  }

 }

 //Print the element
 for(int i=0; i<arr.size(); i++){
  cout<<arr[i]<<" ";
 }
}

int main(){
  vector<int>arr{12,56,78,2,35,9};

  Selection_sort(arr);
}