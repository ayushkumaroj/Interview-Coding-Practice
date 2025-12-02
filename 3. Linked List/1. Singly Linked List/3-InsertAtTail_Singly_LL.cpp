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

void printLL(Node* &head){
  Node* temp = head;

  while(temp != NULL){
    cout<<temp->data<<" ";
    temp = temp->next;
  }
}

// Function: Insert a new node at the tail (head) of the linked list.
// TC: O(1) -> Because we have direct access to tail, no traversal needed
// SC: O(1) -> Only one new node created
void InsertAtTail(Node* &head, Node* &tail, int data){
  // Step 1: If linked list is empty (head is NULL), we create the first node
  if(head == NULL){
    // Step 2: Create a new node with the given data
    Node* newNode = new Node(data);
    // Step 3: This new node will be both head and tail since it's the only node
    head = newNode;
    tail = newNode;
    // Step 4: Exit the function because insertion is done
    return;
  }

  // Step 5: If linked list is NOT empty, create a new node with given data
  Node* newNode = new Node(data);
  // Step 6: Connect the current tail node to the new node
  tail->next = newNode;
  // Step 7: Move the tail pointer to the new node because it is now the last node
  tail = newNode;
}

int main(){
  // Step 8: Create the first node with value 10 and make head point to it
  Node* head = new Node(10);
  // Step 9: Since there is only one node, tail will also point to head
  Node* tail = head;
  
  // Step 10: Insert new nodes at the tail of the linked list
  InsertAtTail(head, tail, 30); // Now list: 10 -> 30
  InsertAtTail(head, tail, 40); // Now list: 10 -> 30 -> 40
  InsertAtTail(head, tail, 50); // Now list: 10 -> 30 -> 40 -> 50
  InsertAtTail(head, tail, 60); // Now list: 10 -> 30 -> 40 -> 50 -> 60

  printLL(head); // Step 11: Print the entire linked list
}
