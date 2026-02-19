#include<iostream>
using namespace std;
#include<vector>

void Insertion_Sort(vector<int>arr){
    int n = arr.size();

    for(int pos=1; pos<n; pos++){
        int elemToInsert = arr[pos];
        int j = pos-1;

        while(j >= 0){
            if(arr[j] > elemToInsert){
                arr[j+1] = arr[j];
                j--;
            }
            else{
                break;
            }
        }
        arr[j+1] = elemToInsert;
    }

    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
}

int main(){
    vector<int>arr = {12, 89,45, 2, 7, 45};

    Insertion_Sort(arr);
}