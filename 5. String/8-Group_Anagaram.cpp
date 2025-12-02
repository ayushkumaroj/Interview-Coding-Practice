#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(N * M log M) where N is the number of strings and M is the max length of a string, because we sort each of the N strings.
// Space Complexity: O(N * M) because the map stores all the original strings.
vector<vector<string>> groupAnagramsBySorting(vector<string>& arr) {
    // Step 1: Get the total number of strings in the input array because we need to loop through all of them.
    int n = arr.size();
    // Step 2: Create a list of lists for the final answer because we need to store groups of anagrams.
    vector<vector<string>> result;
    // Step 3: Create a map because we need a way to group the original strings using their sorted version as a key.
    unordered_map<string, vector<string>> mp;

    // Step 4: Loop through each string in the input array because we need to process every single string.
    for (int i = 0; i < n; i++) {
        // Step 5: Create a copy of the current string because we need to sort it without changing the original.
        string temp = arr[i];
        // Step 6: Sort the copied string alphabetically because this makes anagrams identical (e.g., "eat" and "tea" both become "aet").
        sort(temp.begin(), temp.end());
        // Step 7: Add the original string to the map, using the sorted string as the key, because this groups all anagrams together under one key.
        mp[temp].push_back(arr[i]);
    }

    // Step 8: Loop through each key-value pair in the map because the map now contains the final groups.
    for (auto it : mp) {
        // Step 9: Add the list of strings (which is a group of anagrams) to our final result because we have found a complete group.
        result.push_back(it.second);
    }
    // Step 10: Return the result because it now contains all the anagrams grouped together.
    return result;
}

// Time Complexity: O(M) where M is the length of the word, because we iterate through the word once to count and once to build the new string.
// Space Complexity: O(M) because the new string we build can be as long as the original word.
string generateFrequencyKey(string word) {
    // Step 1: Create an array of size 26 and set all values to 0 because we need to count the frequency of each letter from 'a' to 'z'.
    int arr[26] = {0};

    // Step 2: Loop through each character of the input word because we need to count them one by one.
    for (char ch : word) {
        // Step 3: Increase the count for the current character.
        // Note: The formula 'ch - 'a'' converts a character to an array index (e.g., 'a' -> 0, 'b' -> 1).
        arr[ch - 'a']++;
    }

    // Step 4: Create an empty string 'new_word' because we will build our unique key in it.
    string new_word = "";
    // Step 5: Loop from 0 to 25 because we want to build the new string alphabetically from 'a' to 'z'.
    for (int i = 0; i < 26; i++) {
        // Step 6: Get the number of times the current character appeared in the original word.
        int freq = arr[i];
        // Step 7: Check if the character appeared at least once because we only add characters that exist in the word.
        if (freq > 0) {
            // Step 8: Add the character to our 'new_word' as many times as it appeared because this creates a sorted, unique key (e.g., "bca" -> "abc").
            new_word = new_word + string(freq, i + 'a');
        }
    }
    // Step 9: Return the newly created key string because it uniquely represents the group of anagrams.
    return new_word;
}

// Time Complexity: O(N * M) where N is the number of strings and M is the max length of a string, because we generate a key for each string.
// Space Complexity: O(N * M) because the map will store all the original strings.
vector<vector<string>> groupAnagramsByFrequency(vector<string>& arr) {
    // Step 1: Get the total number of strings because we need to loop through them all.
    int n = arr.size();
    // Step 2: Create a map because we need to group strings using their frequency key.
    unordered_map<string, vector<string>> mp;
    // Step 3: Create a list of lists for the final result because we will store the groups of anagrams here.
    vector<vector<string>> result;

    // Step 4: Loop through each string in the input array because we need to process every word.
    for (int i = 0; i < n; i++) {
        // Step 5: Get the current word from the array.
        string word = arr[i];
        // Step 6: Generate the unique frequency key for the current word because this key will be the same for all its anagrams.
        string new_word = generateFrequencyKey(word);
        // Step 7: Add the original word to the map using the generated key because this places it in the correct anagram group.
        mp[new_word].push_back(word);
    }

    // Step 8: Loop through the map because all strings have been processed and grouped inside it.
    for (auto& it : mp) {
        // Step 9: Add each group of anagrams from the map to our final result list.
        result.push_back(it.second);
    }

    // Step 10: Return the final result because it now contains all the grouped anagrams.
    return result;
}


void printResult(vector<vector<string>>& result) {
    for (auto& group : result) {
        cout << "[ ";
        for (auto& word : group) {
            cout << word << " ";
        }
        cout << "]\n";
    }
}

int main() {
    vector<string> arr = {"eat", "tea", "tan", "ate", "nat", "bat"};

    cout << "Grouping Anagrams using Sorting-Based Approach:\n";
    vector<vector<string>> result1 = groupAnagramsBySorting(arr);
    printResult(result1);

    cout << "\nGrouping Anagrams using Frequency-Count-Based Approach:\n";
    vector<vector<string>> result2 = groupAnagramsByFrequency(arr);
    printResult(result2);

    return 0;
}
