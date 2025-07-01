#include<iostream>
using namespace std;
#include<vector>

//Brute Force(TC: O(N2), SC:O(N))
int BruteForce(vector<int>arr){
  vector<int>ans;

  for(int i=0; i<arr.size(); i++){
    if(arr[i] % 2 == 0){
      ans.push_back(arr[i]);
    }
  }

  for(int j= 0; j<arr.size(); j++){
    if(arr[j] % 2 != 0){
      ans.push_back(arr[j]);
    }
  }

  //print the answer array
  for(int i=0; i<ans.size(); i++){
    cout<<ans[i]<<" ";
  }
}

//Using Two pointer (TC: O(N), SC:O(1))
int Using_Two_Pointer(vector<int>arr){
  int start = 0;
  int end = arr.size()-1;

  while(start <= end){
    if(arr[start] % 2 == 0){
      start++;
    }
    else if(arr[end] % 2 != 0){
      end--;
    }
    else if(arr[end] % 2 == 0){
      swap(arr[start], arr[end]);
      start++;
      end--;
    }
  }
  //print the array
  for(int i=0; i<arr.size(); i++){
    cout<<arr[i]<<" ";
  }
}

int main(){
  vector<int>arr{3,1,2,4};

  // Using_Two_Pointer(arr);
  BruteForce(arr);
}