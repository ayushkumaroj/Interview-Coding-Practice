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

// Function to insert a node at the end of the list
void insert(Node*& head, int data) {
    Node* newNode = new Node(data);
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
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data;
        if (temp->next != NULL) cout << " -> ";
        temp = temp->next;
    }
    cout << endl;
}


// Time Complexity: O(N) because, in the worst case, it traverses the entire list to find the section and reverse it.
// Space Complexity: O(1) because it only uses a few extra pointer variables, regardless of the list's size.
Node* reverseBetween(Node* head, int left, int right){
    // Step 1: Create a 'dummyNode' because it simplifies handling the edge case where the reversal starts from the very first node (left = 1).
    Node* dummyNode = new Node(0);
    // Step 2: Connect the dummy node to the actual head of the list because this makes the rest of the list accessible through the dummy.
    dummyNode->next = head;

    // Step 3: Create 'leftprev' pointing to the dummy node because this pointer will end up at the node right before the reversal section.
    Node* leftprev = dummyNode;
    // Step 4: Create 'currNode' pointing to the head because this pointer will travel to the start of the reversal section.
    Node* currNode = head;

    // Step 5: Loop 'left-1' times to position our pointers because we need 'leftprev' and 'currNode' to be at the correct starting points before reversing.
    for(int i=0; i<left-1; i++){
        // Step 6: Move both pointers one step forward in each iteration because we are walking down the list to find the start of the sublist.
        leftprev = leftprev->next;
        currNode = currNode->next;
    }

    // Step 7: Save the starting node of the sub Linkedlist in 'subListHead' because this node will become the tail of the reversed sublist, and we'll need it later
    //  to connect the list back together.
    Node* subListHead = currNode;

    // Step 8: Initialize 'prevNode' to NULL because it will be used to build the reversed part of the list, starting with nothing.
    Node* prevNode = NULL;
    // Step 9: Initialize 'futureNode' to NULL because we need a temporary variable to hold the next node so we don't lose it during reversal.
    Node* futureNode = NULL;
    // Step 10: Loop from 'left' to 'right' (inclusive) because this is the exact number of nodes we need to reverse.
    for(int i=0; i<=right-left; i++){
        // Step 11: Store the next node in 'futureNode' because we are about to break the link to it.
        futureNode = currNode->next;
        // Step 12: Reverse the link of the current node to point to the previous node because this is the core step of the reversal process.
        currNode->next = prevNode;
        // Step 13: Move 'prevNode' forward to the current node because 'currNode' is now part of the reversed section.
        prevNode = currNode;
        // Step 14: Move 'currNode' forward to the next node in the original list because we need to process the next node.
        currNode = futureNode;
    }

    // Step 15: Connect the node before the sublist ('leftprev') to the new head of the reversed sublist ('prevNode') because this links the first part
    //  of the list to our reversed section.
    leftprev->next = prevNode;
    // Step 16: Connect the tail of the reversed sublist ('subListHead') to the node that comes after it ('currNode') because this links our reversed 
    // section to the rest of the list.
    subListHead->next = currNode;

    // Step 17: Return the node after the dummy node because this is the true head of the modified list, especially if the original head was part of the reversal.
    return dummyNode->next;
}

int main() {
    Node* head = NULL;

    // Insert elements into the linked list
    insert(head, 1);
    insert(head, 2);
    insert(head, 3);
    insert(head, 4);
    insert(head, 5);

    cout << "Original List: ";
    printList(head);

    int left = 2, right = 4;
    head = reverseBetween(head, left, right);

    cout << "List after reversing from position " << left << " to " << right << ": ";
    printList(head);

    return 0;
}