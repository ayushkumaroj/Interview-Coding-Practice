#include<iostream>
using namespace std;
#include<vector>

vector<int> runningSumInPlace(vector<int>&nums){
    int n = nums.size();
    for(int i=1; i<n; i++){
        nums[i] = nums[i] + nums[i-1];
    }
    return nums;
}

vector<int> runningSumExtraArray(vector<int>&nums){
    int n = nums.size();
    vector<int>run(n);
    run[0] = nums[0];
    for(int i=1; i<n; i++){
        run[i] = run[i-1] + nums[i];
    }
    return run;
}

int main() {
    vector<int> nums = {1, 2, 3, 4, 5};

    cout << "Original Array: ";
    for (int x : nums) cout << x << " ";
    cout << endl;

    // Approach 1
    vector<int> result1 = runningSumInPlace(nums);
    cout << "Running Sum (In-place): ";
    for (int x : result1) cout << x << " ";
    cout << endl;

    // Reset nums for second approach
    nums = {1, 2, 3, 4, 5};

    // Approach 2
    vector<int> result2 = runningSumExtraArray(nums);
    cout << "Running Sum (Extra Array): ";
    for (int x : result2) cout << x << " ";
    cout << endl;

    return 0;
}