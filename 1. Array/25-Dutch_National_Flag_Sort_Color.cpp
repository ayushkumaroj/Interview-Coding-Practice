#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

//Note: In header include #include<algorithm>
//TC: O(NlogN), SC: O(nlogn)
int Sort_Color(vector<int>arr){
  sort(arr.begin(), arr.end());

  for(int i=0; i<arr.size(); i++){
    cout<<arr[i]<<" ";
  }
}

int usingCounting(vector<int>arr){
  int countZero = 0;
  int countOne = 0;
  int countTwo = 0;

  for(int i=0; i<arr.size(); i++){
    if(arr[i] == 0){
      countZero++;
    }
    else if(arr[i] == 1){
      countOne++;
    }
    else if(arr[i] == 2){
      countTwo++;
    }
  }

  while(countZero == 0){
    countZero--;
  }
  while(countOne == 0){
    countOne--;
  }
  while(countTwo == 0){
    countTwo--;
  }
  
  //print the array
  for(int i=0; i<arr.size(); i++){
    cout<<arr[i]<<" ";
  }
}

//Using Three Pointer (TC: O(N), SC: O(N))
void usingTwoPointer(vector<int>& arr) {
    int low = 0,
    mid = 0, 
    high = arr.size() - 1;

    while (mid <= high) {
        if (arr[mid] == 0) {
            swap(arr[low], arr[mid]);
            low++;
            mid++;
        }
        else if (arr[mid] == 1) {
            mid++;
        }
        else { // arr[mid] == 2
            swap(arr[mid], arr[high]);
            high--;
        }
    }
}

int main(){
  vector<int>arr{0,1,0,1,2,1,2,1};
  Sort_Color(arr);

  usingTwoPointer(arr);
}