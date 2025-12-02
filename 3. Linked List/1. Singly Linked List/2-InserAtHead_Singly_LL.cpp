#include<iostream>
using namespace std;

// Step 1: Define a Node class to represent each element in the linked list
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

// Function: Insert a new node at the beginning (head) of the linked list. 
// TC: O(1) , Always takes constant time because we only adjust a few pointers.
// Space Complexity: O(1) -> No extra space except the new node.
void insertAtHead(Node* &head, Node* &tail, int data){
  // Step 2: Check if the linked list is empty (head is NULL)
  if(head == NULL){
    // Step 3: Create a new node because the list is empty
    Node* newNode = new Node(data);
    // Step 4: Make this new node both head and tail (as it's the only node)
    head = newNode;
    tail = newNode;
    // Step 5: Exit function because insertion is complete
    return;
  }

  // Step 6: If the list is NOT empty, create a new node with given data
  Node* newNode = new Node(data);
  // Step 7: Link this new node to the current head
  newNode->next = head;
  // Step 8: Update head to point to this new node
  head = newNode;
}

// Step 9: Print all nodes of the linked list.
void PrintLL(Node* &head){
  Node* temp = head;

  while(temp != NULL){
    cout<<temp->data<<" ";
    temp = temp->next;
  }
}

int main(){
  // Step 10: Initially create the first node with data = 10
  Node* head = new Node(10);
  // Step 11: Since the list has one node, tail will point to head
  Node* tail = head;

  // Step 12: Insert new nodes at the head (beginning of the list)
  insertAtHead(head, tail, 20); // Insert 20 at head
  insertAtHead(head, tail, 30); // Insert 30 at head
  insertAtHead(head, tail, 40); // Insert 40 at head

  // Step 13: Print the linked list
  PrintLL(head);
}
// Note: Code will be same for Node class and Print ll
