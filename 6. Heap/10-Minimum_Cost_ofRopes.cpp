#include<iostream>
using namespace std;
#include<vector>
#include<queue>

// Overall Time Complexity: O(N log N) where N is the number of items in the list.
// Overall Space Complexity: O(N) because the priority queue will store all N items.
int minCost(vector<int>& arr) {
    // Step 1: Get the number of items in the input list 'arr' because we need to know how many items to process.
    int n = arr.size();
        
    // Step 2: Create a variable 'minCost' and set it to 0 because we need a place to add up and store the total cost as we go.
    int minCost = 0;
    
    // Step 3: Create a priority queue 'pq' that holds integers because we need a way to always find the two *smallest* items quickly.
    priority_queue<int, vector<int>, greater<int>>pq;
    // Note: 'greater<int>' is a special rule that makes this a 'min-heap', which keeps the smallest number at the top.
    
    // Step 4: Start a loop that runs from 0 up to (but not including) 'n' because we need to look at every item in the input list 'arr'.
    for(int i=0; i<n; i++){
        // Step 5: Add the item from the list 'arr' at position 'i' into the min-heap because the heap will automatically sort it to keep the smallest ones at the top.
        pq.push(arr[i]);
    }
        
    // Step 6: Keep looping as long as there is more than one item in the queue because we need to combine items until only one is left.
    while(pq.size() > 1){
        // Step 7: Get the smallest item from the top of the queue and store it as 'y' because this is the first item to combine.
        int y = pq.top();
        // Step 8: Remove the smallest item from the queue because we have taken it out to be combined.
        pq.pop();
        // Step 9: Get the *new* smallest item (which was the second smallest) and store it as 'x' because this is the second item to combine.
        int x = pq.top();
        // Step 10: Remove this item from the queue because we are also taking it out to be combined.
        pq.pop();
            
        // Step 11: Add the two items 'y' and 'x' together and put their sum back into the queue because this new sum is now an item that needs to be combined later.
        pq.push(y+x);
        // Step 12: Add this same sum (y+x) to our 'minCost' total because the problem states the cost of combining two items is their sum.
        minCost = minCost + (y+x);
        // Note: Concept: This is a greedy algorithm. By always combining the two smallest available items (ropes/files), we ensure the final cost is the minimum possible.
            
    }
    // Step 13: After the loop is finished and only one item is left in the queue, return the total 'minCost' because this is the final answer.
    return minCost;
}

int main() {
vector<int>arr = {4, 3, 2, 6};
cout << "Minimum cost to connect ropes: " << minCost(arr) << endl;

return 0;
}