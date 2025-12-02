#include<iostream>
using namespace std;

class Node{
  public:
  int data;
  Node* next;
  Node* prev;

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

// Time: O(1) - Only a few simple steps no matter how big the list is, Space: O(1) - Only creates one new node
void insertAtHead(Node* &head, Node* &tail, int data){
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

// Function To Delete Head In Doubly LL
// Time: O(1) - Only need to change a few pointers, Space: O(1) - No new memory needed
void DeleteHead(Node* &head, Node* &tail){
  // Step 1: Check if head is NULL because if list is empty we have nothing to delete and should avoid crashing.
  if(head == NULL){
    // Step 2: Print message to user because they tried to delete from empty list and should know why nothing happened.
    cout<<"Nothing to delete";
    // Step 3: Return immediately because we cannot delete anything from empty list.
    return;
  }
  // Step 4: Save current head in temp pointer because we will need to delete this node after we fix all the connections.
  Node* temp = head;
  // Step 5: Move head pointer to the next node because the second node will become the new first node.
  head = head->next;
  // Step 6: Check if new head exists because we need to handle case where list becomes empty differently.
  if(head != NULL){
    // Step 7: Set new head's prev to NULL because first node should never point backward to anything.
    head->prev = NULL;
  }else{
    // Step 8: Set tail to NULL too because if head is NULL then list is completely empty so tail must also be NULL.
    tail = NULL;
  }
  // Step 9: Set old head's next to NULL because we want to completely disconnect the deleted node from list.
  temp->next = NULL;
  // Step 10: Delete the old head node because we need to free up memory and prevent memory leaks.
  delete temp;
  // Step 11: Return because deletion is complete.
  return;
}

// Function To delete Tail of Doubly LL
// Time: O(1) - Only need to change a few pointers, Space: O(1) - No new memory needed
void DeleteTail(Node* &head, Node* &tail){
  // Step 1: Check if head is NULL because if list is empty we have nothing to delete and should avoid crashing.
  if(head == NULL){
    // Step 2: Print message to user because they tried to delete from empty list and should know why nothing happened.
    cout<<"Nothing to delete";
    // Step 3: Return immediately because we cannot delete anything from empty list.
    return;
  }
  // Step 4: Save current tail in temp pointer because we will need to delete this node after we fix all the connections.
  Node* temp = tail;
  // Step 5: Move tail pointer to the previous node because the second-to-last node will become the new last node.
  tail = tail->prev;
  // Step 6: Check if new tail exists because we need to handle case where list becomes empty differently.
  if(tail != NULL){
    // Step 7: Set new tail's next to NULL because last node should never point forward to anything.
    tail->next = NULL;
  }else{
    // Step 8: Set head to NULL too because if tail is NULL then list is completely empty so head must also be NULL.
    head = NULL;
  }
  // Step 9: Set old tail's prev to NULL because we want to completely disconnect the deleted node from list.
  temp->prev = NULL;
  // Step 10: Delete the old tail node because we need to free up memory and prevent memory leaks.
  delete temp;
  // Step 11: Return because deletion is complete.
  return;
}

// Time: O(n) - Must visit every single node to count them all, Space: O(1) - Only uses simple counter variables
int getLength(Node* &head){
  // Step 1: Create temp pointer starting at head because we need to walk through list without losing head pointer.
  Node* temp = head;
  // Step 2: Create counter variable starting at 0 because we haven't counted any nodes yet.
  int len = 0;
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

// Function to delete Node at specific Position
// Time : O(n) - Need to walk through list to find position, Space: O(1) - Only uses pointer variables
void Delete_Specific_Position(Node* &head, Node* &tail, int positionToDelete){
  // Step 1: Get current length of list by calling getLength because we need to check if given position actually exists.
  int LenghtOFLinkedList = getLength(head);

  // Step 2: Check if position is less than 1 or greater than list length because these positions don't exist and would cause crashes.
  if(positionToDelete < 1 || positionToDelete > LenghtOFLinkedList){
    // Step 3: Print error message because user gave invalid position and should know why deletion failed.
    cout<<"Invalid position";
    // Step 4: Return immediately because we cannot delete from position that doesn't exist.
    return;
  }

  // Step 5: Check if position is 1 because deleting first node is special case that changes head pointer.
  if(positionToDelete == 1){
    // Step 6: Call DeleteHead function because it already knows how to properly delete first node.
    DeleteHead(head, tail);
    // Step 7: Return immediately because DeleteHead did all the work for us.
    return;
  }

  // Step 8: Check if position equals list length because deleting last node is special case that changes tail pointer.
  if(positionToDelete == LenghtOFLinkedList){
    // Step 9: Call DeleteTail function because it already knows how to properly delete last node.
    DeleteTail(head, tail);
    // Step 10: Return immediately because DeleteTail did all the work for us.
    return;
  }

  // Step 11: Create counter starting at 1 because we count positions starting from 1, not 0.
  int i = 1;
  // Step 12: Create pointer starting at head because we need to walk to position before the one we want to delete.
  Node* left = head;
  // Step 13: Keep moving forward until we reach one position before target because we need the node before deletion point.
  while(i < positionToDelete-1){
    // Step 14: Move to next node because we haven't reached the right spot yet.
    left = left->next;
    // Step 15: Add 1 to counter because we moved one position forward.
    i++;
  }
  // Step 16: Find the node we actually want to delete because left is pointing one position before it.
  Node* curr = left->next;
  // Step 17: Find the node that comes after the one we want to delete because we'll need to connect left directly to this one.
  Node* right = curr->next;

  // Step 18: Connect left node directly to right node (skip curr) because we're removing curr from the chain.
  left->next = right;
  // Step 19: Connect right node back to left node (skip curr) because doubly linked lists need connections both ways.
  right->prev = left;
  // Step 20: Set curr's prev to NULL because we want to completely disconnect deleted node from list.
  curr->prev = NULL;
  // Step 21: Set curr's next to NULL because we want to completely disconnect deleted node from list.
  curr->next = NULL;
  // Step 22: Delete the curr node because we need to free up memory and prevent memory leaks.
  delete curr;
}

// Time : O(n) - Must visit every node once to print them all, Space: O(1) - Only uses one pointer variable
void printLL(Node* &head){
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

  // Step 3: Insert 20 at head because we want to add it at beginning of list.
  insertAtHead(head, tail, 20);
  // Step 4: Insert 30 at head because we want to add it at beginning, pushing others back.
  insertAtHead(head, tail, 30);
  // Step 5: Insert 40 at head because we want to add it at beginning, making it the new first item.
  insertAtHead(head, tail, 40);
  // Step 6: Insert 50 at head because we want to add it at beginning, making it the new first item.
  insertAtHead(head, tail, 50);

  // Step 7: Delete node at position 2 because we want to remove the second item from list.
  Delete_Specific_Position(head, tail, 2);
  // Step 8: Print the entire list because we want to see what our final list looks like after deletion.
  printLL(head);
}