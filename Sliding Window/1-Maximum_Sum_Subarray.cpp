#include <bits/stdc++.h>
using namespace std;

long long maximumSubarraySum(vector<int>& nums, int k) {
    // Step 1: I check how many numbers are in the array because I need to know if size k window is possible
    int n = nums.size();

    // Step 2: If the array has less than k elements, I return 0 because a window of size k cannot be made
    if (n < k){
        return 0;
    } 

    // Step 3: I create windowSum to store the sum of current window so I don't calculate sum again and again
    long long windowSum = 0;
    // Step 4: I create maxSum to store the biggest valid sum because this is what I want to return
    long long maxSum = 0;

    // Step 5: I create a map to count elements in the window so I can check if all elements are different
    unordered_map<int, int> freqMap;

    // Step 6: I build the first window of size k because sliding window always starts from the first k elements
    for (int i = 0; i < k; i++) {
        // Step 6.1: I add the current number to windowSum because it is inside the window
        windowSum += nums[i];
        // Step 6.2: I increase its count because this number appears one more time in the window
        freqMap[nums[i]]++;
    }

    // Step 7: I check if the first window has k different numbers because only then it is a valid window
    if (freqMap.size() == k) {
        // Step 7.1: I store this sum as maxSum because this is the first valid window
        maxSum = windowSum;
    }

    // Step 8: Now I slide the window to the right so that I can check all subarrays of size k
    for (int right = k; right < n; right++) {
        // Step 9: I find the number that is going out of the window because window size must stay k
        int removeVal = nums[right - k];
        // Step 10: I subtract this number from windowSum because it is no longer in the window
        windowSum -= removeVal;
        // Step 11: I reduce its count because one occurrence is removed from the window
        freqMap[removeVal]--;
        // Step 12: If its count becomes zero, I remove it from the map because it is not in the window anymore
        if (freqMap[removeVal] == 0) {
            freqMap.erase(removeVal);
        }

        // Step 13: I take the new number that is entering the window from the right
        int addVal = nums[right];
        // Step 14: I add this new number to windowSum because it is now part of the window
        windowSum += addVal;
        // Step 15: I increase its count because this number is added to the window
        freqMap[addVal]++;

        // Step 16: I check again if the window has k different numbers because only then it is valid
        if (freqMap.size() == k) {
            // Step 17: I update maxSum if the current windowSum is bigger than the previous maxSum
            maxSum = max(maxSum, windowSum);
        }
    }

    // Step 18: After checking all windows, I return the maximum valid sum I found
    return maxSum;
}

int main() {
    vector<int> nums = {1, 5, 4, 2, 9, 9, 9};
    int k = 3;

    cout << "Maximum sum of distinct subarray of size "
         << k << " is: "
         << maximumSubarraySum(nums, k) << endl;

    return 0;
}
