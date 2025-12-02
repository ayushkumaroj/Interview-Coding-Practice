#include<iostream>
using namespace std;
#include<vector>
#include<queue>
#include<algorithm>

// Overall Time Complexity: O(N log N) where N is the number of stones.
// Overall Space Complexity: O(N) because the priority queue will store all N stones.
int lastStoneWeight(vector<int>& stones) {
    // Step 1: Create a priority queue 'pq' because we need a way to always get the two heaviest stones easily.
    priority_queue<int>pq;
    // Note: By default, a priority_queue in C++ is a 'max-heap', which keeps the *largest* number at the top.

    // Step 2: Go through each stone ('ele') in the input list 'stones'.
    for(int ele : stones){
        // Step 3: Add the current stone's weight to the priority queue because the queue will automatically sort it to keep the heaviest ones at the top.
        pq.push(ele);
    }

    // Step 4: Keep looping as long as there is more than one stone in the queue because we need to smash stones together until only one (or zero) is left.
    while(pq.size()>1){
        // Step 5: Get the heaviest stone's weight from the top of the queue and store it as 'y' because this is the first stone for the smash.
        int y = pq.top();
        // Step 6: Remove the heaviest stone from the queue because we have taken it out to be smashed.
        pq.pop();
        // Step 7: Get the *new* heaviest stone's weight (which was the second heaviest) and store it as 'x' because this is the second stone for the smash.
        int x = pq.top();
        // Step 8: Remove this stone from the queue because we are also taking it out to be smashed.
        pq.pop();

        // Step 9: Check if the two stones have different weights because if they are the same, they both get destroyed.
        if(y != x){
            // Step 10: Add the leftover piece (weight y-x) back into the queue because this new stone can be smashed in the next loop.
            // Note: We do 'y-x' because we know 'y' was the biggest or equal to 'x' since it came from the max-heap first.
            pq.push(y-x);
        }
        // Step 11: If 'y == x', we do nothing because both stones are destroyed and we don't add anything back to the queue.
    }

    // Step 12: After the loop, check if there is exactly one stone left in the queue.
    if(pq.size() == 1){
        // Step 13: If one stone is left, return its weight because this is the final answer.
        return pq.top();
    }else{
        // Step 14: If the queue is empty (meaning all stones destroyed each other), return 0.
        return 0;
    }
}

// # USING SORTING
// Overall Time Complexity: O(N^2 log N) where N is the number of stones.
// Overall Space Complexity: O(log N) because 'std::sort' can use O(log N) stack space for recursion.
int lastStoneWeightSort(vector<int>& stones) {
    // Step 1: Keep looping as long as there is more than one stone in our list because we need to smash stones together until only one (or zero) is left.
    while(stones.size() > 1){
        // Step 2: Sort the entire list from smallest to largest because this is how we find the two heaviest stones, which will be at the very end.
        sort(stones.begin(), stones.end());
            
        // Step 3: Get the last stone in the list (the heaviest) and store it as 'y' because this is the first stone for the smash.
        int y = stones[stones.size()-1];
        // Step 4: Remove the last stone from the list because we have taken it out to be smashed.
        stones.pop_back();

        // Step 5: Get the *new* last stone in the list (the second heaviest) and store it as 'x' because this is the second stone for the smash.
        int x = stones[stones.size()-1];
        // Step 6: Remove this stone from the list because we are also taking it out to be smashed.
        stones.pop_back();

        // Step 7: Check if the two stones have different weights because if they are the same, they both get destroyed.
        if(y != x){
            // Step 8: Add the leftover piece (weight y-x) back into the list because this new stone will be part of the next round of smashing.
            // Note: We do 'y-x' because we know 'y' was the biggest or equal to 'x' since we sorted the list first.
            stones.push_back(y-x);
        }
        // Step 9: If 'y == x', we do nothing because both stones are destroyed and we don't add anything back to the list.
    }

    // Step 10: After the loop, check if there is exactly one stone left in the list.
    if(stones.size() == 1){
        // Step 11: If one stone is left, return it (it's at the first position, index 0) because this is the final answer.
        return stones[0];
    }
    // Step 12: If the condition in Step 10 is false, it means the list is empty.
    else{
        // Step 13: Return 0 because no stones are left.
        return 0;
    }
}

int main() {
vector<int>stones = {2, 7, 4, 1, 8, 1};

cout << "Result using priority queue method: " << lastStoneWeight(stones) << endl;

stones = {2, 7, 4, 1, 8, 1};
cout << "Result using sorting method: " << lastStoneWeightSort(stones) << endl;

return 0;

}