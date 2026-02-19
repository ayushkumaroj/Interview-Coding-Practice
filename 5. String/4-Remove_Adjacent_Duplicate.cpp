#include<iostream>
using namespace std;
#include<string>
#include<stack>
#include<algorithm>

// Time Complexity: O(N) because we go through the string one time.
// Space Complexity: O(N) because in the worst case (no duplicates), the stack will hold all characters.
string removeDuplicatesUsingStack(string s){
    // Step 1: Get the length of the string because we need to know how many times to loop.
    int n = s.length();
    // Step 2: Create a stack of characters because a stack helps us easily see and remove the last character we added.
    stack<char>st;
   
    // Step 3: Start a loop to check every character in the string one by one.
    for(int i=0; i<n; i++){
        // Step 4: Check if the stack has characters and if the top character is the same as the current character from the string.
        if(!st.empty() && st.top() == s[i]){
            // Step 5: If they match, remove the top character from the stack because we found a pair of duplicates that needs to be removed.
            st.pop();
        }
        else{
            // Step 6: If they don't match, add the current character to the stack because it's not a duplicate of the previous one.
            st.push(s[i]);
        }
    }

    // Step 7: Create an empty string 'result' because we need a place to build our final answer.
    string result = "";
    // Step 8: Start a loop that runs as long as the stack is not empty.
    while(!st.empty()){
        // Step 9: Add the top character from the stack to our 'result' string because these are the characters left after removing duplicates.
        result.push_back(st.top());
        // Step 10: Remove the top character from the stack because we have already added it to our result.
        st.pop();
    }

    // Step 11: Reverse the 'result' string because the characters were added from the stack in reverse order.
    reverse(result.begin(), result.end());
    // Step 12: Return the final, correct string.
    return result;
}

string removeDuplicatesUsingRecursion(string s){
    // STEP 1: Store the length of the string
    int n = s.length();

    // STEP 2: Traverse the string to find adjacent duplicates
    for (int i = 1; i < n; i++){
        // STEP 3: Check if current character and previous character are same
        if (s[i] == s[i - 1]){
            // STEP 4: Store the part BEFORE the duplicate pair
            string leftPart = s.substr(0, i - 1);

            // STEP 5: Store the part AFTER the duplicate pair
            string rightPart = s.substr(i + 1);

            // STEP 6: Combine both parts to form a new string
            string newString = leftPart + rightPart;

            // STEP 7: Call the function again with the new string
            string result = removeDuplicatesUsingRecursion(newString);

            // STEP 8: Return the final result
            return result;
        }
    }

    // STEP 9: Base case – no adjacent duplicates found
    return s;
}


// Time Complexity: O(N) because the fast pointer goes through the string only once.
// Space Complexity: O(1) because we are modifying the original string in place and using only a few extra variables.
string removeDuplicatesUsingTwoPointers(string s){
    // Step 1: Get the length of the string because we need to know when to stop our loop.
    int n = s.length();
    // Step 2: Create a 'slow' pointer and set it to 0 because it will keep track of the end of our clean, non-duplicate string.
    int slow = 0;
    // Step 3: Create a 'fast' pointer and set it to 0 because it will move through the original string to check each character.
    int fast = 0;

    // Step 4: Loop through the entire string using the 'fast' pointer.
    for(fast = 0; fast<n; fast++){
        // Step 5: Check if the clean string is empty (slow == 0) OR if the current character ('s[fast]') is different from the
        //  last character of our clean string ('s[slow-1]').
        if(slow == 0 || s[slow-1] != s[fast]){
            // Step 6: If it's a new character, copy it to the position of the 'slow' pointer because we are adding it to our clean string.
            s[slow] = s[fast];
            // Step 7: Move the 'slow' pointer forward because our clean string is now one character longer.
            slow++;
        }
        else{
            // Step 8: If the current character is a duplicate of the last one, move the 'slow' pointer back because this effectively
            //  removes the last character, deleting the duplicate pair.
            slow--;
        }
    }
    // Step 9: Return the part of the string from the beginning up to the 'slow' pointer's final position because that is our final result.
    // Note: s.substr(0, slow) extracts the final result from the modified string, from index 0 up to (but not including) the index 'slow'.
    return s.substr(0, slow);
}


// Main function
int main(){
    string s;
    cout << "Enter a string: ";
    cin >> s;

    cout << "Using Stack: " << removeDuplicatesUsingStack(s) << endl;
    cout << "Using Recursion: " << removeDuplicatesUsingRecursion(s) << endl;
    cout << "Using Two Pointers: " << removeDuplicatesUsingTwoPointers(s) << endl;

    return 0;
}