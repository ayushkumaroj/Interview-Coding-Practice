#include<iostream>
using namespace std;

class Node{
  public:
  int data;
  Node* prev;
  Node* next;

  // Step 1: Create a default constructor that sets everything to safe starting values because we need a way to make empty nodes without crashing.
  Node(){
    // Step 2: Set data to 0 because we need some default number value when no data is given.
    this->data = 0;
    // Step 3: Set next pointer to NULL because this node doesn't connect to anything yet and NULL means "nothing".
    this->next = NULL;
    // Step 4: Set prev pointer to NULL because this node doesn't connect backward to anything yet.
    this->prev = NULL;
  }

  // Step 5: Create a constructor that takes data as input because we often want to create a node with specific data right away.
  Node(int data){
    // Step 6: Store the given data in this node because that's what we want this node to hold.
    this->data = data;
    // Step 7: Set next to NULL because this new node doesn't connect forward to anything yet.
    this->next = NULL;
    // Step 8: Set prev to NULL because this new node doesn't connect backward to anything yet.
    this->prev = NULL;
  }
};

// Function to insert a node at the head of the list.
// Time: O(1) - Only a few simple steps no matter how big the list is, Space: O(1) - Only creates one new node
void InsertAtHead(Node* &head, Node* &tail, int data){
  // Step 1: Check if head is NULL to see if list is completely empty because empty lists need special handling.
  if(head == NULL){
    // Step 2: Create a new node with the given data because we need something to put in our empty list.
    Node* newNode = new Node(data);
    // Step 3: Make head point to our new node because head should always point to the first item.
    head = newNode;
    // Step 4: Make tail point to our new node too because in a list with only one item, head and tail point to same thing.
    tail = newNode;
    // Step 5: Return immediately because we're done - no more steps needed for empty list.
    return;
  }

  // Step 6: Create a new node with given data because this will become our new first item.
  Node* newNode = new Node(data);
  // Step 7: Make new node's next pointer point to current head because new node needs to connect to what used to be first.
  newNode->next = head;
  // Step 8: Make current head's prev pointer point back to new node because doubly linked lists connect both ways.
  head->prev = newNode;
  // Step 9: Change head to point to new node because new node is now the actual first item in list.
  head = newNode;
}

// Function To Insert At Tail
// Time: O(1) - Just attach to end without searching, Space: O(1) - Only one new node created
void InsertAtTail(Node* &head, Node* &tail, int data){
  // Step 1: Check if head is NULL to see if list is empty because empty lists need different handling.
  if(head == NULL){
    // Step 2: Create new node with given data because we need something to put in our empty list.
    Node* newNode = new Node(data);
    // Step 3: Set head to point to new node because head should point to first (and only) item.
    head = newNode;
    // Step 4: Set tail to point to new node because tail should point to last (and only) item.
    tail = newNode;
    // Step 5: Return immediately because we finished handling the empty list case.
    return;
  }

  // Step 6: Create new node with given data because this will become our new last item.
  Node* newNode = new Node(data);
  // Step 7: Connect current tail's next to new node because current last item should point to new last item.
  tail->next = newNode;
  // Step 8: Connect new node's prev back to current tail because doubly linked lists connect both directions.
  newNode->prev = tail;
  // Step 9: Update tail to point to new node because new node is now the actual last item.
  tail = newNode;
}

//Function To calculate Length of Doubly LL
// Time: O(n) - Must visit every single node to count them all, Space: O(1) - Only uses simple counter variables
int getLength(Node* &head){
  // Step 1: Create counter variable starting at 0 because we haven't counted any nodes yet.
  int len = 0;
  // Step 2: Create temp pointer starting at head because we need to walk through list without losing head pointer.
  Node* temp = head;

  // Step 3: Keep looping while temp is not NULL because NULL means we reached the end of list.
  while(temp != NULL){
    // Step 4: Add 1 to our counter because we found another node to count.
    len++;
    // Step 5: Move temp to next node because we need to keep walking through the list.
    temp = temp->next;
  }
  // Step 6: Return the final count because that's how many nodes we found.
  return len;
}

//Function to Insert At Specific Position
// Time: O(n) - Might need to walk through most of list to find position, Space: O(1) - Only one new node
void InsertAtSpecificPos(Node* &head, Node* &tail, int data, int positionToInsert){
  // Step 1: Check if position is 1 because position 1 means "at the beginning" which is same as insert at head.
  if(positionToInsert == 1){
    // Step 2: Call InsertAtHead function because it already knows how to handle putting things at beginning.
    InsertAtHead(head, tail, data);
    // Step 3: Return immediately because InsertAtHead did all the work for us.
    return;
  }

  // Step 4: Get length of list by calling getLength because we need to know if position is at the end.
  int lenghtOfLL = getLength(head);

  // Step 5: Check if position equals length because that means "at the end" which is same as insert at tail.
  if(positionToInsert == lenghtOfLL){
    // Step 6: Call InsertAtTail function because it already knows how to handle putting things at end.
    InsertAtTail(head, tail, data);
    // Step 7: Return immediately because InsertAtTail did all the work for us.
    return;
  }

  // Step 8: Create counter starting at 1 because we start counting positions from 1, not 0.
  int i = 1;
  // Step 9: Create pointer starting at head because we need to walk to the right position.
  Node* prevNode = head;
  // Step 10: Keep moving forward until we reach one spot before where we want to insert because we need to insert between two existing nodes.
  while(i < positionToInsert-1){
    // Step 11: Move to next node because we haven't reached the right spot yet.
    prevNode = prevNode->next;
    // Step 12: Add 1 to counter because we moved one position forward.
    i++;
  }

  // Step 13: Find the node currently at our target position because we need to insert right before it.
  Node* curr = prevNode->next;
  // Step 14: Create new node with given data because this is what we want to insert.
  Node* newNode = new Node(data);
  // Step 15: Connect prevNode's next to new node because prevNode should now point to our inserted node.
  prevNode->next = newNode;
  // Step 16: Connect new node's prev back to prevNode because doubly linked lists need backward connections.
  newNode->prev = prevNode;
  // Step 17: Connect new node's next to curr because new node should point forward to what comes after it.
  newNode->next = curr;
  // Step 18: Connect curr's prev back to new node because curr should point backward to our inserted node.
  curr->prev = newNode;
}

// Function To Print Doubly ll
// Time : O(n) - Must visit every node once to print them all, Space: O(1) - Only uses one pointer variable
void PrinLL(Node* &head){
  // Step 1: Create temp pointer starting at head because we need to walk through list without changing head.
  Node* temp = head;
  // Step 2: Keep looping while temp is not NULL because NULL means we reached end of list.
  while(temp != NULL){
    // Step 3: Print the data from current node followed by space because we want to show what's in this node.
    cout<<temp->data<<" ";
    // Step 4: Move temp to next node because we need to continue walking through rest of list.
    temp = temp->next;
  }
}

int main(){
  // Step 1: Create first node with data 10 because we need to start our list with something.
  Node* head = new Node(10);
  // Step 2: Set tail to point to same node as head because in a one-item list, first and last are the same.
  Node* tail = head;

  // Step 3: Insert 12 at head because we want to add it at beginning of list.
  InsertAtHead(head, tail, 12);
  // Step 4: Insert 152 at head because we want to add it at beginning, pushing others back.
  InsertAtHead(head, tail, 152);
  // Step 5: Insert 1232 at head because we want to add it at beginning, making it the new first item.
  InsertAtHead(head, tail, 1232);
  // Step 6: Insert another 1232 at head because we want to add duplicate at beginning.
  InsertAtHead(head, tail, 1232);

  // Step 7: Insert 107322 at position 2 because we want to put it as second item in list.
  InsertAtSpecificPos(head, tail, 107322, 2);

  // Step 8: Print the entire list because we want to see what our final list looks like.
  PrinLL(head);
}