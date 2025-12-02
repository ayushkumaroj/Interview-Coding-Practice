#include<iostream>
#include<vector>
using namespace std;

//Uisng Shifting (TC: O(N^2), SC: O(N))
int Using_Shifting(vector<int>nums, vector<int>index){
  // Step 1: Create an empty target array.
  vector<int>target;

  // Step 2: Iterate over all elements in nums.
  for(int i=0; i<nums.size(); i++){
    // Step 3: Extract the insertion position and the value to insert.
    int insert_pos = index[i];
    int value = nums[i];

    // Step 4: Add a placeholder element at the end to increase the size by 1.
    target.push_back(0);

    // Step 5: Shift elements to the right from the end until insert_pos.
    for(int j=target.size()-1; j>insert_pos; j--){
      target[j] = target[j-1];
    }

    // Step 6: Insert the value at the correct position.
    target[insert_pos] = value;
  }

  // Step 7: Print the final target array.
  for(int i=0; i<target.size(); i++){
    cout<<target[i] <<" ";
  }
}

 
//Using Inbuilt Function (TC: O(N^2), SC: O(N)
int Create_Target_Array(vector<int>nums, vector<int>index){
  // Step 1: Initialize an empty target vector.
  vector<int>target;
  int size = nums.size();
  
  // Step 2: Loop through nums[] and index[] simultaneously.
  for(int i=0; i<size; i++){
     // Step 3: Insert nums[i] into the target vector at position index[i].
     // The STL insert() method shifts elements to the right automatically.
     target.insert(target.begin() + index[i], nums[i]);
  }

  // Step 4: Print the final target array.
  for(int i=0; i<target.size(); i++){
    cout<<target[i]<<" ";
  }
}

int main(){
  vector<int>nums{0,1,2,3,4};
  vector<int>index{0,1,2,2,1};

  Using_Shifting(nums, index);
}