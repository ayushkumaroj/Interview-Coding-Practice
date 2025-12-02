#include<iostream>
using namespace std;
#include<queue>
#include<algorithm>


// Time Complexity: O(N log N) because the main operation is sorting the entire list of N numbers.
// Space Complexity: O(1) because we are sorting the list in-place and not using any extra storage that grows with the input size.
int findKthSmallest_Sorting(vector<int>arr, int k){
    // Step 1: Sort the list of numbers from smallest to largest because arranging the numbers in order makes it very easy to
    //  find the k-th smallest one by its position.
    sort(arr.begin(), arr.end());

    // Note: We use k-1 because computer lists (arrays/vectors) start counting from 0. So, the 1st item is at position 0, the
    //  2nd is at position 1, and the k-th item is at position k-1.
    // Step 2: Get the number at the (k-1)th position in the sorted list because this will be the k-th smallest number.
    int kthSmallest = arr[k-1];

    // Step 3: Return the number we found because this is the final answer.
    return kthSmallest;
}

// Time Complexity: O(N log K) because we check each of the N numbers, and for each one, we might add or remove it from the heap,
//  which takes log K time as the heap's size is kept at a maximum of K.
// Space Complexity: O(K) because the heap stores at most K numbers at any given time to keep track of the smallest elements.
int findKthSmallest_MaxHeap(vector<int>arr, int k){
    // Step 1: Get the total number of items in the list because we need to loop through all of them.
    int n = arr.size();

    // Step 2: Create a max-heap (a special list that always keeps the largest item at the top) because this will help us efficiently
    //  keep track of the k smallest numbers we've seen so far.
    priority_queue<int>pq;

    // Step 3: Go through each number in the original list one by one because we need to consider every number to find the correct answer.
    for(int i=0; i<n; i++){
        // Step 4: Add the current number to our max-heap because we want to compare it with the other small numbers we have found.
        pq.push(arr[i]);

        // Step 5: Check if our heap now has more than k numbers because our goal is to only keep the k smallest numbers.
        if(pq.size() > k){
            // Step 6: If the heap is too big, remove the largest number from it (which is always at the top) because if we have more than
            //  k items, the largest one can't be the k-th smallest, so we discard it.
            pq.pop();
        }
    }

    // Step 7: Get the number at the top of the heap because after checking all numbers, the top of the heap is the largest of the k smallest
    //  numbers, which is the k-th smallest number overall.
    int kthSmallest = pq.top();
    // Step 8: Return the number we found because it is our final answer.
    return kthSmallest;
}

int main() {
    vector<int> arr = {7, 10, 4, 3, 20, 15};
    int k = 3;

    // Using brute-force sorting approach
    int kthSmallest1 = findKthSmallest_Sorting(arr, k);
    cout << "Kth smallest element (Sorting): " << kthSmallest1 << endl;

    // Using optimized max-heap approach
    int kthSmallest2 = findKthSmallest_MaxHeap(arr, k);
    cout << "Kth smallest element (Max-Heap): " << kthSmallest2 << endl;

    return 0;
}