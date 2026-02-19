#include <bits/stdc++.h>
using namespace std;

// A node of the Doubly Linked List
class Node {
public:
    char val;        // Stores the character value of this node
    Node* prev;      // Pointer to the previous node in the list
    Node* next;      // Pointer to the next node in the list

    // Constructor to create a new node
    Node(char v) {
        val = v;         // Assign the character value
        prev = nullptr;  // Initially, no previous node
        next = nullptr;  // Initially, no next node
    }
};

class Solution {
public:
    string firstNonRepeating(string &s){
        // STEP 1: Create dummy head node
        // This helps avoid edge cases when inserting or deleting nodes
        Node* head = new Node('#');
        // STEP 2: Create dummy tail node
        Node* tail = new Node('#');
        // STEP 3: Connect head and tail to form an empty DLL
        head->next = tail;
        tail->prev = head;

        // STEP 4: Create an array to store node addresses for each character
        // Index represents ASCII value of character
        Node* charNode[256];
        // STEP 5: Create an array to mark characters that are repeated
        bool repeated[256];

        // STEP 6: Initialize both arrays
        for (int i = 0; i < 256; i++) {
            charNode[i] = nullptr;   // No character node exists initially
            repeated[i] = false;     // No character is repeated initially
        }

        // STEP 7: String to store the final answer
        string ans = "";
        // STEP 8: Get the length of input string
        int n = s.length();

        // STEP 9: Traverse the string character by character using index
        for (int i = 0; i < n; i++){
            // STEP 10: Get the current character
            char c = s[i];
            // STEP 11: Convert character to its ASCII index
            int idx = (int)c;

            // STEP 12: Process only if the character is not already repeated
            if (repeated[idx] == false){
                // STEP 13: If character is seen for the first time
                if (charNode[idx] == nullptr){
                    // STEP 14: Create a new node for this character
                    Node* node = new Node(c);

                    // STEP 15: Insert the node just before the tail
                    node->next = tail;
                    node->prev = tail->prev;
                    tail->prev->next = node;
                    tail->prev = node;
                    // STEP 16: Store node address in charNode array
                    charNode[idx] = node;
                }else{
                    // STEP 17: Character is seen second time, so it becomes repeating

                    // STEP 18: Get the node address of this character
                    Node* node = charNode[idx];

                    // STEP 19: Remove the node from the DLL
                    node->prev->next = node->next;
                    node->next->prev = node->prev;

                    // STEP 20: Remove reference from charNode array
                    charNode[idx] = nullptr;

                    // STEP 21: Mark character as repeated
                    repeated[idx] = true;
                }
            }

            // STEP 22: Check if DLL contains any non-repeating character
            if (head->next != tail){
                // STEP 23: Add the first non-repeating character to answer
                ans = ans + head->next->val;
            }
            else{
                // STEP 24: If no non-repeating character exists, add '#'
                ans = ans + '#';
            }
        }

        // STEP 25: Free all allocated memory of DLL
        Node* curr = head;
        while (curr != nullptr){
            Node* temp = curr;   // Store current node
            curr = curr->next;   // Move to next node
            delete temp;         // Delete stored node
        }

        // STEP 26: Return the final result string
        return ans;
    }
};



// Time Complexity: O(N)
// Space Complexity: O(1)
string firstNonRepeating(string &s){
    // Step 1: Frequency array for all characters
    int freq[256];

    // Step 2: Initialize frequency array
    for (int i = 0; i < 256; i++) {
        freq[i] = 0;
    }

    // Step 3: Queue to store non-repeating candidates
    queue<char> q;

    // Step 4: Answer string
    string ans;
    ans.reserve(s.length());   // IMPORTANT: avoid reallocation

    // Step 5: Traverse string using index
    int n = s.length();
    for (int i = 0; i < n; i++){
        // Step 6: Current character
        char c = s[i];

        // Step 7: Increase frequency
        freq[(int)c]++;

        // Step 8: If first time seen, push to queue
        if (freq[(int)c] == 1) {
            q.push(c);
        }

        // Step 9: Remove repeating characters from front
        while (!q.empty() && freq[(int)q.front()] > 1) {
            q.pop();
        }

        // Step 10: Append result WITHOUT string concatenation
        if (!q.empty()) {
            ans.push_back(q.front());
        } else {
            ans.push_back('#');
        }
    }

    // Step 11: Return result
    return ans;
}



// ===== Main Function =====
int main() {
    // Step 1: Create a string 's' because we need a place to store the user's input.
    string s;
    // Step 2: Show a message on the screen asking the user for a string because the program needs input to work.
    cout << "Enter a string: ";
    // Step 3: Read the text the user types and save it into the string 's' because this is the data we will process.
    cin >> s;

    // Step 4: Call the first function with the user's string and save the output in 'resultDLL' because we want to test the Doubly Linked List method.
    string resultDLL = firstNonRepeatingDLL(s);
    // Step 5: Print the result from the DLL method because we want to show the user the answer.
    cout << "DLL Approach: " << resultDLL << endl;

    // Step 6: Call the second function and save its output in 'resultFreq' because we want to test the Frequency/Index method.
    string resultFreq = firstNonRepeatingFrequency(s);
    // Step 7: Print the result from the Frequency/Index method because we want to show the user the answer and let them compare.
    cout << "Frequency+Index Approach: " << resultFreq << endl;

    // Step 8: End the program successfully because it has finished all its tasks.
    return 0;
}