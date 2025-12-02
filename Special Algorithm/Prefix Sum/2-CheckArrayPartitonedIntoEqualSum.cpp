#include<iostream>
using namespace std;
#include<vector>

int equilibriumIndexPrefixSumInPlace(vector<int>arr){
    int n = arr.size();

    for(int i=1; i<n; i++){
        arr[i] = arr[i] + arr[i-1];
    }

    int idx = -1;
    for(int i=1; i<n; i++){
        if(2*arr[i] == arr[n-1]){
            idx = i;
            break;
        }
    }

    if(idx != -1){
        return idx;
    }
    else{
        return -1;
    }
}

// Main function to test
int main() {
    vector<int> arr = {2, 3, 5, 1, 6, 2, 2};

    int idx = equilibriumIndexPrefixSumInPlace(arr);

    if (idx != -1)
        cout << "Equilibrium index found at position: " << idx << endl;
    else
        cout << "No Equilibrium index found" << endl;

    return 0;
}