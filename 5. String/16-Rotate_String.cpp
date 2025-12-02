#include<iostream>
using namespace std;
#include<string>
#include<vector>
#include<algorithm>

// Time Complexity: O(n^2) because we have a main loop that runs 'n' times (where 'n' is the length of the string), and inside that loop, two operations each 
// take O(n) time: the string comparison (s == goal) and the string concatenation (s = lastChar + s), leading to a total time of n * (n + n) which is O(n^2).
// Space Complexity: O(n) because the function receives the string 's' by value, which means a copy of the original string (of size 'n') is created and stored 
// in memory for the function to use and modify.
bool isRotationByManualShift(string s, string goal) {
    // Step 1: Check if the lengths of the two strings are different because a rotated string must have the exact same number of characters as the original string,
    //  so if the lengths don't match, one cannot be a rotation of the other.
    if (s.length() != goal.length())
        // Step 2: Immediately stop the function and return 'false' because we have confirmed it's impossible for the strings to be rotations if their lengths are
        //  not equal.
        return false;

    // Step 3: Store the length of the string 's' in a variable 'n' because we will need this value to control how many times we loop, ensuring we check every
    //  possible rotation.
    int n = s.length();

    // Step 4: Start a loop that will repeat 'n' times (once for each character) because a string of length 'n' has exactly 'n' possible unique rotations,
    //  and we must check every single one to see if it matches the 'goal'.
    for (int i = 0; i < n; i++) {
        // Step 5: Compare the current, potentially rotated, version of string 's' with the 'goal' string because if they are identical at any point, it means 
        // we have found a rotation of 's' that matches 'goal' exactly.
        if (s == goal)
            // Step 6: Immediately stop the function and return 'true' because we have successfully found a match, and no further checks or rotations are necessary.
            return true;

        // (The commented-out lines below show a left shift, while the active code performs a right shift)
        // // Step 3: Perform one left shift
        // char firstChar = s[0];
        // s.erase(s.begin()); // remove first char
        // s.push_back(firstChar); // add it to end

        // Step 7: Get the very last character from the string 's' and store it in the 'lastChar' variable because this is the character we are going to move 
        // to the front to perform one right rotation.
        char lastChar = s.back();


        // Step 8: Remove the last character from the string 's' because we are about to re-insert it at the beginning, and this prevents us from duplicating 
        // the character.
        s.pop_back();
        // Step 9: Create a new version of string 's' by adding the 'lastChar' (which we saved) to the very beginning of the (now shorter) string 's' because
        //  this action completes one full right rotation (e.g., "abcd" becomes "d" + "abc" = "dabc").
        // Note: This string concatenation operation (lastChar + s) creates an entirely new string in memory and then copies it back into 's', which is an O(n)
        //  operation and a key reason for the O(n^2) overall time complexity.
        s = lastChar + s;
    }

    // Step 10: If the loop finishes without ever finding a match (meaning we tried all 'n' rotations) return 'false' because this confirms that the 'goal' string
    //  is not a rotation of the original 's' string.
    return false;
}

// Time Complexity: O(n^2) because the function has a loop that iterates 'n' times (where 'n' is the string length), and inside this loop, both the string 
// comparison (s == goal) and the std::rotate function take O(n) time, resulting in a total time of n * (n + n), which simplifies to O(n^2).
// Space Complexity: O(n) because the string 's' is passed by value, which means a separate copy of the entire string (of size 'n') is created and stored
//  in memory for this function to use and modify.
bool isRotationByRotateFunction(string s, string goal) {
    // Step 1: Get the length of the input string 's' and store it in a variable 'n' because we need this value to compare lengths and to control our loop 
    // so we check exactly 'n' possible rotations.
    int n = s.length();

    // Step 2: Compare the length of 's' (stored in 'n') with the length of 'goal' because if the lengths are not identical, it's impossible for one to be
    //  a rotation of the other, so we can stop immediately.
    if(n != goal.length()){
        // Step 3: Return 'false' right away because the length check failed, confirming they cannot be rotations.
        return false;
    }

    // Step 4: Start a loop that will run 'n' times (from i=0 up to n-1) because a string of length 'n' has 'n' possible rotations, and we need to check each one.
    for(int i=0; i<n; i++){
        // Step 5: Check if the current state of string 's' is exactly equal to the 'goal' string because if they match, we have found that 'goal' is indeed
        //  a rotation of the original 's'.
        if(s == goal){
            // Step 6: Stop the function and return 'true' immediately because we have successfully found a match, and no more checks are needed.
            return true;
        }

        // Step 7: Perform a single left rotation on the string 's' in-place because we need to check the *next* possible rotation in the following loop
        //  iteration to see if it matches the 'goal'.
        // Note: The std::rotate(first, middle, last) function rearranges the string so that the element pointed to by 'middle' (s.begin()+1, which is the
        //  second character) becomes the new first character, and the element at 'first' (s.begin(), the first character) gets moved to the end.
        rotate(s.begin(), s.begin()+1, s.end());
    }
    // Step 8: If the loop completes all 'n' iterations without finding a match, return 'false' because this means we have checked every possible rotation
    //  and none of them were equal to the 'goal'.
    return false;
}


// Time Complexity: O(n^2) in the worst case. This is because creating the 'temp' string (s + s) takes O(n) time. Then, the 'find' operation, which searches
//  for 'goal' (length n) inside 'temp' (length 2n), can take up to O(2n * n) or O(n^2) time in the worst-case scenario (like a naive substring search).
// Space Complexity: O(n) because we create a new string variable 'temp' that stores 's + s', and this new string has a length of 2n, which means the
//  memory used is directly proportional to the original string's length 'n'.
bool isRotationByConcatenation(string s, string goal) {
    // Step 1: Get the length of the original string 's' and store it in a variable 'n' because we will need this value for our length comparison.
    int n = s.length();
    // Step 2: Get the length of the 'goal' string and store it in a variable 'm' because we need to compare it with the length of 's'.
    int m = goal.length();
    // Step 3: Check if the length of 'goal' (m) is different from the length of 's' (n) because a rotation must have the exact same number of characters,
    //  so if they differ, it's impossible.
    if(m != n){
        // Step 4: Immediately stop the function and return 'false' because the lengths do not match, proving it cannot be a rotation.
        return false;
    }
    // Step 5: Create a new string 'temp' by concatenating 's' with itself (e.g., "abc" + "abc" = "abcabc") because this clever trick creates a single string
    //  that contains every possible rotation of 's' as a substring.
    // Note: This works because if 'goal' (e.g., "bca") is a rotation of 's' (e.g., "abc"), it must be formed by a suffix ("bc") and a prefix ("a") of 's'. 
    // Doubling 's' to "abcabc" guarantees this "bca" combination will appear.
    string temp = s + s;

    // Step 6: Search inside our new 'temp' string to see if the 'goal' string exists within it because if 'goal' is found, it proves 'goal' is a valid
    //  rotation of 's'.
    // Note: The 'find()' function returns the starting index if the substring is found, but if it's not found, it returns a special constant value called
    //  'string::npos'.
    if(temp.find(goal) != string::npos){
        // Step 7: Return 'true' because the 'find' function did *not* return 'string::npos', which means it successfully found 'goal' as a substring inside 'temp'.
        return true;
    }
    // Step 8: This 'else' block is executed if the 'if' condition was false because it means 'find()' returned 'string::npos', indicating the 'goal' string
    //  was not found in 'temp'.
    else{
        // Step 9: Return 'false' because 'goal' was not found in the doubled string, proving that 'goal' is not a rotation of 's'.
        return false;
    }
}






