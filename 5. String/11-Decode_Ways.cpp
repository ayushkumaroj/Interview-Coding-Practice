#include<iostream>
using namespace std;
#include<unordered_map>
#include<vector>

// # RECURSIVE APPROCH
// Time Complexity: O(2^n), where 'n' is the length of the string. This is because, in the worst case (like "1111..."), each call branches into two new calls, 
// creating an exponential number of operations.
// Space Complexity: O(n), where 'n' is the length of the string. This is because of the memory used by the "call stack" (the chain of function calls)
//  which can go as deep as the length of the string.
int recurDecodings(int index, const string &s) {
    // Step 1: Get the total length of the string 's' and store it in 'n' because we need to know when our 'index' has successfully reached the end.
    int n = (int)s.size();

    // Step 2: Check if our current position ('index') is at the very end of the string (length 'n') because if it is, we have found one complete, 
    // valid way to decode the string, so we return 1.
    if (index == n) {
        return 1;
    }
    // Step 3: Check if the number at the current position ('index') is a '0' because a '0' cannot be decoded by itself (like 'A' or 'B') and cannot start
    // a two-digit code (like '05'). This path is invalid, so we return 0.
    if (s[index] == '0') {
        return 0;
    }
    // Step 4: Check if we are at the very last number in the string (position n-1) because if we are (and we know from Step 3 it's not '0'), we can only
    // decode it as one single digit, which is one valid way.
    if (index == n - 1) {
        return 1;
    }

    // Step 5: Find all the ways to decode by treating the current number as a single digit (like '1' -> 'A')
    // because this calculates all possibilities for the *rest* of the string starting from the *next* number (index + 1).
    int waysSingle = recurDecodings(index + 1, s);
    
    // Step 6: Create a variable 'waysTwo' to count the ways we can decode using two numbers (like '12' -> 'L')
    // because we need to add this to our 'waysSingle' count later. We start it at 0 just in case a two-digit decode isn't possible.
    int waysTwo = 0;

    // Step 7: Get the number at the current position ('index') and call it 'first'
    // because we need to check if this number can be the start of a valid two-digit code (like '1' or '2').
    char first = s[index];
    
    // Step 8: Get the number at the *next* position ('index + 1') and call it 'second'
    // because we need to combine it with 'first' to see if they make a valid code (like '12' or '25').
    char second = s[index + 1];

    // Step 9: Check if the 'first' number is a '1'
    // because if it is, it can be combined with *any* 'second' number (from '0' to '9') to make a valid code ('10' through '19').
    if (first == '1') {
        // Step 10: If a valid two-digit code is found (like '1' + any number), find all the ways to decode the *rest* of the string
        // because we are using up *two* numbers ('first' and 'second'), so we must jump ahead 2 positions (index + 2).
        waysTwo = recurDecodings(index + 2, s);
    } 
    // Step 11: If 'first' was not '1', check if it is a '2'
    // because '2' can also start a two-digit code, but only with specific 'second' numbers ('0' through '6').
    else if (first == '2') {
        // Step 12: Check if the 'second' number is between '0' and '6' (inclusive) because this makes a valid two-digit code (from '20' = 'T' to '26' = 'Z').
        // Note: This check works because we are comparing characters. '0' is 48 in ASCII, '6' is 54. 
        // This is a simple way to check if a character-digit is in a specific range.
        if (second >= '0' && second <= '6') {
            // Step 13: If the code is valid (like '20' to '26'), find all the ways to decode the *rest* of the string
            // because we are using up *two* numbers, so we must jump ahead 2 positions (index + 2).
            waysTwo = recurDecodings(index + 2, s);
        } else {
            // Step 14: If the 'second' number is not '0'-'6' (e.g., the code is '27'), this is not a valid two-digit code
            // because 'Z' is 26. So, the number of ways for this two-digit path is zero.
            waysTwo = 0;
        }
    } 

    // Step 15: If the 'first' number was not '1' or '2' (e.g., it was '3' or '4')
    // because it can *never* be the start of a valid two-digit code (the highest possible code is '26' ('Z')). So, the number of ways for this path is zero.
    else {
        waysTwo = 0;
    }

    // Step 16: Add the ways from decoding a single number ('waysSingle') and the ways from decoding two numbers ('waysTwo')
    // because the total number of ways is the sum of all possible choices we can make from this position.
    return waysSingle + waysTwo;
}

int numDecodings(const string &s) {
    // Step 1: Check if the string 's' is empty because if there are no numbers, there are zero ways to decode it.
    if (s.empty()) return 0;
    
    // Step 2: Start the main counting process (recursion) at the beginning of the string (position 0) because we need to find all the ways to decode the 
    // *entire* string from the start.
    return recurDecodings(0, s);
}




// # MEMOIZATION APPROACH
// Step 1: Create a global storage map called 'hashMap' because we need a place to save (or "memoize") the answers for parts of the string we've already 
// solved, so we don't have to calculate them again.
unordered_map<int, int> hashMap;

// Time Complexity: O(N) because we solve for each string position (index) only once thanks to the 'hashMap' (memoization), where N is the string length.
// Space Complexity: O(N) because the 'hashMap' might store an answer for every position, and the recursion can go N levels deep in the call stack.
int recurDecodings(int index, const string &s) {
    // Step 2: Check if the 'index' has reached the very end of the string because if it has, it means we successfully found one complete way to decode
    //  the entire string.
    if (index == (int)s.length()) {
        // Step 3: Give back the number 1 because finding one complete way counts as 1 valid solution.
        return 1;
    }

    // Step 4: Check if the character at the current 'index' is a '0' because numbers starting with '0' (like "0", "01", "05") are not allowed by the problem's rules.
    if (s[index] == '0') {
        // Step 5: Give back the number 0 because if we hit a '0', this path is invalid and leads to 0 solutions.
        return 0;
    }

    // Step 6: Check if the 'index' is at the very last character of the string because if it is (and we already know from Step 4 it's not '0'), 
    // it's a valid single-digit decoding.
    if (index == (int)s.length() - 1) {
        // Step 7: Give back the number 1 because this single last character forms 1 valid solution by itself.
        return 1;
    }

    // Step 8: Check if we have already saved an answer for this 'index' in our 'hashMap' because if we have, we can just use the saved answer instead 
    // of doing the work all over again.
    if (hashMap.find(index) != hashMap.end()) {
        // Step 9: Give back the saved answer from the 'hashMap' for this 'index' because this saves a lot of time by reusing old work.
        return hashMap[index];
    }

    // Step 10: Create a variable 'result' and set it to 0 because we need a place to add up all the possible decoding ways we find from this 'index'.
    int result = 0;

    // This block checks the path of taking just one digit
    {
        // Step 11: Try decoding just one digit by calling the same function again for the next position ('index + 1') because we want to find all solutions 
        // that start by taking the current character as one letter (e.g., '1' as 'A').
        int waysIfTakeOne = recurDecodings(index + 1, s);
        // Step 12: Add the number of ways found from Step 11 to our 'result' because we are counting all possibilities, and this adds the ones from the 
        // "take one digit" path.
        result = result + waysIfTakeOne;
    }

    // This block checks the path of taking two digits
    {
        // Step 13: Get the character at the current 'index' and store it in 'c1' because this is the first digit of a potential two-digit number.
        char c1 = s[index];
        // Step 14: Get the character at the next 'index' ('index + 1') and store it in 'c2' because this is the second digit of a potential two-digit number.
        char c2 = s[index + 1];
        
        // Note: (c1 - '0') is a common way to change a number character (like '2') into an actual number (like 2).
        // Step 15: Change the first character 'c1' into a number and multiply by 10 (e.g., '2' becomes 20) because this gives us the "tens" part of the
        //  two-digit number.
        int tens = (c1 - '0') * 10;
        // Step 16: Change the second character 'c2' into a number (e.g., '6' becomes 6) because this gives us the "ones" part.
        int ones = (c2 - '0');
        // Step 17: Add the 'tens' and 'ones' parts together to get the full two-digit number (e.g., 20 + 6 = 26) because we need this number to see if it's a 
        // valid letter (between 10 and 26).
        int twoDigit = tens + ones;

        // Step 18: Check if the 'twoDigit' number is between 10 and 26 (inclusive) because only these numbers can be decoded as a single letter (10='J', 26='Z').
        if (twoDigit >= 10 && twoDigit <= 26) {
            // Step 19: If it is valid, try decoding from two steps ahead ('index + 2') by calling the function again because we just used two digits, so we need 
            // to find solutions for the rest of the string.
            int waysIfTakeTwo = recurDecodings(index + 2, s);
            // Step 20: Add the number of ways found from Step 19 to our 'result' because this adds all the possibilities from the "take two digits" path.
            result = result + waysIfTakeTwo;
        } else {
            // Step 21: If the 'twoDigit' number was not valid (like '31'), add 0 to the result because this path is not allowed and gives 0 solutions.
            result = result + 0;
        }
    }

    // Step 22: Save the final 'result' (the total ways for this 'index') into our 'hashMap' because we want to remember it in case we are asked about this 'index' 
    // again later.
    hashMap[index] = result;
    // Step 23: Give back the final 'result' because this is the total number of ways to decode the string starting from this 'index'.
    return result;
}

int decodeWaysMemoized(const string &s) {
    // Step 24: Empty the 'hashMap' because we need to clear out any saved answers from a previous time this function was used, as this is a new string.
    hashMap.clear();
    // Step 25: Call the main helper function 'recurDecodings' starting at 'index' 0 because we want to find the total number of ways to decode the *entire* 
    // string from the beginning.
    return recurDecodings(0, s);
}

int main() {
// Input string to decode.
string s;
cout << "Enter the string of digits: ";
cin >> s;

// Calculate number of decoding ways.
int result = numDecodings(s);

// Output the result.
cout << "Total number of ways to decode: " << result << endl;

return 0;

}