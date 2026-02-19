#include <iostream>
#include <algorithm> // Required for min
#include <cmath>     // Required for abs
using namespace std;

class CircularLock{
    private:
    long long R_value;
    long long D_value;

    public:
    // Step 1: Define a constructor that accepts the current state 'R' and desired state 'D' because we need to initialize the lock object with the specific combination values provided by the user.
    CircularLock(long long R, long long D){
        // Step 2: Assign the input 'R' to the class member 'R_value' because we need to permanently store the starting sequence within the object to use it later in calculations.
        R_value = R;
        // Step 3: Assign the input 'D' to the class member 'D_value' because we need to permanently store the target sequence within the object so we know what we are aiming for.
        D_value = D;
    }

    /*
    - Time Complexity: O(d) or O(log N) : The loop runs once for every digit in the number 'R'. If the number is N, the number of digits 'd' is approximately log10(N). Therefore, the time taken grows logarithmically with the size of the input number.
    - Space Complexity: O(1) : We are using a fixed number of integer variables (totalRotations, currentDigit, etc.) to perform the calculation. No matter how large the input number is, the amount of extra memory used remains constant.
    */

    int rotationCount(){
        // Step 4: Create a local copy of 'R_value' named 'R' because we will be modifying this number (chopping off digits) during the loop, and we don't want to destroy the original data stored in the class.
        long long R = R_value;
        // Step 5: Create a local copy of 'D_value' named 'D' because we need to modify this number in parallel with 'R' to extract matching digits one by one.
        long long D = D_value;
        
        // Step 6: Initialize 'totalRotations' to 0 because this variable will act as an accumulator to store the sum of rotations calculated for all digits, and it must start empty.
        int totalRotations = 0;
        int currentDigit;
        int targetDigit;

        // Step 7: Start a while loop that continues as long as 'R' is greater than 0 because we need to process the number digit-by-digit from right to left until no digits remain.
        while(R){
            // Step 8: Extract the last digit of 'R' using the modulo operator because we need to isolate the single digit currently at the ones place to compare it.
            // Note: The modulo operator (%) gives the remainder of a division. For example, 123 % 10 results in 3, which is the last digit.
            currentDigit = R % 10;

            // Step 9: Extract the last digit of 'D' using the modulo operator because we need the corresponding target digit at the exact same position to calculate the distance.
            targetDigit = D % 10;

            // Step 10: Update 'R' by dividing it by 10 because integer division discards the last decimal digit, effectively shifting the number to the right so we can process the next digit in the next iteration.
            // Note: Integer division drops the remainder. For example, 123 / 10 results in 12.
            R = R / 10;
            // Step 11: Update 'D' by dividing it by 10 because we must also shift the target number to keep it aligned with the current number 'R'.
            D = D / 10;

            // Step 12: Calculate 'forwardRotations' by taking the absolute difference between the two digits because this gives us the number of steps needed if we rotate directly in one direction.
            // Note: The abs() function returns the magnitude of the difference, ensuring the result is positive regardless of which digit is larger (e.g., |3 - 7| = 4).
            int forwardRotations = abs(currentDigit - targetDigit);

            // Step 13: Calculate 'backWardRotations' by subtracting the forward distance from 10 because a circular lock wraps around, so the alternative path is the total circle size (10) minus the direct path.
            // Note: In a circular set of digits (0-9), if going forward takes X steps, going the other way matches the complement, which is 10 - X.
            int backWardRotations = 10 - forwardRotations;

            // Step 14: Add the smaller of the two rotation values to 'totalRotations' because the lock can turn both ways, so we naturally choose the most efficient (shortest) path for every digit.
            totalRotations = totalRotations + min(forwardRotations, backWardRotations);
        }
        
        // Step 15: Return the final 'totalRotations' because the loop has finished processing all digits and this variable now holds the minimum moves required for the entire sequence.
        return totalRotations;
    }
};

int main(){
    long long R,D;
    // Step 16: Prompt the user to enter the current lock sequence because the program requires input data to determine the starting state of the lock.
    cout<<"Enter current lock sequence(R): ";
    // Step 17: Read the user's input and store it in variable 'R' because we need to capture the starting number sequence provided via the console.
    cin>>R;

    // Step 18: Prompt the user to enter the desired lock sequence because the program needs to know the target state to calculate the difference.
    cout<<"Enter Desired lock sequence (D): ";
    // Step 19: Read the user's input and store it in variable 'D' because we need to capture the target number sequence provided via the console.
    cin>>D;

    // Step 20: Create an instance of the CircularLock class named 'lock' and pass 'R' and 'D' because this initializes the object with the user's specific data.
    CircularLock lock(R,D);

    // Step 21: Call the 'rotationCount' method and store the result because we need to execute the logic that calculates the optimal number of moves.
    int result = lock.rotationCount();

    // Step 22: Display the final result to the user because they need to see the calculated minimum number of rotations.
    cout<<"Minimum rotations required is: "<< result << endl;

    // Step 23: Return 0 to the operating system because this signifies that the main function executed successfully and the program is ending normally.
    return 0;
    
}