#include<iostream>
using namespace std;
#include<vector>

/*
- Concept Note: Palindrome Rearrangement
A string can be rearranged to form a palindrome if at most one of its characters appears an odd number of times.
All other characters must appear an even number of times.

For example:
"aabbc" -> can be "abcba". (Here 'c' appears once, which is odd).
"aabb" -> can be "abba". (Here all characters appear an even number of times).
"aabbcd" -> cannot be a palindrome. (Here 'c' and 'd' appear an odd number of times).

*/
// Time Complexity: O(n) — because the code loops through the input string exactly one time.
// Space Complexity: O(1) — because the 'count' vector has a fixed size (256) that does not change with the string's length.
bool canBeRearrangedAsPalindrome(string s) {
    // Step 1: Get the length of the string 's' and store it in 'n' because we need to know how many characters we have to check.
    int n = s.length();

    // Step 2: Create a variable 'oddCount' and set it to 0 because we need a counter to keep track of how many unique characters appear an odd number of times.
    int oddCount = 0;

    // Step 3: Create an array named 'count' of size 256 and fill it with zeros because we need to store the frequency of every possible 
    // character (based on ASCII values 0-255).
    vector<int> count(256, 0);

    // Step 4: Start a loop that goes from the first to the last character of the string because we must count every character to check if a palindrome is possible.
    for (int i = 0; i < n; i++) {
        // Step 5: Increase the count for the current character 's[i]' by 1 because we have seen this character one more time.
        count[s[i]]++;

        // Step 6: Check if the new count of this character is an odd number (like 1, 3, 5...) because this tells us if the character's frequency has just become odd.
        if (count[s[i]] % 2 == 1) {
            // Step 7: Increase 'oddCount' by 1 because we now have one more character that has an odd total count.
            oddCount++;
        }
        // Step 8: If the count is not odd, it must be an even number (like 2, 4, 6...) because that's the only other possibility.
        else {
            // Step 9: Decrease 'oddCount' by 1 because a character that previously had an odd count now has an even one, so the total number of characters
            //  with odd counts goes down.
            oddCount--;
        }
    }

    // Step 10: After the loop, check if our 'oddCount' is greater than 1 because a valid palindrome can have at most one character with an odd
    //  count (this character becomes the center of the palindrome).
    if (oddCount > 1) {
        // Step 11: Return 'false' because if more than one character has an odd count, it's impossible to form a palindrome.
        return false;
    }
    // Step 12: If 'oddCount' is not greater than 1 (meaning it's 0 or 1) because this is the rule for a string that can be rearranged into a palindrome.
    else {
        // Step 13: Return 'true' because the string can be successfully rearranged into a palindrome.
        return true;
    }
}

int main() {
    string s;
    cout << "Enter a string: ";
    cin >> s;

    if (canBeRearrangedAsPalindrome(s))
        cout << "Yes, the string can be rearranged into a palindrome." << endl;
    else
        cout << "No, the string cannot be rearranged into a palindrome." << endl;

    return 0;
}