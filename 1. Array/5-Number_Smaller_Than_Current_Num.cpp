// ------------------------------------------------------------------
// 🔍 Problem Title: [Your Problem Name Here]
// 📌 Problem Statement:
//     Brief explanation of the problem.
//     Input: ...
//     Output: ...
// ------------------------------------------------------------------

#include<iostream>
using namespace std;
#include<vector>

// ------------------------------------------------------------------
// ✅ Approach 1: Brute Force
// ------------------------------------------------------------------
/*
🔸 Idea:
    - Explain the core logic or steps.
🔸 Time Complexity: ...
🔸 Space Complexity: ...
*/
vector<int> usingLoop(vector<int>arr){
  vector<int>result;
  for(int i=0; i<arr.size(); i++){
    int count = 0;
    for(int j= 0; j<arr.size(); j++){
      if(arr[j] < arr[i]){
        count++;
        
      }
    }
    result.push_back(count);
  }
  return result;
}

// ------------------------------------------------------------------
// ✅ Approach 1: Using Hash Map
// ------------------------------------------------------------------
/*
🔸 Idea:
    - Explain the core logic or steps.
🔸 Time Complexity: ...
🔸 Space Complexity: ...
*/

vector<int> usingMap(vector<int>arr){
  
}



// ------------------------------------------------------------------
// 🔁 Main Function – Test All Approaches
// ------------------------------------------------------------------

int main() {
  vector<int>arr{8,1,2,2,3};

  cout<<"Number of element smaller then current is: "<<endl;
  vector<int>ans = usingLoop(arr);
  for(int i=0; i<ans.size(); i++){
    cout<<ans[i]<<" ";
  }
   

  return 0;
}
