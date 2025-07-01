#include<iostream>
using namespace std;
#include<vector>

int four_Sum(vector<int>arr, int sum){
  for(int i=0; i<arr.size(); i++){
    for(int j=i+1; j<arr.size(); j++){
      for(int k=j+1; k<arr.size(); k++){
        for(int l = k+1; l<arr.size(); l++){
         if(arr[i]+arr[j]+arr[k]+arr[l] == sum){
           cout<<"("<<arr[i]<<","<<arr[j]<<","<<arr[k]<<","<<arr[l]<<")";
         }
        }
      }
    }
  }
}

int main(){
  vector<int>arr{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int sum = 10;

  four_Sum(arr, sum);

}