#include<iostream>
using namespace std;
#include<vector>

void union_without_duplicate(vector<int>arr, vector<int>brr){
  //create one answer array
  vector<int>ans;
  

  //insert all elem of arr intp ans
  for(int i=0; i<arr.size(); i++){
    ans.push_back(arr[i]);
  }

  //before inserting elem of brr. check elem in ans or not
  for(int i=0; i<brr.size(); i++){
    int flag = 0;
    for(int j=0; j<ans.size(); j++){
      if(brr[i] == ans[j]){
        flag = 1;
        break;
      }
    }
    if(flag == 0){
      ans.push_back(brr[i]);
    }
  }

  //print the arary
  for(int i=0; i<ans.size(); i++){
    cout<<ans[i]<<" ";
  }
}

int main(){
  vector<int>arr{1, 2, 3, 4};
  vector<int>brr{2, 3, 4, 5};

  union_without_duplicate(arr, brr);
}