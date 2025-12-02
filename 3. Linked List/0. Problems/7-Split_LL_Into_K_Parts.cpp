#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

// Insert at head
void insertAtHead(Node*& head, Node*& tail, int data) {
    // Step 1: Check if list is empty because we need to handle first node differently
    if (head == NULL) {
        // Step 2: Create new node because we need something to put in the empty list
        Node* newNode = new Node(data);
        // Step 3: Point head to new node because this is now the first element
        head = newNode;
        // Step 4: Point tail to new node because in a single-node list, head and tail are same
        tail = newNode;
        return;
    }
    // Step 5: Create new node because we have data to add to existing list
    Node* newNode = new Node(data);
    // Step 6: Connect new node to current head because new node will become the first element
    newNode->next = head;
    // Step 7: Update head to point to new node because this is now the first element
    head = newNode;
}

// Print linked list
void PrintLL(Node* head) {
    // Step 1: Keep moving through list until we reach the end because we want to print all nodes
    while (head != NULL) {
        // Step 2: Print current node's data because we want to show what's in this node
        cout << head->data << " ";
        // Step 3: Move to next node because we need to continue through the list
        head = head->next;
    }
    // Step 4: Print newline because we want clean output formatting
    cout << endl;
}

// Function to split linked list into k parts
// Time Complexity: O(L + k) where L is length of list because we go through list once to count, then once to split
// Space Complexity: O(k) because we create a result vector of size k
vector<Node*> splitListToParts(Node* head, int k) {
    // Step 1: Create pointer to start counting nodes because we need to know total length first
    Node* curr = head;
    // Step 2: Create counter variable starting at 0 because we haven't counted any nodes yet
    int L = 0;
    // Step 3: Go through entire list counting nodes because we need total length to split evenly
    while (curr != NULL) {
        // Step 4: Add 1 to counter because we found another node to count
        L++; 
        // Step 5: Move to next node because we need to continue counting through the list
        curr = curr->next;
    }

    // Step 6: Calculate base size for each part because we need to divide nodes as evenly as possible
    int eachBucketNodes = L / k;
    // Step 7: Calculate how many parts get extra nodes because division might not be exact
    int remainderNodes = L % k;
    // Step 8: Create result vector with k empty parts because we need k separate lists to return
    vector<Node*> result(k, NULL);
    // Step 9: Reset pointer to start of original list because now we need to actually split it
    curr = head;
    // Step 10: Create previous pointer as NULL because we'll need it to break connections between parts
    Node* prev = NULL;

    // Step 11: Loop k times because we need to create exactly k parts
    for (int i = 0; i < k; i++) {
        // Step 12: Set start of this part to current node because this is where this part begins
        result[i] = curr;
        // Step 13: Calculate nodes for this part because some parts get extra nodes from remainder
        int nodesThisPart = eachBucketNodes + (remainderNodes > 0 ? 1 : 0);
        // Step 14: Move through nodes for this part because we need to find where this part ends
        for (int count = 1; count <= nodesThisPart; count++) {
            // Step 15: Remember current node as previous because we'll need to cut connection after this
            prev = curr;
            // Step 16: Check if current node exists because we might run out of nodes
            if (curr != NULL) {
                // Step 17: Move to next node because we're still building this part
                curr = curr->next;
            }
        }
        
        // Step 18: Check if we had nodes in this part because empty parts don't need cutting
        if (prev != NULL) {
            // Step 19: Break connection to next part because each part must be separate list
            prev->next = NULL;
        }
        // Step 20: Reduce remainder count because we used one extra node for this part
        remainderNodes--;
    }
    
    // Step 21: Return vector with all parts because this is what the function promises to give back
    return result;
}

int main() {
    // Step 1: Create head pointer as NULL because list starts empty
    Node* head = NULL;
    // Step 2: Create tail pointer as NULL because list starts empty
    Node* tail = NULL;

    // Step 3: Build linked list 1->2->3->4->5->6->7 by inserting at head because we want test data
    insertAtHead(head, tail, 7);
    insertAtHead(head, tail, 6);
    insertAtHead(head, tail, 5);
    insertAtHead(head, tail, 4);
    insertAtHead(head, tail, 3);
    insertAtHead(head, tail, 2);
    insertAtHead(head, tail, 1);

    // Step 4: Print original list because user wants to see what we're splitting
    cout << "Original list: ";
    PrintLL(head);

    // Step 5: Set k to 3 because we want to split into 3 parts for testing
    int k = 3;
    // Step 6: Call split function because this is the main operation we want to test
    vector<Node*> parts = splitListToParts(head, k);

    // Step 7: Print header for results because user needs to see the split parts clearly
    cout << "\nSplitted lists:\n";
    // Step 8: Loop through all parts because we want to show each part separately
    for (int i = 0; i < k; i++) {
        // Step 9: Print part number because user needs to know which part this is
        cout << "Part " << i + 1 << ": ";
        // Step 10: Print this part's nodes because user wants to see the actual split result
        PrintLL(parts[i]);
    }

    // Step 11: Return 0 because program finished successfully
    return 0;
}