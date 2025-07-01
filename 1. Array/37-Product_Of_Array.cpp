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

//TC: O(N), SC: O(N)
int Using_LinearTime_ExtraSpace(vector<int>arr){
  int n = arr.size();
  vector<int>ans(n,1);
  vector<int>prefix(n,1); //Prefix = left sub Array
  vector<int>suffix(n,1); // suffix = right Sub Array

  //Calculate prefix(left array) product
  for(int i=1; i<n; i++){
    prefix[i] = prefix[i-1] * arr[i-1];
  }

  //Calculte suffix(right array) product
  for(int i=n-2; i>=0; i--){
    suffix[i] = suffix[i+1] * arr[i+1];
  }

  for(int i=0; i<n; i++){
    ans[i] = prefix[i] * suffix[i];
  }

  //print the answer
  for(int i=0; i<ans.size(); i++){
    cout<<ans[i]<<" ";
  }

}

//TC: O(N) , SC: O(1)
int Optimized(vector<int>arr){
  int n = arr.size();
  vector<int>ans(n, 1);

  //Prefix = ans
  for(int i=1; i<n; i++){
    ans[i] = ans[i-1] * arr[i-1];
  }

  //suffix
  int suffix = 1;
  for(int i=n-2; i>=0; i--){
    suffix = suffix * arr[i+1];
    ans[i] = ans[i] * suffix;
  }

  //Print the answer
  for(int i=0; i<arr.size(); i++){
    cout<<ans[i]<<" ";
  }
}


int main(){
  vector<int>arr{1,2,3,4};

  // Brute_Force(arr);
  Optimized(arr);
}