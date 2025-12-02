#include<iostream>
using namespace std;
#include<vector>
#include<queue>

// Overall Time Complexity: O(N log K) where N is the total number of points and K is the number we want to find.
// Overall Space Complexity: O(K) because the priority queue will store at most 'K' points.
vector<vector<int>> kClosest(vector<vector<int>>& arr, int k) {
    // Step 1: Create a short name 'piv' for a pair of (integer, vector of integers) because 'piv' is shorter and makes the code easier to read.
    typedef pair<int, vector<int>>piv;
    // Note: We will use this pair to store {distance, point_coordinates}.

    // Step 2: Create a priority queue 'pq' that holds our 'piv' pairs because this structure will help us keep track of the 'k' smallest distances.
    priority_queue<piv>pq;
    // Note: This is a 'max-heap' by default. It always keeps the pair with the *largest* first value (the distance) at the very top.

    // Step 3: Go through each point ('v') in the input list 'arr' one by one.
    for(vector<int> v: arr){
        // Step 4: Get the first number from the point vector, which is the 'x' coordinate.
        int x = v[0];
        // Step 5: Get the second number from the point vector, which is the 'y' coordinate.
        int y = v[1];
            
        // Step 6: Calculate the squared distance from the center (0,0) to the point (x,y) because this tells us how far the point is.
        int distSq = x*x + y*y;
        // Note: Concept: We use the squared Euclidean distance (x² + y²). We don't need the square root (sqrt) because if (distA)² > (distB)², then distA > distB. 
        // This avoids slow math operations.

        // Step 7: Add the pair {squared_distance, point_vector} to the max-heap because the heap will automatically sort it based on the distance.
        pq.push({distSq, v});

        // Step 8: Check if the heap now has more than 'k' items because we only want to keep the 'k' points with the smallest distances.
        if(pq.size() > k){
            // Step 9: If the size is too big, remove the top item because the top item is the one with the *largest* distance, which we don't want.
            pq.pop();
        }
    }
    // Note: After this loop, the 'pq' holds exactly the 'k' points that are closest to the origin (0,0).

    // Step 10: Create an empty list 'ans' to hold our final answer because we need a place to store the 'k' closest point vectors.
    vector<vector<int>>ans;
        
    // Step 11: Keep looping as long as our priority queue still has items in it.
    while(pq.size()>0){
        // Step 12: Get the pair at the top of the queue and take its second part (the 'v') because this is the actual point vector we want to save.
        vector<int> v = pq.top().second;
        // Step 13: Add this point vector to our 'ans' list.
        ans.push_back(v);
        // Step 14: Remove the top item from the queue because we have finished processing it.
        pq.pop();
    }
        
    // Step 15: Return the final list of 'k' closest points because this is the function's final output.
    // Note: The problem doesn't require the final 'k' points to be in any specific order, so we don't need to sort the 'ans' list.
    return ans;
}

int main() {
    // Step 1: Create a list of 2D points.
    vector<vector<int>> points = {
        {1, 3},
        {-2, 2},
        {5, 8},
        {0, 1}
    };

    // Step 2: Choose how many closest points to the origin (0, 0) we want.
    int k = 2;

    // Step 3: Call the function to find the 'k' closest points.
    vector<vector<int>> result = kClosest(points, k);

    // Step 4: Check if we got any result before printing.
    if (result.size() > 0) {
        cout << "The " << k << " closest points to the origin are:" << endl;

        // Step 5: Print each point nicely.
        for (int i = 0; i < result.size(); i++) {
            cout << "(" << result[i][0] << ", " << result[i][1] << ")";
            if (i != result.size() - 1) {
                cout << ", ";
            }
        }
        cout << endl;
    } else {
        // Step 6: Handle case where result is empty.
        cout << "No points found. Please check the input data." << endl;
    }

    // Step 7: Run another test case to verify correctness.
    vector<vector<int>> points2 = {
        {3, 3},
        {5, -1},
        {-2, 4}
    };
    int k2 = 2;

    vector<vector<int>> result2 = kClosest(points2, k2);

    // Step 8: Print the second test case result.
    cout << "For the second test case, the " << k2 << " closest points are:" << endl;
    for (int i = 0; i < result2.size(); i++) {
        cout << "(" << result2[i][0] << ", " << result2[i][1] << ")";
        if (i != result2.size() - 1) {
            cout << ", ";
        }
    }
    cout << endl;

    // Step 9: Optional validation message.
    if (!result.empty() && !result2.empty()) {
        cout << "All test cases executed successfully!" << endl;
    } else {
        cout << "Something went wrong during execution." << endl;
    }

    // Step 10: Return 0 to indicate successful program execution.
    return 0;
}
