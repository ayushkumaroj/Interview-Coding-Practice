#include<iostream>
#include<vector>
using namespace std;

int main(){
  // vector<int>arr{3, 0, 4, 1, 2};

  // cout<<arr[arr[2]]<<endl;
  // cout<<arr[arr[1]+1]<<endl;

  // int a[5] = {10,20,30,40,50};
  // int pos[5] = {3,0,4,1,2};
  // cout<<a[pos[2]]<<endl;

  // vector<int>arr{2,0,3,1};
  // cout<<arr[arr[arr[1]]]<<endl;

  vector<int>mark{1,2,0,1,2};
  vector<int>count(3, 0);

  for(int i=0; i<5; i++){
    count[mark[i]]++;
  }

  for(int i=0; i<3; i++){
    cout<<count[i]<<" ";
  }
}