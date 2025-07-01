#include<iostream>
using namespace std;
#include<vector>

//TC: O(N^3) SC: O(N)
int sorted_Increasing_Triplet(vector<int>arr){
  int n = arr.size();
  int found = 0;

  for(int i=0; i<n; i++){
    for(int j=i+1; j<n; j++){
      if(arr[i] < arr[j]){
        for(int k = j+1; k<n; k++){
          if(arr[j] < arr[k]){
            cout<<"Triplet: ("<<arr[i]<<","<<arr[j]<<","<<arr[k]<<")"<<endl;
            // return true;
          }
        }
      }
    }
  }
  if(found == 0){
    cout<<"No sorted triplet found"<<endl;
  }
}

int sorted_Increasing_Triplet2(vector<int>arr){
  int n = arr.size();
  if(n < 3){
    return false;
  }

  int min_index = 0;
  int low = -1;
  int mid = -1;

  for(int i=1; i<n; i++){
    if(arr[i] < arr[min_index]){
      min_index = i;
    }
    else if(mid == -1 || arr[i] <= arr[mid]){
      low = min_index;
      mid = i;
    }
    else if(arr[i] > arr[mid]){
      //found the increasing triplet
       cout << "Sorted Triplet Found: (" << arr[low] << ", " << arr[mid] << ", " << arr[i] << ")" << endl;
            // return true;
        }
    }
   cout << "No sorted triplet found in the array." << endl;
   return false;
}

int main(){
  vector<int>arr{5,4,3,7,6,1,9};

  int ans = sorted_Increasing_Triplet2(arr);
  cout<<"Is Increasing Triplet Exists: "<<ans;
}