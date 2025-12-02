#include<iostream>
using namespace std;
#include<vector>
#include<unordered_map>[]
#include<queue>

// Overall Time Complexity: O(N log K), where N is the number of elements in the input vector and K is the number of unique elements.
// This is because we iterate through N elements to count frequencies, then push K unique elements into a priority queue, which takes log K time for each push.
// Overall Space Complexity: O(N), because in the worst case, the map, priority queue, and the final answer vector might store all N elements if they are unique.
vector<int> frequencySort(vector<int>& nums) {
    // Step 1: Create a map to hold numbers and how many times they appear because a map is very fast for counting unique items.
    unordered_map<int, int> mp;

    // Step 2: Go through each number ('ele') in the input list 'nums' because we need to count every single number.
    for (int ele : nums) {
        // Step 3: Increase the count for the current number in our map because this is how we keep track of how many times we've seen each number.
        mp[ele]++;
    }

    // Step 4: Create a short name 'pi' for a pair of two integers because it makes the code easier to write and read later on.
    typedef pair<int, int> pi;

    // ---
    // Note on Concept: The 'Compare' class below is a custom comparator.
    // A standard C++ priority queue is a "max-heap," which always puts the largest item at the top.
    // We are giving it our own set of rules to change this behavior. Our rules will make it put items with the lowest frequency at the top,
    // and if two items have the same frequency, it will put the one with the larger value at the top.
    // ---
    
    // Step 5: Create a special set of rules called 'Compare' for sorting because the priority queue needs to know how to order the elements correctly.
    class Compare {
    public:
        // Step 6: This is the main rule function that compares two pairs, 'a' and 'b', because this function decides which pair should have lower priority.
        bool operator()(pi a, pi b) {
            // Step 7: Check if the frequency of 'a' (a.first) is the same as the frequency of 'b' (b.first) because if they are equal, we need a tie-breaking rule.
            if (a.first == b.first) {
                // Step 8: If frequencies are the same, check if the value of 'a' (a.second) is smaller than the value of 'b' (b.second) because this rule 
                // tells the queue to give the smaller value a lower priority, effectively putting the larger value at the top.
                if (a.second < b.second) {
                    return true;
                } else {
                    return false;
                }
            } 
            // Step 9: If the frequency of 'a' is greater than the frequency of 'b', return true because this tells the queue to give the higher frequency
            //  a lower priority, effectively putting the item with the lower frequency at the top.
            else if (a.first > b.first) {
                return true;
            } else {
                return false;
            }
        }
    };

    // Step 10: Create a priority queue named 'pq' using our special sorting rules ('Compare') because it will automatically keep the pairs sorted for us.
    priority_queue<pi, vector<pi>, Compare> pq;

    // Step 11: Go through each pair (the number and its count) in our map because we need to put them all into our sorted queue.
    for (auto x : mp) {
        // Step 12: Get the frequency (the count of the number) from the map pair because we need it for sorting.
        int freq = x.second;
        // Step 13: Get the value (the actual number) from the map pair because this is the number itself.
        int val = x.first;
        // Step 14: Add the pair of {frequency, value} to the priority queue because the queue will automatically place it in the correct sorted position
        //  according to our 'Compare' rules.
        pq.push({freq, val});
    }

    // Step 15: Create an empty list called 'ans' because this is where we will build our final sorted result.
    vector<int> ans;

    // Step 16: Keep doing this loop as long as there are items in the priority queue because we need to process every unique number.
    while (!pq.empty()) {
        // Step 17: Get the frequency from the top item in the queue because this tells us how many times to add the number to our answer.
        int freq = pq.top().first;
        // Step 18: Get the value from the top item in the queue because this is the number we need to add.
        int val = pq.top().second;
        // Step 19: Remove the top item from the queue because we are done with it and need to get to the next one.
        pq.pop();

        // Step 20: Run a loop that repeats 'freq' times because we need to add the number to our answer list exactly that many times.
        for (int i = 0; i < freq; i++) {
            // Step 21: Add the number ('val') to our final answer list because this builds the sorted output piece by piece.
            ans.push_back(val);
        }
    }

    // Step 22: Return the final sorted list because the function's job is now complete.
    return ans;
}

int main() {
// Step 1: Create a vector of numbers (input array)
vector<int> nums = {1, 1, 2, 2, 2, 3};
// Step 2: Call the function and store the result
vector<int> result = frequencySort(nums);

// Step 3: Print the result
cout << "Output: ";
for (int ele : result) {
    cout << ele << " ";
}
cout << endl;

return 0;
}
