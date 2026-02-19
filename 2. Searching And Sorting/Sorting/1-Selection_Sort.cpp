#include<iostream>
using namespace std;
#include<vector>

void Selection_Sort(vector<int>arr){
    int n = arr.size();

    for(int i=0; i<n-1; i++){
        int minIndex = i;

        for(int j=i+1; j<n; j++){
            if(arr[j] < arr[minIndex]){
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }

    for(int i=0; i<n; i++){
        cout<< arr[i]<<" ";
    }
}

int main(){
    vector<int>arr = {14, 89, 90, 12, 1, 10};

    Selection_Sort(arr);
}