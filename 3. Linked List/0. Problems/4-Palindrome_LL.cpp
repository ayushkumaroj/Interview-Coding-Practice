#include<iostream>
#include<stack>
using namespace std;
#include<vector>

class Node {
public:
    int data;
    Node* next;

    // Step 1: Create a basic constructor that sets data to 0 because we need a way to make empty nodes with safe default values
    Node() {
        // Step 2: Set data to 0 because we want a safe default value when no data is given
        this->data = 0;
        // Step 3: Set next pointer to NULL because this new node doesn't point to any other node yet
        this->next = NULL;
    }

    // Step 4: Create a constructor that takes data value because we need a way to make nodes with specific values
    Node(int data) {
        // Step 5: Set the node's data to the given value because we want to store the actual number the user wants
        this->data = data;
        // Step 6: Set next pointer to NULL because this new node doesn't point to any other node yet
        this->next = NULL;
    }
};

// Time Complexity: O(n), Space Complexity: O(1)
void insertAtTail(Node* &head, int data) {
    // Step 1: Create a new node with the given data because we need to add this value to the end of the list
    Node* newNode = new Node(data);
    // Step 2: Check if the list is empty by seeing if head is NULL because empty lists need special handling
    if (head == NULL) {
        // Step 3: Set head to point to our new node because this will be the first and only node in the list
        head = newNode;
        // Step 4: Exit the function because we're done adding the first node
        return;
    }
    // Step 5: Create a temp pointer starting at head because we need to find the last node without changing head
    Node* temp = head;
    // Step 6: Move temp through the list until we find the last node because we want to add after the current last node
    while (temp->next != NULL) {
        // Step 7: Move to the next node because the current node is not the last one yet
        temp = temp->next;
    }
    // Step 8: Connect the last node to our new node because we want to extend the list with our new data
    temp->next = newNode;
}

// Time Complexity: O(n), Space Complexity: O(n)
// USING STACK
bool checkPalindromeUsingStack(Node* head){
    // Step 1: Create an empty stack to hold node values because we need to read the list values in reverse order later
    stack<int>st;
    // Step 2: Use a temporary pointer starting at head because we need to traverse the list without changing the original head pointer
    Node* temp = head;

    // Step 3: Walk through the whole list and push each node's data onto the stack because this stores the list values in reverse order
    while(temp != NULL){
        // Step 4: Put the current node's value on the stack because we want to compare it later with values from the front
        st.push(temp->data);
        // Step 5: Move to the next node because we need to collect all values from the entire list
        temp = temp->next;
    }

    // Step 6: Reset temp to the start of the list because we need to compare values from the beginning again
    temp = head;
    // Step 7: Compare each node from the front with corresponding values from the back using the stack because palindromes read the same forwards and backwards
    while(temp != NULL){
        // Step 8: Get the value from the top of the stack because this represents the corresponding value from the end of the list
        int topElem = st.top();
        // Step 9: Remove that top value from the stack because we need to access the next value from the end in the next iteration
        st.pop();
        // Step 10: Compare the current front value with the current end value because if any pair doesn't match, it's not a palindrome
        if(temp->data != topElem){
            // Step 11: Return false immediately because we found a mismatch so we can stop checking
            return false;
        }
        // Step 12: Move temp forward to the next node because we need to compare the next pair of values
        temp = temp->next;
    }
    // Step 13: Return true because all pairs matched, meaning the list reads the same forwards and backwards
    return true;
}

// Time Complexity: O(n), Space Complexity: O(1)
// Helper function for array approach
bool checkPalindrome(vector<int>arr){
    // Step 1: Get the total number of elements in the array because we need to know the boundaries for comparison
    int n = arr.size();
    // Step 2: Set the starting index pointer to 0 because we want to start comparing from the first element
    int s = 0;
    // Step 3: Set the ending index pointer to the last element because we want to start comparing from the last element
    int e = n-1;

    // Step 4: Compare elements from start and end moving towards the middle because palindromes have matching elements at symmetric positions
    while(s <= e){
        // Step 5: Check if the elements at start and end positions don't match because if they don't match, it's not a palindrome
        if(arr[s] != arr[e]){
            // Step 6: Return false because we found a mismatch in symmetric positions
            return false;
        }
        // Step 7: Move the start pointer forward because we need to check the next inner pair
        s++;
        // Step 8: Move the end pointer backward because we need to check the next inner pair from the other side
        e--;
    }
    // Step 9: Return true because all symmetric pairs matched, confirming it's a palindrome
    return true;
}

// Time Complexity: O(n), Space Complexity: O(n)
// Using Array approach
bool checkPalindromeWithArray(Node* head){
    // Step 1: Create an empty vector to store all linked list values because we need to access elements by index for easy comparison
    vector<int>arr;
    // Step 2: Use a temporary pointer starting at head because we need to traverse the list without changing the original head pointer
    Node* temp = head;
    // Step 3: Traverse the linked list and copy each node's data into the array because we want all values stored in a structure that supports random access
    while(temp != NULL){
        // Step 4: Add the current node's value to the end of the array because we want to maintain the same order as the linked list
        arr.push_back(temp->data);
        // Step 5: Move to the next node because we need to collect values from the entire list
        temp = temp->next;
    }
    // Step 6: Use the helper function to check if the array values form a palindrome because the helper function handles the two-pointer comparison logic
    return checkPalindrome(arr);
}

// Time Complexity: O(n), Space Complexity: O(1)
// Function to find the middle node of the linked list using slow and fast pointers
Node* getMid(Node* head) {
    // Step 1: Start slow pointer at head because the slow pointer will move one step at a time to eventually reach the middle
    Node* slow = head;
    // Step 2: Start fast pointer at the second node because the fast pointer moves two steps at a time, and starting at second node helps find the correct middle
    Node* fast = head->next;

    // Step 3: Move fast two steps and slow one step until fast reaches the end because when fast reaches the end, slow will be exactly at the middle node
    while (fast != NULL && fast->next != NULL) {
        // Step 4: Move fast pointer two steps forward because fast pointer travels twice as fast as slow pointer
        fast = fast->next->next;
        // Step 5: Move slow pointer one step forward because slow pointer travels at half the speed of fast pointer
        slow = slow->next;
    }
    // Step 6: Return the slow pointer because it now points to the middle node that divides the list into two equal halves
    return slow;
}

// Time Complexity: O(n), Space Complexity: O(1)
// Function to reverse a linked list starting from given head node
Node* reverse(Node* head) {
    // Step 1: Initialize current pointer at head because we need to traverse through each node in the original list
    Node* curr = head;
    // Step 2: Initialize previous pointer as NULL because the first node of original list will become the last node of reversed list
    Node* prev = NULL;
    // Step 3: Initialize next pointer as NULL because we need this to temporarily store the next node before we break the link
    Node* next = NULL;

    // Step 4: Loop through the list to reverse the direction of pointers one by one because reversing helps us compare the second half with the first half for palindrome checking
    while (curr != NULL) {
        // Step 5: Save the next node before breaking the link because we don't want to lose the rest of the list
        next = curr->next;
        // Step 6: Reverse the current node's pointer to point backwards because we're changing the direction of the entire list
        curr->next = prev;
        // Step 7: Move prev to the current node because prev now represents the new head of the reversed portion
        prev = curr;
        // Step 8: Move curr to the next node in the original list because we need to continue reversing the remaining nodes
        curr = next;
    }
    // Step 9: Return prev as the new head of the reversed list because prev now points to what was originally the last node
    return prev;
}

// Time Complexity: O(n), Space Complexity: O(1)
// Function to check if the linked list is palindrome (reads same forwards and backwards)
bool isPalindrome(Node* head) {
    // Step 1: Check if list is empty or has only one node because empty lists and single-element lists are always palindromes
    if (head == NULL || head->next == NULL) {
        // Step 2: Return true because lists with 0 or 1 elements read the same forwards and backwards
        return true;
    }

    // Step 3: Find the middle node to divide the list into two halves because we need to compare the first half with the reversed second half
    Node* middle = getMid(head);

    // Step 4: Reverse the second half of the list starting after the middle node because reversing the second half allows us to compare both halves element by element
    Node* secondHalfStart = reverse(middle->next);
    // Step 5: Connect the middle node to the start of the reversed second half because we want to keep the list structure intact during comparison
    middle->next = secondHalfStart; 

    // Step 6: Initialize first pointer at the head of the original first half because we need to compare elements from the beginning
    Node* head1 = head;
    // Step 7: Initialize second pointer at the head of the reversed second half because we need to compare elements from what was originally the end
    Node* head2 = secondHalfStart;
    // Step 8: Initialize palindrome flag as true because we assume it's a palindrome until we find a mismatch
    bool palindrome = true;

    // Step 9: Compare data of nodes from both halves one by one because if any corresponding elements don't match, the list is not a palindrome
    while (head2 != NULL) {
        // Step 10: Check if the current elements from both halves don't match because a mismatch means it's not a palindrome
        if (head1->data != head2->data) {
            // Step 11: Set palindrome flag to false because we found elements that don't match
            palindrome = false;
            // Step 12: Break out of the loop because there's no need to check further once we find a mismatch
            break;
        }
        // Step 13: Move the first half pointer forward because we need to compare the next pair of elements
        head1 = head1->next;
        // Step 14: Move the second half pointer forward because we need to compare the next pair of elements
        head2 = head2->next;
    }

    // Step 15: Restore the original list by reversing the second half back to its original order because it's good practice to keep input data unchanged after function completion
    middle->next = reverse(secondHalfStart);
    // Step 16: Return the palindrome result because this tells us whether the list reads the same forwards and backwards
    return palindrome;
}

bool PalindromeUsingRecursion(Node* head, Node*& curr){
    if(head == NULL){
        return true;
    }
    bool ans = PalindromeUsingRecursion(head->next, curr);

    if(head->data != curr->data){
        return false;
    }

    curr = curr->next;
    return ans;
}

bool PalindromeUsingRecursion(Node* head){
    Node* curr = head;  // left pointer
    return PalindromeUsingRecursion(head, curr);
}

int main() {
    // Step 1: Create a head pointer and set it to NULL because we're starting with an empty linked list
    Node* head = NULL;

    // Step 2: Insert 1 at the tail because we want to build our test palindrome list: 1->2->3->2->1
    insertAtTail(head, 1);
    // Step 3: Insert 2 at the tail because we're continuing to build our palindrome pattern
    insertAtTail(head, 2);
    // Step 4: Insert 3 at the tail because this will be the middle element of our palindrome
    insertAtTail(head, 3);
    // Step 5: Insert 2 at the tail because we're creating the mirror pattern for palindrome verification
    insertAtTail(head, 2);
    // Step 6: Insert 1 at the tail because this completes our palindrome pattern that should read the same forwards and backwards
    insertAtTail(head, 1);

    // Step 7: Call the stack-based palindrome check function because we want to test if our list is actually a palindrome
    if (checkPalindromeUsingStack(head)) {
        // Step 8: Print success message because the function confirmed our list is a palindrome
        cout << "Linked List is a palindrome" << endl;
    } else {
        // Step 9: Print failure message because the function determined our list is not a palindrome
        cout << "Linked List is NOT a palindrome" << endl;
    }

    // Step 10: Return 0 because this indicates successful program completion
    return 0;
}