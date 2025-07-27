#include<iostream>
#include<vector>
using namespace std;

//Uisng Shifting (TC: O(N^2), SC: O(N))
int Using_Shifting(vector<int>nums, vector<int>index){
  vector<int>target;

  for(int i=0; i<nums.size(); i++){
    //Extract insert position and value
    int insert_pos = index[i];
    int value = nums[i];

    //make space for the new element 
    target.push_back(0);

    //Shift all elem to right from insert_pos
    for(int j=target.size()-1; j>insert_pos; j--){
      target[j] = target[j-1];
    }

    //Insert the value at correct position
    target[insert_pos] = value;
  }

  // print the target array
  for(int i=0; i<target.size(); i++){
    cout<<target[i] <<" ";
  }
}

 
//Using Inbuilt Function (TC: O(N^2), SC: O(N)
int Create_Target_Array(vector<int>nums, vector<int>index){
  vector<int>target;
  int size = nums.size();
  //we have to insert element into target array based on index and nums

  for(int i=0; i<size; i++){
    // Inserts nums[i] at position index[i] in the target vector
     target.insert(target.begin() + index[i], nums[i]);
  }

  //print the targte array
  for(int i=0; i<target.size(); i++){
    cout<<target[i]<<" ";
  }
}

int main(){
  vector<int>nums{0,1,2,3,4};
  vector<int>index{0,1,2,2,1};

  Using_Shifting(nums, index);
}