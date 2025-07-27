#include<iostream>
using namespace std;
#include<vector>

/*
- Condition: Element must be in sorted order
- If array have 1000 element then Linear search take 1000 comparsion in worst case. But Binary search just take 10 comparison, which far less then 1000 comparison.
- TC: Best: O(1) , Average: O(nlogn) , Worst: O(logn)
- SC: O(1)
*/
int Binary_Search(vector<int>arr, int key){
  int size = arr.size();

  int start = 0;
  int end = size-1;
  int mid =  start + (end - start)/2;

  while(start <= end){
    //Return the mid index if it equal to target
    if(key == arr[mid]){
      return mid;
    }
    //If target is greater then mid, then search in right part
    else if(key > arr[mid]){
      start = mid+1;
    }
    //If target is less then mid, then search in left part
    else if(key < arr[mid]){
      end = mid - 1;
    }

    //Update the mid with updated start and end
    mid = (start + end)/2;

  }

  //If key is not found return -1
  return -1;
}

int main(){
  vector<int>arr{2,4,6,8,10,12,16};
  int key = 12;

  int ans = Binary_Search(arr, key);

  if(ans == -1){
    cout<<"Key is not present in the array"<<endl;
  }
  else{
    cout<<"Key "<<" "<< key <<" "<<"is found at index: "<<" "<<ans;
  }

  return 0;
}

