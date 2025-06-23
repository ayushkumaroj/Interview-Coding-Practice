#include<iostream>
using namespace std;
#include<vector>

//Brute Force: TC: 0(N^2), SC:O(N)
int first_repeating(vector<int>arr){
  int n = arr.size();

  for(int i=0; i<n; i++){
    for(int j=i+1; j<n; j++){
      if(arr[i] == arr[j]){
        return arr[j];
      }
    }
  }
}

int First_Repeating_elem(vector<int>arr){
  int n = arr.size();
  //Create an array of size 10^6
  vector<int>count_Array(10000, 0);

  //count Freq of each elem
  for(int i=0; i<n; i++){
    count_Array[arr[i]]++;
  }

  for(int i=0; i<n; i++){
    //if any elem appear greater than or equal 2
    //then return that
    if(count_Array[arr[i]] >= 2){
      int ans = arr[i];
      return ans;
    }
  }
}

int main(){
  vector<int>arr{1,2,3,4,5,6, 6};

  // int ans = first_repeating(arr);
  // cout<<"The first repeating element is: "<<ans;

  int ans2 = First_Repeating_elem(arr);
  cout<<"The first repeating element is: "<<ans2;

}