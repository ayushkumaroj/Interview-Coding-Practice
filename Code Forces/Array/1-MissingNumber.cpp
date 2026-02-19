/*
Find Missing Number in Array 
Arr[] = {1,2,4,5} , N= 5, O/P = 3
*/

#include<iostream>
using namespace std;
#include<vector>

int MissingNumber(vector<int>arr){
   int n = arr.size()-1;
    int sumOfN = n*(n+1)/2;

    int sum = 0;
    for(int i=0; i<n; i++){
        sum = sum+arr[i];
    }

    int result = sumOfN-sum;
    cout<<"Missing Number is: "<<" "<<result;
    
}

int main(){
    vector<int>arr = {1,2,4,5};
   int ans = MissingNumber(arr);
   cout<<ans<<" "<<endl;

   return 0;
}