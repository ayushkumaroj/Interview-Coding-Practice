#include <iostream>
using namespace std;

// Node class
class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

// Time Complexity: O(N) because in the worst case, we might have to travel through the entire list to find the right spot to insert the new item.
// Space Complexity: O(1) because we only create one new node and use a few helper pointers, which doesn't depend on the list's size.
Node* sortedInsert(Node* head, int data) {
    // Step 1: Check if the list is empty because if it is, we need to create the very first item.
    if (head == NULL) {
        // Step 2: Create a new node with the given data because this will be the first and only node in the list.
        Node* newNode = new Node(data);
        // Step 3: Make the new node point to itself because in a circular list with one item, it forms a circle by pointing back to itself.
        newNode->next = newNode; 
        // Step 4: Return the new node because it is now the head of the list
        return newNode;
    }

    // Step 5: Create a pointer 'prev' starting at the head because we need a pointer to trail behind 'curr'.
    Node* prev = head;
    // Step 6: Create a pointer 'curr' starting at the second node because we will check for the right spot between 'prev' and 'curr'.
    Node* curr = head->next;

    // Step 7: Start a loop that goes around the entire circle because we need to check every position to find the correct one.
    do {
        // Step 8: Check if the new data fits between the 'prev' and 'curr' nodes because this is the most common place for an insertion in a sorted list.
        if (data >= prev->data && data <= curr->data) {
            // Step 9: Create the new node to be inserted because we have found the correct spot for it.
            Node* newNode = new Node(data);
            // Step 10: Connect 'prev' to the new node because the new node comes after 'prev'.
            prev->next = newNode;
            // Step 11: Connect the new node to 'curr' because 'curr' comes after the new node.
            newNode->next = curr;
            // Step 12: Return the head of the list because our job is done and the list's head hasn't changed.
            return head;
        }
        // Step 13: Check if we have reached the end of the sorted sequence (e.g., from 10 back to 2) because this is a special case in a sorted circular list.
        else if (prev->data > curr->data) {
            // Step 14: Check if the new data is larger than the biggest number OR smaller than the smallest number because if it is, it should be
            //  inserted at this wrap-around point.
            if (data >= prev->data || data <= curr->data) {
                // Step 15: Create the new node to be inserted because we found the correct spot for it at the wrap-around point.
                Node* newNode = new Node(data);
                // Step 16: Connect 'prev' to the new node because the new node comes after 'prev'.
                prev->next = newNode;
                // Step 17: Connect the new node to 'curr' because 'curr' comes after the new node.
                newNode->next = curr;
                // Step 18: Return the head of the list because the insertion is complete.
                return head;
            }
        }
        // Step 19: Move 'prev' one step forward because we haven't found the spot yet.
        prev = curr;
        // Step 20: Move 'curr' one step forward because we need to check the next pair of nodes.
        curr = curr->next;
    } while (prev != head);

    // Step 21: Create the new node because the loop finished without finding a spot, which means all items in the list are the same.
    Node* newNode = new Node(data);
    // Step 22: Connect 'prev' (which is now the last node) to the new node because this inserts the node at the end of the chain.
    prev->next = newNode;
    // Step 22: Connect 'prev' (which is now the last node) to the new node because this inserts the node at the end of the chain.
    newNode->next = curr;
    // Step 22: Connect 'prev' (which is now the last node) to the new node because this inserts the node at the end of the chain.
    return head;
}

// Function to print the circular linked list
void printList(Node* head) {
    if (head == NULL) {
        cout << "List is empty!" << endl;
        return;
    }

    Node* temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}

// Main function
int main() {
    Node* head = NULL;

    // Insert elements
    head = sortedInsert(head, 3);
    head = sortedInsert(head, 5);
    head = sortedInsert(head, 1);
    head = sortedInsert(head, 7);
    head = sortedInsert(head, 2);
    head = sortedInsert(head, 6);

    cout << "Circular Linked List: ";
    printList(head);

    return 0;
}
