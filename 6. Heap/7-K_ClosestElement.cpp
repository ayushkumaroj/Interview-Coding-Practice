#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
#include<queue>

// Overall Time Complexity: O(N log K + K log K) where N is the total numbers and K is the number of elements to find.
// Overall Space Complexity: O(K) because the priority queue will store at most 'K' elements.
vector<int>findKClosestElement(vector<int>&arr, int k, int x){
    // Step 1: Create a short name 'pi' for a pair of two integers because using 'pi' is shorter and makes the code easier to read.
    typedef pair<int,int>pi;
    // Note: We will use this pair to store {distance, number}.

    // Step 2: Create a priority queue 'pq' that holds pairs because this structure will help us keep track of the 'k' smallest distances.
    priority_queue<pi>pq;
    // Note: This is a 'max-heap' by default. It always keeps the pair with the *largest* first value (the distance) at the very top.

    // Step 3: Go through each number ('ele') in the input list 'arr' one by one.
    for(int ele: arr){
        // Step 4: Find the distance between the target 'x' and the current number 'ele' because this tells us how close the number is.
        int distance = abs(x-ele);
        // Note: 'abs()' is the absolute value formula. It makes sure the distance is always a positive number (e.g., abs(5-10) is 5).
        
        // Step 5: Add the pair {distance, number} to the max-heap because the heap will automatically sort it based on the distance.
        pq.push({distance, ele});
        
        // Step 6: Check if the heap now has more than 'k' items because we only want to keep the 'k' items with the smallest distances.
        if(pq.size() > k){
            // Step 7: If the size is too big, remove the top item because the top item is the one with the *largest* distance, which we don't want.
            pq.pop();
        }
    }
    // Note: After this loop, the 'pq' holds exactly the 'k' elements that are closest to 'x'.

    // Step 8: Create an empty list 'ans' because we need a place to store our final 'k' numbers from the heap.
    vector<int>ans;
    
    // Step 9: Keep looping as long as our priority queue still has items in it.
    while(pq.size() > 0){
        // Step 10: Get the pair at the top of the queue and take its second part (the 'ele') because this is the actual number we want to save.
        int ele = pq.top().second;
        // Step 11: Add this number to our 'ans' list.
        ans.push_back(ele);
        // Step 12: Remove the top item from the queue because we have finished processing it.
        pq.pop();
    }
    // Note: At this point, 'ans' has all 'k' closest numbers, but they are not in sorted order.

    // Step 13: Sort the 'ans' list from the beginning to the end because the problem requires the final answer to be in ascending order.
    sort(ans.begin(), ans.end());
    
    // Step 14: Return the final sorted list of 'k' closest numbers because this is the function's final output.
    return ans;
}

// Main function to test
int main() {
    // Step 1: Create an example input array
    vector<int> arr = {1, 2, 3, 4, 5};

    // Step 2: Define k (number of closest elements) and x (target value)
    int k = 4;
    int x = 3;

    // Step 3: Call the function
    vector<int> result = findKClosestElement(arr, k, x);

    // Step 4: Display the result
    cout << "The " << k << " closest elements to " << x << " are: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    // Step 5: Run another test case for verification
    vector<int> arr2 = {10, 15, 7, 3, 4};
    int k2 = 2;
    int x2 = 8;

    vector<int> result2 = findKClosestElement(arr2, k2, x2);

    // Step 6: Print the second test result
    cout << "The " << k2 << " closest elements to " << x2 << " are: ";
    for (int num : result2) {
        cout << num << " ";
    }
    cout << endl;

    // Step 7: Optional validation message
    if (!result.empty() && !result2.empty()) {
        cout << "Both test cases executed successfully!" << endl;
    } else {
        cout << "Something went wrong with the test cases." << endl;
    }

    // Step 8: Return 0 to indicate successful execution
    return 0;
}