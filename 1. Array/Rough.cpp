#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

void sort_number(vector<int>arr){
 
  int start = 0;
  int end = arr.size()-1;

  while(start <= end){
    if(arr[start] > arr[end]){
      swap(arr[start], arr[end]);
      start++;
      end--;
    }else{
      start++;
      end--;
    }
  }

  for(int i=0; i<arr.size(); i++){
    cout<<arr[i]<<" ";
  }
  
}

int main(){
  vector<int>arr{12, 45, 67, 98};

  sort_number(arr);
}