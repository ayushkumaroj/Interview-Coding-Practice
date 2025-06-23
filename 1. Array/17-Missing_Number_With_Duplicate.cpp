// Find missing elements from an Array with duplicates
// Array: [1, 2, 2, 4, 5]  
// N = 5  
// Missing number = 3  
// (Note: '2' is duplicated)

#include<iostream>
using namespace std;
#include<vector>

void MissingWithDuplicate(vector<int>arr){
  int n = arr.size();

  for(int i=0; i<n; i++){
    //Take the absolute of elem
    int elem = abs(arr[i]);
    //if elem is greater then zero
    if(arr[elem-1] > 0){
      //mark that elem negative
      arr[elem-1] = -arr[elem-1];
    }
  }

  for(int i=0; i<n; i++){
    //if elem is positive
    if(arr[i] > 0){
      //print next index
      cout<<(i+1)<<endl;
    }
  }
}

int main(){
  vector<int>arr{1,3,5,3,4, 4};
  
  MissingWithDuplicate(arr);
}
