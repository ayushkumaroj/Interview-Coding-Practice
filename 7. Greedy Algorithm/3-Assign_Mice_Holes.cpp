#include <iostream>
#include <vector>
#include <algorithm> // Required for sort
#include <climits>   // Required for INT_MIN
#include <cmath>     // Required for abs
using namespace std;

class MouseHole{
    private:
    vector<int>mices;
    vector<int>holes;

    public:
    // Step 1: Define a constructor that takes two vectors as input because we need to initialize the object with the specific positions of mice and holes before performing any calculations.
    MouseHole(vector<int>m, vector<int>h){
        // Step 2: Copy the values from the input vector 'm' into the class member 'mices' because we need to store this data inside the object to use it in other functions later.
        mices = m;
        // Step 3: Copy the values from the input vector 'h' into the class member 'holes' because we need to persist the hole locations within the object for the assignment logic.
        holes = h;
    }

    /*
    - Time Complexity: O(N log N) :The most time-consuming operations are the two sort functions, which take O(N log N) time. The loop runs N times, which is O(N), so the sorting dominates the overall complexity.
    - Space Complexity: O(1) : We are not creating any new data structures that grow with input size; we are simply rearranging the existing vectors and using a few variables for tracking values.
    */
    int assignHoles(){
        int numMice = holes.size(); // number of mice = number of holes

        // Step 4: Sort the 'mices' vector in ascending order because the most efficient way to minimize the maximum travel time is to match the mouse at the smallest position to the hole at the smallest position.
        // Note: This uses a 'Greedy Algorithm' strategy, where making the locally optimal choice (smallest mouse to smallest hole) leads to the globally optimal solution.
        sort(mices.begin(), mices.end());

        // Step 5: Sort the 'holes' vector in ascending order because we need the hole positions to align perfectly with the sorted mice positions (1st mouse to 1st hole, 2nd to 2nd, etc.).
        sort(holes.begin(), holes.end());

        // Step 6: Initialize a variable 'maxTime' to the smallest possible integer value because we need a starting point to compare against, ensuring any actual time calculated will be larger than this initial value.
        // Note: INT_MIN is a constant from <climits> that represents the minimum value a standard integer variable can hold.
        int maxTime = INT_MIN;

        // Step 7: Start a loop that iterates from 0 up to 'numMice' because we must calculate the travel time for every single mouse-to-hole pair to find the maximum one.
        for(int i=0; i<numMice; i++){
            // Step 8: Calculate the absolute difference between the current mouse's position and the current hole's position because distance is always positive regardless of direction.
            // Note: The abs() function removes the negative sign, so if a mouse moves from 4 to 2, the result is 2 (distance), not -2.
            int timeNeeded = abs(mices[i] - holes[i]);
            
            // Step 9: Update 'maxTime' to be the larger of the current 'maxTime' or the new 'timeNeeded' because the total time required is determined by the mouse that takes the longest to reach its hole.
            // Note: The max() function compares two arguments and returns the greater value.
            maxTime = max(maxTime, timeNeeded);
        }

        // Step 10: Return the final 'maxTime' because this value represents the minimum time required for the last mouse to finish moving, which is the answer to the problem.
        return maxTime;

    }

};

int main(){
    // Step 11: Create a vector 'mices' with initial values because this simulates the input data representing the starting coordinates of the mice.
    vector<int>mices = {4, -4, 2};
    
    // Step 12: Create a vector 'holes' with initial values because this simulates the input data representing the fixed coordinates of the holes.
    vector<int> holes = {4, 0,5};

    // Step 13: Create an object 'obj' of class MouseHole passing the data vectors because this triggers the constructor to set up the problem state.
    MouseHole obj(mices, holes);
    
    // Step 14: Call the 'assignHoles' function and store the result because we need to execute the logic and capture the calculated minimum time.
    int result = obj.assignHoles();

    // Step 15: Output the result to the console with a descriptive message because the user needs to see the final answer clearly displayed.
    cout<<"Minimum time required: "<< result << endl;

    // Step 16: Return 0 to the system because this indicates that the main function has completed its execution successfully without errors.
    return 0;
}