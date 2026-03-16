#include <bits/stdc++.h>
using namespace std;

//Brute force: TC: O(n^3), SC: O(1)
bool hasTripletSumZero(vector<int>& nums) {
    // Step 1: Get the size of the input array
    int n = nums.size();

    // Step 2: Loop through each element and take it as the first number of the triplet
    for (int i = 0; i < n - 2; i++) {
        // Step 3: For each first number, choose the second number (starts from i+1)
        for (int j = i + 1; j < n - 1; j++) {
            // Step 4: For each pair, choose the third number (starts from j+1)
            for (int k = j + 1; k < n; k++) {
                // Step 5: Calculate the sum of the three selected numbers
                int sum = nums[i] + nums[j] + nums[k];

                // Step 6: If the sum equals zero, return true (triplet found)
                if (sum == 0) {
                    return true; 
                }
            }
        }
    }

    // Step 7: If no triplet sums to zero after checking all combinations, return false
    return false;
}

//Using Binary Search, TC: O(n^2logn), SC: O(1)
vector<vector<int>> threeSumBinarySearch(vector<int>& nums) {
    // Step 1: Create a vector to store all triplets that sum to zero
    vector<vector<int>> result;
    int n = nums.size();
    int target = 0; // We are looking for triplets that sum up to 0

    // Step 2: Sort the array
    // Why? Because binary search only works on sorted arrays and sorting also helps skip duplicates
    sort(nums.begin(), nums.end());

    // Step 3: Loop through each element as the first number of the triplet
    for (int i = 0; i < n - 2; i++) {
        // Step 4: Skip duplicate values for i to avoid repeating the same triplet
        if (i > 0 && nums[i] == nums[i - 1]) continue;

        // Step 3: Pick the second element
        for (int j = i + 1; j < n - 1; j++) {
            // Step 6: Skip duplicate values for j to avoid duplicate triplets
            if (j > i + 1 && nums[j] == nums[j - 1]) continue;

            // Step 7: Calculate the value needed for the third number
            int required = target - nums[i] - nums[j];

            // Step 8: Use Binary Search on the remaining part of the array
            int start = j + 1;
            int end = n - 1;
            while (start <= end) {
                // Step 9: Find the middle element
                int mid = start + (end - start) / 2;
                // Step 10: Check if the middle element is the required third number
                if (nums[mid] == required) {
                    // Step 11: If yes, we found a valid triplet, so store it
                    result.push_back({nums[i], nums[j], nums[mid]});
                    // Step 12: Exit binary search for this pair as we only need one triplet
                    break;
                }
                // Step 13: If mid value is smaller than required, move right 
                else if (nums[mid] < required) {
                    start = mid + 1; // Search in the right half
                } 
                // Step 14: If mid value is greater than required, move left
                else {
                    end = mid - 1;   // Search in the left half
                }
            }
        }
    }
    // Step 17: Return all the triplets found
    return result;
}


//Using Two pointer Approch : TC: O(N^2), SC: O(1)
vector<vector<int>> threeSum(vector<int>& nums) {
    // Step 1: Create a vector to store the final triplets
    vector<vector<int>> result;
    // Step 2: Get the size of the input array
    int n = nums.size();

    // Step 3: Sort the array
    // Why? Sorting helps us apply the two-pointer approach and skip duplicates easily
    sort(nums.begin(), nums.end()); 
    int target = 0;

   // Step 4: Loop through each element as the first number of the triplet
    for (int i = 0; i < n - 2; i++) {
        // Step 5: Skip duplicate values for the first number to avoid duplicate triplets
        if (i > 0 && nums[i] == nums[i - 1]) continue; // Skip duplicates for 'i'

        // Step 6: Set up two pointers: one from the next element, one from the end
        int start = i + 1;
        int end = n - 1;

        // Step 7: Move the two pointers toward each other
        while (start < end) {
            // Step 8: Calculate the sum of the three numbers
            int sum = nums[i] + nums[start] + nums[end];
            // Step 9: If the sum is exactly zero, we found a valid triplet
            if (sum == target) {
                // Found a valid triplet
                result.push_back({nums[i], nums[start], nums[end]});

                // Step 10: Skip duplicate values for the second number
                while (start < end && nums[start] == nums[start + 1]) start++;
                // Step 11: Skip duplicate values for the third number
                while (start < end && nums[end] == nums[end - 1]) end--;

                // Step 12: Move both pointers to search for the next unique pair
                start++;
                end--;
            }
            // Step 13: If the sum is less than zero, we need a bigger number, so move the left pointer right
            else if (sum < target) {
                start++; // Increase sum
            }
            // Step 14: If the sum is more than zero, we need a smaller number, so move the right pointer left
            else {
                end--; // Decrease sum
            }
        }
    }
    // Step 15: Return all the valid unique triplets
    return result;
}


int main() {
    // Example input array
    vector<int> nums = {-1, 0, 1, 2, -1, -4};

    // Call the function and store result
    bool result = hasTripletSumZero(nums);

    // Print output based on the result
    if (result) {
        cout << "True - There exists a triplet with sum 0" << endl;
    } else {
        cout << "False - No such triplet found" << endl;
    }

    return 0; // End of program
}
