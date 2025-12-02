#include <iostream>
#include <cstdint>

using namespace std;

// This is a special type of list called an XOR Linked List.
// It saves memory by using one pointer ('link') to store information
// about both the previous and the next node.
// This is done using a math trick called XOR.

struct Node {
    int data;
    Node* link; // This stores the XOR of the memory addresses of the previous and next nodes.
};

// A helper function to do the XOR math on memory addresses.
Node* XOR(Node* a, Node* b) {
    // Step 1: Do an XOR operation on the memory addresses of two nodes because this special trick lets us store information 
    // about both the previous and next nodes in a single pointer, saving space.
    return (Node*)((uintptr_t)(a) ^ (uintptr_t)(b));
}

// This function adds a new number to the end of the list.
// Time Complexity: O(n) because in the worst case, we have to travel through the whole list to find the end.
// Space Complexity: O(1) because we only create one new node and a few helper pointers, no matter how big the list is.
void insert(Node** head_ref, int value) {
    // Step 1: Make a brand new empty node because we need a place to put the new value.
    Node* newNode = new Node();
    // Step 2: Put the given value into the new node because that's the data we want to store.
    newNode->data = value;

    // Step 3: Check if the list is empty because if it is, this new node will be the first and only node.
    if (*head_ref == NULL) {
        // Step 4: Set the new node's link to NULL because as the only node, it has no previous or next node to point to.
        newNode->link = NULL;
        // Step 5: Make the head point to our new node because it's now the start of the list.
        *head_ref = newNode;
        // Step 6: Stop the function because we are done adding the first node.
        return;
    }

    // Step 7: Create a pointer 'curr' and point it to the head because we need to travel through the list starting from 
    // the beginning without losing the original head.
    Node* curr = *head_ref;
    // Step 8: Create a pointer 'prev' and set it to NULL because at the start, the first node has no node before it.
    Node* prev = NULL;
    // Step 9: Create a pointer 'future' because we need a place to hold the address of the next node as we travel.
    Node* future;

    // Step 10: Start a loop to travel to the end of the list because we need to find the last node to add our new node after it.
    while (true) {
        // Step 11: Find the next node in the list by using XOR because the 'link' of the current node stores the XOR of the previous 
        // and next node's addresses.
        future = XOR(prev, curr->link);
        // Step 12: Check if we have reached the end of the list because the 'future' node will be NULL when 'curr' is the last node.
        if (future == NULL) {
            // Step 13: Exit the loop because we have found the last node.
            break;
        }
        // Step 14: Update 'prev' to be the current node because in the next step, our current node will become the previous one.
        prev = curr;
        // Step 15: Move to the next node because we are traveling down the list.
        curr = future;
    }

    // Step 16: Update the link of the last node (which is 'curr') because it now needs to point to the new node we are adding.
    curr->link = XOR(prev, newNode);
    // Step 17: Set the link of our new node because it is now the very last node, so its 'next' is NULL.
    newNode->link = XOR(curr, NULL);
}

// This function prints the list from start to end.
// Time Complexity: O(n) because we visit every single node once to print it.
// Space Complexity: O(1) because we only create a few helper pointers to move through the list.
void traverse(Node* head) {
    // Step 1: Create a pointer 'curr' and point it to the head because we need to travel through the list starting from the beginning
    //  without losing the original head.
    Node* curr = head;
    // Step 2: Create a pointer 'prev' and set it to NULL because at the start, the first node has no node before it.
    Node* prev = NULL;
    // Step 3: Create a pointer 'future' because we need a place to hold the address of the next node as we travel.
    Node* future;

    cout << "Forward Traversal: ";
    // Step 4: Start a loop that continues as long as we haven't fallen off the end of the list because we want to visit every single node.
    while (curr != NULL) {
        // Step 5: Print the data in the current node because that's the purpose of traversing the list.
        cout << curr->data << " ";
        // Step 6: Find the next node in the list by using XOR because the 'link' of the current node stores the XOR of the previous and next node's addresses.
        future = XOR(prev, curr->link);
        // Step 7: Update 'prev' to be the current node because in the next step, our current node will become the previous one.
        prev = curr;
        // Step 8: Move to the next node because we are traveling forward down the list.
        curr = future;
    }
    cout << endl;
}

// This function prints the list from end to start.
// Time Complexity: O(n) because we visit every single node once to print it.
// Space Complexity: O(1) because we only create a few helper pointers to move through the list.
void traverseBackward(Node* tail) {
    // Step 1: Create a pointer 'curr' and point it to the tail because we want to travel backward from the end of the list.
    Node* curr = tail;
    // Step 2: Create a pointer 'future' and set it to NULL because when starting from the tail, the node 'after' it is nothing.
    Node* future = NULL;
    // Step 3: Create a pointer 'prev' because we need a place to hold the address of the previous node as we travel backward.
    Node* prev;

    cout << "Backward Traversal: ";
    // Step 4: Start a loop that continues as long as we haven't fallen off the start of the list because we want to visit every single node.
    while (curr != NULL) {
        // Step 5: Print the data in the current node because that's the purpose of traversing the list.
        cout << curr->data << " ";
        // Step 6: Find the previous node in the list by using XOR because the 'link' of the current node stores the XOR of the previous
        //  and next node's addresses.
        prev = XOR(future, curr->link);
        // Step 7: Update 'future' to be the current node because in the next step, our current node will become the 'next' one from the perspective
        // of the node we are moving to.
        future = curr;
        // Step 8: Move to the previous node because we are traveling backward up the list.
        curr = prev;
    }
    cout << endl;
}

// This function finds the last node in the list.
// Time Complexity: O(n) because we have to travel through the whole list to find the end.
// Space Complexity: O(1) because we only create a few helper pointers.
Node* getTail(Node* head) {
    // Step 1: Create a pointer 'curr' and point it to the head because we need to travel through the list starting from the beginning.
    Node* curr = head;
    // Step 2: Create a pointer 'prev' and set it to NULL because at the start, the first node has no node before it.
    Node* prev = NULL;
    // Step 3: Create a pointer 'future' because we need a place to hold the address of the next node.
    Node* future;

    // Step 4: Start a loop to travel to the end of the list because we want to find the very last node.
    while (curr != NULL) {
        // Step 5: Find the next node in the list by using XOR because this lets us move forward.
        future = XOR(prev, curr->link);
        // Step 6: Check if we have reached the end of the list because the 'future' node will be NULL when 'curr' is the last node.
        if (future == NULL) {
            // Step 7: Return the current node because it is the tail (the last node).
            return curr;
        }
        // Step 8: Update 'prev' to be the current node because we are about to move forward.
        prev = curr;
        // Step 9: Move to the next node because we are traveling down the list.
        curr = future;
    }
    // Step 10: Return NULL if the list was empty because an empty list has no tail.
    return NULL;
}


int main() {
    // Step 1: Create a head pointer and set it to NULL because we are starting with an empty list.
    Node* head = NULL;

    // Step 2: Add some numbers to the list because we need data to test our functions.
    insert(&head, 10);
    insert(&head, 20);
    insert(&head, 30);
    insert(&head, 40);

    // Step 3: Print the list from start to end because we want to check if the insert and forward traversal work correctly.
    traverse(head);

    // Step 4: Find the last node in the list because we need a starting point to travel backward.
    Node* tail = getTail(head);
    // Step 5: Print the list from end to start because we want to check if the backward traversal works correctly.
    traverseBackward(tail);

    // Step 6: End the program because we are finished.
    return 0;
}


