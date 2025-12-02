#include<iostream>
using namespace std;
#include<algorithm>

/*
- Time Complexity: O(N)
  Explanation: The algorithm uses a single 'for' loop that iterates through the input string 'columnTitle' one time. The length of this string is 'N'. 
  Inside the loop, all operations (accessing a character, multiplication, subtraction, addition) take a constant amount of time (O(1)). Therefore, 
  the total time taken is directly proportional to the length of the string, which is O(N).

- Space Complexity: O(1)
  Explanation: We only use a few simple variables ('n', 'result', 'i', 'ch') to store a single number or character. The amount of memory used does not
  grow as the input string 'columnTitle' gets longer. This means the space requirement is constant, or O(1).
*/ 
int convertExcelColumnToNumber(string columnTitle) {
    // Step 1: Get the total number of characters in the 'columnTitle' string and store it in an integer variable 'n' because we need to know exactly
    //  how many times our loop must run to process every single character in the input string.
    // Note: The .size() function is a built-in method for strings that returns its length (how many characters it has), which is essential for controlling our loop.
    int n = columnTitle.size();
    // Step 2: Create an integer variable 'result' and initialize it to 0 because this variable will be used to build our final column number, 
    // and starting at zero ensures we have a clean slate for our calculation.
    // Note: This process is analogous to converting any number from a different base (like binary or hexadecimal) to our standard decimal (base-10) system,
    //  where you start with a total of 0.
    int result = 0;

    // Step 3: Start a 'for' loop that initializes a counter 'i' at 0 and continues to run as long as 'i' is less than 'n' (the string length) 
    // because this allows us to iterate through the string from left to right, processing one character at a time at index 'i'.
    for(int i=0; i<n; i++){
        // Step 4: Get the character at the current index 'i' from the 'columnTitle' string and store it in a 'char' variable 'ch' because we need to 
        // isolate this single character to convert it into its numeric value for this loop iteration.
        char ch = columnTitle[i];
        // Step 5: Multiply the current 'result' by 26 before adding the new character's value because this "shifts" all the previously calculated values
        //  one place to the left in the base-26 system, making room for the new 'digit' we are about to add.
        // Note: This is the core logic of base conversion. In our normal base-10 system, if you have '12' and want to add '3', you first multiply '12' by 10 
        // to get '120' (shifting it left) and then add the '3'. Here, we multiply by 26 because the Excel system has 26 'digits' (A-Z).
        result = result * 26;
        // Step 6: Add the numeric value of the current character 'ch' to the 'result' because this completes the process of adding the current 'digit's' value
        //  to our running total.
        // Note: The formula (ch - 'A' + 1) converts the character to its 1-based number. (ch - 'A') uses ASCII subtraction to get a 0-based value
        //  (e.g., 'A'-'A'=0, 'B'-'A'=1). We then add 1 to get the 1-based Excel value (A=1, B=2, Z=26).
        result = result + (ch - 'A' + 1);
    }

    // Step 7: After the loop has finished processing all characters, return the final calculated 'result' because this integer value now holds the
    //  correct column number corresponding to the input string.
    return result;
}