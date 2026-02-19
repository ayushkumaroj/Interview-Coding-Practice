#include<iostream>
using namespace std;
#include<vector>

void Bubble_Sort(vector<int>arr){
    int size = arr.size();

    for(int pass = 0; pass<size-1; pass++){
        int isAnySwapDone = false;

        for(int i=0; i<size-pass-1; i++){
            if(arr[i] > arr[i+1]){
                swap(arr[i], arr[i+1]);
                isAnySwapDone = true;
            }
        }

        if(isAnySwapDone == false){
            break;
        }
    }

    for(int i=0; i<size; i++){
        cout<<arr[i]<<" ";
    }
}

int main(){
    vector<int>arr = {12, 70, 23, 56, 1, 19};

    Bubble_Sort(arr);
}