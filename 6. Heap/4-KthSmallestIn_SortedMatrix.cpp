#include<iostream>
using namespace std;
#include<vector>
#include<queue>

// Step 1: Create a blueprint named 'Element' to hold three pieces of information together.
class Element {
    public:
    // Step 2: A number from the matrix because we need to compare the numbers.
    int value;
    // Step 3: The row where the number is located because we need to know where it came from.
    int row;
    // Step 4: The column where the number is located because we need to find the *next* number in that same row.
    int col;

    // Step 5: Create a helper (a constructor) to build a new 'Element' easily.
    Element(int v, int r, int c) {
        // Step 6: Set the 'value' of this Element to the number 'v' given to us.
        value = v;
        // Step 7: Set the 'row' of this Element to the row 'r' given to us.
        row = r;
        // Step 8: Set the 'col' of this Element to the column 'c' given to us.
        col = c;
    }
};

// Step 9: Create a class with rules for sorting because a priority queue needs to know how to order 'Element' objects.
class Compare {
    public:
    // Step 10: Define the actual comparison function that the queue will use. It compares 'a' and 'b'.
    bool operator()(Element a, Element b) {
        // Step 11: Check if the value of 'a' is bigger than the value of 'b'.
        if (a.value > b.value) {
            // Step 12: If 'a' is bigger, return true because this tells the queue that 'a' has lower priority and 'b' (the smaller one) should go to the top.
            return true; 
        } else {
            // Step 13: If 'a' is not bigger, return false because this tells the queue that 'a' (the smaller or equal one) should go to the top.
            return false; 
        }
    }
    // Note: This 'Compare' class makes the priority queue a 'min-heap', which always keeps the smallest 'value' at the very top.
};

// Overall Time Complexity: O(N log N + K log N), where N is the number of rows and K is the number we are looking for.
// Overall Space Complexity: O(N) because the priority queue will store at most N elements (one for each row).
int kthSmallest(vector<vector<int>>& matrix, int k) {
    // Step 14: Get the number of rows in the matrix because we need to know how many rows to check.
    int n = matrix.size();

    // Step 15: Create a priority queue that holds 'Element' objects and uses our 'Compare' rules because this will keep the smallest numbers at the top.
    priority_queue<Element, vector<Element>, Compare> minHeap;

    // Step 16: Loop through each row one time (from row 0 to row n-1).
    for (int i = 0; i < n; i++) {
        // Step 17: Create a new 'Element' for the first item (at column 0) of the current row 'i' because we need to start by looking at the smallest item in each row.
        Element ele(matrix[i][0], i, 0);
        // Step 18: Add this new element to our min-heap because the heap will sort it and find the smallest one overall.
        minHeap.push(ele);
    }

    // Step 19: Create a temporary 'Element' variable to hold the smallest item we pull from the heap because we need to remember it.
    Element curr(0, 0, 0); // We just give it dummy values (0,0,0) for now.

    // Step 20: Start a loop that will run exactly 'k' times because we want to find the k-th smallest item.
    for (int count = 0; count < k; count++) {
        // Step 21: Get the smallest element that is currently at the top of the heap and copy it into 'curr' because this is the next smallest item in our sorted order.
        curr = minHeap.top();
        // Step 22: Remove the smallest element from the top of the heap because we are done processing it.
        minHeap.pop();

        // Step 23: Get the row of the element we just removed because we need to check this row for its *next* element.
        int r = curr.row;
        // Step 24: Get the column of the element we just removed because this tells us where we are in that row.
        int c = curr.col;

        // Step 25: Check if there is another column to the right in the same row because we can only add the next element if one exists.
        if (c + 1 < n) {
            // Step 26: Create a new 'Element' for the item in the same row 'r' but at the next column 'c + 1'.
            Element nextEle(matrix[r][c + 1], r, c + 1);
            // Step 27: Add this next element to the heap because it is now a candidate for being the next smallest item.
            minHeap.push(nextEle);
        } else {
            // Step 28: If there are no more elements in this row, do nothing and let the loop continue because we have finished this row.
            continue;
        }
    }

    // Step 29: After the loop has run 'k' times, 'curr' holds the last element we popped because that element is the k-th smallest one.
    return curr.value;
}

int main() {
    // Step 1: Create a sample matrix for testing.
    vector<vector<int>> matrix = {
        {1, 5, 9},
        {10, 11, 13},
        {12, 13, 15}
    };

    // Step 2: Choose which smallest element we want to find (example: 8th smallest).
    int k = 8;

    // Step 3: Call the kthSmallest function and store the result.
    int result = kthSmallest(matrix, k);

    // Step 4: Print the output with a message.
    cout << "The " << k << "th smallest element in the matrix is: " << result << endl;

    // Step 5: Add one more example to verify correctness.
    vector<vector<int>> matrix2 = {{-5}};
    int k2 = 1;
    int result2 = kthSmallest(matrix2, k2);

    // Step 6: Print the second test result.
    if (result2 == -5) {
        cout << "Test 2 Passed: The " << k2 << "st smallest element is: " << result2 << endl;
    } else {
        cout << "Test 2 Failed. Expected -5 but got " << result2 << endl;
    }

    // Step 7: Return 0 to signal successful program execution.
    return 0;
}
