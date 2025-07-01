#include<iostream>
using namespace std;
#include<vector>

int Search_In_Sorted_Array(vector<int>arr, int sum){
  int n = arr.size();
  int i;

  //Step1: Find pivot (index where a[i] > a[i+1])
  for(i=0; i<n-1; i++){
    if(arr[i] > arr[i+1]){
      break;
    }
  }

  //Step 2: Set start and end
  int start = (i+1) % n; //Index of smallest elem
  int end = i; //Index of largest elem

  //Step 3: Two pointer approch in rotated array
  while(start != end){
    if(arr[start] + arr[end] == sum){
      return true;
    }
    else if(arr[start] + arr[end] < sum){
      //move forward in circular manner
      start = (start + 1)%n;
    }
    else if(arr[start] + arr[end] > sum){
      //Move backward in circular manner
      end = (n + end -1) % n;
    }
  }
  //If no pair found
  return false;
}

int main(){
  vector<int>arr{11,15,26,38,9,10};
  int sum = 206;

  cout<<Search_In_Sorted_Array(arr, sum);
}