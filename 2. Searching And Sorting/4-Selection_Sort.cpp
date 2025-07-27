#include<iostream>
using namespace std;
#include<vector>

/*
- Selection Sort is a simple comparison-based sorting algorithm that selects the smallest (or largest) element from the unsorted part of the array and places it at the correct(starting) position in each iteration.

- Why outer loop run till n-1 : Selection sort me har step pe ek element apni sahi jagah chala jaata hai. Jab last me sirf 1 element bacha hota hai, to wo already sorted hota hai. Isliye loop ko n-1 tak hi chalate hain. n tak chalane ka koi matlab nahi hota."

- TC: O(N^2) , SC: O(1)
*/
int Selection_Sort(vector<int>arr){
  int size = arr.size();

  //Outer loop represent no of round (size-1)
  for(int i=0; i<size-1; i++){
    int min_Index = i;

    //Inner loop represent range of minimum element from i to n
    for(int j=i+1; j<size; j++){
      if(arr[j] < arr[min_Index]){
        //New minimum then store
        min_Index = j;
      }
    }
    //Swap
    swap(arr[i], arr[min_Index]);
  }

  //Print the sorted array
  for(int i=0; i<size; i++){
    cout<<arr[i] << " ";
  }
}


int main(){
  vector<int>arr{23,89,14,87,90};

  Selection_Sort(arr);
}


