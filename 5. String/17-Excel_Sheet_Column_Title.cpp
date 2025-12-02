#include<iostream>
using namespace std;
#include<algorithm>


/*
- Time Complexity: O(log_26(N)) or O(log N), bcz The algorithm works by repeatedly dividing the input 'columnNumber' by 26 in each loop iteration. 
  This is similar to converting a base-10 number to another base. The number of divisions (and thus loop iterations) required is proportional to the
  logarithm of 'columnNumber' with base 26, which is an O(log N) operation. The final string reversal takes O(log N) time as well, as the length of the 
  string is also O(log N).

- Space Complexity: O(log_26(N)) or O(log N)
  Explanation: The extra space used is to store the 'result' string. The length of this string (the number of characters in the Excel title) grows
  logarithmically with the input 'columnNumber'. For example, 1-26 (N) needs 1 char, 27-702 (N*26) needs 2 chars, etc. Therefore, the space required is O(log N).
*/ 
string convertToExcelColumnTitle(int columnNumber) {
    // Step 1: Create an empty string variable named 'result' because we need a place to build and store the column title characters as we calculate them, one by one.
    // Note: Initializing a string as empty ensures it doesn't contain any random or 'garbage' data before we start adding our calculated characters to it.
    string result;

    // Step 2: Start a loop that will continue to run as long as the 'columnNumber' is greater than zero because this structure allows us to keep processing
    //  the number until we have handled all its 'digits' in the base-26 (A-Z) system.
    while(columnNumber > 0){
        // Step 3: Decrease the 'columnNumber' by 1 before doing any calculations because Excel columns are 1-based (A=1, B=2, ..., Z=26), but our calculations
        //  using the modulo operator are 0-based (0-25), so this subtraction correctly shifts the range from 1-26 down to 0-25.
        // Note: This 1-based (human counting) to 0-based (computer math) conversion is the most important part of this algorithm. For example, it 
        // makes column 1 ('A') become 0, and column 26 ('Z') become 25, which works perfectly with the 26 letters of the alphabet.
        columnNumber--;
        // Step 4: Calculate the remainder of the (now 0-based) 'columnNumber' when divided by 26 and store it in a variable 'remain' because this
        //  remainder value (which will be from 0 to 25) directly tells us which character (A-Z) belongs at the current position.
        // Note: The modulo operator (%) gives us the remainder of a division. In a base-26 system, this is how we find the value of the 'ones' place 
        // (the rightmost 'digit') before moving to the next place value.
        int remain = columnNumber % 26;
        // Step 5: Convert the numeric 'remain' value (0-25) into its corresponding alphabet character ('A'-'Z') and store it in 'ch' because
        //  computer character sets (like ASCII) store letters in a sequential order, allowing us to add an integer offset (like 0, 1, 2) to 
        // a base character (like 'A') to get the correct letter (A, B, C).
        // Note: This line uses ASCII character arithmetic. 'A' has a specific numeric value (65). So, if 'remain' is 0, 'A' + 0 = 'A' (65).
        //  If 'remain' is 1, 'A' + 1 = 'B' (66), and so on, up to 'A' + 25 = 'Z' (90).
        char ch = remain + 'A';
        // Step 6: Add the newly found character 'ch' to the very end of our 'result' string because this is how we build our answer, letter by letter.
        result.push_back(ch);
        // Step 7: Update the 'columnNumber' by dividing it by 26 (and dropping any remainder) because this effectively "moves" us to the next 'digit'
        //  to the left in the base-26 system, just like dividing 123 by 10 in our normal base-10 system moves you to 12.
        columnNumber = columnNumber/26;
    }

    // Step 8: Reverse the entire 'result' string in place because we built the string by adding the rightmost (least significant) characters first
    //  (e.g., 'AA' was built as 'A', then 'A'), so the final string is currently in the wrong order (e.g., 'AB' would have been built as 'BA').
    // Note: This is necessary because the modulo operation always finds the rightmost 'digit' first. Reversing at the end puts the most 
    // [significant 'digit' (calculated last) at the beginning, where it belongs.
    reverse(result.begin(), result.end());
    // Step 9: Send the final, reversed 'result' string back as the answer of the function because this string now holds the correct Excel column title.
    return result;
}