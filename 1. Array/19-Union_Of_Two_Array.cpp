#include<iostream>
using namespace std;
#include<vector>

void union_Array(vector<int>arr, vector<int>brr){

  //create on array
  vector<int>ans;

  //put elem of arr into ans
  for(int i=0; i<arr.size(); i++){
    ans.push_back(arr[i]);
  }

  //put elem of brr into ans
  for(int j=0; j<brr.size(); j++){
    ans.push_back(brr[j]);
  }

  //print the answer array , which is union
  for(int i=0; i<ans.size(); i++){
    cout<<ans[i]<<" ";
  }
}

int main(){
  vector<int>arr{2,4,6,8};
  vector<int>brr{1,3,7,6};

  union_Array(arr, brr);
}