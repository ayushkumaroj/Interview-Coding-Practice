#include<iostream>
using namespace std;
#include<vector>
#include<unordered_map>
#include<algorithm>

/*
 - Time Complexity: O(N * K log K), where N is the number of strings in the input vector 'strs' and K is the maximum length of a single string.
   This is because we must iterate through all N strings (the O(N) part). For each string, we perform a sort operation, which takes O(K log K) time.
 - Space Complexity: O(N * K), where N is the number of strings and K is the average length of a string.
   This is because, in the worst case, our 'anagramGroup' map and the final 'result' vector will need to store a copy of every character from the original input list.
*/
vector<vector<string>> groupAnagramsBySorting(vector<string>& strs) {
    // Step 1: Store the total number of strings from the input vector 'strs' into a variable 'n' because we need this count to set the boundary for our loop,
    //  ensuring we iterate through every string in the list exactly once.
    int n = strs.size();
    
    // Step 2: Declare an unordered_map named 'anagramGroup' where the key is a string and the value is a vector of strings because this map is the core of
    //  our solution, allowing us to group all original words (the values) that are anagrams of each other under a single, unique key (the sorted word).
    // Note: An unordered_map (or hash map) provides very fast average-case lookups and insertions (close to O(1)) by using a hash function to compute an 
    // index for each key, making it highly efficient for grouping items.
    unordered_map<string, vector<string>> anagramGroup;

    // Step 3: Start a 'for' loop that iterates from index 'i' = 0 up to 'n' (the total number of strings) because this loop is necessary to process every single
    //  string in our input list 'strs'.
    for (int i = 0; i < n; i++) {
        // Step 4: Create a copy of the string at the current index 'i' from 'strs' and store it in a new variable named 'word' because we need this copy to hold
        //  the original, unsorted string, which is what we ultimately want to store in our results.
        string word = strs[i];

        // Sort the characters of the word to form the key
        // Step 5: Create another string variable 'sortedWord' and initialize it with the value of 'word' because this variable will be modified by sorting,
        //  and we need it to serve as the unique key for our anagram map, while 'word' remains unchanged.
        string sortedWord = word;
        // Step 6: Call the 'sort' function to rearrange all characters within the 'sortedWord' string into alphabetical order because this is the key logic: 
        // all anagrams, when sorted, will result in the exact same string (e.g., "tea" and "eat" both become "aet").
        // Note: This relies on the core property of anagrams: they are permutations of the same set of characters. Sorting provides a 'canonical' or standard 
        // representation that is identical for all words in a single anagram group.
        sort(sortedWord.begin(), sortedWord.end());
        // Group words having the same sorted key
        // Step 7: Use the 'sortedWord' (e.g., "aet") as a key to access the 'anagramGroup' map and add the original, unsorted 'word' (e.g., "tea") to the
        //  vector associated with that key because this action effectively groups all original strings that are anagrams of each other into the same list (vector)
        //  within the map.
        anagramGroup[sortedWord].push_back(word);
    }

    // Collect all groups into a result vector
    // Step 8: Declare a new vector of string vectors named 'result' because the function's required return type is a list of lists (not a map), and this
    //  variable will hold the final grouped anagrams, extracted from our map.
    vector<vector<string>> result;
    
    // Step 9: Start a range-based 'for' loop to iterate through each element (a key-value pair) in the 'anagramGroup' map because we need to extract every vector of
    //  anagrams that we've built inside the map and put them into our final 'result' list.
    // Note: The 'auto& group' syntax automatically deduces the type (a std::pair) and 'group' becomes a reference (&) to it. 'group.first' is the key (sorted word),
    //  and 'group.second' is the value (the vector of anagrams).
    for (auto& group : anagramGroup) {
        // Step 10: Add the 'value' part of the current map pair (which is 'group.second') to the end of the 'result' vector because 'group.second' is the actual 
        // vector containing a complete group of anagrams, and we are collecting all these groups into our final result list.
        result.push_back(group.second);
    }

    // Step 11: Return the 'result' vector from the function because it now contains all the separate groups of anagrams, which is the final answer the function
    //  is designed to produce.
    return result;
}

/*
 - This is a helper function to generate a unique key for a word based on its character counts.
 - Time Complexity (for getKey): O(K), where K is the length of the string 's'.
   This is because we iterate through the string once to count characters (O(K)) and then iterate a fixed 26 times to build the key (O(26)), so the total time 
   is O(K + 26), which simplifies to O(K).

 - Space Complexity (for getKey): O(1) (constant space).
   This is because the 'count' vector is always size 26 and the resulting 'key' string has a maximum length independent of K (it's based on counts, e.g., "1#2#..."),
  so the space used is fixed.
*/
string getKey(string s) {
    // Step 1: Get the size (number of characters) of the input string 's' and store it in the variable 'n' because we need this value to know how many times 
    // to loop to check every character in the string.
    int n = s.size();
    
    // Step 2: Create a vector of integers called 'count' with a fixed size of 26, and initialize all its elements to 0 because this vector will store the
    //  frequency of each letter, where index 0 is for 'a', index 1 for 'b', and so on, up to index 25 for 'z'.
    // Note: This approach assumes the input strings only contain lowercase English letters, which is a fixed set of 26 characters.
    vector<int>count(26, 0);

    // Step 3: Start a 'for' loop that will run 'n' times (once for each character in the string 's') because we need to look at every character to count 
    // its occurrences.
    for (int i = 0; i < n; i++) {
        // Step 4: Get the character at the current loop index 'i' from the string 's' and store it in a variable 'ch' because this gives us the specific 
        // character we need to count.
        char ch = s[i];
        
        // Step 5: Calculate the correct index for our 'count' vector by subtracting the character 'a' from 'ch', and then increment the value at that index by 
        // 1 because this operation converts the character into its corresponding 0-25 index (e.g., 'a' becomes 0, 'b' becomes 1) to track its frequency.
        // Note: This technique, known as ASCII subtraction, works because characters are stored as numerical ASCII values, and 'a' through 'z' are sequential.
        //  'c' - 'a' results in 2, which is the correct index for 'c'.
        count[ch - 'a'] += 1;
    }

    // Step 6: Create a new, empty string variable named 'key' because we will build a unique signature string (the key) in this variable based on the character
    //  counts we just gathered.
    string key = "";
    
    // Step 7: Start a 'for' loop that will run exactly 26 times (for indices 0 through 25) because we need to check the count for every letter of the alphabet
    // to build our complete key string.
    for (int i = 0; i < 26; i++) {
        // Step 8: Append the current count (converted to a string) followed by a '#' character to the 'key' string because this creates a unique, readable 
        // signature for the word's character makeup (e.g., "1#0#1#...").
        // Note: The '#' delimiter is extremely important. Without it, a count of "11 'a's" and "1 'b'" (key "111") would look the same as "1 'a'" and "11 'b's" 
        // (also "111"). The '#' makes the key unambiguous: "11#1#" vs "1#11#".
        key = key + to_string(count[i]) + "#";
    }
    
    // Step 9: Return the final, fully constructed 'key' string from the function because this key (e.g., "1#1#1#0...") will be used to identify all anagrams,
    //  as all anagrams will generate the exact same key.
    return key;
}


/*
 - Time Complexity: O(N * K), where N is the number of strings in the 'strs' vector and K is the maximum length of a single string.
   This is because we must iterate through all N strings in the input vector. For each string, we call the 'getKey' function, which takes O(K) time to count
   characters and build the key.

 - Space Complexity: O(N * K), where N is the number of strings and K is the average length of a string.
   This is because our 'mp' (unordered_map) and the final 'result' vector will, in the worst-case scenario, need to store a copy of every single original
   string from the input.
*/
vector<vector<string>> groupAnagrams(vector<string>& strs) {
    // Step 1: Get the total number of strings in the input vector 'strs' and store it in the variable 'n' because we need this count to set the limit for our 
    // loop, ensuring we process every string.
    int n = strs.size();
    
    // Step 2: Declare an unordered_map named 'mp' where the key is a string and the value is a vector of strings because this map will store our anagram groups,
    //  using the unique character-count key (e.g., "1#0#1#...") to group all matching original words (e.g., "eat", "tea").
    // Note: An unordered_map (or hash map) is used for its fast O(1) average time for insertions and lookups, making it very efficient for grouping items based
    //  on a key.
    unordered_map<string, vector<string>>mp;

    // Step 3: Start a 'for' loop that iterates from index 'i' = 0 up to 'n' (the total number of strings) because this loop is required to process each string
    //  from the input vector 'strs' one by one.
    for (int i = 0; i < n; i++) {
        // Step 4: Create a copy of the string at the current index 'i' and store it in a variable named 'word' because this variable holds the original, unsorted
        //  word (like "eat") that we want to store in our map.
        string word = strs[i];
        
        // Step 5: Call the 'getKey' helper function, passing it the 'word', and store the returned unique key string in a variable named 'key' because this
        //  'key' (e.g., "1#1#1#0...") represents the character signature of the word.
        string key = getKey(word);
        
        // Step 6: Use the 'key' to find the matching vector in the 'mp' (map) and add the original 'word' to that vector because this is the main grouping
        //  step, where all words that produce the same key are collected into the same list.
        mp[key].push_back(word);
    }

    // Step 7: Declare a new vector of string vectors named 'result' because this variable will hold our final output, as the function needs to return a list of
    //  lists, not a map.
    vector<vector<string>>result;
    
    // Step 8: Start a range-based 'for' loop to iterate through every key-value pair (named 'it') in our map 'mp' because we need to extract all the grouped
    //  vectors from the map and put them into our 'result' list.
    // Note: 'it' is a pair; 'it.first' would be the key (e.g., "1#1#1#0..."), and 'it.second' is the value (the vector<string> containing "eat", "tea", etc.).
    for (auto it : mp) {
        // Step 9: Add the 'value' part of the current map pair (which is 'it.second') to the end of our 'result' vector because 'it.second' is the complete
        //  vector of anagrams for one group, and we are collecting all these groups.
        result.push_back(it.second);
    }
    
    // Step 10: Return the 'result' vector from the function because it now contains all the grouped anagrams as a list of lists, which is the final answer.
    return result;
}

int main() {
    // Step 1: Create a vector of strings as input because we need test data to check how our anagram grouping functions perform.
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};

    // Step 2: Call the 'groupAnagramsBySorting' function using the input vector 'strs'
    // because we want to test the grouping logic that uses sorting as the key generation approach.
    vector<vector<string>> resultBySorting = groupAnagramsBySorting(strs);

    // Step 3: Print the grouped anagrams obtained from the sorting-based method because this helps us verify that all anagrams are correctly grouped.
    cout << "Grouped Anagrams using Sorting:" << endl;
    for (auto group : resultBySorting) {
        cout << "[ ";
        for (auto word : group) {
            cout << word << " ";
        }
        cout << "]" << endl;
    }

    cout << endl; // Add spacing for clarity in console output

    // Step 4: Call the 'groupAnagrams' function using the same input vector 'strs'
    // because we also want to test the grouping logic that uses frequency-based keys generated by the 'getKey' function.
    vector<vector<string>> resultByCount = groupAnagrams(strs);

    // Step 5: Print the grouped anagrams obtained from the character-count-based method
    // because this lets us compare the results between both implementations.
    cout << "Grouped Anagrams using Character Count (getKey):" << endl;
    for (auto group : resultByCount) {
        cout << "[ ";
        for (auto word : group) {
            cout << word << " ";
        }
        cout << "]" << endl;
    }

    // Step 6: Return 0 from main because returning 0 indicates that the program ran successfully.
    return 0;
}
