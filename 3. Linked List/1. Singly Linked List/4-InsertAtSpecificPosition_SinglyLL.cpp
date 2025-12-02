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

//Function To Insert Node at Head of Singly LL
// Time: O(1) , Space: O(1)
void insertAtheadSinglyLL(Node* &head, Node* &tail, int data){
  // Step 1: If the list is empty, we need to create the first node and make both head and tail point to it.
  if(head == NULL){
    // Step 2: Make a new node with the given data because there is no node yet.
    Node* newNode = new Node(data);
    // Step 3: Point head to this new node because it is now the first node.
    head = newNode;
    // Step 4: Also point tail to the same node because it is also the last node in a 1-element list.
    tail = newNode;
    // Step 5: Stop here because insertion is done for the empty-list case.
    return;
  }
  // Step 6: If the list is not empty, create a new node and put it before the current head.
  Node* newNode = new Node(data);
  // Step 7: Link the new node to the current head so it sits at the front.
  newNode->next = head;
  // Step 8: Move head to the new node because it is now the first node.
  head = newNode;
}

// Function To Insert Node At Tail In Singly LL
// Time: O(1) , Space: O(1)
void insertAtTailSinglyLL(Node* &head, Node* &tail, int data){
  // Step 1: If the list is empty, we create the first node and update both head and tail.
  if(head == NULL){
    // Step 2: Build a new node because there is no node in the list yet.
    Node* newNode = new Node(data);
    // Step 3: Head should point to the new node since it is the first node.
    head = newNode;
    // Step 4: Tail also points to the same node because it is the last node as well.
    tail = newNode;
    // Step 5: Stop here because insertion is done for the empty-list case.
    return;
  }
  // Step 6: If the list is not empty, make a new node and attach it after the current tail.
  Node* newNode = new Node(data);
  // Step 7: Connect the old tail to the new node so the new node comes last.
  tail->next = newNode;
  // Step 8: Move tail pointer to the new node because it is now the last node.
  tail = newNode;
}

// Function Find Length of Singly Linked List
//  Time: O(n) — we look at each node once ,Space: O(1) — we only use a few fixed variables
int findLengthSinglyLL(Node* head){
  // Step 1: Start counting from the head so we can measure how many nodes are in the list.
  Node* temp = head;
  int len = 1;
  // Step 2: Move through the list one node at a time until we reach NULL (end of list).
  while(temp != NULL){
    // Step 3: Increase the count because we are on a valid node.
    len++; 
    // Step 4: Go to the next node to continue counting.
    temp = temp->next; 
  }
  // Step 5: Return the total number of nodes so callers know the length of the list.
  return len;
}

// Function to Insert a new node at a given position in the list.
// TC: Insert at head or tail: O(1),Insert in the middle: O(n) (we may need to walk to the position)
// SC: O(1)
void insertAtSpecificPositionSinglyLL(Node* &head, Node* &tail, int data, int position){
  // Step 1: If the list is empty, create the first node and set both head and tail to it.
  if(head ==  NULL){
    // Step 2: Create a new node because there is no node yet.
    Node* newNode = new Node(data);
    // Step 3: Head should point to the new node since it is the first element.
    head = newNode;
    // Step 4: Tail also points to the same node because it is also the last element.
    tail = newNode;
    // Step 5: Stop here because insertion for empty list is done.
    return;
  }

  // Step 6: If position is 0, we want to add the node at the very start of the list.
  if(position == 0){
    // Step 7: Reuse the head insert function so we do not repeat code.
    insertAtheadSinglyLL(head, tail, data);
    // Step 8: Stop here because we already handled this case.
    return;
  }

  // Step 9: Find the current length to check if the insert is at the end.
  int len = findLengthSinglyLL(head);

  // Step 10: If position equals the current length, we are inserting after the last node (at the tail).
  if(position == len){
    // Step 11: Reuse the tail insert function to add at the end quickly.
    insertAtTailSinglyLL(head, tail, data);
    // Step 12: Stop here because we handled the tail case.
    return;
  }

  // (Optional safety) If position is out of range, you could handle it here.
  // For simplicity, we assume 0 <= position <= len.

  // Step 13: To insert in the middle, first walk to the node just before the desired position.
  int i=1;   //Start from 1 because position 0 was already handled above.
  Node* prev = head; //prev will stop at (position - 1)-th node.

  // Step 14: Move prev forward until it is the node right before where we want to insert.
  while(i < position){
    //Move prev one step forward to approach the target spot.
    prev = prev->next;
    //Increase i to count how many steps we have taken.
    i++;
  }
  // Step 15: curr is the node that is currently at the 'position' where the new node will be placed in front of it.
  Node* curr = prev->next;

  // Step 16: Create the new node that we want to place at the given position.
  Node* newNode = new Node(data);
  // Step 17: Point the new node to curr so it sits before the old node at that position.
  newNode->next = curr;
  // Step 18: Make prev point to the new node so the chain connects correctly.
  prev->next = newNode;
}

// Print Function Singly LL 
// Time: O(n) — prints each node once , Space: O(1)
void print(Node* &head){
  // Step 1: Start from the head to print values in order.
  Node* temp = head;
  // Step 2: Keep going until we hit NULL which means we are past the last node.
  while(temp != NULL){
    // Step 3: Print the current node's data so we can see list contents.
    cout<<temp->data<<" ";
    // Step 4: Move to the next node to continue printing.
    temp = temp->next;
  }
}

int main(){
  // Step 29: Create initial list with one node
  Node* head = new Node(10);
  Node* tail = head;

  // Step 30: Insert nodes at head
  insertAtheadSinglyLL(head, tail, 20);
  insertAtheadSinglyLL(head, tail, 30);
  insertAtheadSinglyLL(head, tail, 40);

  // Step 31: Insert node with value 1000 at position 2 (0-based index)
  insertAtSpecificPositionSinglyLL(head, tail, 1000, 2);
  // Step 32: Print the linked list
  print(head);
}