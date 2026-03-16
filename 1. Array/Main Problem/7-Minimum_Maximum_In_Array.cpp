#include<iostream>
using namespace std;
#include<limits.h>

int MaximumElem(int arr[], int size){
  //Initialize maxi with INT_MIN (smallest integer possible)
  int maxi = INT_MIN;

  //Run a loop for every element
  for(int i=0; i<size-1; i++){
    //if current element is greater then maxi
    if(arr[i] > maxi){
      //then update the maxi with current element
      maxi = arr[i];
    }
  }
  //finally return the maxi
  return maxi;
}

int MinimumElem(int arr[], int size){
  //declare mini variable with INT_MAX (Largets integer possible)
  int mini = INT_MAX;

  //Run a loop on element
  for(int i=0; i<size-1; i++){
    //If current element is smaller then mini
    if(arr[i] < mini){
      //then update the mini
      mini = arr[i];
    }
  }
  //finally return the mini
  return mini;
}

int main(){
  //create array and cal size
  int arr[] = {3,1,2,5,4};
  int size = 5;

  //print the Max element
  int MaxElement = MaximumElem(arr, size);
  cout<<"The maximu element is: "<<MaxElement<<endl;

  //Print the Min Element
  int MinElement = MinimumElem(arr, size);
  cout<<"The minimu element is: "<<MinElement<<endl;

  return 0;
}