#include<iostream>
using namespace std;
#include<vector>

int Bubble_Sort(vector<int>arr){
  int size = arr.size();

  for(int i=0; i<size-1; i++){
    int swapped = 0;
    for(int j=1; j<size-i; j++){
      if(arr[j-1] > arr[j]){
        swapped = 1;
        swap(arr[j-1], arr[j]);
      }
    }
    if(swapped == 0){
      break;
    }

  }

  cout<<"The Sorted array are: ";
  for(int i=0; i<arr.size(); i++){
    cout<<arr[i]<<" ";
  }
  
}

int main(){
  vector<int>arr{10,1,7,6,14,9};

  Bubble_Sort(arr);
}