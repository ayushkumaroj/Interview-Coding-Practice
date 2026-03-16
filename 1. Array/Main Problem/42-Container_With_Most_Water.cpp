#include<iostream>
using namespace std;
#include <iostream>
#include <vector>
#include <algorithm> // for min() and max()
using namespace std;

// TC: O(N^2), SC: O(1)
int maxAreaBruteForce(vector<int>& height) {
    // Step 1: Start with maxWater as 0 because we have not calculated anything yet
    int maxWater = 0;

    // Step 2: Pick the first bar as the left side of the container
    for (int i = 0; i < height.size(); i++) {

        // Step 3: Pick another bar on the right side (after the left one)
        for (int j = i + 1; j < height.size(); j++) {

            // Step 4: Find how wide the container is
            // Width = difference between positions of left and right bars
            int container_width = j - i;

            // Step 5: The water level depends on the shorter bar
            // Because water will overflow from the shorter side
            int container_height = min(height[i], height[j]);

            // Step 6: Calculate how much water this pair of bars can hold
            int curr_water = container_width * container_height;

            // Step 7: If this is the biggest area so far, update maxWater
            maxWater = max(maxWater, curr_water);
        }
    }

    // Step 8: Return the biggest water area we found
    return maxWater;
}

//USing Two Pointer , TC: O(N), SC: O(1)
int maxArea(vector<int>& height) {
    // Step 1: Start with max_Water as 0 because we have not calculated any area yet
    int max_Water = 0;   
    
    // Step 2: Place one pointer at the left end and one at the right end of the array
    int left_line = 0;              
    int right_line = height.size()-1; 

    // Step 3: Keep checking until both pointers meet in the middle
    while (left_line < right_line) {
        // Step 4: Find how wide the container is (distance between the two pointers)
        int container_width = right_line - left_line;

        // Step 5: The height of water depends on the shorter line
        int container_height = min(height[left_line], height[right_line]);

       // Step 6: Calculate how much water this container can hold
        int curr_water = container_width * container_height;

        // Step 7: If this is the largest so far, update max_Water
        max_Water = max(max_Water, curr_water);

        // Step 8: Move the pointer at the shorter line inward
        // Why? Because moving the taller line won’t help increase height,
        // but moving the shorter one might find a taller bar
        if (height[left_line] < height[right_line]) {
            left_line++;  // Move from left side
        } else {
            right_line--;  // Move from right side
        }
    }

    // Step 9: After checking all possible positions, return the maximum water found
    return max_Water;
}


int main() {
    // Example input: heights of vertical lines
    vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};

    // Call the function and store result
    int result = maxArea(height);

    // Output the result
    cout << "Maximum water that can be contained: " << result << endl;

    return 0;
}
