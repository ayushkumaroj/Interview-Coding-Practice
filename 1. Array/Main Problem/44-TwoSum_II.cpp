#include <iostream>
#include <vector>
using namespace std;

//Using Two pointer : TC: O(n), SC: O(1)
vector<int> twoSum(vector<int>& numbers, int target) {\
    // Step 1: Create a vector to store the result indices
    vector<int> ans;
    // Step 2: Set up two pointers: one at the start and one at the end
    int start = 0; 
    int end = numbers.size() - 1;

    // Step 3: Move the pointers until they meet
    while (start < end) {
        // Step 4: Calculate the sum of the numbers at the two pointers
        int sum = numbers[start] + numbers[end]; // Calculate sum of two elements
        // Step 5: If the sum equals the target, we found the answer
        if (sum == target) {
            ans.push_back(start + 1); // Convert to 1-based index
            ans.push_back(end + 1); // Return the result immediately
            return ans;
        }
        //Step 6: If the sum is smaller than the target, move the start pointer to the right
        // Why? Moving right increases the sum because the array is sorted
        else if (sum < target) {
            start++;
        }
        // Step 7: If the sum is bigger than the target, move the end pointer to the left
        // Why? Moving left decreases the sum because the array is sorted
        else {
            // If sum is greater than target, move end to the left to decrease sum
            end--;
        }
    }

    // Step 8: If no pair is found, return {-1, -1} as an indicator
    return {-1, -1};
}

int main() {
    int n, target;

    // Input size of array
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> numbers(n);
    // Input array elements (must be sorted)
    cout << "Enter " << n << " sorted numbers: ";
    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
    }

    // Input target sum
    cout << "Enter target: ";
    cin >> target;

    // Call the twoSum function
    vector<int> result = twoSum(numbers, target);

    // Output the result
    if (result[0] == -1) {
        cout << "No pair found with given target.\n";
    } else {
        cout << "Indices (1-based): " << result[0] << " " << result[1] << endl;
    }

    return 0;
}
