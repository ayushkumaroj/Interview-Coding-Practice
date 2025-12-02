#include<iostream>
using namespace std;

// Definition for singly-linked list.
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
// Time Complexity: O(2n) → O(n), Space Complexity: O(1)
// Using Two Pass Solution
Node* DeleteKthNodeFromEnd(Node* &head, int k){
  // Step 1: Create a dummy node with data 0 because we need a node before head to handle edge cases like deleting the first node
  Node* dummyNode = new Node(0);
  // Step 2: Connect dummy node to the original head because dummy node acts as a safe starting point that won't get deleted
  dummyNode->next = head;
  // Step 3: Initialize length counter to 0 because we need to count how many nodes are in the entire list
  int length = 0;
  // Step 4: Create temp pointer starting at head because we need to traverse the list without changing the original head
  Node* temp = head;
  // Step 5: Traverse the entire list to count total nodes because we need the length to calculate the position from start
  while(temp != NULL){
    // Step 6: Increment length counter because we found another node to count
    length++;
    // Step 7: Move to next node because we need to count all nodes in the list
    temp = temp->next;
  }
  // Step 8: Reset temp to dummy node because we need to start from before the head to find the node before our target
  temp = dummyNode;
  // Step 9: Calculate position to delete from start because kth from end equals (length-k+1)th from start
  int posToDelFromStart = length-k+1;

  // Step 10: Initialize counter to 1 because we're counting positions starting from 1
  int i=1;
  // Step 11: Move temp to the node just before our target position because we need the previous node to change its next pointer
  while(i < posToDelFromStart-1){
    // Step 12: Increment counter because we're moving one position forward
    i++;
    // Step 13: Move temp to next node because we're getting closer to the node before our target
    temp = temp->next;
  }
  // Step 14: Skip over the target node by connecting current node directly to the node after target because this removes the target node from the chain
  temp->next = temp->next->next;
  // Step 15: Return dummy node's next pointer because this points to the new head of the modified list
  return dummyNode->next;
}

// Time Complexity: O(n), Space Complexity: O(1)
// Using One Pass Solution - Using Slow and Fast pointer
Node* DeleteKthNodeFromEnd2(Node* &head, int k){
  // Step 1: Create a dummy node with data 0 because we need a node before head to handle edge cases like deleting the first node
  Node* dummyNode = new Node(0);
  // Step 2: Connect dummy node to the original head because dummy node acts as a safe starting point that won't get deleted
  dummyNode->next = head;

  // Step 3: Initialize fast pointer at dummy node because fast pointer will move ahead first to create the required gap
  Node* fast = dummyNode;
  // Step 4: Initialize slow pointer at dummy node because slow pointer will end up at the node before our target for deletion
  Node* slow = dummyNode;

  // Step 5: Move fast pointer k+1 steps ahead because we need a gap of k+1 between fast and slow to find kth node from end
  for(int i=0; i<=k; i++){
    // Step 6: Move fast pointer one step forward because we're creating the required distance between fast and slow pointers
    fast = fast->next;
  }

  // Step 7: Move both pointers until fast reaches the end because when fast reaches end, slow will be k+1 positions behind (at node before target)
  while(fast != NULL){
    // Step 8: Move fast pointer one step forward because we need to continue until fast reaches the null end
    fast = fast->next;
    // Step 9: Move slow pointer one step forward because slow must maintain the k+1 gap behind fast pointer
    slow = slow->next;
  }

  // Step 10: Skip over the target node by connecting slow to the node after the target because this removes the kth node from end
  slow->next = slow->next->next;

  // Step 11: Return dummy node's next pointer because this points to the new head of the modified list
  return dummyNode->next;
}



// Function to insert a new node at the end of the list
void insertNode(Node* &head, int data) {
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
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

// Main function
int main() {
    Node* head = NULL;

    // Insert nodes
    insertNode(head, 10);
    insertNode(head, 20);
    insertNode(head, 30);
    insertNode(head, 40);
    insertNode(head, 50);

    cout << "Original List: ";
    printList(head);

    int k;
    cout << "Enter the value of k to delete kth node from end: ";
    cin >> k;

    head = DeleteKthNodeFromEnd(head, k);

    cout << "Modified List: ";
    printList(head);

    return 0;
}
