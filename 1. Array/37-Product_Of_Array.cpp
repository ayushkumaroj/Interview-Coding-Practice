#include<iostream>
using namespace std;
#include<vector>

// TC: O(N^2), SC: O(N)
int Brute_Force(vector<int>arr){
  int n = arr.size();
  vector<int>ans(n, 1);

  for(int i=0; i<n; i++){
    int prod = 1;
    for(int j=0; j<n; j++){
      if(i != j){
        prod = prod * arr[j];
      }
    }
    ans[i] = prod;
  }

  //Print the answer
  for(int i=0; i<ans.size(); i++){
    cout<<ans[i]<<" ";
  }
}


//TC: O(N) , SC: O(N)
int ProductOfArray(vector<int>arr){
  int n = arr.size();

  //Create two array left and right of size n
  //Left array contain product of all elem from 0 to i-1
  vector<int>left(n);
  //Right array contain product of all elem from i+1 to n-1
  vector<int>right(n);

  //Fill left array
  left[0] = 1;
  for(int i=1; i<n; i++){
    left[i] = left[i-1] * arr[i-1];
  }

  //Fill right array
  right[n-1] = 1;
  for(int i=n-2; i>=0; i--){
    right[i] = right[i+1] * arr[i+1];
  }

  //Store the prod of left and right into ans
  vector<int>ans(n);
  for(int i=0; i<n; i++){
    ans[i] = left[i] * right[i];
  }

  //Print the answer
  for(int i=0; i<ans.size(); i++){
    cout<<ans[i]<<" ";
  }
}


int main(){
  vector<int>arr{1,2,3,4};

  // Brute_Force(arr);
  // Optimized(arr);
  ProductOfArray(arr);
}