#include <iostream>
#include <vector>
#include <string>
using namespace std;
#include<algorithm>

// Overall Time: O(min(len1, len2)) because in the worst case, we check every letter up to the end of the shorter string.
// Overall Space: O(min(len1, len2)) because we create a new string to store the common part, which can be as long as the shorter string.
string getCommonPart(string first, string second) {
    // Step 1: Get the length of the first word and save it in 'len1'
    // because we need to know where this word ends so our check does not go too far.
    int len1 = first.length();
    // Step 2: Get the length of the second word and save it in 'len2'
    // because we need to know where this second word ends so our check does not go too far.
    int len2 = second.length();

    // Step 3: Create a counter 'i' and set it to 0
    // because this will help us look at each letter of the first word, starting from the beginning (position 0).
    int i = 0;
    // Step 4: Create a counter 'j' and set it to 0
    // because this will help us look at each letter of the second word, starting from the beginning (position 0).
    int j = 0;

    // Step 5: Start a loop that keeps running as long as 'i' is inside the first word AND 'j' is inside the second word
    // because we need to compare letters from both words, and we must stop if we reach the end of either word.
    while (i < len1 && j < len2) {
        // Step 6: Check if the letter from the first word (at position 'i') is NOT the same as the letter from the second word (at position 'j')
        // because if the letters are different, it means the common part has ended.
        if (first[i] != second[j]) {
            // Step 7: Stop the loop right away
            // because we found the first different letter, so there are no more common letters to check.
            break;
        }
        // Step 8: Move to the next letter in the first word by adding 1 to 'i'
        // because the letters at 'i' and 'j' were the same, so now we need to check the *next* pair of letters.
        i++;
        // Step 9: Move to the next letter in the second word by adding 1 to 'j'
        // because the letters at 'i' and 'j' were the same, so now we need to check the *next* pair of letters.
        j++;
    }

    // Step 10: Create a new word 'commonPart' by cutting a piece from the 'first' word
    // because 'i' stopped at the *end* of the common part, so we need to get all letters from the start (position 0) up to (but not including) position 'i'.
    // Note: The 'substr(start, length)' concept is used here. substr(0, i) means "start at position 0 and take 'i' letters".
    string commonPart = first.substr(0, i);
    
    // Step 11: Send back the 'commonPart' as the answer from this function
    // because this new word is the piece that was the same at the start of both 'first' and 'second'.
    return commonPart;
}


/*
- Overall Time: O(n * m), where 'n' is the number of words in the list and 'm' is the length of the longest word.
because we loop through all 'n' words, and for each word, we might compare up to 'm' letters in the worst case.
- Overall Space: O(m), where 'm' is the length of the *final answer* (the longest common prefix).
because we need to store that answer string (this does not count the input list).
*/
string longestCommonPrefix_ByComparingEachString(vector<string>& strs) {
    // Step 1: Get the total number of words in the list and save it in 'n'
    // because we need to know if the list is empty and how many times we need to loop.
    int n = strs.size();

    // Step 2: Check if the number of words 'n' is less than 1 (meaning the list is empty)
    // because if the list is empty, there is no common part, so we must stop.
    if (n < 1) {
        // Step 3: Send back an empty word "" 
        // because an empty list has no words, so the common starting part is just "empty".
        return "";
    }

    // Step 4: Create a variable 'commonPart' and set it to be the *first word* in the list (at position 0)
    // because we need to start with something, so we guess that the *whole first word* is the answer, and then we will check it against all the other words.
    string commonPart = strs[0];

    // Step 5: Start a loop that goes from the *second* word (at position 1) to the end of the list
    // because we already used the first word (at position 0) as our starting guess, so now we must compare it to every *other* word.
    for (int i = 1; i < n; i++) {
        // Step 6: Call the helper function 'getCommonPart' to find what's common between our *current* 'commonPart' and the *next word* in the list (strs[i])
        // because we need to find the part that is common to *all* words. This line updates 'commonPart' to be only the piece that matches *both* the old 'commonPart'
        //  and the new word.
        commonPart = getCommonPart(commonPart, strs[i]);
        // Step 7: Check if the 'commonPart' has become an empty word ""
        // because if 'commonPart' is empty, it means we found a word that has *nothing* in common with the others, so the final answer must be empty.
        if (commonPart == "") {   
            // Step 8: Stop the loop early
            // because if the common part is already empty, there is no need to check the rest of the words. The answer will not get any longer.
            break;
        }
    }
    // Step 9: Send back the final 'commonPart' that is left after checking all the words
    // because this variable now holds the starting piece that was common to *every single word* in the list.
    return commonPart;
}

// Overall Time: O(n) where 'n' is the number of words in the list ,because we have to look at every word one time to find its length.
// Overall Space: O(1), because we only use a few simple variables to store numbers, not new lists or words.
int findMinLenString(vector<string>& strs) {
    // Step 1: Get the total number of words in the list and save it in 'n'
    // because we need to know how many words we have to check in our loop.
    int n = strs.size();
    // Step 2: Get the length of the *first* word and guess that it is the smallest length
    // because we need to start with some length to compare all the other lengths against.
    int minLen = strs[0].length();

    // Step 3: Start a loop that looks at every *other* word, starting from the second word (at position 1)
    // because we already used the first word as our starting guess, so now we check all the rest.
    for (int i = 1; i < n; i++) {   
        // Step 4: Check if our current smallest length ('minLen') is *bigger* than the length of the current word we are looking at (strs[i])
        // because if we find a word that is even shorter, we need to update our smallest length.
        if (minLen > strs[i].length()) {
            // Step 5: Update 'minLen' to be this new, smaller length
            // because we just found a shorter word, so this is the new "smallest length so far".
            minLen = strs[i].length();
        }
    }
    
    // Step 6: Send back the final 'minLen' value after checking all the words, because this number is the smallest length we found in the entire list.
    return minLen;
}


// Overall Time: O(n * m), where 'n' is the number of words and 'm' is the length of the *shortest* word.
// because for each letter ('m' times), we must check that same letter in every single word ('n' times).
// Overall Space: O(m), where 'm' is the length of the final common part (the answer).
// because we need to build and store the 'result' word, which can grow up to 'm' letters long.
string longestCommonPrefix_ByCheckingEachChar(vector<string>& strs) {
    // Step 1: Get the total number of words in the list and save it in 'n', 
    int n = strs.size();

    // Step 2: Check if the number of words 'n' is 0 or less (meaning the list is empty), because if the list is empty, there is no common part, so we must stop.
    if (n <= 0) {
        // Step 3: Send back an empty word "" , because an empty list has no words, so the common starting part is just "empty".
        return "";
    }

    // Step 4: Call the helper function 'findMinLenString' to find the length of the shortest word in the list
    // because the common part cannot be *longer* than the shortest word, so we only need to check up to that length.
    int minLen = findMinLenString(strs);
    
    // Step 5: Create an empty word 'result' , because we will build our answer by adding one matching letter at a time to this word.
    string result = "";

    // Step 6: Start a loop that checks each *letter position* (or column), from the start (position 0) up to the shortest length ('minLen')
    // because we are checking one letter *position* at a time across all the words.
    for (int i = 0; i < minLen; i++) {
        // Step 7: Get the letter at the current position 'i' from the *first word* (strs[0])
        // because we need to use this letter as the "test" letter to compare against all other words at the same position.
        char currentChar = strs[0][i];
        
        // Step 8: Create a flag 'allMatch' and set it to true
        // because we will *assume* all words match at this position, and we will set this to false if we find even one word that does not match.
        bool allMatch = true;

        // Step 9: Start an inner loop that checks every *other* word, starting from the second word (at position 1)
        // because we need to see if the letter at position 'i' in *every other word* is the same as our 'currentChar'.
        for (int j = 1; j < n; j++) {
            
            // Step 10: Check if the letter in the current word (strs[j]) at position 'i' is NOT the same as our 'currentChar'
            // because if we find a mismatch, it means the common part has ended.
            if (strs[j][i] != currentChar) { 
                // Step 11: Set the 'allMatch' flag to false, because we found a letter that did not match, so not all words match at this position.
                allMatch = false;       
                // Step 12: Stop this *inner* loop (the 'j' loop) right away
                // because we already found one mismatch, so we do not need to check the rest of the words at this position.
                break;
            }
        }

        // Step 13: After checking all words for position 'i', check if the 'allMatch' flag is *still* true
        // because if it is true, it means *every* word had the same letter at this position.
        if (allMatch) {   
            // Step 14: Add the 'currentChar' to the end of our 'result' word, because this letter is common to all words, so it is part of our answer.
            // Note: The 'result += char' concept means "add this one letter to the end of the existing word."
            result += currentChar;
        } else {
            // Step 15: If the 'allMatch' flag is false, because this means we found a mismatch at position 'i', so the common part has ended.
            break;
        }
    }

    // Step 16: Send back the final 'result' word, because this word contains all the letters that matched across all words from the beginning.
    return result;
}


// Overall Time: O(n * (high - low)), where 'n' is the number of words, because we loop 'n' times, and for each word, we check (high - low + 1) letters.
// Overall Space: O(1), because we only use a few simple variables and a reference to a word.
bool allHaveSameprefix(vector<string>& strs, int low, int high) {
    // Step 1: Get the total number of words in the list and save it in 'n', because we need to know how many words we have to check in our loop.
    int n = strs.size();
    
    // Step 2: Get the *first word* from the list and save it in 'firstWord',because we will use its letters as the "test" letters to compare all other words against.
    string firstWord = strs[0];

    // Step 3: Start a loop that checks *every* word in the list, starting from the first one (at position 0)
    // because we must confirm that *all* words have the exact same letters in the part we are checking.
    for (int i = 0; i < n; i++) {
        // Step 4: Start an inner loop that checks each *letter position*, starting from 'low' and ending at 'high'
        // because this is the specific *part* (or "chunk") of the word we need to test.
        for (int j = low; j <= high; j++) {  
            // Step 5: Check if the letter in the current word (strs[i]) at position 'j' is NOT the same as the letter in the 'firstWord' at the *same* position 'j'
            // because if even one letter is different, the words do not match in this part.
            if (strs[i][j] != firstWord[j]) {
                // Step 6: Stop everything and send back 'false' (meaning "no, they do not all match")
                // because we found one mismatch, so we know this part is not common to all words.
                return false;
            }
        }
    }
    
    // Step 7:[ If the loops finish without finding *any* mismatches, send back 'true'
    // because] this means every single word matched the 'firstWord' perfectly in the part from 'low' to 'high'.
    return true;
}


// Overall Time: O(n * m * log(m)), where 'n' is the number of words and 'm' is the shortest word's length.
// because the 'while' loop runs log(m) times, and inside it, 'allHaveSameprefix' takes O(n*m) time in the worst case.
// Overall Space: O(m), because we need to build and store the 'result' word, which can be up to 'm' letters long.
string longestCommonPrefix_ByBinarySearch(vector<string>& strs) {
    // Step 1: Get the total number of words in the list and save it in 'n', because we need to check if the list is empty.
    int n = strs.size();
    // Step 2: Check if the number of words 'n' is 0 or less (meaning the list is empty), because if the list is empty, there is no common part, so we must stop.
    if (n <= 0) {
        // Step 3: Send back an empty word "", because an empty list has no words, so the common starting part is just "empty".
        return "";
    }

    // Step 4: Call the helper function 'findMinLenString' to find the length of the *shortest* word
    // because the common part cannot be longer than the shortest word in the list.
    int minLen = findMinLenString(strs);
    // Step 5: Create an empty word 'result', because this is where we will add the matching parts of the prefix as we find them.
    string result = "";
    // Step 6: Create a variable 'low' and set it to 0, because this is the *starting* letter position (index 0) of the part we are searching.
    int low = 0;
    // Step 7: Create a variable 'high' and set it to the *last* possible letter position (minLen - 1)
    // because this is the *ending* position of the part we are searching.
    int high = minLen - 1;

    // Step 8: Start a loop that keeps running as long as 'low' is not past 'high'
    // because this is the main part of the binary search, which keeps "guessing" and shrinking the search area.
    while (low <= high) {  
        // Step 9: Find the *middle* position between 'low' and 'high', because this is our "test" position to see if the prefix is common up to this point.
        // Note: This is the standard formula for finding the middle in a binary search.
        int mid = (low + high) / 2;
        // Step 10: Call the helper function to check if *all* words have the *same letters* in the part from 'low' to 'mid'
        // because we need to know if this specific chunk of letters is common to all words.
        if (allHaveSameprefix(strs, low, mid)) {
            // Step 11: If they *do* match, cut out that matching part (from 'low' to 'mid') from the first word and add it to our 'result'
            // because this part is confirmed to be common, so it belongs in our final answer.
            // Note: 'substr(start, length)' is used. The length is (mid - low + 1) to include the letter at 'mid'.
            result += strs[0].substr(low, mid - low + 1);
            // Step 12: Move 'low' to be one position *after* 'mid'
            // because we already checked and saved the part up to 'mid', so now we must search the *next* part (the right side).
            low = mid + 1;
            
        } else {
            // Step 13: If the words did *not* match in the 'low' to 'mid' part, because this means the common prefix must have ended *before* 'mid'.
            // Step 14: Move 'high' to be one position *before* 'mid', because we need to search for a smaller, working prefix in the *left side* of
            //  our current chunk.
            high = mid - 1;
        }
    }
    // Step 15: Send back the final 'result' word, because this word now contains all the matching parts we found and added together, 
    // which forms the longest common prefix.
    return result;
}

// Overall Time: O(n * m * log n), where 'n' is the number of words and 'm' is the average length of the words.
// because sorting the 'n' words takes O(n * m * log n) time (since comparing two words takes 'm' time), and this is the slowest part of the function.
// Overall Space: O(m), where 'm' is the length of the final common prefix.
// because we need to store the 'commonPrefix' string. (Note: The sort itself might use O(log n) or O(n) space depending on the system's implementation).
string longestCommonPrefix_BySorting(vector<string>& strs) {
    // Step 1: Get the total number of words in the list and save it in 'n'
    // because we need to know how many words we have, to check if the list is empty and find the last word.
    int n = strs.size();
    
    // Step 2: Check if the number of words 'n' is 0 or less (meaning the list is empty), // because if the list is empty, there is no common part, so we must stop.
    if (n <= 0) {
        // Step 3: Send back an empty word "" , because an empty list has no words, so the common starting part is just "empty".
        return "";
    }

    // Step 4: Sort all the words in the list from A to Z (alphabetical order)
    // because after sorting, any common part *must* be shared by the very first word and the very last word.
    // Note: This is the key idea. If "flower" and "flow" are common, they'll be at the ends of a list like ["flow", "flower", "flight"]. 
    // The common part of "flight" and "flow" is "fl", which is all that's common to all three.
    sort(strs.begin(), strs.end());

    // Step 5: Get the *first* word from the now-sorted list, because this word will be the most different from the last word (alphabetically).
    string firstWord = strs[0];
    // Step 6: Get the *last* word from the now-sorted list, because if the first and last words share a common starting part, all the words in between 
    // *must* also share it.
    string lastWord = strs[n - 1];

    // Step 7: Find the length of the *shorter* word between the first and last, because the common part cannot be longer than the shorter of these two words.
    int minLen = min(firstWord.length(), lastWord.length());
    
    // Step 8: Create a counter 'i' and set it to 0, because this will help us look at each letter of the words, starting from the beginning (position 0).
    int i = 0;

    // Step 9: Start a loop that runs as long as we are inside the shorter length ('minLen') AND the letters at position 'i' in both words are the same
    // because we want to find the *last* position where the letters still match.
    while (i < minLen && firstWord[i] == lastWord[i]) {   
        // Step 10: Move to the next letter position by adding 1 to 'i', because the letters at the current position 'i' matched, so now we check the next pair.
        i++;
    }

    // Step 11: Cut a piece from the 'firstWord', starting from position 0 and taking 'i' letters
    // because our loop stopped at position 'i', which is the *first place the letters did not match*, so the common part is everything *before* 'i'.
    string commonPrefix = firstWord.substr(0, i);
    
    // Step 12: Send back the 'commonPrefix' as the answer
    // because this piece is the longest part that was the same in the first and last words, and therefore in *all* the words.
    return commonPrefix;
}


