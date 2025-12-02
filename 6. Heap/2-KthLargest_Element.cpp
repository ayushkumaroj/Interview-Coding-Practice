#include<iostream>
using namespace std;
#include<algorithm>
#include<queue>


// Time Complexity: O(N log N) because the most time-consuming part is sorting the list of N numbers.
// Space Complexity: O(1) because the list is sorted in-place, using no extra memory that depends on the input size.
int findKthLargest_Sorting(vector<int>arr, int k){
    // Step 1: Get the total count of numbers in the list because we need this to calculate the index from the end of the list.
    int n = arr.size();
    // Step 2: Sort the list of numbers from the smallest to the largest because this arrangement allows us to find the largest elements at the end of the list.
    sort(arr.begin(), arr.end());

    // Note: The formula to find the k-th largest element's index is (n - k). For example, in a list of 10 items (n=10), the 1st 
    // largest (k=1) is at index 10-1=9. The 2nd largest (k=2) is at index 10-2=8.
    // Step 3: Get the number at the (n-k)th position in the sorted list because this will be the k-th largest number.
    int kthLargest = arr[n-k];

    // Step 4: Return the number we found because this is the function's final answer.
    return kthLargest;
}

// Time Complexity: O(N log K) because we iterate through N numbers, and each heap operation (push or pop) takes log K time since
//  the heap's size is limited to K.
// Space Complexity: O(K) because the min-heap will store a maximum of K numbers at any point.
int findKthLargest_MinHeap(vector<int>arr, int k){
    // Step 1: Get the total number of items in the list because we will need to loop through all of them.
    int n = arr.size();

    // Step 2: Create a min-heap (a special list that always keeps the SMALLEST item at the top) because this structure will help us
    //  efficiently track the k largest numbers.
    priority_queue<int, vector<int>, greater<int>>pq;

    // Step 3: Go through each number in the original list one by one because we must examine every number to find the correct k-th largest.
    for(int i=0; i<n; i++){
        // Step 4: Add the current number to the min-heap because we want to include it in our group of the largest numbers found so far.
        pq.push(arr[i]);
        // Step 5: Check if the heap has grown to have more than k numbers because we only want to keep the top k largest numbers.
        if(pq.size() > k){
            // Step 6: If the heap is too big, remove the smallest number (which is at the top of a min-heap) because it can't be one of the
            //  top k largest elements, so we no longer need to track it.
            pq.pop();
        }
    }

    // Step 7: Get the number at the top of the heap because, after checking all elements, this top number is the smallest among the k largest
    //  numbers, which is precisely the k-th largest number overall.
    int kthLargest = pq.top();

    // Step 8: Return the final number because this is our answer.
    return kthLargest;
}

int main() {
    vector<int> arr = {7, 10, 4, 3, 20, 15};
    int k = 3;

    // Using brute-force sorting approach
    int kthLargest1 = findKthLargest_Sorting(arr, k);
    cout << "Kth largest element (Sorting): " << kthLargest1 << endl;

    // Using optimized min-heap approach
    int kthLargest2 = findKthLargest_MinHeap(arr, k);
    cout << "Kth largest element (Min-Heap): " << kthLargest2 << endl;

    return 0;
}