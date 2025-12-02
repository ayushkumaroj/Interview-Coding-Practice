#include<iostream>
#include<vector>
using namespace std;

//TC: O(N), SC: O(N)
void twoMissingNum(vector<int>arr){
    int n = arr.size(); // Current size of input array
    int m = n+2; // Total numbers expected (including the two missing ones)

    // Step 1: Create an auxiliary array 'brr' of size (m+1) initialized to 0.
    // This will help us mark which numbers are present in the original array.
    vector<int>brr(m+1, 0);

    // Step 2: Traverse the input array and mark presence in 'brr'.
    // If arr[i] exists, set brr[arr[i]] = 1.
    cout << "The two missing numbers are: ";
    for(int i=0; i<n; i++){
        brr[arr[i]] = 1;  
    }

    // Step 3: Traverse from 1 to m (since numbers are from 1 to m).
    // If brr[i] == 0, it means that number 'i' is missing.
    for(int i=1; i<=m; i++){
        if(brr[i] == 0){
            cout<<i<<" ";
        }
    }
}


//TC: O(N), SC:O(1)
void usingAddition(vector<int> arr){
    int n = arr.size(); // Current size of input array
    int m = n+2; // Total numbers expected (including the two missing ones)'
    
    // Step 1: Calculate the sum of first 'm' natural numbers using formula: sum = m*(m+1)/2
    int total_sum = m*(m+1)/2;

    // Step 2: Calculate the sum of all elements present in the array
    int sum = 0;
    for(int i=0; i<n; i++){
        sum += arr[i];
    }

    // Step 3: Find the sum of the two missing numbers
    int missing_sum = total_sum - sum;

    // Step 4: Compute the average (midpoint) of the two missing numbers
    // avg = missing_sum / 2 (this helps in dividing numbers into two groups: <= avg and > avg)
    int avg = missing_sum / 2;

    // Step 5: Compute sum of all numbers from 1 to avg
    int sum_oneToAvg = 0;
    for(int i=1; i<=avg; i++){
        sum_oneToAvg += i;
    }

    // Step 6: Compute sum of array elements which are less than or equal to avg
    int Sum_LessThen_Avg = 0;
    for(int i=0; i<n; i++){
        if(arr[i] <= avg){
            Sum_LessThen_Avg += arr[i];
        }
    }

    // Step 7: First missing number = difference of two sums (expected vs actual for <= avg)
    int first_Missing = sum_oneToAvg - Sum_LessThen_Avg;
    // Step 8: Second missing number = missing_sum - first missing number
    int second_Missing = missing_sum - first_Missing;

    // Step 9: Output the two missing numbers
    cout<<"The first missing element is: "<<first_Missing<<endl;
    cout<<"The second missing element is: "<<second_Missing<<endl;
}

int main(){
    vector<int> A = {1, 3, 5, 6};
    twoMissingNum(A);
    return 0;
}
