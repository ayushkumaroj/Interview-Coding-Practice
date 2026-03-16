#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

//Brute Force: TC: O(N^2), SC: O(N)
vector<int> findTwoSum(vector<int>& nums, int target) {
    // Step 1: Get the size of the input array
    int n = nums.size();  
    // Step 2: Create a vector to store the two numbers that add up to the target
    vector<int> ans;      

    // Step 3: Loop through each number as the first number in the pair
    for (int i = 0; i < n - 1; i++) {
        // Step 4: For each first number, loop through the remaining numbers to find a matching second number
        for (int j = i + 1; j < n; j++) {
            // Step 5: Check if the sum of the two selected numbers equals the target
            if (nums[i] + nums[j] == target) {
                // Step 6: If yes, store both numbers in the result vector
                ans.push_back(nums[i]); 
                ans.push_back(nums[j]); 
                // Step 7: Exit the inner loop since we found a valid pair
                break;                  
            }
        }
    }
    // Step 8: Return the pair of numbers found
    return ans;
}

// USing Binary Search ,TC: O(nlogn) (for loop(n) + binary search(logn)), SC: O(1)
void UsingBinarySearch(vector<int>& nums, int target) {
    // Step 1: Get the size of the input array
    int n = nums.size();
    // Step 2: Sort the array so that binary search can work
    sort(nums.begin(), nums.end()); 

    // Step 3: Loop through each element to treat it as the first number
    for (int i = 0; i < n - 1; i++) {
        // Step 4: Take the current number as the first number
        int x = nums[i];   
        // Step 5: Calculate the number we need to reach the target     
        int y = target - x; 
        // Step 6: Set up binary search for the remaining part of the array   
        int start = i + 1;
        int end = n - 1;

       // Step 7: Perform binary search to find the second number
        while (start <= end) {
            // Step 8: Find the middle index
            int mid = start + (end - start) / 2;

            // Step 9: If we found the second number
            if (nums[mid] == y) {
                // Found the pair → print and return
                cout << "The two numbers that sum to " << target << " are: " << x << " and " << nums[mid] << endl;
                break; // Exit the inner loop after finding a pair
            } 
            // Step 10: If the middle value is smaller than what we need, search on the right side
            else if (nums[mid] < y) {
                start = mid + 1; // Search right
            }
            // Step 11: If the middle value is bigger than what we need, search on the left side
            else {
                end = mid - 1; // Search left
            }
        }
    }

    // Step 12: If no pair is found after checking all elements
    cout << "No pair found that adds up to " << target << endl;
}



//Uisng two pointer 
//TC: O(nlogn) (sorting-O(nlogn)+two-pointer: O(n))
void UsingTwoPointer(vector<int>& nums, int target) {
    // Step 1: Get the size of the array
    int n = nums.size();

    // Step 2: Create a vector of pairs to store each number along with its original index
    // Why? Because sorting will change the order, and we need the original indices for the answer
    vector<pair<int, int>> arr;
    for (int i = 0; i < n; i++) {
        arr.push_back({nums[i], i}); // {value, index}
    }

    // Step 3: Sort the vector of pairs by the value
    // Why? Because the two-pointer technique works only on sorted values
    sort(arr.begin(), arr.end());

    // Step 4: Place two pointers: one at the start and one at the end
    int left = 0, right = n - 1;

    // Step 5: Move the pointers until they meet
    while (left < right) {
        // Step 6: Calculate the sum of the two current numbers
        int sum = arr[left].first + arr[right].first;

        // Step 7: If the sum equals the target, print their original indices and return
        if (sum == target) {
            cout << "Indices: " << arr[left].second << " and " << arr[right].second << endl;
            return; // Exit after finding the pair
        }
        // Step 8: If the sum is less than the target, move the left pointer to the right to increase the sum
        else if (sum < target) {
            left++; 
        }
        // Step 9: If the sum is greater than the target, move the right pointer to the left to decrease the sum
        else {
            right--; 
        }
    }

    // Step 10: If no pair was found, print a message
    cout << "No pair found that adds up to " << target << endl;
}


int main() {
    // Example input
    vector<int> nums = {2, 7, 11, 15}; // Our array of numbers
    int target = 9; // The sum we are looking for

    // Call the function
    vector<int> result = findTwoSum(nums, target);

    // Print the result
    if (!result.empty()) {
        cout << "The two numbers that sum to " << target << " are: ";
        for (int num : result) {
            cout << num << " ";
        }
        cout << endl;
    } else {
        cout << "No pair found that adds up to " << target << endl;
    }

    return 0; // End of program
}
