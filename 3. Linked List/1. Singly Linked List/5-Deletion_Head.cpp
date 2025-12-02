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
    cout<<"Deleted value "<<this->data <<endl;
  }
};

void insertAtHead(Node* &head, int data){
  if(head == NULL){
    Node* newNode = new Node(data);
    head = newNode;
  }else{
    Node* newNode = new Node(data);
    newNode->next = head;
    head = newNode;
  }
}

// TC: O(1)  -> deleting the head node uses a fixed number of operations.
// SC: O(1)
void DeleteHead(Node* &head, Node* &tail){
  // Step 1: Check if the linked list is empty.If head is NULL there is nothing to remove, so print a message and stop.
  if(head == NULL){
    cout<<"Cannot delete LL is empty";
    return;
  }
  // Step 2: Save the current head in a temporary pointer. bcz  We keep temp so we can delete the old head after moving the head pointer.
  Node* temp = head;
  // Step 3: Move head to the next node.This makes the second node (if any) the new head. If there was only one node, head becomes NULL.
  head = head->next;
  // Step 4: Disconnect the old head from the list.Setting temp->next = NULL removes any link from the node we will delete to the list (good practice).
  temp->next = NULL;
  // Step 5: Free the memory of the old head node. delete temp removes the node and prevents a memory leak.
  delete temp;

  // Step 6: If the list is now empty, update tail to reflect that.If head is NULL after deletion, the list became empty so tail should also be NULL.
  if(head == NULL){
    // Set tail to NULL.
    tail = NULL;
  }
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
  DeleteHead(head, tail);
  cout<<endl;
  PrintLL(head);
}