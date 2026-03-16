#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>


// Brute Force : TC: O(n^2) , SC: O(N)
vector<vector<int>>mergeInterval(vector<vector<int>>&mergeInterval){
  int n = mergeInterval.size();
  // Step 1: Create a visited array to mark intervals that are already merged
  vector<bool>visited(n, false);

  // Step 2: Create a result vector to store the merged intervals
  vector<vector<int>>result;

  // Step 3: Start outer loop to pick each interval one by one
  for(int i=0; i<n; i++){
    // If the current interval is already merged, skip it
    if(visited[i] == true){
      continue;
    }
    // Step 4: Take current interval as starting point
    int x1 = mergeInterval[i][0];
    int x2 = mergeInterval[i][1];

    // Step 5: Inner loop to check for overlapping intervals with the current one
    for(int j=i+1; j<n; j++){
      // If the interval is already merged, skip it
      if(visited[j] == true){
        continue;
      }

      // Step 6: Take another interval for comparison
      int y1 = mergeInterval[j][0];
      int y2 = mergeInterval[j][1];

      // Step 7: Check if the two intervals overlap
      // Overlap occurs when start of one <= end of other
      if((x2 >= y1) && (x1 <= y2)){
        // Step 8: Merge intervals by updating x1 and x2
        x1 = min(x1, y1);
        x2 = max(x2, y2);
        visited[j] = true; // Mark this interval as merged
      }
    }
    // Step 9: Mark the current interval as visited
    visited[i] = true;
    // Step 10: Add the merged interval into the result
    result.push_back({x1, x2});
  }
  // Step 11: Return the merged intervals
  return result;
}

//Using Sorting (TC: O(nlogn), SC: O(n))
vector<vector<int>>Optimized(vector<vector<int>>&mergeInterval){
  int n = mergeInterval.size();

  // Step 1: Sort the intervals by their starting times
  // Sorting ensures that if two intervals overlap, they will appear next to each other
  sort(mergeInterval.begin(), mergeInterval.end());

  // Step 2: Create a vector to store the merged intervals
  vector<vector<int>>ans;

  // Step 3: Traverse through all intervals one by one
  for(int i=0; i<n; i++){
    // Step 4: If ans is empty OR current interval does NOT overlap with the last interval in ans
    if(ans.empty() || mergeInterval[i][0] > ans.back()[1]){
      // Step 5: No overlap, so add the current interval as a new entry in ans
      ans.push_back(mergeInterval[i]);
    }else{
      // Step 6: Overlap found, merge the intervals
      // Update the end time of the last interval in ans to the maximum end time
      ans.back()[1] = max(ans.back()[1] , mergeInterval[i][1]);
    }
  }
  // Step 7: Return the merged intervals
  return ans;
}


int main(){
  vector<vector<int>>interval = {{0,2}, {1,5}, {6,10}, {8,9}};

  vector<vector<int>>result = mergeInterval(interval);

  cout<<"Merged Interval: "<<endl;
  for(int i=0; i<result.size(); i++){
    cout<<"["<<result[i][0] <<","<<result[i][1]<<"]";
  }
}