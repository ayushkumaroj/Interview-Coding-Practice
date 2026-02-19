#include<iostream>
using namespace std;
#include<vector>

int usingLoop(vector<int>arr, int n){
    //Step 1: I check number from 1 to n+1 because one number in this full range must be missing
    for(int i=1; i<=n+1; i++){
        //Step 2: I set flag to 0 because at first I assume that number i is missing
        int flag = 0;

        //Step 3: I go through the whole array to see if number i is present or not
        for(int j=0; j<n; j++){
            //step 4: If i find number i in the array, I set flag to 1 because it exist
            if(arr[i] == i){
                flag = 1;
                break;
            }
        }

        //Step 5: If flag is still 0 after checking the array, it means number i was never found
        if(flag == 0){
            //Step 6: I return i because this is the missing number
            return i;
        }

        //Step 7: If no number is missing(just for safety), I return -1
        return -1;
    }
}

// Approach 2: SUM METHOD
// TC: O(N), SC: O(1)
int UsingSumOfN(vector<int> arr, int n) {

    // Step 1: Expected sum of numbers from 1 to n+1 because one number is missing and the full range becomes 1 to n+1
    // NOTE: Normally we use N*(N+1)/2 when numbers are from 1 to N, but here numbers are from 1 to n+1 so we use (n+1)*(n+2)/2
    int sumofN = (n + 1) * (n + 2) / 2;

    // Step 2: Calculate the actual sum of all elements present in the array because this tells us what values are already included
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }

    // Step 3: Missing number is the difference between expected sum and actual sum because the missing value was never added
    return sumofN - sum;
}

