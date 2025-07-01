#include<iostream>
using namespace std;
#include<vector>

int triple_sum(vector<int>arr, int sum){

  for(int i=0; i<arr.size(); i++){
    for(int j=i+1; j<arr.size(); j++){
      for(int k= j+1; j<arr.size(); j++){
        if(arr[i] + arr[j] + arr[k] == sum){
          cout<<"("<<arr[i]<<","<<arr[j]<<","<<arr[k]<<")";
        }
      }
    }
  }
}


int main(){
  vector<int>arr{10, 20, 30, 40};
  int sum = 60;

  triple_sum(arr, sum);
}