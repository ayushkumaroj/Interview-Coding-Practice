#include<iostream>
using namespace std;
#include<unordered_map>
#include<limits.h>
#include<vector>

// Time Complexity: O(length of sub + length of t) because we loop through both strings once.
// Space Complexity: O(1) because the frequency arrays have a fixed size of 256.
bool containAll(string sub, string t){
    // Step 1: Create an array to count characters in 'sub' because we need to know how many of each character we have.
    vector<int>freqSub(256, 0);
    // Step 2: Create an array to count characters in 't' because we need to know how many of each character we need.
    vector<int>freqP(256, 0);

    // Step 3: Loop through each character in the 'sub' string because we want to count every character in it.
    for(char c: sub){
        // Step 4: Increase the count for the current character because we have found one more of it.
        freqSub[c]++;
    }

    // Step 5: Loop through each character in the 't' string because we want to count every character we need.
    for(char c: t){
        // Step 6: Increase the count for the current character because we need one more of it.
        freqP[c]++;
    }

    // Step 7: Loop through all possible character values (0-255) because we need to compare the counts for every character.
    for(int i=0; i<256; i++){
        // Step 8: Check if the count of a character in 'sub' is less than in 't' because if we have fewer characters than we need, this 'sub' is not a valid window.
        if(freqSub[i] < freqP[i]){
            // Step 9: Return false immediately because we have found a required character that is missing from 'sub'.
            return false;
        }
    }
    // Step 10: Return true because the loop finished, which means 'sub' has at least as many of every character as 't' needs.
    return true;
}

// Time Complexity: O(n^3) where n is the length of string 's' because we have two nested loops (n^2) and inside we call 'containAll' which takes about O(n) time.
// Space Complexity: O(n) because we store substrings which can be as large as the original string 's'.
string minWindowBruteForce(string s, string t){
    // Step 1: Get the size of the string 's' because we need it for our loops.
    int n = s.size();
    // Step 2: Create an empty string 'ans' because we need a place to store our final answer.
    string ans = "";
    // Step 3: Create a variable 'minSize' and set it to a very big number because we want to find the smallest size, and any real size will be smaller than this.
    int minSize = INT_MAX;

    // Step 4: Start a loop with 'i' from the beginning to the end of 's' because this will be the starting point of our substring.
    for(int i=0; i<n; i++){
        // Step 5: Start a second loop with 'j' from 'i' to the end of 's' because this will be the ending point of our substring.
        for(int j=i; j<n; j++){
            // Step 6: Calculate the size of the current window from i to j.
            // Note: The formula for size is (end - start + 1). Here, it is (j - i + 1).
            int currWindowSize = j-i+1;
            // Step 7: Get the actual substring from 's' using the start 'i' and the size because we need to check this specific piece of the string.
            string sub = s.substr(i, currWindowSize);

            // Step 8: Check if this substring has all the characters from 't' because we are only interested in substrings that are valid windows.
            if(containAll(sub, t)){
                // Step 9: If the current substring is smaller than the smallest we have found so far because we are looking for the minimum window.
                if(sub.size() < minSize){
                    // Step 10: Update 'minSize' with the new smallest size because we have found a better answer.
                    minSize = sub.size();
                    // Step 11: Update 'ans' to be this new smaller substring because it's our best answer yet.
                    ans = sub;
                }
            }
        }
    }
    // Step 12: Return the 'ans' string because it holds the smallest valid window we found after checking all possibilities.
    return ans;
}


// Time Complexity: O(length of s + length of t) because each pointer 'i' and 'j' will traverse the string 's' only once.
// Space Complexity: O(k) where 'k' is the number of unique characters in 't', because the map stores character counts for 't'.
string minWindowSlidingWindow(string s, string t){
    // Step 1: Get the length of the string 's' because we need it for our loop bounds.
    int n = s.length();
    // Step 2: Check if 't' is longer than 's' because it is impossible to find 't' in 's' if it is.
    if(t.length() > n){
        // Step 3: Return an empty string because no solution is possible.
        return "";
    }

    // Step 4: Create a map to store the frequency of characters in 't' because we need to keep track of which characters we need and how many.
    unordered_map<char, int>mp;
    // Step 5: Loop through the string 't' to count its characters because we need to populate our map with the required character counts.
    for(char ch: t){
        mp[ch]++;
    }

    // Step 6: This variable holds the total number of characters we still need to find in our window.
    int requiredCount = t.length();
    // Step 7: Create a pointer 'i' for the start of the window, initialized to 0 because the window starts at the beginning.
    int i=0; 
    // Step 8: Create a pointer 'j' for the end of the window, initialized to 0 because the window starts at the beginning.
    int j=0;
    // Step 9: Set 'minSize' to a very large number because we want to find the smallest window, and any real window will be smaller.
    int minSize = INT_MAX;
    // Step 10: Create 'start_i' to remember the starting index of the smallest window because we need it to create the final answer string.
    int start_i = 0;

    // Step 11: Start a loop to move the end pointer 'j' across the string 's' because this expands the window to find required characters.
    while(j < n){
        // Step 12: Get the character at the end of the current window.
        char ch = s[j];
        // Step 13: Check if the character is one we need (its count in the map is > 0) because finding a needed character gets us closer to a valid window.
        if(mp[ch] > 0){
            // Step 14: Decrease the count of required characters because we just found one.
            requiredCount--;
        }
        // Step 15: Decrease the character's count in the map because we have now 'used' this character in our window.
        mp[ch]--;
        
        // Step 16: Start a loop that runs when we have found all required characters because now we can try to make the window smaller from the left.
        while(requiredCount == 0){
            // Step 17: Calculate the size of the current valid window.
            // Note: The formula for size is (end - start + 1). Here, it is (j - i + 1).
            int currentWindowSize = j-i+1;

            // Step 18: Check if this valid window is smaller than the minimum size found so far because we are looking for the smallest possible window.
            if(minSize > currentWindowSize){
                // Step 19: Update 'minSize' to this new smaller size because we've found a better solution.
                minSize = currentWindowSize;
                // Step 20: Save the starting index 'i' of this new smallest window because we'll need it to return the final answer.
                start_i = i;
            }
            // Step 21: Increase the count of the character at the start of the window ('i') in the map because we are about to remove it from the window.
            mp[s[i]]++;
            // Step 22: Check if the count of that character is now greater than 0 because this means it's a character we need, and our window will become invalid.
            if(mp[s[i]] > 0){
                // Step 23: Increase 'requiredCount' because our window is no longer valid and we need to find this character again.
                requiredCount++;
            }
            // Step 24: Move the start of the window 'i' to the right because we are shrinking the window to find a smaller one.
            i++;
        }
        
        // Step 25: Move the end of the window 'j' to the right because we need to either find more required characters or expand the window for the next check.
        j++;
    }

    // Step 26: After checking everything, if 'minSize' is still the very large number because this means we never found a valid window.
    if(minSize == INT_MAX){
        // Step 27: Return an empty string because no solution was found.
        return "";
    }
    // Step 28: Otherwise, a solution was found.
    else{
        // Step 29: Return the smallest substring using the saved starting index and minimum size because this is our final answer.
        return s.substr(start_i, minSize);
    }
}

int main() {
    string s, t;

    cout << "Enter string s: ";
    cin >> s;

    cout << "Enter string t: ";
    cin >> t;

    cout << "\nUsing Brute Force Approach:\n";
    string ans1 = minWindowBruteForce(s, t);
    if (ans1.empty())
        cout << "No valid window found\n";
    else
        cout << "Minimum window substring: " << ans1 << endl;

    cout << "\nUsing Optimized Sliding Window Approach:\n";
    string ans2 = minWindowSlidingWindow(s, t);
    if (ans2.empty())
        cout << "No valid window found\n";
    else
        cout << "Minimum window substring: " << ans2 << endl;

    return 0;
}
