#include <iostream>
using namespace std;

// Node definition using 'data' and 'next'
class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

// Function to insert a new node at the end of the list
void insert(Node*& head, int value) {
    Node* newNode = new Node(value);
    if (head == NULL) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to print the linked list
void printList(Node* head) {
    if (head == NULL) {
        cout << "List is empty!" << endl;
        return;
    }
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Time Complexity: O(N^2) because for each item in the list, we might have to search through the entire sorted part to find the correct place for it.
// Space Complexity: O(1) because we are sorting the list without using extra memory that grows with the size of the list; we only use a few helper pointers.
Node* insertionSortList(Node* head) {
    // Step 1: Check if the list is empty or has only one item because such lists are already sorted, so we can return them right away.
    if (head == NULL || head->next == NULL) {
        return head;
    }

    // Step 2: Create a new helper node called dummyNode because it makes it easier to insert an item at the very beginning of the list without special checks.
    Node* dummyNode = new Node(0); 
    // Step 3: Connect the helper node to the start of our list because it now acts as a placeholder before the real first item.
    dummyNode->next = head;

    // Step 4: Create a pointer 'curr' starting at the head because it will mark the end of the part of the list that is already sorted.
    Node* curr = head;
    // Step 5: Start a loop to go through the list because we need to check every item to see if it's in the right sorted place.
    while (curr != NULL && curr->next != NULL) {
        // Step 6: Check if the next item is bigger than or equal to the current one because if it is, they are in the correct order and we don't need to do anything.
        if (curr->data <= curr->next->data) {
            // Step 7: Move 'curr' to the next item because the sorted part of our list just got one item longer.
            curr = curr->next;
        } else {
            // Step 8: If the next item is smaller, it's out of place because we need to move it to its correct position in the sorted part.
            // Step 9: Store the out-of-place item in 'toInsert' because we need a temporary holder for it while we find its new home.
            Node* toInsert = curr->next;
            // Step 10: Unlink the 'toInsert' item from the list because we are going to place it somewhere else.
            curr->next = toInsert->next;

            // Step 11: Create another pointer 'prev' and start it at the helper node because we need to search for the correct new spot from the
            //  very beginning of the list.
            Node* prev = dummyNode;
            // Step 12: Loop from the beginning to find where 'toInsert' should go because we need to find the node that should come right before
            //  our 'toInsert' node.
            while (prev->next != NULL && prev->next->data < toInsert->data) {
                prev = prev->next;
            }
            // Step 13: Connect the 'toInsert' item to the next item in the sequence because this puts 'toInsert' in its correct sorted position.
            toInsert->next = prev->next;
            // Step 14: Connect 'prev' to the 'toInsert' item because this completes the insertion into the sorted part of the list.
            prev->next = toInsert;
        }
    }
    
    // Step 15: Get the correct start of the sorted list because the dummyNode points to the new head, which might have changed.
    Node* newHead = dummyNode->next;
    // Step 16: Remove the helper dummyNode from memory because we don't need it anymore and it's good practice to clean up.
    delete dummyNode;
    // Step 17: Return the new head of the fully sorted list because the function's job is done.
    return newHead;
}

// Main function
int main() {
    Node* head = NULL;

    // Insert elements into the linked list
    insert(head, 4);
    insert(head, 2);
    insert(head, 1);
    insert(head, 3);

    cout << "Original List: ";
    printList(head);

    // Sort the list
    head = insertionSortList(head);

    cout << "Sorted List: ";
    printList(head);

    return 0;
}
