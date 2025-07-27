#include<iostream>
using namespace std;

/*
- Doesn't require sorted data
- Useful when array is unsorted and small
- TC: Best Case: O(1) , Worst Case: O(n), Avg Case: O(n)
- SC: O(1)
*/
void Linear_Search(int arr[], int n, int key){
  bool found = false;
  for(int i=0; i<n; i++){
    if(arr[i] == key){
      cout<<"Element found at index: "<<i<<endl;
      found = true;
      break;
    }
  }

  if(!found){
    cout<<"Element not found in the array";
  }
}

int main(){
  int n, key;
  cout<<"Enter number of elements: ";
  cin>>n;

  int arr[n];

  //Input array element
  cout<<"Enter "<<n <<"elements: "<<endl;
  for(int i=0; i<n; i++){
    cin>>arr[i];
  }

  //Input the value to search
  cout<<"Enter the element to search: ";
  cin>>key;

  Linear_Search(arr, n, key);

}