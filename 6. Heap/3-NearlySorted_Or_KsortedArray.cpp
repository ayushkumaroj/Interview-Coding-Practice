#include<iostream>
using namespace std;
#include<vector>
#include<queue>



// Time Complexity: O(n * log(k)) because we go through all 'n' numbers, and for each one, we do an operation on the priority queue (heap)
//  which takes log(k) time as its size is at most k+1.
// Space Complexity: O(n) because we use an extra answer array of size 'n' to store the result and a priority queue of size 'k'.
vector<int> nearlySortedArray_ExtraArray(vector<int>&arr, int k){
    // Step 1: Get the total number of elements in the input array because we need to know how many times to loop.
    int n = arr.size();
    // Step 2: Create a min-priority queue (a type of min-heap) because it automatically keeps the smallest number at the top, which makes it easy to find.
    priority_queue<int, vector<int>, greater<int>>pq;
    // Step 3: Create a new empty vector (array) called 'ans' because we need a place to store the final sorted numbers.
    vector<int>ans;
    // Step 4: Start a loop to go through each number in the input array one by one because we have to process every number to sort them.
    for(int i=0; i<n; i++){
        // Step 5: Add the current number from the input array into the priority queue because we want the queue to organize it with the other numbers.
        pq.push(arr[i]);

        // Step 6: Check if the number of items in the priority queue is more than 'k' because if it is, the smallest element in the current group
        //  of numbers is ready to be placed in the sorted list.
        if(pq.size() > k){
            // Step 7: Take the smallest number from the top of the queue and add it to our answer array because it's the next number in the correct sorted order.
            ans.push_back(pq.top());
            // Step 8: Remove the smallest number from the queue because we have already used it and don't need it anymore.
            pq.pop();
        }
    }
    // Step 9: Start a loop that runs as long as the priority queue is not empty because there are still some numbers left in the queue that need
    //  to be added to our answer array.
    while(pq.size() > 0){
        // Step 10: Take the smallest remaining number from the top of the queue and add it to our answer array because these are the final numbers
        //  in the sorted sequence.
        ans.push_back(pq.top());
        // Step 11: Remove that number from the queue because we've now placed it in the answer array.
        pq.pop();
    }
    // Step 12: Return the 'ans' array because it now contains all the numbers from the original array in sorted order.
    return ans;
}


// Time Complexi[ty: O(n * log(k)) because we process all 'n' elements, and each operation on the priority queue of size 'k' takes log(k) time.
// Space Complexity: O(k) because the only extra space we use is for the priority queue, which holds at most k+1 elements.
void nearlySortedArray_InPlace(vector<int>&arr, int k){
    // Step 1: Get the total number of elements in the array because we need this to control our main loop.
    int n = arr.size();
    // Step 2: Create a min-priority queue because it's an efficient way to always know the smallest number among a group of elements.
    priority_queue<int, vector<int>, greater<int>>pq;
    // Step 3: Create an index variable 'idx' and set it to 0 because we need to keep track of where to place the next sorted number in the original array.
    int idx = 0;

    // Step 4: Start a loop to iterate through every number in the array because we need to examine each one to sort the whole array.
    for(int i=0; i<n; i++){
        // Step 5: Add the current number to the priority queue because the queue will arrange it and keep the smallest at the top.
        pq.push(arr[i]);

        // Step 6: Check if the priority queue's size has become bigger than 'k' because this tells us that the smallest element in the current window
        //  is at the top and ready to be placed.
        if(pq.size() > k){
            // Step 7: Take the smallest number from the queue and put it back into the original array at the position 'idx' because this is its correct sorted spot.
            arr[idx] = pq.top();
            // Step 8: Increase 'idx' by 1 because we want to place the next sorted number in the next position in the array.
            idx++;
            // Step 9: Remove the smallest number from the queue because we have already placed it correctly in the array.
            pq.pop();
        }
    }
    // Step 10: Start a new loop to handle any numbers still left in the queue because the main loop has finished, but the largest numbers are still in the queue.
    while(pq.size()> 0){
        // Step 11: Take the next smallest number from the queue and place it in the array at the current 'idx' because these are the remaining elements to be sorted.
        arr[idx] = pq.top();
        // Step 12: Move the index 'idx' forward because the next remaining number should go into the next spot.
        idx++;
        // Step 13: Remove the number from the queue because it is now in its final sorted position in the array.
        pq.pop();
    }
}



int main() {
    // Example input: nearly sorted array
    vector<int> arr = {6, 5, 3, 2, 8, 10, 9};
    int k = 3;

    cout << "Original nearly sorted array: ";
    for (int num : arr) cout << num << " ";
    cout << endl;

    // Approach 1: Using Extra Array
    vector<int> result = nearlySortedArray_ExtraArray(arr, k);
    cout << "Sorted using Extra Array approach: ";
    for (int num : result) cout << num << " ";
    cout << endl;

    // Approach 2: In-place sorting
    vector<int> arr2 = {6, 5, 3, 2, 8, 10, 9}; // fresh copy of array
    nearlySortedArray_InPlace(arr2, k);
    cout << "Sorted using In-Place approach: ";
    for (int num : arr2) cout << num << " ";
    cout << endl;

    return 0;
}