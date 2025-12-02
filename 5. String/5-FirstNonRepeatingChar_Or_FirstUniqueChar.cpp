#include<iostream>
using namespace std;
#include<string.h>
#include<unordered_map>
#include<vector>
#include<limits.h>

// Overall Time Complexity: O(N*N) or O(N^2) where N is the length of the string. This is slow.
// Overall Space Complexity: O(1) because we only use a few variables.
int firstUniqCharBruteForce(string s){
    // Step 1: Get the length of the string 's' because we need to know how many times to loop.
    int n = s.length();

    // Step 2: Start a loop with index 'i' to check each character one by one, from start to end.
    for(int i=0; i<n; i++){
        // Step 3: Create a boolean variable 'repeated' and set it to false because we will use this to track if the character at 's[i]' is found anywhere else.
        bool repeated = false;

        // Step 4: Start a second loop with index 'j' because we need to compare the character 's[i]' with every other character in the string.
        for(int j=0; j<n; j++){
            // Step 5: Check if the characters 's[i]' and 's[j]' are the same, but make sure we are not comparing the character with itself (i != j) 
            // because a character always matches itself.
            if(i != j && s[i] == s[j]){
                // Step 6: If we find a match, set 'repeated' to true because we now know the character is not unique.
                repeated = true;
                // Step 7: Stop the inner loop using 'break' because we have already found a duplicate, so there is no need to keep searching.
                break;
            }
        }

        // Step 8: After the inner loop is finished, check if the 'repeated' variable is still false because this means no duplicates were found for 's[i]'.
        if(repeated == false){
            // Step 9: If the character is unique, return its index 'i' immediately because this is the *first* unique character we have found.
            return i;
        }
    }

    // Step 10: If the outer loop finishes without finding any unique character, return -1 because it means no unique character exists in the string.
    return -1;
}


// Overall Time Complexity: O(N) where N is the length of the string because we pass through the string twice.
// Overall Space Complexity: O(C) where C is the number of unique characters. This is at most 256, so it's considered constant O(1).
int firstUniqCharHashMap(string s){
    // Step 1: Get the length of the string because we will need it for our loop.
    int n = s.length();
    // Step 2: Create a hash map named 'freq' to store each character and its count because this is a fast way to count how many times each character appears.
    unordered_map<char,int>freq;

    // Step 3: Loop through each character 'c' in the string 's' because we need to count every character first.
    for(char c: s){
        // Step 4: Increase the count for the character 'c' in our map because we have seen it one more time.
        freq[c]++;
    }

    // Step 5: Loop through the string again, this time using an index 'i' from 0 to n-1 because we need to check the characters in their original order.
    for(int i=0; i<n; i++){
        // Step 6: Check the count of the character at the current index 's[i]' in our frequency map because we are looking for a character with a count of exactly 1.
        if(freq[s[i]] == 1){
            // Step 7: If the count is 1, return the current index 'i' because this is the first unique character we have found.
            return i;
        }
    }

    // Step 8: If the loop finishes, it means no character had a count of 1, so return -1.
    return -1;
}


// Overall Time Complexity: O(N) where N is the length of the string because we loop through the string once and then through a small fixed-size array (26).
// Overall Space Complexity: O(1) because the arrays we use always have a fixed size of 26, no matter how long the string is.
int firstUniqCharArray(string s){
    // Step 1: Get the length of the string 's' because we will use it in our loop.
    int n = s.length();
    // Step 2: Create a vector 'freq' of size 26 and set all values to 0 because we need to store the count for each lowercase letter from 'a' to 'z'.
    vector<int>freq(26, 0);
    // Step 3: Create a vector 'firstIndex' of size 26 and set all values to -1 because we need to store the first position we see each letter.
    vector<int>firstIndex(26, -1);

    // Step 4: Loop through the string using an index 'i' because we need to process each character and its position.
    for(int i=0; i<n; i++){
        // Step 5: Convert the character `s[i]` into an index from 0 to 25 because this lets us use the character to access our arrays.
        // NOTE: The formula `s[i] - 'a'` works because characters 'a' through 'z' have sequential ASCII values. For example, 'a' - 'a' is 0, 'b' - 'a' is 1, and so on.
        int idx = s[i] - 'a';
        // Step 6: Increase the frequency count for the character at the calculated index `idx`.
        freq[idx] = freq[idx]+1;

        // Step 7: Check if we have seen this character before by looking at its entry in 'firstIndex' because we only want to record its position the 
        // very first time we see it.
        if(firstIndex[idx] == -1){
            // Step 8: If this is the first time, save the current index 'i' in the 'firstIndex' array because this is the first place this character appeared.
            firstIndex[idx] = i;
        }
    }

    // Step 9: Create a variable 'minIndex' and set it to the largest possible integer value because we will use it to find the smallest index among all 
    // the unique characters.
    int minIndex = INT_MAX;
    // Step 10: Loop 26 times (from i=0 to 25) because we need to check the results for every possible lowercase letter.
    for(int i=0; i<26; i++){
        // Step 11: Check if the character corresponding to index 'i' appeared exactly once.
        if(freq[i] == 1){
            // Step 12: If it is a unique character, check if its first index is smaller than the current 'minIndex' we have because we are looking for
            //  the smallest index of all unique characters.
            if(firstIndex[i] < minIndex){
                // Step 13: If we found a smaller index, update 'minIndex' to this new smaller index.
                minIndex = firstIndex[i];
            }
        }
    }

    // Step 14: After checking all the letters, see if 'minIndex' is still the largest possible integer value because this would mean we never found a
    //  unique character.
    if(minIndex == INT_MAX){
        // Step 15: If no unique character was found, return -1.
        return -1;
    }else{
        // Step 16: Otherwise, return the 'minIndex' we found because it is the index of the first unique character.
        return minIndex;
    }
}


int main() {
    // Step 1: Create a string 's' because we need a variable to store the user's input.
    string s;
    // Step 2: Print a message to the screen because we need to ask the user to enter a string.
    cout << "Enter a string: ";
    // Step 3: Read the input from the user and store it in the 's' variable.
    cin >> s;

    // Step 4: Call the brute-force function with the user's string and print the returned index because we want to show the result of the first method.
    cout << "First non-repeating character index (Brute-force): "
         << firstUniqCharBruteForce(s) << endl;

    // Step 5: Call the hash map function and print the returned index because we want to show the result of the second method.
    cout << "First non-repeating character index (HashMap): "
         << firstUniqCharHashMap(s) << endl;

    // Step 6: Call the array function and print the returned index because we want to show the result of the third, optimized method.
    cout << "First non-repeating character index (Array Optimized): "
         << firstUniqCharArray(s) << endl;

    // Step 7: End the program successfully.
    return 0;
}