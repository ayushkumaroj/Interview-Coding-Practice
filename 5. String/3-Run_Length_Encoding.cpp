#include<iostream>
using namespace std;
#include<string>

// Time Complexity: O(n) because we look at each character in the string only once.
// Space Complexity: O(n) because the new 'result' string can grow up to twice the size of the original string in the worst case (e.g., "abc" becomes "a1b1c1").
string LengthEncoding(string s){
    // Step 1: Get the length of the string 's' and save it in a variable 'n' because we need to know when to stop our main loop.
    int n = s.length();
    // Step 2: Create a new, empty string called 'result' because we need a place to build and store the new compressed string.
    string result = "";

    // Step 3: Start a loop to go through each character of the string from start to end because we need to check every character to count 
    // how many times it repeats.
    for(int i=0; i<n; i++){
        // Step 4: Create a variable 'count' and set it to 1 because we are looking at a character, so we have found at least one of it.
        int count = 1;

        // Step 5: Start a small loop to check if the next character is the same as the current one because we need to count all the repeating 
        // characters that are together in a group.
        while(i+1 < n && s[i] == s[i+1]){
            // Step 6: Move to the next character by increasing 'i' because we have confirmed it's a repeat, and we want our main loop to skip it later.
            i++;
            // Step 7: Increase the 'count' by one because we have found one more repeating character.
            count++;
        }

        // Step 8: Add the current character to our 'result' string because we have finished counting all repeats for this character group.
        result.push_back(s[i]);
        // Step 9: Add the final count of the character to the 'result' string because this tells us how many times that character appeared in a row.
        // NOTE: The to_string() function changes the number 'count' into a string. This is important because you can only add strings to other strings.
        result.append(to_string(count));
    }

    // Step 10: After the loop has checked all characters, send back the final 'result' string because it now contains the compressed version of the original string.
    return result;
}

int main(){
    string s = "aaaabbbccc";

    string ans = LengthEncoding(s);
    cout<<ans;
}