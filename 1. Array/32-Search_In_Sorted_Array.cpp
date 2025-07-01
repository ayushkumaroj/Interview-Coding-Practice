/*
Input:
An integer array arr[] of size n (sorted in ascending order).
An integer target_sum.

Output: true if any two distinct elements in the array sum up to target_sum, otherwise false.
Input: arr[] = {2, 4, 7, 11, 14, 20}, target_sum = 18  
Output: true  
(Explanation: 4 + 14 = 18)

Input: arr[] = {1, 3, 5, 8, 10}, target_sum = 17  
Output: false

*/

#include<iostream>
using namespace std;
#include<vector>

//TC: O(N) , SC: O(1)
int search_in_Sorted(vector<int>arr, int target_sum){
  int start = 0;
  int end = arr.size()-1;

  while(start <= end){
    if(arr[start] + arr[end] > target_sum){
      end--;
    }
    else if(arr[start] + arr[end] < target_sum){
      start++;
    }
    else if(arr[start] + arr[end] == target_sum){
      return true;
    }
  }

  return false;
}

int main(){
  vector<int>arr{2,4,7,11,14,20};
  int target_sum = 138;

  cout<<search_in_Sorted(arr, target_sum);
}