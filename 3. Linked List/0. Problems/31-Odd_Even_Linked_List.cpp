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

// Time Complexity: O(N) because we visit each node in the list exactly once.
// Space Complexity: O(1) because we rearrange the list in place using only a few extra pointers, not extra memory that grows with the list size.
Node* oddEvenList(Node* head){
    // Step 1: Check if the list is empty or has only one node because in these cases, the list is already correctly arranged.
    if(head == NULL || head->next == NULL){
        return head;
    }

    // Step 2: Create a pointer 'odd' for the odd-numbered positions, starting at the first node.
    Node* odd = head;
    // Step 3: Create a pointer 'even' for the even-numbered positions, starting at the second node.
    Node* even = head->next;
    // Step 4: Save the starting point of the even list because we will need to connect the end of the odd list to it later.
    Node* evenStart = head->next;

    // Step 5: Start a loop that continues as long as there are at least two more nodes to process because this ensures we have a valid odd and even node to link.
    while(even != NULL && even->next != NULL){
        // Step 6: Connect the current odd node to the next odd node because this skips over the even node that is in between them.
        odd->next = even->next;
        // Step 7: Connect the current even node to the next even node because this skips over the odd node that is in between them.
        even->next = even->next->next;

        // Step 8: Move the 'odd' pointer to the new end of the odd list because we have just added a node to it.
        odd = odd->next;
        // Step 9: Move the 'even' pointer to the new end of the even list because we have just added a node to it.
        even = even->next;
    }
    // Step 10: Connect the end of the odd list to the start of the even list because the separation is done and we need to join them to form the final list.
    odd->next = evenStart;
    // Step 11: Return the original head because the first node (which is odd) never changes its position as the start of the list.
    return head;
}

// Function to insert a node at the end of the list
void insertAtTail(Node* &head, int data) {
    Node* newNode = new Node(data);
    if(head == NULL) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while(temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to print the linked list
void printList(Node* head) {
    Node* temp = head;
    while(temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    Node* head = NULL;

    // Example Input: 1 -> 2 -> 3 -> 4 -> 5
    int n;
    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter " << n << " elements: ";
    for(int i = 0; i < n; i++) {
        int val;
        cin >> val;
        insertAtTail(head, val);
    }

    cout << "Original List: ";
    printList(head);

    head = oddEvenList(head);

    cout << "Rearranged List (Odd positions first, Even positions next): ";
    printList(head);

    return 0;
}