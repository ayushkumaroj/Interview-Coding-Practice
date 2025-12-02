#include<iostream>
using namespace std;
#include<vector>
#include<queue>

// Overall Time: O(n), where 'n' is the length of the word, because we loop through the word 'n' times to count, and then we loop 'n' times again in 
// total to place all the letters into the new word.
// Overall Space: O(n), because we create a 'result' word that is the same size 'n' as the input word (The 'count' list is O(1) because it's always size 26).
string reorganizeString_UsingFrequencyPlacement(string s) {
    // Step 1: Get the length of the input word and save it in 'n' because we need this number to know how many letters there are and to calculate the allowed limit.
    int n = s.length();
    // Step 2: Calculate the *most* times any single letter is allowed to appear because if a letter appears more than this, we can't put other letters in between 
    // them to separate them.
    // Note: The formula (n + 1) / 2 handles both even and odd lengths. For n=5, max is 3 ("ababa"). For n=4, max is 2 ("abab").
    int maxAllowed = (n + 1) / 2;  // pre-calculate once
    // Step 3: Create a list of 26 zeros, one for each letter from 'a' to 'z' because we need a place to store how many times we see each letter.
    vector<int> count(26, 0);
    // Step 4: Create a variable 'maxFreq' and set it to 0 because we need to keep track of the *highest count* we have found so far.
    int maxFreq = 0;
    // Step 5: Create a variable 'maxFreqCh' to hold a letter because we need to remember *which letter* has the highest count (we set it to 'a' just to start).
    char maxFreqCh = 'a';

    // Step 6: Count frequency of each character and find the most frequent one
    // Step 7: Start a loop to look at every single letter in the input word 's' because we need to count all the letters and find the most common one.
    for (int i = 0; i < n; i++) {
        // Step 8: Get the current letter we are looking at because we are processing this one letter in this loop turn.
        char ch = s[i];
        // Step 9: Find the position for this letter in our count list (0-25) because 'a' - 'a' is 0, 'b' - 'a' is 1, etc. This turns the letter into a number
        //  we can use as a list position.
        // Note: This is a common formula to change a lowercase letter into a list position (index).
        int index = ch - 'a';
        // Step 10: Add 1 to the count for that letter's position because we have seen this letter one more time.
        count[index]++;
        // Step 11: Update max frequency and character
        // Step 12: Check if this letter's new count is bigger than the biggest count we've seen because if it is, we need to update our 'max' variables.
        if (count[index] > maxFreq) {
            // Step 13: Update 'maxFreq' to this new, higher count because this is now the biggest count we have found.
            maxFreq = count[index];
            // Step 14: Update 'maxFreqCh' to remember *this* letter because this letter is now the most common one.
            maxFreqCh = ch;
        }
        // Step 15: If any character count exceeds limit, not possible
        // Step 16: Check if this letter's count is now *more* than the 'maxAllowed' limit because if it is, the problem is impossible to solve (e.g., "aaab").
        if (count[index] > maxAllowed) {
            // Step 17: Stop the function right away and send back an empty word because we found one letter appears too many times, so no solution is possible.
            return "";
        }
    }

    // Step 18: Create a new word 'result' (as a copy of 's') because this is where we will build our final rearranged answer. We make it the same size so we
    //  can place letters at specific positions.
    string result = s;
    // Step 19: Create a position marker 'index' and set it to 0 because we will start placing letters at the very beginning (position 0) of the 'result' word.
    int index = 0;

    // Step 20: Place the most frequent character at even indices (0, 2, 4, ...)
    // Step 21: Start a loop that keeps running as long as we still have letters of the 'maxFreqCh' type left to place because we need to place all of this
    // most common letter *first* to spread it out.
    while (count[maxFreqCh - 'a'] > 0) {
        // Step 22: Put the most common letter at the current 'index' position in our 'result' word because this is the first spot in our "every-other-spot" 
        // placement plan.
        result[index] = maxFreqCh;
        // Step 23: Move the 'index' marker forward by 2 steps (to 0, 2, 4, ...) because this leaves an empty spot (like 1, 3, 5, ...) in between each letter, 
        // which is the whole point.
        index += 2;
        
        // Step 24: Lower the count for this letter by 1 because we just used one of these letters, so we have one less to place.
        count[maxFreqCh - 'a']--;
    }

    // Step 25: Place remaining characters
    // Step 26: Start a loop that goes through every possible letter from 'a' to 'z' because we need to place all the *other* letters that are left.
    for (char ch = 'a'; ch <= 'z'; ch++) {
        // Step 27: Start an inner loop that runs as long as the current letter 'ch' still has a count greater than 0 because we need to place *all* copies of 
        // this letter.
        while (count[ch - 'a'] > 0) {
            // Step 28: Check if our marker 'index' has gone past the end of the word because if it has, it means we filled all the even spots (0, 2, 4...) 
            // and now we must "wrap around" to fill the odd spots (1, 3, 5...).
            if (index >= n) {
                // Step 29: Set the marker 'index' to 1 (the first *odd* spot) because this is where we start filling the "in-between" gaps.
                index = 1;
            }
            // Step 30: Put the current letter 'ch' at the current 'index' position because this is the next available spot (either a remaining even 
            // spot or an odd spot).
            result[index] = ch;
            // Step 31: Move the 'index' marker forward by 2 steps again because we are still placing letters in every-other-spot (e.g., 1, 3, 5...).
            index += 2;
            // Step 32: Lower the count for this letter 'ch' by 1 because we just placed one of them.
            count[ch - 'a']--;
        }
    }

    // Step 33: Send back the final 'result' word because it now contains all the letters, rearranged so no two same letters are next to each other.
    return result;
}


// Overall Time: O(n), where 'n' is the length of the word, because we look at all 'n' letters to count them, and then we build and pull each of the
//  'n' letters from the heap.Each heap action (push/pop) is O(log 26), which is a small, constant time (so we treat it as O(1)).
// Overall Space: O(n), // because we have to build a new 'result' word that will hold all 'n' letters. 
// (The 'count' list and heap are tiny and constant size, so they don't grow with 'n').
string reorganizeString_UsingMaxHeap(string s) {
    // Step 1: Get the length of the input word and save it in 'n'
    // because we need this number to know how many letters there are and to calculate the allowed limit.
    int n = s.length();
    // Step 2: Calculate the *most* times any single letter is allowed to appear
    // because if a letter appears more than this, it's impossible to separate them (e.g., "aaab").
    // Note: The formula (n + 1) / 2 handles both even (n=4, max=2) and odd (n=5, max=3) lengths.
    int maxAllowed = (n + 1) / 2; // pre-calculate once
    // Step 3: Create a list of 26 zeros, one for each letter from 'a' to 'z'
    // because we need a place to store how many times we see each letter.
    
    vector<int> count(26, 0);
    // Step 4: Count frequency of each character
    // Step 5: Start a loop to look at every single letter in the input word 's'
    // because we need to count all the letters and check if any letter appears too many times.
    for (int i = 0; i < n; i++) {
        // Step 6: Get the current letter we are looking at
        // because we are processing this one letter in this loop turn.
        char ch = s[i];
        // Step 7: Find the position for this letter in our count list (0-25)
        // because 'a' - 'a' is 0, 'b' - 'a' is 1, etc. This turns the letter into a number we can use as a list position.
        // Note: This is a common formula to change a lowercase letter into a list position (index).
        int index = ch - 'a';
        // Step 8: Add 1 to the count for that letter's position
        // because we have seen this letter one more time.
        count[index]++;
        // Step 9: If any character occurs more than allowed, not possible
        // Step 10: Check if this letter's count is now *more* than the 'maxAllowed' limit
        // because if it is, the problem is impossible to solve, so we must stop early.
        if (count[index] > maxAllowed) {
            // Step 11: Stop the function right away and send back an empty word
            // because we found one letter appears too many times, so no solution is possible.
            return "";
        }
    }

    // Step 12: Create max heap (priority queue)
    // Step 13: Create a new short name 'P' for a pair (number, letter)
    // because this makes the code easier to read than typing `pair<int, char>` every time.
    typedef pair<int, char> P;
    // Step 14: Create a max heap (priority queue) that will store our pairs ('P')
    // because a max heap will always keep the pair with the *biggest count* (the 'int') at the very top, ready to be picked.
    priority_queue<P, vector<P>> pq;

    // Step 15: Start a loop that goes from 0 to 25 (one for each spot in our 'count' list)
    // because we need to check every letter of the alphabet to see if we have any counts for it.
    for (int i = 0; i < 26; i++) {
        // Step 16: Check if the count for the current letter is greater than 0
        // because we only want to add letters to our heap if they actually appeared in the word.
        if (count[i] > 0) {
            // Step 17: Turn the number 'i' back into its letter (0 becomes 'a', 1 becomes 'b')
            // because we need to store the actual letter, not just its list position.
            // Note: Concept: 'a' + i is the reverse of `ch - 'a'`. It converts an index back to a char.
            char ch = 'a' + i;
            
            // Step 18: Add the (count, letter) pair into the max heap
            // because the heap will automatically put this pair in the correct place based on its count.
            pq.push(P(count[i], ch)); // Push pair (count, character)
        }
    }

    // Step 19: Create an empty word 'result'
    // because this is where we will build our final rearranged answer, one letter at a time.
    string result = "";

    // Step 20: Pick two most frequent characters at a time
    // Step 21: Start a loop that keeps running as long as the heap has 2 or more letters in it
    // because the main idea is to always pick the *two* most common letters and add them to the word.
    while (pq.size() >= 2) {
        // Step 22: Get the pair with the *highest* count from the top of the heap
        // because this is the most common letter we have right now.
        P first = pq.top();
        // Step 23: Remove this pair from the heap
        // because we are about to use it, so it's no longer in the heap.
        pq.pop();
        // Step 24: Get the pair with the *next highest* count from the top of the heap
        // because this is the second most common letter we have.
        P second = pq.top();
        // Step 25: Remove this second pair from the heap
        // because we are also using this one right now.
        pq.pop();

        // Step 26: Add the letter from the *first* pair to our 'result' word
        // because we are adding the most common letter to our answer.
        result += first.second;
        // Step 27: Add the letter from the *second* pair to our 'result' word
        // because by adding these two different letters one after another, we know they are not the same.
        result += second.second;

        // Step 28: Lower the count of the first pair by 1
        // because we just used one of its letters.
        first.first--;
        // Step 29: Lower the count of the second pair by 1
        // because we just used one of its letters.
        second.first--;

        // Step 30: Check if the first pair *still* has letters left to use (count > 0)
        // because if it does, we need to put it back in the heap to be used again later.
        if (first.first > 0) {
            // Step 31: Push the first pair (with its new, smaller count) back into the heap
            // because it will now be sorted again based on its new count.
            pq.push(first);
        }
        // Step 32: Check if the second pair *still* has letters left to use (count > 0)
        // because if it does, we also need to put it back in the heap.
        if (second.first > 0) {
            // Step 33: Push the second pair (with its new, smaller count) back into the heap
            // because it will be sorted again based on its new count.
            pq.push(second);
        }
    }

    // Step 34: Add last remaining character (if any)
    // Step 35: Check if the heap is *not* empty (meaning one letter is left)
    // because after the loop, we might have one last letter left over that couldn't be paired.
    if (!pq.empty()) {
        // Step 36: Add that last letter to the end of the 'result' word
        // because this is the final letter, and it's guaranteed to be different from the one before it (which was 'second.second' in the last loop).
        result += pq.top().second;
    }

    // Step 37: Send back the final 'result' word
    // because it now contains all the letters, rearranged so no two same letters are next to each other.
    return result;
}

int main() {
    string s = "aab";
    
    cout << "Using Max Heap: " << reorganizeString_UsingMaxHeap(s) << endl;
    cout << "Using Frequency Placement: " << reorganizeString_UsingFrequencyPlacement(s) << endl;

    return 0;
}
