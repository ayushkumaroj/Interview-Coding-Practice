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

  ~Node(){
    cout<<"Deleted value "<<this->data;
  }
};

void insertAtHead(Node* &head, int data){
  if(head == NULL){
    Node* newNode = new Node(data);
    head = newNode;
  }

  Node* newNode = new Node(data);
  newNode->next = head;
  head = newNode;
}

// Function to Delete Head of Singly LL
// Time Complexity: O(1) , Space Complexity: O(1)
void DeleteHeadSinglyLL(Node* &head, Node* &tail){
  // Step 1: If list is empty, there’s nothing to delete.
  if(head == NULL){
    cout<<"Cannot delete LL is empty";
    return;
  }
  // Step 2: Store the current head in a temp variable to delete later.
  Node* temp = head;
  // Step 3: Move head pointer to the next node (new first node).
  head = head->next;
  // Step 4: Disconnect old head from the list so it’s safe to delete.
  temp->next = NULL;
  // Step 5: Delete the old head to free memory.
  delete temp;
  return;
}

// Function to Find Length of Singly LL
int LengthLinkedList(Node* &head){
  int len  = 0;
  Node* temp = head;

  while(temp != NULL){
    len++;
    temp = temp->next;
  }

  return len;
}

// Function to delete tail of singly LL
// Time Complexity: O(n) — must find node before tail. , Space Complexity: O(1)
void DeleteTailSinglyLL(Node* &head, Node* &tail){
  // Step 1: Find total size of linked list to locate second last node.
  int TotalSize = LengthLinkedList(head);

  // Step 2: Start from head and stop at node just before tail.
  int i = 1;
  Node* prev = head;
  while(i < TotalSize-1){
    prev = prev->next;
    i++;
  }
  // Step 3: Disconnect last node from list.
  prev->next = NULL;
  // Step 4: Store current tail in temp so we can delete it.
  Node* temp = tail;
  // Step 5: Update tail to new last node.
  tail = prev;
  // Step 6: Delete the old tail node.
  delete temp;
  return;
}

//Delete Specific Node
// Time Complexity: O(n) because we might need to go through the list to find the position
// Space Complexity: O(1) because we only use a few extra variables
void DeleteSpecificNode(Node* &head, Node* &tail, int postionToDel){
  // Step 1: Check if list is empty because we cannot delete from nothing
  if(head == NULL){
    cout<<"Linked List is empty Nothing to delete";
    return;
  }
  
  // Step 2: Check if we want to delete first node because head deletion needs special handling
  if(postionToDel == 1){
    // Step 3: Call existing head deletion function because it already handles head and tail updates properly
    DeleteHeadSinglyLL(head, tail);
    return;
  }

  // Step 4: Get total length of list because we need to know if we're deleting the last node
  int sizeOfLL = LengthLinkedList(head);

  // Step 5: Check if we're deleting the last node because tail deletion needs special handling
  if(postionToDel == sizeOfLL){
    // Step 6: Call existing tail deletion function because it already handles tail updates properly
    DeleteTailSinglyLL(head, tail);
    return;
  }

  // Step 7: Start counter at 1 because positions start from 1, not 0
  int i=1;
  // Step 8: Start from head because we need to find the node before deletion target
  Node* prev = head;
  // Step 9: Move to position just before the node to delete because we need prev to fix connections
  while(i < postionToDel-1){
    // Step 10: Move one step forward because we're getting closer to target position
    prev = prev->next;
    // Step 11: Increase counter because we moved one position forward
    i++;
  }

  // Step 12: Get pointer to node we want to delete because we need to remove this specific node
  Node* curr = prev->next;
  // Step 13: Connect previous node to the node after current because we're removing current from the chain
  prev->next = curr->next;
  // Step 14: Break current node's connection to rest of list because we want to isolate it before deletion
  curr->next = NULL;
  // Step 15: Free memory of the deleted node because we don't want memory leaks
  delete curr;
  return;
}

void PrintLL(Node* &head){
  Node* temp = head;
  while(temp != NULL){
    cout<<temp->data<<" ";
    temp = temp->next;
  }
}

int main(){
  Node* head = new Node(10);
  Node* tail = head;

  insertAtHead(head, 20);
  insertAtHead(head, 30);
  insertAtHead(head, 40);
  insertAtHead(head, 50);

  PrintLL(head);
  cout<<endl;
  DeleteSpecificNode(head, tail, 2);
  cout<<endl;
  PrintLL(head);
}