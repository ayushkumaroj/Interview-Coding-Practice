#include<iostream>
using namespace std;
#include<vector>

// TC: O(N^2), SC: O(N)
int Brute_force(vector<int>arr){
  int n = arr.size();

  for(int i=0; i<n-1; i++){
    int leftSum = 0;
    int rightSum = 0;

    //Calculate left sum (0 to i)
    for(int j=0; j<=i; j++){
      leftSum = leftSum + arr[j];
    }

    // calculate right sum (i+1 to n-1)
    for(int j=i+1; j<n; j++){
      rightSum = rightSum + arr[j];
    }

    //check if both side are equal
    if(leftSum == rightSum){
      // Split point found at index i
      return i;
    }
  }
  return -1;
}

//TC: O(N) , SC: O(1)
int Find_Split_Index(vector<int>arr){
  int sum = 0;
  // Step 1: Calculate total sum
  for(int i=0; i<arr.size(); i++){
    sum = sum + arr[i];
  }

  int leftSum = sum;
  int rightSum = 0;

  // Step 2: Traverse from right to left
  for(int i = arr.size()-1; i>=0; i--){
    rightSum = rightSum + arr[i];
    leftSum = leftSum - arr[i];

    if(leftSum == rightSum){
      // Split at this index
       return i;
    }
  }
  // No split point found
  return -1;
}

int main(){
  vector<int>arr{1, 2, 3, 4, 5, 5};

  // int ans = Brute_force(arr);
  int ans2 = Find_Split_Index(arr);
  cout<<"Answer is"<<" "<<ans2;
}