#include<iostream>
using namespace std;
#include<vector>

/*
Arr[] = [2, 5, 1, 7, 9]
suppose i=0 , and j=2  || arr[i] = 2 , arr[j] = 1
Inversion : Inversion means if index i< j and a[i] > a[j] then it will count as 1 inversion
*/ 

// Brute Force: TC: O(N^2) , SC: O(1)
int Count_Inversion(vector<int>arr){
  int count = 0;
  
  for(int i=0; i<arr.size(); i++){
    for(int j=0; j<arr.size(); j++){
      if(i<j && arr[i]>arr[j]){
        count++;
      }
    }
  }

  cout<<"The Number of Inversion are: "<<count<<endl;
}

//Using Merge Sort (TC: O(nlogn), SC: O(N))
int merge(vector<int>&arr, int st, int mid, int end){
  int len1 = mid-st+1;
  int len2 = end-mid;
  int invCount = 0;

  //create an array
  int* left = new int[len1];
  int* right = new int[len2];

  //copy val of array to right and left sub array
  int k=st;
  for(int i=0; i<len1; i++){
    left[i] = arr[k];
    k++;
  }
  k=mid+1;
  for(int i=0; i<len2; i++){
    right[i] = arr[k];
    k++;
  }

  //Merge 2 sorted array
  int leftIndx = 0;
  int rightIndx = 0;
  int startInx = st;
  int mainArrayIndx = startInx;

  //Run a loop until any of the array finishes
  while(leftIndx < len1 && rightIndx<len2){
    if(left[leftIndx] < right[rightIndx]){
      arr[mainArrayIndx] = left[leftIndx];
      mainArrayIndx++;
      leftIndx++;
    }
    else if(right[rightIndx] < left[leftIndx]){
      arr[mainArrayIndx] = right[rightIndx];
      mainArrayIndx++;
      rightIndx++;
      //count inversion
      invCount = invCount + (len1-leftIndx);
    }
  }

  //copy left array value if right array has finished
  while(leftIndx < len1){
    arr[mainArrayIndx] = left[leftIndx];
    mainArrayIndx++;
    leftIndx++;
  }

  //copy right array value if left array has finished
  while(rightIndx < len2){
    arr[mainArrayIndx] = right[rightIndx];
    mainArrayIndx++;
    rightIndx++;
  }

  return invCount;
}


int mergeSort(vector<int>&arr, int st, int end){
  if(st < end){
    int mid = st + (end-st)/2;

    int leftInvCount = mergeSort(arr, st, mid);
    int rightInvCount = mergeSort(arr, mid+1, end);

    int invCount = merge(arr, st, mid, end);

    int totalInvCount = leftInvCount + rightInvCount + invCount;
    return totalInvCount;
  }

  //If invalid index is present
  return 0;
}

int main(){
  vector<int>arr{6, 3, 5, 2, 7};
  
  // Count_Inversion(arr);
  int ans = mergeSort(arr, 0, arr.size()-1);
  cout<<"Total Inv count is: "<<" "<<ans;
}