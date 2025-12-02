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

// Time Complexity: O(N) because we travel through the list with fast and slow pointers to find the middle, which takes linear time.
// Space Complexity: O(1) because we only use a few extra pointers and do not use any extra space that grows with the list size.
pair<Node* ,Node*> splitList(Node* head){
    // Step 1: Check if the list is empty because if it is, we cannot split it, so we return two empty lists.
    if(head == NULL){
        return {NULL, NULL};
    }

    // Step 2: Create two pointers, 'slow' and 'fast', both starting at the head because we will use them to find the middle of the circular list.
    Node* slow = head;
    Node* fast = head;

    // Step 3: Start a loop where 'fast' moves two steps and 'slow' moves one step because this is how we find the middle of the list. The loop stops
    //  when 'fast' is near the end.
    while(fast->next != head && fast->next->next != head){
        // Step 4: Move 'fast' two nodes ahead and 'slow' one node ahead because this technique ensures 'slow' will be at the last node of the first 
        // half when the loop ends.
        fast = fast->next->next;
        slow = slow->next;
    }
    // Step 5: Check if the list has an even number of nodes because if it does, we need to move 'fast' one more step so it points to the very last node.
    if(fast->next->next == head){
        fast = fast->next;
    }

    // Step 6: The head of the first new list is the same as the original head because the first half starts from the beginning.
    Node* head1 = head;
    // Step 7: The head of the second new list starts right after where the 'slow' pointer stopped because 'slow' is the end of the first half.
    Node* head2 = slow->next;
    // Step 8: Make the second list circular because 'fast' is the last node of the original list, and it now needs to point to the start of the second half ('head2').
    fast->next = slow->next;
    // Step 9: Make the first list circular because 'slow' is the last node of the first half, and it now needs to point back to its own start ('head1').
    slow->next = head;
    // Step 10: Return the pair of new heads because the original list has now been split into two.
    return {head1, head2};
}

// Function to insert node in a circular linked list
Node* insert(Node* head, int data) {
    Node* newNode = new Node(data);
    if (!head) {
        newNode->next = newNode;
        return newNode;
    }

    Node* temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = head;
    return head;
}

// Function to print a circular linked list
void printList(Node* head) {
    if (!head) return;
    Node* temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}

int main() {
    Node* head = NULL;

    // Insert nodes
    head = insert(head, 1);
    head = insert(head, 2);
    head = insert(head, 3);
    head = insert(head, 4);
    head = insert(head, 5);
    head = insert(head, 6);

    cout << "Original Circular Linked List: ";
    printList(head);

    // Split the list
    pair<Node*, Node*> halves = splitList(head);
    Node* head1 = halves.first;
    Node* head2 = halves.second;

    cout << "First Half: ";
    printList(head1);

    cout << "Second Half: ";
    printList(head2);

    return 0;
}