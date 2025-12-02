#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node() {
        this->data = 0;
        this->next = NULL;
    }

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

// Time Complexity: O(N) because even with a nested loop, each node is visited a constant number of times in total.
// Space Complexity: O(1) because we only use a few extra pointers and do not use any extra space that grows with the list size.
Node* removeAllDuplicatesInSortedList(Node* head) {
    // Step 1: Check if the list is empty or has only one node because in that case, no duplicates can exist.
    if (head == NULL || head->next == NULL) {
        return head;
    }

    // Step 2: Create a 'dummyNode' because the original head of the list might be a duplicate and need to be removed. This gives us a safe starting point.
    Node* dummyNode = new Node(0);
    // Step 3: Connect the dummyNode to the actual head of the list.
    dummyNode->next = head;

    // Step 4: Create a 'prev' pointer, starting at the dummyNode because it will always point to the last node that is not a duplicate.
    Node* prev = dummyNode;
    // Step 4: Create a 'prev' pointer, starting at the dummyNode because it will always point to the last node that is not a duplicate.
    Node* curr = head;

    // Step 6: Loop through the list until we have checked every node.
    while (curr != NULL) {
        // Step 7: Check if the current node is the beginning of a sequence of duplicates by looking at the next node.
        if (curr->next != NULL && curr->data == curr->next->data) {
            // Step 8: If it is a duplicate, start an inner loop to skip over all the nodes that have the same value.
            while (curr->next != NULL && curr->data == curr->next->data) {
                // Step 9: Keep moving 'curr' forward until it points to the last node in the duplicate sequence.
                curr = curr->next;
            }
            // Step 10: Remove the entire sequence of duplicates by linking 'prev' to the node that comes after the sequence.
            prev->next = curr->next;
        } else {
            // Step 11: If the current node is not a duplicate, it's a unique number we want to keep, so we move 'prev' forward.
            prev = prev->next;
        }
        // Step 12: Move 'curr' forward to check the next node in the list.
        curr = curr->next;
    }
    // Step 13: Return the node after the dummyNode because that is the new head of the list after removing all duplicates.
    return dummyNode->next;
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
    int n;

    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter elements (sorted order): ";
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        insertNode(head, val);
    }

    cout << "\nOriginal Linked List: ";
    printList(head);

    head = removeAllDuplicatesInSortedList(head);

    cout << "Linked List after removing all duplicates: ";
    printList(head);

    return 0;
}
