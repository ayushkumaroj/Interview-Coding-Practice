#include<iostream>
using namespace std;
#include<vector>

void Array_Intersection(vector<int>arr, vector<int>brr){
  //create answer array
  vector<int>ans;

  for(int i=0; i<arr.size(); i++){
    for(int j=0; j<brr.size(); j++){
      //if both elem are common then put it into ans
      if(arr[i] == brr[j]){
        ans.push_back(arr[i]);
      }
    }
  }

  //print the answer array
  for(int i=0; i<ans.size(); i++){
    cout<<ans[i]<<" ";
  }
}

int main(){
  vector<int>arr{1,2,3,4,6,8};
  vector<int>brr{3, 4, 9, 10};

  Array_Intersection(arr, brr);
}