#include<iostream>
using namespace std;
#include<vector>

vector<int> reverse(vector<int> arr){
  // declare start and end pointers
  int start = 0;
  int end = arr.size() - 1; // Fix the end pointer
  // run a loop until start index becomes less than end index
  while(start < end){
    // swap start & end
    swap(arr[start], arr[end]);
    start++;
    end--;
  }
  return arr;
}

int main(){
  // create an array
  vector<int> arr{1, 2, 3, 4, 5};
  
  // call reverse function
  vector<int> result = reverse(arr);

  // print the reverse array
  cout << "The reverse array is: ";
  for(int i = 0; i < result.size(); i++){
    cout << result[i] << " ";
  }
}
