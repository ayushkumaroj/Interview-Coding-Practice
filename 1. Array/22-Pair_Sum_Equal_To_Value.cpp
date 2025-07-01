#include<iostream>
using namespace std;
#include<vector>

int Pair_Sum(vector<int>arr, int sum){
  for(int i=0; i<arr.size(); i++){
    for(int j=i+1; j<arr.size(); j++){
      //if sum of prev and next elem are equal to sum
      if(arr[i] + arr[j] == sum){
        cout<<"("<<arr[i]<<","<<arr[j]<<")"<<endl;
      }
    }
  }
}

int main(){
  vector<int>arr{1, 3, 5, 7, 2, 4, 6};
  int sum = 9;

  Pair_Sum(arr, sum);
}