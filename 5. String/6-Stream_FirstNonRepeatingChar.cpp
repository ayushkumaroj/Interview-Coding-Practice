#include <bits/stdc++.h>
using namespace std;

// A structure to represent one block (or node) in our list.
class Node {
    public:
    char val; // Step 1: Create a character variable 'val' because we need a place to store the character's value in this node.
    Node* prev; // Step 2: Create a pointer 'prev' because we need to know the address of the node that comes before this one in the list.
    Node* next; // Step 3: Create a pointer 'next' because we need to know the address of the node that comes after this one in the list.

    // This is a special function to create a new Node.
    Node(char v) {
        val = v; // Step 4: Set the node's character 'val' to the value 'v' we received because this is the character we want to store.
        prev = nullptr; // Step 5: Set the 'prev' pointer to null (nothing) because when a node is first created, it's not connected to any other node before it.
        next = nullptr; // Step 6: Set the 'next' pointer to null (nothing) because when a node is first created, it's not connected to any other node after it.
    }
};

// ===== DLL Approach =====
// Overall Time Complexity: O(N) where N is the length of the string.
// Overall Space Complexity: O(C) where C is the number of unique characters (at most 256 for ASCII), so it's considered constant O(1).
string firstNonRepeatingDLL(string &s) {
    // Step 1: Create a starting dummy node 'head' and an ending dummy node 'tail' because it makes adding or removing other nodes easier without 
    // worrying about empty list cases.
    Node* head = new Node('#');
    Node* tail = new Node('#');
    // Step 2: Connect the head and tail nodes to each other because this sets up our initial empty list.
    head->next = tail;
    tail->prev = head;

    // Step 3: Create a map 'charNode' to store characters and their node addresses because we need a quick way to find a character's node in the list later.
    unordered_map<char, Node*> charNode;
    // Step 4: Create a map 'repeated' to keep track of characters that have shown up more than once because we want to ignore them quickly in the future.
    unordered_map<char, bool> repeated;

    // Step 5: Create an empty string 'ans' because we need a place to build our final answer string step-by-step.
    string ans = "";

    // Step 6: Loop through each character 'c' in the input string 's' because we need to process the string one character at a time.
    for (char c : s) {
        // Step 7: Check if the character 'c' is NOT in the 'repeated' map because if it is already repeated, we don't need to do anything.
        if (!repeated[c]) {
            // Step 8: Check if we have NEVER seen this character before (it's not in the 'charNode' map) because this tells us if it's a new, non-repeating character.
            if (charNode.find(c) == charNode.end()) {
                // Step 9: Create a new node for the new character 'c' because we need to add it to our list of non-repeating characters.
                Node* node = new Node(c);
                // Step 10: Connect the new node to the end of our list (right before the 'tail' dummy node) because we add new non-repeating
                //  characters in the order they appear.
                node->next = tail;
                node->prev = tail->prev;
                tail->prev->next = node;
                tail->prev = node;
                // Step 11: Save the new node's address in our 'charNode' map because we'll need it to find and remove this node quickly if we see this character again.
                charNode[c] = node;
            } else { // Step 12: This part runs if we have seen the character exactly once before because now it's a repeating character.
                // Step 13: Get the node for the character 'c' from the map because we need to remove it from our list of non-repeating characters.
                Node* node = charNode[c];
                // Step 14: Remove the node from the list by connecting its previous and next nodes to each other because this character is no longer non-repeating.
                node->prev->next = node->next;
                node->next->prev = node->prev;
                // Step 15: Remove the character 'c' from the 'charNode' map because its node is no longer in the list.
                charNode.erase(c);
                // Step 16: Mark the character 'c' as repeated because we don't want to process it ever again.
                repeated[c] = true;
            }
        }

        // Step 17: Check if our list of non-repeating characters has at least one node because we need to know what to add to our answer string.
        if (head->next != tail)
            // Step 18: If the list is not empty, add the character from the first real node (head->next) to the answer because this is the first
            //  non-repeating character found so far.
            ans += head->next->val;
        else
            // Step 19: If the list is empty, add a '#' to the answer because it means there are no non-repeating characters at this point.
            ans += '#';
    }

    // Step 20: Start cleaning up the memory we used for the list to avoid memory leaks.
    Node* curr = head;
    // Step 21: Loop through the entire list, including the dummy nodes, because we need to delete every single node we created.
    while (curr) {
        Node* temp = curr; // Step 22: Temporarily save the current node because we are about to move to the next one and will lose track of this one.
        curr = curr->next; // Step 23: Move to the next node in the list because we need to continue the cleanup process.
        delete temp; // Step 24: Delete the saved node because its memory is no longer needed.
    }

    // Step 25: Return the final answer string because the function has finished its job.
    return ans;
}


// Overall Time Complexity: O(N * C) where N is the string length and C is the number of unique characters.
// This is slower than the DLL approach because of the inner loop.
// Overall Space Complexity: O(C) where C is the number of unique characters, so it's considered constant O(1).
string firstNonRepeatingFrequency(string &s) {
    // Step 1: Get the length of the string 's' because we will use it in our loops and for setting initial values.
    int n = s.length();
    // Step 2: Create a map 'mp' to store each character, its count, and the index where it first appeared because we need all this info to find the answer.
    // NOTE: The pair stores {frequency, first index}.
    unordered_map<char, pair<int,int>> mp;
    // Step 3: Create an empty string 'ans' because we need a place to build our final answer string.
    string ans = "";

    // Step 4: Loop through the string from the first character to the last using an index 'i' because we need to process each character and know its position.
    for (int i = 0; i < n; i++) {
        // Step 5: Get the character at the current position 'i' because it's the character we are processing now.
        char c = s[i];

        // Step 6: Check if we have seen the character 'c' before by looking for it in the map because we need to know whether to add it or update it.
        if (mp.find(c) != mp.end()) {
            // Step 7: If we have seen it, just increase its count (the first item in the pair) by 1 because it has appeared again.
            mp[c].first += 1;
        } else {
            // Step 8: If it's a new character, add it to the map with a count of 1 and its current index 'i' because this is its first appearance.
            mp[c] = {1, i};
        }

        // Step 9: Create a variable 'minIndex' and set it to a very large number (n) because we will use it to find the smallest index among non-repeating characters.
        int minIndex = n;
        // Step 10: Create a character 'result' and set it to '#' because this will be our answer if we don't find any non-repeating character.
        char result = '#';
        // Step 11: Loop through every character 'x' we have stored in our map so far because we need to check all of them to find the first non-repeating one.
        for (auto x : mp) {
            // Step 12: Check if a character has a count of 1 AND its first index is smaller than our current 'minIndex' because this is how we find
            //  the *first* non-repeating character.
            if (x.second.first == 1 && x.second.second < minIndex) {
                // Step 13: If we found a better character (one that appeared earlier), update 'minIndex' and 'result' because we are keeping track
                //  of the best answer so far.
                minIndex = x.second.second;
                result = x.first;
            }
        }

        // Step 14: Add the 'result' for this step to our final answer string because we have finished processing the string up to this point.
        ans += result;
    }

    // Step 15: Return the completed answer string because we have processed the entire input string.
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