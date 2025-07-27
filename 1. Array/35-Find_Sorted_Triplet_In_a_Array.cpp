#include<iostream>
using namespace std;
#include<vector>

//TC: O(N^3) SC: O(N)
int sorted_Increasing_Triplet(vector<int>arr){
  int n = arr.size();
  int found = 0;

  for(int i=0; i<n; i++){
    for(int j=i+1; j<n; j++){
      // arr[i] must be less than arr[j]
      if(arr[i] < arr[j]){
        for(int k = j+1; k<n; k++){
          // arr[j] must be less than arr[k]
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

  // Stores index of minimum element so far
  int min_index = 0;
  // Index of the 1st element of the triplet
  int low = -1;
  // Index of the 2nd element of the triplet
  int mid = -1;

  for(int i=1; i<n; i++){
    if(arr[i] < arr[min_index]){
      // Found new minimum → update min_index
      min_index = i;
    }
    else if(mid == -1 || arr[i] <= arr[mid]){
      // Found a better mid value → current is greater than min but less than previous mid
      low = min_index;
      mid = i;
    }
    else if(arr[i] > arr[mid]){
      // Found the 3rd element → arr[low] < arr[mid] < arr[i]
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