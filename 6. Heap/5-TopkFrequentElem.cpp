#include<iostream>
using namespace std;
#include<queue>
#include<unordered_map>

// Time Complexity: O(n * log(k)) because we first loop through 'n' items to count frequencies, then we loop through the unique items
//  (at most 'n') and for each, we perform a heap operation which takes log(k) time.
// Space Complexity: O(n + k) because the map can store up to 'n' unique numbers, and the priority queue stores 'k' numbers.
vector<int> topKFrequent(vector<int>& nums, int k){
    // Step 1: Get the total number of elements in the input list because we need to know how many times to loop to count frequencies.
    int n = nums.size();

    // Step 2: Create a hash map called 'mp' because we need a fast way to store each unique number and count how many times it appears.
    unordered_map<int,int>mp;
    // Step 3: Start a loop to go through each number in the input list because we have to count every single one.
    for(int i=0; i<n; i++){
        // Step 4: For the current number, find it in the map and increase its count by 1 because this is how we track its frequency.
        mp[nums[i]]++;
    }

    // Step 5: Create a shorter name 'pi' for a pair of integers because it makes the code for the priority queue easier to write and read.
    typedef pair<int,int>pi;
    // Step 6: Create a min-priority queue that stores pairs because this structure will automatically keep the pair with the smallest frequency
    //  at the top, making it easy to remove.
    priority_queue<pi, vector<pi>, greater<pi>>pq;

    // Step 7: Start a loop that  goes through every number-frequency pair in our map because we need to process them to find the top 'k' elements.
    for(auto x: mp){
        // Step 8: Get the element (the number itself) from the map pair because this is the value we ultimately want.
        int ele = x.first;
        // Step 9: Get the frequency (the count) of that number from the map pair because the frequency decides which numbers are more important.
        int freq = x.second;

        // Step 10: Push the {frequency, element} pair into the priority queue because the queue will use the frequency to sort it.
        // Note: We store the frequency first in the pair because the priority queue organizes its contents based on the first item of the pair.
        pq.push({freq, ele});

        // Step 11: Check if the priority queue now has more than 'k' items because we only want to keep track of the 'k' most frequent ones.
        if(pq.size() > k){
            // Step 12: If the size is greater than 'k', remove the top element because it has the lowest frequency among the items currently in
            //  the queue, so it's not part of our top 'k'.
            pq.pop();
        }
    }

    // Step 13: Create a new empty vector 'ans' because we need a list to store our final result.
    vector<int>ans;
    // Step 14: Start a loop that runs as long as the priority queue is not empty because we need to extract all 'k' elements that remain in it.
    while(pq.size() > 0){
        // Step 15: Get the pair at the top of the queue and take its second value (the element) because this is the number we want to add to our answer.
        int ele = pq.top().second;
        // Step 16: Add this element to our answer list because it is one of the top 'k' frequent elements.
        ans.push_back(ele);
        // Step 17: Remove the element from the queue because we have already added it to our answer and need to get the next one.
        pq.pop();
    }

    // Step 18: Return the final answer list because it now contains the 'k' most frequent elements.
    return ans;
}

int main() {
    vector<int> nums = {1, 1, 1, 2, 2, 3};
    int k = 2;

    vector<int> result = topKFrequent(nums, k);

    cout << "Top " << k << " frequent elements: ";
    for (int ele : result) { 
        cout << ele << " ";
    }
    cout << endl;

    return 0;
}