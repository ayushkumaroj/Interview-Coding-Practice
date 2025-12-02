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

Node* findNthNode(Node* temp, int k){
    int count = 1;
    while(temp != NULL){
        if(count == k){
            return temp;
        }
        count++;
        temp = temp->next;
    }
    return temp;
}

// Time Complexity: O(N) because we go through the list once to find the length, and then a second time to find the new last node.
// Space Complexity: O(1) because we only use a few pointers and variables to perform the rotation.
Node* rotate_list_Right(Node* head, int k){
    // Step 1: Check if the list is empty or if k is 0 because if so, no rotation is needed and we can return the list as it is.
    if(head == NULL || k==0){
        return head;
    }

    // Step 2: Create a 'tail' pointer starting at the head because we need to find the last node of the list.
    Node* tail = head;
    // Step 3: Create a 'len' counter starting at 1 because we need to find the total length of the list.
    int len = 1;
    // Step 4: Loop until we are at the last node of the list because we need to find the tail and the length.
    while(tail->next != NULL){
        // Step 5: Move the 'tail' pointer forward.
        tail = tail->next;
        // Step 6: Increase the length counter.
        len = len+1;
    }

    // Step 7: Check if k is a multiple of the length because if it is, rotating the list will bring it back to the same starting position.
    if(k % len == 0){
        return head;
    }

    // Step 8: Update k to be the remainder of k divided by length because rotating by len+1 is the same as rotating by 1.
    k = k % len;

    // Step 9: Connect the last node ('tail') to the first node ('head') because this temporarily makes the list a circle, which makes it easy to rotate.
    tail->next = head;
    // Step 10: Find the node that will become the new last node of the list because this is the node at position (len - k).
    Node* newLastNode = findNthNode(head, len-k);

    // Step 11: Set the new head of the list because it is the node that comes right after our new last node.
    head = newLastNode->next;
    // Step 12: Break the circle by setting the next of the new last node to NULL because this officially makes it the end of the list.
    newLastNode->next = NULL;
    // Step 13: Return the new head of the rotated list.
    return head;
}

// ------------------- Insert at End -------------------
void insertNode(Node*& head, int data) {
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

// ------------------- Print Linked List -------------------
void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// ------------------- Main Function -------------------
int main() {
    Node* head = NULL;
    int n, k;

    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        insertNode(head, val);
    }

    cout << "Enter k (positions to rotate right): ";
    cin >> k;

    cout << "\nOriginal Linked List: ";
    printList(head);

    head = rotate_list_Right(head, k);

    cout << "Rotated Linked List: ";
    printList(head);

    return 0;
}