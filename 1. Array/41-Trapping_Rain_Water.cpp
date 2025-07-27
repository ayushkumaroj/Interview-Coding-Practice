#include<iostream>
using namespace std;
#include<vector>

// Brute Force: TC: O(N^2), SC: O(1)
void trapBruteForce(vector<int>height){
  int n = height.size(); // Step 1: Get number of bars
  int trappedWater = 0; // Step 2: Initialize total trapped water to 0

  // Step 3: Loop through each bar to calculate trapped water at that position
  for(int i=0; i<n; i++){

    // Step 4: Find tallest bar on the left of current bar (including itself)
    int leftMax = 0;
    for(int j=0; j<=i; j++){
      leftMax = max(leftMax, height[j]);
    }

    // Step 5: Find tallest bar on the right of current bar (including itself)
    int rightMax = 0;
    for(int j = i; j<n; j++){
      rightMax = max(rightMax, height[j]);
    }

    // Step 6: Water trapped = min(leftMax, rightMax) - current height
    int minHeight = min(leftMax, rightMax);
    trappedWater = trappedWater + (minHeight - height[i]);
  }

  //Print the answer 
  cout<<"The water trapped: "<<" "<<trappedWater<<endl;
}

// Using Extra space (TC: O(N), SC: O(N))
void BetterApprochTrap(vector<int>&height){
  // Step 1: Get the total number of bars in the given height array
  int n = height.size();
  // Step 2: Create two arrays to store the maximum height on the left and right side for each bar
  // Why? These help us quickly check the tallest barrier on both sides of a bar to know how much water it can hold.
  vector<int>Leftmax_Support(n);
  vector<int>RightMax_Support(n);

  // Calculate the Leftmax support for each bar 
  // Step 3: Initialize the first position of Leftmax_Support to 0 because there is no bar to the left of the first bar
  Leftmax_Support[0] = 0;
  // Step 4: Loop from the second bar (index 1) to the last bar
  for(int i=1; i<n; i++){
    // Step 5: For each bar, store the maximum height seen so far on its left side
    // This is the maximum between the previous Leftmax_Support and the previous bar's height
    Leftmax_Support[i] = max(Leftmax_Support[i-1], height[i-1]);
  }

  // Calculate the Rightmax support for each bar 
  // Step 6: Initialize the last position of RightMax_Support to 0 because there is no bar to the right of the last bar
  RightMax_Support[n-1] = 0;
  // Step 7: Loop from the second-last bar (index n-2) to the first bar
 for(int i=n-2; i>=0; i--){
  // Step 8: For each bar, store the maximum height seen so far on its right side
  // This is the maximum between the next RightMax_Support and the next bar's height
  RightMax_Support[i] = max(RightMax_Support[i+1], height[i+1]);
 }

 // Step 9: Initialize trappedWater to 0 to keep track of the total water trapped
 int trappedWater = 0;
 // Step 10: Loop through each bar to calculate the trapped water
 for(int i=0; i<n; i++){
  // Step 11: Find the smaller barrier between the left and right sides of the current bar
  int min_height = min(Leftmax_Support[i], RightMax_Support[i]);
  // Step 12: If the smaller barrier is higher than the current bar, water can be trapped
  if(min_height > height[i]){
    // Step 13: Add the water trapped at this position (difference between min_height and current bar height)
    trappedWater = trappedWater + (min_height - height[i]);
  }
 }
 // Step 14: Print the total amount of water trapped
 cout<<"The water trapped: "<<" "<<trappedWater<<endl;
}


//Using Peak split method = TC: O(n) (Single pass to find max + two passes for left and right parts), SC: O(1)
void BestAprochPeakSplit(vector<int>&height){
  // Step 1: Get the total number of bars in the given height array
  int n = height.size();

  // Step 2: Initialize variables to keep track of max heights seen so far and total water trapped
  int maxLeft_Support = 0; // Tracks the tallest bar encountered so far from the left
  int maxRight_Support = 0; // Tracks the tallest bar encountered so far from the right
  int waterStored = 0; // Stores the total trapped water

  //Step 3: Find the tallest bar in the array
  // Initialize the tallest bar's height and its index
  int maxHeight = height[0];
  int Max_index = 0; 
  
  // Step 4: Traverse the array to find the tallest bar (the peak)
  for(int i=0; i<n; i++){
    if(height[i] > maxHeight){
      maxHeight = height[i];
      Max_index = i;
    }
  }

  //Step 5: Calculate trapped water on the LEFT side of tallest bar
  // Traverse from the start (index 0) to the tallest bar's index
  for(int i=0; i<Max_index; i++){
    // Step 6: If the current bar is shorter than the tallest bar seen so far from the left,
    if(maxLeft_Support > height[i]){
      // then water can be trapped above this bar
      waterStored = waterStored + (maxLeft_Support - height[i]);
    }
    else{
      // Step 7: If the current bar is taller, update maxLeft_Support
      maxLeft_Support = height[i];
    }
  }

  //Step 8: Calculate trapped water on the RIGHT side of tallest bar
  //Traverse from the end (index n-1) to the tallest bar's index
  for(int i=n-1; i>Max_index; i--){
    // Step 9: If the current bar is shorter than the tallest bar seen so far from the right,
    if(maxRight_Support > height[i]){
      // then water can be trapped above this bar
      waterStored = waterStored + (maxRight_Support - height[i]);
    }
    else{
     // Step 10: If the current bar is taller, update maxRight_Support
     maxRight_Support = height[i];
    }
  }
  
 cout<<"The water trapped: "<<" "<<waterStored<<endl;
}

int main(){
  vector<int>height = {5,4,3,2,1};

  BestAprochPeakSplit(height);
}