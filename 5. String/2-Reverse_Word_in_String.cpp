#include<iostream>
using namespace std;
#include<string>
#include<sstream>
#include<algorithm>


// Time Complexity: O(N), where N is the number of characters in the string, because we iterate through the string once.
// Space Complexity: O(N) because the stringstream and the result string create copies of the words, taking up extra space.
string ReverseWordsUsingStringStream(string s){
    // Step 1: Put the whole sentence into a stringstream because this makes it easy to pull out one word at a time.
    stringstream ss(s);
    // Step 2: Create an empty string called 'token' because we need a temporary place to hold each word we read.
    string token = "";
    // Step 3: Create an empty string called 'result' because this is where we will build our new sentence with reversed words.
    string result = "";

    // Step 4: Start a loop that reads one word at a time into 'token' because we need to process every word in the sentence.
    while(ss >> token){
        // Step 5: Check if the 'result' string already has words in it because we only want to add a space before the new word if it's not the very first word.
        if(!result.empty()){
            // Step 6: Add the new word to the front of the 'result' string, with a space, because this action reverses the order of the words.
            result = token + " " + result;
        }
        // Step 7: This part runs if 'result' is empty (it's the first word).
        else{
            // Step 8: Set 'result' to be the first word because there are no other words yet to put it in front of.
            result =  token;
        }
    }
    // Step 9: Return the final 'result' string because it now holds the sentence with the words in the correct reversed order.
    return result;
    
}

// Time Complexity: O(N), where N is the number of characters, because we pass over the string a fixed number of times.
// Space Complexity: O(1) because we are modifying the string in its original place and not using extra space that grows with the string size.
string ReverseWordsInPlace(string s){
    // Step 1: Get the length of the string because we need to know when to stop our loops.
    int n = s.length();
    // Step 2: Reverse the entire string character by character because this gets the words in the right order, but each word is spelled backward.
    // Note: For example, "hello world" becomes "dlrow olleh".
    reverse(s.begin(), s.end());

    // Step 3: Create a variable 'i' to track our position in the string because we need to read every character.
    int i = 0;
    // Step 4: Create 'wordStart' to remember the beginning of the current word because we need to know which part of the string to reverse next.
    int wordStart = 0;
    // Step 5: Create 'currPos' to track where to write the next character in our cleaned-up string because this helps remove extra spaces.
    int currPos = 0;

    // Step 6: Start a loop to go through the whole string because we need to find and fix each word.
    while(i<n){
        // Step 7: Start an inner loop to find a complete word by looking for characters that are not a space.
        while(i<n && s[i] != ' '){
            // Step 8: Copy the character from its original spot to the new, clean position because we are rebuilding the string without extra spaces.
            s[currPos] = s[i];
            // Step 9: Move both the reading and writing positions forward.
            i++;
            currPos++;
        }

        // Step 10: Check if we actually found a word because we don't want to do anything if we just saw spaces.
        if(wordStart < currPos){
            // Step 11: Reverse just the word we found because this flips it from backward spelling (e.g., "dlrow") to correct spelling ("world").
            reverse(s.begin()+wordStart , s.begin()+currPos);
            // Step 12: Add a single space after the corrected word because words in a sentence need to be separated.
            s[currPos] = ' ';
            // Step 13: Move the writing position past the space we just added.
            currPos = currPos+1;
            // Step 14: Set the start of the next word to our current writing position.
            wordStart = currPos;
        }
        // Step 15: Move the reading position forward because we need to skip over the space(s) to find the next word.
        i++;
    }
    
    // Step 16: Cut off any extra parts of the string at the end because our cleaning process might leave a trailing space.
    s = s.substr(0, currPos-1);
    // Step 17: Return the modified string because it now has its words reversed and any extra spaces removed.
    return s;
}

// Main function to test both approaches
int main() {
    string str = "Hello world from Ayush";

    cout << "Original string: " << str << endl;

    string reversed1 = ReverseWordsUsingStringStream(str);
    cout << "Reversed using stringstream: " << reversed1 << endl;

    string reversed2 = ReverseWordsInPlace(str);
    cout << "Reversed in-place: " << reversed2 << endl;

    return 0;
}