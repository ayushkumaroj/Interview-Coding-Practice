#include<iostream>
#include<vector>
using namespace std;

//TC: O(N), SC: O(N)
void twoMissingNum(vector<int>arr){
    int n = arr.size();
    int m = n+2;
    //create a vector and initialize with 0
    vector<int>brr(m+1, 0);

    //mark number which are presnt in input array
    for(int i=0; i<n; i++){
        brr[arr[i]] = 1;  
    }

    //print the two missing element
    for(int i=1; i<=m; i++){
        if(brr[i] == 0){
            cout<<i<<" ";
        }
    }
}


//TC: O(N), SC:O(1)
void usingAddition(vector<int> arr){
    int n = arr.size();
    int m = n+2;
    //1. find total sum
    int total_sum = m*(m+1)/2;

    //2. cal array elem sum
    int sum = 0;
    for(int i=0; i<n; i++){
        sum += arr[i];
    }

    //3. find missing elem sum and avg
    int missing_sum = total_sum - sum;
    int avg = missing_sum / 2;

    //4. sum all elem from 1 to avg
    int sum_oneToAvg = 0;
    for(int i=1; i<=avg; i++){
        sum_oneToAvg += i;
    }

    //5. sum elem which are less then avg
    int Sum_LessThen_Avg = 0;
    for(int i=0; i<n; i++){
        if(arr[i] <= avg){
            Sum_LessThen_Avg += arr[i];
        }
    }

    //6. find first and second missing
    int first_Missing = sum_oneToAvg - Sum_LessThen_Avg;
    int second_Missing = missing_sum - first_Missing;

    cout<<"The first missing element is: "<<first_Missing<<endl;
    cout<<"The second missing element is: "<<second_Missing<<endl;
}

int main(){
    vector<int> A = {1, 3, 5, 6};
    usingAddition(A);
    return 0;
}
