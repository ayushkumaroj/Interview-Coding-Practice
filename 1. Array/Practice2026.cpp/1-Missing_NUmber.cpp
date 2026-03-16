#include<iostream>
using namespace std;
#include<vector>

int findMissing(vector<int>arr){
   int n = arr.size();
   int totalSum = n*(n+1)/2;

   int sum = 0;
   for(int i=0; i<n; i++){
        sum = sum + arr[i];
    }

   return totalSum - sum;
}


int main(){
    vector<int>arr{1,2,4,5};
    int result = findMissing(arr);

    cout<<"The Missing Number is: "<<result;
}