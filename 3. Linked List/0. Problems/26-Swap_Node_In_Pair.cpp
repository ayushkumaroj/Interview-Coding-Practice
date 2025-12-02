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
// Space Complexity: O(1) because we only use a few extra pointers and do not need extra memory that grows with the list size.
Node* swapPairsIterative(Node* head){
    // Step 1: Check if the list has 0 or 1 nodes because in that case, there is nothing to swap.
    if(head == NULL || head->next == NULL){
        return head;
    }

    // Step 2: Create a 'prev' pointer to keep track of the node before the current pair because we need to connect the previous part 
    // of the list to the newly swapped pair.
    Node* prev = NULL;
    // Step 3: 'first' is the first node of the pair we are about to swap.
    Node* first = head;
    // Step 4: 'second' is the second node of the pair we are about to swap.
    Node* second = head->next;
    // Step 5: 'future' will point to the node after the pair because we need to save a link to the rest of the list before we change any pointers.
    Node* future = NULL;

    // Step 6: Loop as long as we have a complete pair of nodes (first and second) to swap.
    while(first != NULL && second != NULL){
        // Step 7: Save the start of the next pair in 'future' because we are about to change 'second->next' and would lose the rest of the list otherwise.
        future = second->next;
        // Step 8: Point the second node to the first node because this is the main step of the swap.
        second->next = first;
        // Step 9: Point the first node to the 'future' node because this connects our swapped pair to the rest of the list.
        first->next = future;

        // Step 10: Check if 'prev' exists because if it does, we need to link the end of the previous pair to the start of our new swapped pair.
        if(prev != NULL){
            // Step 11: Connect the previous part of the list to 'second' because 'second' is now the new head of the current pair.
            prev->next = second;
        }else{
            // Step 12: If 'prev' is NULL, it means this was the very first pair, so 'second' becomes the new head of the entire list.
            head = second;
        }

        // Step 13: Update 'prev' to be 'first' because for the next iteration, 'first' will be the node just before the next pair.
        prev = first;
        // Step 14: Move 'first' to 'future' to start processing the next pair.
        first = future;
        // Step 15: Check if there is a next pair to process because if 'future' is not NULL, a new pair exists.
        if(future != NULL){
            // Step 16: Set 'second' to be the second node of the next pair.
            second = future->next;
        }else{
            // Step 17: If there is no next pair, set 'second' to NULL because this will stop the while loop.
            second = NULL;
        }
    }
    // Step 18: Return the new head of the list because the original head has been changed if there was at least one pair.
    return head;
}

// Time Complexity: O(N) because the function is called for each node in the list once.
// Space Complexity: O(N) because the function calls are stored on the call stack, which could be as deep as N/2 calls.
Node* swapPairsRecursive(Node* head){
    // Step 1: This is the base case. If the list is empty or has only one node, we can't swap, so we return it as is. This stops the recursion.
    if(head == NULL || head->next == NULL){
        return head;
    }

    // Step 2: Create a 'temp' pointer to the second node (head->next) because this node will become the new head of this pair after swapping.
    Node* temp = head->next;
    // Step 3: Make a recursive call to swap the rest of the list starting from the third node (head->next->next) because we need to solve the smaller problem first.
    // Step 4: Link the first node's 'next' pointer to the result of the recursive call because this connects the current pair to the already-swapped rest-of-the-list.
    head->next = swapPairsRecursive(head->next->next);
    // Step 5: Complete the swap by pointing the second node ('temp') back to the first node ('head').
    temp->next = head;
    // Step 6: Return 'temp' because it is now the head of this swapped pair, and it will be used by the previous function call to link its list.
    return temp;
}

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

    // Inserting nodes
    int n;
    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        insertNode(head, val);
    }

    cout << "\nOriginal List: ";
    printList(head);

    // Using Iterative Approach
    Node* iterativeResult = swapPairsIterative(head);
    cout << "After Pair Swap (Iterative): ";
    printList(iterativeResult);

    // Resetting the list for Recursive Approach
    head = NULL;
    cout << "\nRe-enter elements for Recursive Swap: ";
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        insertNode(head, val);
    }

    cout << "Original List: ";
    printList(head);

    // Using Recursive Approach
    Node* recursiveResult = swapPairsRecursive(head);
    cout << "After Pair Swap (Recursive): ";
    printList(recursiveResult);

    return 0;
}