#include<iostream>
using namespace std;
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<queue>


/*
- Time Complexity: O(N), where N is the length of the input string 's'.This is because the function performs three main steps: 1) It iterates through the 
  N characters of 's' to count frequencies,which is O(N). 2) It sorts a frequency vector, but this vector has a fixed size of 123 (for the ASCII character set),
  so the sort time is constant (O(123 * log 123)) and does not depend on N. 3) It builds the final string, which involves appending a total of N characters,
 taking O(N) time. The dominant factor is N, so the total time is O(N).

- Space Complexity: O(1) (constant auxiliary space).
 This is because the 'vec' vector used to store frequencies always has a fixed size of 123, regardless of the length of the input string 's'. The space 
used for the output 'result' string (which can be O(N)) is typically not counted in auxiliary space complexity.
*/

string frequencySortBySorting(string s) {
    // Step 1: Create a type alias 'P' for 'pair<char, int>' because this makes the code shorter and more readable, allowing us to write 'P' instead of the
    //  longer 'pair<char, int>' when defining our vector.
    typedef pair<char, int> P;
    
    // Step 2: Create a vector named 'vec' of size 123, containing our 'P' pairs, because this vector will act as a frequency map, using a character's ASCII 
    // value as a direct index to store its count.
    // Note: A size of 123 (indices 0-122) is chosen as a safe upper bound to cover all standard lowercase ('a' is 97) and uppercase ('A' is 65) letters, 
    // as well as digits and symbols.
    vector<P>vec(123);

    // Step 3: Start a range-based 'for' loop to iterate through each character 'ch' in the input string 's' because we need to examine every single character
    //  to count its total occurrences.
    for (char &ch : s) {
        // Step 4: Access the pair at the index 'ch' in our vector (e.g., 'a' accesses index 97) and get its current frequency count (the .second value) because
        //  we need to know the old count before we can increment it.
        int freq = vec[ch].second;
        
        // Step 5: Update the pair at the character's index 'ch' by storing the character itself in the .first field and the new incremented frequency (freq + 1)
        //  in the .second field because this tracks both the character and its updated count.
        // Note: We must store the character 'ch' in .first, because after we sort the vector, the index 'i' will no longer correspond to the character's ASCII 
        // value, so we need 'vec[i].first' to know what character it is.
        vec[ch] = {ch, freq + 1};
    }

    // Step 6: Define a lambda function named 'lambda' that will be used by the 'sort' algorithm to compare two pairs (p1 and p2) because we need to provide custom
    //  sorting logic that is not alphabetical.
    // Note: A lambda function is a small, inline function defined right where it's needed, which is perfect for custom comparators for algorithms like 'sort'.
    auto lambda = [&](P &p1, P &p2) {
        // Step 7: Return true if the frequency (p1.second) of the first pair is greater than the frequency (p2.second) of the second pair because this comparison
        //  rule will force the 'sort' function to arrange the pairs in descending order (highest frequency first).
        return p1.second > p2.second;
    };

    // Step 8: Call the standard 'sort' function to reorder the entire 'vec' from its beginning to its end, using our custom 'lambda' function as the comparison
    //  rule because this is the core step that arranges all the character pairs from most frequent to least frequent.
    sort(vec.begin(), vec.end(), lambda);

    // Step 9: Initialize an empty string variable named 'result' because this is where we will build our final sorted output string by adding character groups
    //  one by one.
    string result = "";
    
    // Step 10: Start a 'for' loop that iterates from index 0 to 122 because we need to loop through our *now sorted* 'vec' to find all the characters that 
    // actually appeared in the string.
    for (int i = 0; i <= 122; i++) {
        // Step 11: Check if the frequency (.second) of the pair at the current sorted index 'i' is greater than 0 because this allows us to process only the 
        // characters that were actually in the input string and skip the dozens of unused characters that still have a count of 0.
        if (vec[i].second > 0) {
            // Step 12: Get the character (the .first element) from the pair at index 'i' because this is the actual character (e.g., 'e') that we need to append.
            char ch = vec[i].first;
            
            // Step 13: Get the frequency (the .second element) from the pair at index 'i' because this tells us exactly how many times we need to append the
            //  character 'ch'.
            int freq = vec[i].second;
            
            // Step 14: Create a temporary string 'temp' that consists of the character 'ch' repeated 'freq' times because this is the C++ constructor to 
            // efficiently create a string like "aaaa" from a character 'a' and a count of 4.
            // Note: The 'string(count, char)' constructor is a standard C++ feature that builds a new string by repeating a given character a specified number
            //  of times.
            string temp = string(freq, ch);
            
            // Step 15: Append the 'temp' string (e.g., "aaaa") to the end of our 'result' string because this adds the full group of the current character
            //  to our final output, maintaining the order from most frequent to least frequent.
            result = result + temp;
        }
    }
    // Step 16: Return the completed 'result' string from the function because it now contains all the original characters, but sorted by their frequency
    //  in descending order.
    return result;
}


/*
- Time Complexity: O(N + U log U), where N is the length of the input string 's' and U is the number of unique characters in 's'.
  This is because we iterate through N characters to build the frequency map (O(N)), then push U unique characters onto the priority queue (O(U log U)), 
  and finally pop U items and build the string. This last step involves O(U log U) for the pop operations and O(N) total time for appending all characters
  to the result string.

 Space Complexity: O(U), where U is the number of unique characters.
 This is because both the 'mp' (unordered_map) and the 'pq' (priority_queue) will store at most U elements, one for each unique character. 
 If the character set is fixed (e.g., ASCII, size 128), this can be considered O(1) constant space.

*/ 
string frequencySortByHeap(string s) {
    // Step 1: Create a type alias 'P' for 'pair<char, int>' because this is a shorthand to make the code cleaner and easier to read, allowing us to 
    // type 'P' instead of the longer 'pair<char, int>' when dealing with our character-frequency pairs.
    typedef pair<char, int> P;

    // Step 2: Define a custom comparator structure named 'lambda' because a standard priority queue needs a rule to compare elements, and we want to order 
    // our pairs based on their frequency (the integer).
    struct lambda {
        // Step 3: Overload the 'operator()' (the function call operator) inside our struct because this is the specific function that the priority_queue
        //  will call to compare two elements (p1 and p2).
        bool operator()(P &p1, P &p2) {
            // Step 4: Return 'true' if the frequency of the first pair (p1.second) is *less than* the frequency of the second pair (p2.second) because 
            // this comparison rule creates a max-heap, which ensures the pair with the highest frequency (the largest .second value) will always be at 
            // the 'top' of the queue.
            return p1.second < p2.second;
        }
    };

    // Step 5: Declare a priority queue named 'pq' that stores our 'P' pairs, uses a 'vector<P>' as its internal container, and uses our 'lambda' struct
    //  as its comparison logic because this data structure will automatically keep the most frequent character-pair at the top, ready for us to access.
    // Note: A priority_queue (or heap) is a data structure that is perfect for this task, as it provides very fast access to the maximum element (O(1)) and
    //  efficient insertion and removal (O(log U), where U is the number of items in the queue).
    priority_queue<P, vector<P>, lambda> pq;

    // Step 6: Declare an unordered_map named 'mp' with a character key and an integer value because we need an efficient way to count the occurrences (frequency)
    //  of each character in the input string 's'.
    // Note: An unordered_map (or hash map) provides an average-case time of O(1) for insertions and lookups, making it the ideal choice for quickly counting
    //  character frequencies.
    unordered_map<char, int> mp;
    
    // Step 7: Start a range-based 'for' loop to iterate through every character 'ch' in the input string 's' because we must examine every character to
    //  create a complete frequency count.
    for (char &ch : s) {
        // Step 8: Use the character 'ch' as a key in our map 'mp' and increment its associated value (the count) by one because this action builds our
        //  frequency table. If 'ch' is not in the map, it's added with a value of 1.
        mp[ch]++;
    }

    // Step 9: Start a range-based 'for' loop to iterate through every key-value pair 'it' in our completed frequency map 'mp' because we now need to
    //  transfer this frequency data into our priority queue.
    for (auto &it : mp) {
        // Step 10: Push a new pair, created from the map's key (it.first, the character) and value (it.second, the frequency), onto the priority queue 'pq'
        //  because this adds the pair to the heap, which will automatically position it based on its frequency according to our 'lambda' rule.
        pq.push({it.first, it.second});
    }

    // Step 11: Initialize an empty string variable named 'result' because this is where we will construct our final sorted string, character by character.
    string result = "";

    // Step 12: Start a 'while' loop that continues to run as long as the priority queue 'pq' is not empty because we need to pull every character group out 
    // of the heap until it's been fully drained.
    while (!pq.empty()) {
        // Step 13: Get the pair 'P' from the very top of the priority queue and copy it into a 'temp' variable because 'pq.top()' always gives us the element
        //  with the highest frequency, which is exactly what we need next.
        P temp = pq.top();
        
        // Step 14: Remove the top element from the priority queue 'pq' because we have now retrieved this pair and are done with it, allowing the heap to
        //  rearrange itself so the next most frequent item moves to the top.
        pq.pop();
        
        // Step 15: Create a temporary string by repeating the character (temp.first) 'temp.second' (frequency) times, and append this new string to our 'result'
        //  because this is how we build the final output, adding the most frequent characters first.
        // Note: The 'string(count, char)' constructor is a standard C++ function that efficiently builds a string by repeating a specific character a given
        //  number of times.
        result += string(temp.second, temp.first);
    }
    
    // Step 16: Return the completed 'result' string from the function because it now holds all the original characters, but sorted in descending order based
    //  on how frequently they appeared.
    return result;
}

int main() {
    // Step 1: Declare a string 's' and initialize it with a sample value
    // because we need a test input to verify both sorting-based and heap-based frequency sort functions.
    string s = "tree";

    // Step 2: Print the original string before sorting for reference.
    cout << "Original String: " << s << endl << endl;

    // Step 3: Call the 'frequencySortBySorting' function and store its result in 'sortedBySort'
    // because we want to see how the string is rearranged when sorted by frequency using sorting logic.
    string sortedBySort = frequencySortBySorting(s);

    // Step 4: Print the result from 'frequencySortBySorting' because it helps us verify the correctness of that approach.
    cout << "Output using Sorting Method:" << endl;
    cout << sortedBySort << endl << endl;

    // Step 5: Call the 'frequencySortByHeap' function and store its result in 'sortedByHeap'
    // because we want to test the heap-based frequency sorting method.
    string sortedByHeap = frequencySortByHeap(s);

    // Step 6: Print the result from 'frequencySortByHeap' because it helps compare the two different algorithms’ outputs.
    cout << "Output using Heap Method:" << endl;
    cout << sortedByHeap << endl << endl;

    // Step 7: Return 0 from 'main' to indicate successful execution.
    return 0;
}



