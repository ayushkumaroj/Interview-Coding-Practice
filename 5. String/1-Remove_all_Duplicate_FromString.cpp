#include<iostream>
using namespace std;
#include<vector>

// Time Complexity: O(n^2) because for each character, we loop through all the characters that came before it.
// Space Complexity: O(n) because in the worst case (a string with no duplicates), the 'ans' string will grow to the same size as the input string.
string removeDuplicatesBruteForce(string s){
    // Step 1: Create an empty string named 'ans' because we need a place to store our final answer with unique characters.
    string ans = "";

    // Step 2: Start a loop that goes through each character of the input string 's' one by one, from start to end, because we need to check every single character.
    for(int i=0; i<(int)s.length(); i++){
        // Step 3: Create a counter 'j' and set it to 0 because we will use this to loop through the part of the string we have already checked.
        int j = 0;

        // Step 4: Start an inner loop that checks from the beginning of the string up to the character right before our current one (s[i]) because we want to see
        //  if our current character has appeared before.
        for(j=0; j<i; j++){
            // Step 5: Check if the current character (s[i]) is the same as any previous character (s[j]) because this is how we find a duplicate.
            if(s[i] == s[j]){
                // Step 6: Stop the inner loop immediately because we have found a duplicate, so there is no need to check further.
                break;
            }
        }

        // Step 7: Check if the inner loop finished completely without finding a duplicate (i.e., 'j' made it all the way to 'i') because this tells us the
        //  character s[i] is unique so far.
        if(i == j){
            // Step 8: Add the unique character to our 'ans' string because it's the first time we've seen it.
            ans = ans + s[i];
        }
    }
    // Step 9: Return the 'ans' string because it now contains only the unique characters from the original string in their first-seen order.
    return ans;
}

// Time Complexity: O(n) because we only loop through the input string one time.
// Space Complexity: O(1) because the 'map' vector has a fixed size (52) that doesn't change no matter how long the input string is.
string removeDuplicatesUsingHashMap(string s){
    // Step 1: Create an empty string named 'ans' because we need a place to store our final result.
    string ans = "";
    // Step 2: Create a boolean list (vector) called 'map' of size 52 and fill it with 'false' because we need to keep track of which characters
    //  (26 uppercase + 26 lowercase) we have already seen.
    vector<bool>map(52,false);

    // Step 3: Start a loop that looks at each character in the string 's' because we need to process every character to decide if it's a duplicate.
    for(int i=0; i<(int)s.length(); i++){
        // Step 4: Create a variable 'index' because we need a place to store the calculated position of the character in our 'map'.
        int index;

        // Step 5: Check if the current character is an uppercase letter because uppercase and lowercase letters need to be stored at different positions
        //  in our 'map'.
        if(isupper(s[i])){
            // Step 6: Calculate the position for the uppercase letter because we need to map 'A'-'Z' to indices 26-51.
            // NOTE: The formula (s[i] - 'A') converts a character like 'A' to 0, 'B' to 1, etc. We add 26 to put it in the second half of our map.
            index = s[i] - 'A' + 26;
        }else{
            // Step 7: Calculate the position for the lowercase letter because we need to map 'a'-'z' to indices 0-25.
            // NOTE: The formula (s[i] - 'a') converts a character like 'a' to 0, 'b' to 1, etc.
            index = s[i] - 'a';
        }
        // Step 8: Check our map at the calculated 'index' to see if the value is 'false' because 'false' means we have not seen this character before.
        if(map[index] == false){
            // Step 9: Add the current character to our 'ans' string because it is a unique character.
            ans = ans+s[i];
            // Step 10: Update the map at that index to 'true' because we want to remember that we have seen this character now.
            map[index] = true;
        }
    }
    // Step 11: Return the 'ans' string because it now holds the final string with all duplicates removed.
    return ans;
}




int main() {
    string s = "bcabc";

    cout << "Brute Force: " << removeDuplicatesBruteForce(s) << endl;
    cout << "Hash Map: " << removeDuplicatesUsingHashMap(s) << endl;

    return 0;
}