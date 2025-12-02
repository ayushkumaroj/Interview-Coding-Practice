#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(){
        this->data = 0;
        this->next = NULL;
    }

    Node(int data){
        this->data = data;
        this->next = NULL;
    }

};

// Time Complexity: O(N) because we have to visit every node in the list one time to decide whether to keep or delete it.
// Space Complexity: O(1) because we only use a few extra pointers to do the work, and the memory used doesn't grow with the size of the list.
Node* deleteNNodeAfterM(Node* head, int m, int n) {
    // Step 1: Create a pointer 'curr' and make it point to the start of the list because we need a way to move through the list without losing the original head.
    Node* curr = head;
    // Step 2: Create a pointer 'deleteStart' and set it to nothing for now because this will later point to the first node we need to delete.
    Node* deleteStart = NULL;

    // Step 3: Start a big loop that keeps going as long as we are not at the end of the list because we need to repeat the process of keeping 'm' nodes and 
    // deleting 'n' nodes until the list ends.
    while (curr != NULL) {
        // Step 4: Start a loop to skip over 'm' nodes because the problem asks us to keep the first 'm' nodes in each section.
        for (int i = 1; i < m; i++) {
            // Step 5: Check if 'curr' is a valid node before moving it to the next one because we might reach the end of the list while skipping.
            if (curr != NULL) {
                curr = curr->next;
            }
        }
        
        // Step 6: If we reach the end of the list while skipping, stop everything and return the head because there are no more nodes to process or delete.
        if (curr == NULL) {
            return head;
        }

        // Step 7: Make 'deleteStart' point to the node right after 'curr' because this is the first node in the group of 'n' nodes we need to remove.
        deleteStart = curr->next;
        // Step 8: Start a loop to delete 'n' nodes because this is the number of nodes the problem asks us to remove.
        for (int i = 1; i <= n; i++) {
            // Step 9: Make sure there is actually a node to delete because we might have reached the end of the list.
            if (deleteStart != NULL) {
                // Step 10: Create a temporary pointer 'temp' to hold the node we are about to delete because we need to free its memory without losing track
                //  of the next node.
                Node* temp = deleteStart;
                // Step 11: Move 'deleteStart' to the next node in the list because we need to continue deleting the next one in the sequence.
                deleteStart = deleteStart->next;
                // Step 12: Delete the node that 'temp' is pointing to because this frees up the computer's memory and removes the node.
                delete temp;
            }
        }

        // Step 13: Connect the last node we kept ('curr') to the node right after the deleted section ('deleteStart') because this patches the hole in the
        // list we created by deleting nodes.
        curr->next = deleteStart;
        // Step 14: Move 'curr' to the new position ('deleteStart') because this sets us up to start the process all over again from this point in the list.
        curr = deleteStart;
    }

    // Step 15: After the main loop is finished, return the head of the modified list because this is the starting point of our updated list.
    return head;
}

// Function to print the linked list
void printList(Node* head) {
    Node* curr = head;
    while (curr != NULL) {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}

// Main function to test the logic
int main() {
    // Creating a sample linked list: 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = new Node(6);
    head->next->next->next->next->next->next = new Node(7);
    head->next->next->next->next->next->next->next = new Node(8);

    cout << "Original List: ";
    printList(head);

    int m = 2, n = 2;
    head = deleteNNodeAfterM(head, m, n);

    cout << "Modified List after skipping " << m << " and deleting " << n << ": ";
    printList(head);

    return 0;
}