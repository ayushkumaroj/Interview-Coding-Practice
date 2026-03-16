/*  Question: Check if a Pair with Given Sum Exists in an Unsorted Array
You are given an unsorted array of integers and a target sum.
Your task is to determine whether there exists any pair of elements in the array such that the sum of the pair is equal to the target sum.
Return true if such a pair exists, otherwise return false.

Input: a[] = {9, 10, 11, 15, 26, 38}, target_sum = 35  
Output: true  
(Explanation: 9 + 26 = 35)

Input: a[] = {1, 2, 3, 9}, target_sum = 8  
Output: false  

*/ 


#include<iostream>
using namespace std;
#include<vector>

//TC: O(N^2), SC: O(1)
int check_target_Sum(vector<int>arr, int target_sum){
  for(int i=0; i<arr.size(); i++){
    for(int j=i+1; j<arr.size(); j++){
      if(arr[i] + arr[j] == target_sum){
        return true;
      }
    }
  }
  return false;
}

int main(){
  vector<int>arr{9, 10, 11, 15, 26, 38};
  int target_sum = 85;

  int  ans = check_target_Sum(arr,target_sum );
  if(ans){
    cout<<"True";
  }
  else{
    cout<<"False";
  }
}
 