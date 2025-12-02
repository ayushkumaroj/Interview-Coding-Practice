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


// function finds the k-th node starting from a given node temp.
// Time Complexity: O(k) because it loops at most k times to find the node.
// Space Complexity: O(1) because it only uses a few extra variables, not depending on the list size.
Node* getKthNode(Node* temp, int k){
    // Step 1: Decrease k by 1 because we are already at the first node, so we only need to move k-1 more times.
    k = k-1;
    // Step 2: Loop until we have moved k-1 steps or we reach the end of the list because we need to find the k-th node without going past the end.
    while(temp != NULL && k>0){
        // Step 3: Decrease k by 1 in each step because we are counting down the moves we need to make.
        k--;
        // Step 4: Move to the next node in the list because this is how we step forward through the list.
        temp = temp->next;
    }
    // Step 5: Return the node we found because this is the k-th node we were looking for, or NULL if it doesn't exist.
    return temp;
}

// function reverses a given linked list.
// Time Complexity: O(N) because it visits every node in the list once to reverse it.
// Space Complexity: O(1) because it only uses a few pointer variables to do the reversal.
Node* ReverseLL(Node* head){
    // Step 1: Create a 'curr' pointer starting at the head because we need a pointer to travel through the list.
    Node* curr = head;
    // Step 2: Create a 'prev' pointer and set it to NULL because this will track the previous node and will eventually become the new head.
    Node* prev = NULL;
    // Step 3: Create a 'future' pointer and set it to NULL because we need to temporarily store the next node before we break the link to it.
    Node* future = NULL;

    // Step 4: Loop through the entire list until 'curr' becomes NULL because we need to visit every single node to reverse it.
    while(curr != NULL){
        // Step 5: Store the next node in 'future' because we are about to change 'curr->next' and we don't want to lose the rest of the list.
        future = curr->next;
        // Step 6: Make the current node's next pointer point to the previous node because this is the main step that actually reverses the link.
        curr->next = prev;
        // Step 7: Move 'prev' up to the current node because the current node is now the last node in our reversed section.
        prev = curr;
        // Step 8: Move 'curr' up to the next node (which we saved in 'future') because we need to continue processing the rest of the original list.
        curr = future;
    }
    // Step 9: Update the head to be 'prev' because after the loop, 'prev' is pointing to the first node of the new, reversed list.
    head = prev;
    // Step 10: Return the new head of the reversed list because the reversal is complete.
    return head;
}

//  function reverses a linked list in groups of k nodes.
// Time Complexity: O(N) because we go through each node a constant number of times (once to find the k-th node and once to reverse it).
// Space Complexity: O(1) because we only use a constant amount of extra memory (a few pointers).
Node* reverseKGroup(Node* head, int k){
    // Step 1: Create a 'temp' pointer starting at the head because we need a pointer to mark the beginning of each k-group.
    Node* temp = head;
    // Step 2: Create a 'prevNode' pointer and set it to NULL because we need to store the last node of the previously reversed group to connect it to the next one.
    Node* prevNode = NULL;

    // Step 3: Loop as long as there are nodes left to process because we need to check the entire list for k-groups.
    while(temp != NULL){
        // Step 4: Find the k-th node of the current group because we need to know where the group ends and if it's a full group of k nodes.
        Node* kthNode = getKthNode(temp, k);
        // Step 5: Check if a full k-group exists because if not, the remaining nodes should be left as they are.
        if(kthNode == NULL){
            // Step 6: Check if we have reversed any groups before because if so, we need to connect the last reversed group to the remaining nodes.
            if(prevNode != NULL){
                // Step 7: Connect the tail of the previous reversed group to the start of the remaining nodes because this joins the parts of the list back together.
                prevNode->next = temp;
            }
            // Step 8: Exit the loop because there are no more full k-groups left to reverse.
            break;
        }
        // Step 9: Store the node that comes after the current k-group because we need to know where the next group starts after we reverse the current one.
        Node* futureNode = kthNode->next;
        // Step 10: Isolate the current k-group by setting its last node's next to NULL because the reverse function needs to know where the sub-list ends.
        kthNode->next = NULL;
        // Step 11: Reverse the isolated k-group because that is the main goal of the function.
        ReverseLL(temp);
        
        // Step 12: Check if this was the very first group in the list because if so, we need to update the main head of the entire list.
        if(temp == head){
            // Step 13: The new head of the list is now the k-th node (which became the head after reversal) because this is the start of the modified list.
            head = kthNode;
        }else{
            // Step 14: Connect the previous group's tail ('prevNode') to the current group's new head ('kthNode') because this links the reversed groups together.
            prevNode->next = kthNode;
        }
        // Step 15: Update 'prevNode' to be the tail of the group we just reversed ('temp' is now the tail) because we will need it for the next connection.
        prevNode = temp;
        // Step 16: Move 'temp' to the start of the next group because we need to continue the process for the rest of the list.
        temp = futureNode;
    }
    // Step 17: Return the new head of the fully modified list because the operation is complete.
    return head;
}


// Function to insert a node at the end
void insert(Node* &head, int data) {
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
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    Node* head = NULL;

    // Inserting elements
    insert(head, 1);
    insert(head, 2);
    insert(head, 3);
    insert(head, 4);
    insert(head, 5);
    insert(head, 6);

    cout << "Original List: ";
    printList(head);

    int k = 2;
    head = reverseKGroup(head, k);

    cout << "Reversed in groups of " << k << ": ";
    printList(head);

    return 0;
}
