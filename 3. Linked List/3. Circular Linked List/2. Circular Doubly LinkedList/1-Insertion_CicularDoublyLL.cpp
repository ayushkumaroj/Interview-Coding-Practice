#include<iostream>
using namespace std;

class Node{
  public:
  int data;
  Node* prev;
  Node* next;

  // Step 1: Create a basic constructor that sets data to 0 because we need a way to make empty nodes with safe default values
  Node(){
    // Step 2: Set data to 0 because we want a safe default value when no data is given
    this->data = 0;
    // Step 3: Set next pointer to NULL because this new node doesn't point to any other node yet
    this->next = NULL;
    // Step 4: Set prev pointer to NULL because this new node doesn't have any node behind it yet
    this->prev = NULL;
  }

  // Step 5: Create a constructor that takes data value because we need a way to make nodes with specific values
  Node(int data){
    // Step 6: Set the node's data to the given value because we want to store the actual number the user wants
    this->data = data;
    // Step 7: Set next pointer to NULL because this new node doesn't point to any other node yet
    this->next = NULL;
    // Step 8: Set prev pointer to NULL because this new node doesn't have any node behind it yet
    this->prev = NULL;
  }
};

// Time Complexity: O(1), Space Complexity: O(1)
// Insert At Head
void InsertAtHeadCircularLL(Node* &head, Node* &tail, int data){
  // Step 1: Check if the list is empty by seeing if head is NULL because we need different steps for empty vs non-empty lists
  if(head == NULL){
    // Step 2: Create a new node with the given data because we need to make the first node of the list
    Node* newNode = new Node(data);
    // Step 3: Set head to point to our new node because this will be the first and only node in the list
    head = newNode;
    // Step 4: Set tail to point to our new node because this node is both the first and last node
    tail = newNode;
    // Step 5: Make the new node's next pointer point to itself because in a circular list every node must point to another node
    head->next = head; //changed for circular linked list
    // Step 6: Make the new node's prev pointer point to itself because in a circular list every node must have a previous node
    head->prev = head; //changed for circular linked list
    // Step 7: Exit the function because we're done setting up the first node
    return;
  }

  // Step 8: Create a new node with the given data because we need to add this data to the front of the existing list
  Node* newNode = new Node(data);
  // Step 9: Make the new node's next pointer point to the current head because the new node will go before the current first node
  newNode->next = head;
  // Step 10: Make the new node's prev pointer point to tail because in a circular list the head's previous node is always the tail
  newNode->prev = tail; //changed for cicular linked list
  // Step 11: Make the current head's prev pointer point to our new node because the new node will now be before the old head
  head->prev = newNode;
  // Step 12: Make the tail's next pointer point to our new node because in a circular list the tail must always point to the head
  tail->next = newNode; //changed for circular linked list
  // Step 13: Update head to point to our new node because the new node is now the first node in the list
  head = newNode;
}

// Time Complexity: O(1), Space Complexity: O(1)
// Insert at tail
void InsertAtTail(Node* &head, Node* &tail, int data){
  // Step 1: Check if the list is empty by seeing if head is NULL because we need different steps for empty vs non-empty lists
  if(head == NULL){
    // Step 2: Create a new node with the given data because we need to make the first node of the list
    Node* newNode = new Node(data);
    // Step 3: Set head to point to our new node because this will be the first and only node in the list
    head = newNode;
    // Step 4: Set tail to point to our new node because this node is both the first and last node
    tail = newNode;
    // Step 5: Make the new node's next pointer point to itself because in a circular list every node must point to another node
    head->next = head; //changed for cicular ll
    // Step 6: Make the new node's prev pointer point to itself because in a circular list every node must have a previous node
    head->prev = head; //changed for cicular ll
    // Step 7: Exit the function because we're done setting up the first node
    return;
  }

  // Step 8: Create a new node with the given data because we need to add this data to the end of the existing list
  Node* newNode = new Node(data);
  // Step 9: Make the new node's prev pointer point to the current tail because the new node will go after the current last node
  newNode->prev = tail;
  // Step 10: Make the new node's next pointer point to head because in a circular list the tail's next node is always the head
  newNode->next = head;
  // Step 11: Make the current tail's next pointer point to our new node because the new node will now be after the old tail
  tail->next = newNode;
  // Step 12: Make the head's prev pointer point to our new node because in a circular list the head's previous node is always the tail
  head->prev = newNode;
  // Step 13: Update tail to point to our new node because the new node is now the last node in the list
  tail = newNode;
}

// Time Complexity: O(n), Space Complexity: O(1)
// Calculate length of circular doubly LL
int getLength(Node* &head){
  // Step 1: Check if the list is empty by seeing if head is NULL because an empty list has length 0
  if(head == NULL){
    // Step 2: Return 0 because there are no nodes to count in an empty list
    return 0;
  }
  // Step 3: Create a counter variable and set it to 0 because we need to keep track of how many nodes we count
  int len =0;
  // Step 4: Create a temp pointer and set it to head because we need to move through the list without changing head
  Node* temp = head;

  // Step 5: Use a do-while loop because we need to count at least one node and stop when we come back to head
  do{ //changed for circular ll
    // Step 6: Add 1 to our counter because we found another node to count
    len++;
    // Step 7: Move temp to the next node because we need to check the next node in the circle
    temp = temp->next;
  }while(temp != head); // Step 8: Keep going until temp points back to head because that means we completed the full circle

  // Step 9: Return the final count because that's how many nodes are in the circular list
  return len;
}

// Time Complexity: O(n), Space Complexity: O(1)
void InsertAtSpecificPos(Node* &head, Node* &tail, int data, int positionToInsert){
  // Step 1: Check if position is 1 because inserting at position 1 means inserting at the head
  if(positionToInsert == 1){
    // Step 2: Call the head insertion function because we already have a function that handles inserting at the beginning
    InsertAtHeadCircularLL(head, tail, data);
    // Step 3: Exit the function because the head insertion function did all the work for us
    return;
  }

  // Step 4: Get the current length of the list because we need to know if the position is valid
  int lengthOfLL = getLength(head);
  // Step 5: Check if position equals length plus 1 because that means inserting at the very end (tail position)
  if(positionToInsert == lengthOfLL + 1){ //changed for circular
    // Step 6: Call the tail insertion function because we already have a function that handles inserting at the end
    InsertAtTail(head, tail, data);
  }

  // Step 7: Check if position is invalid by seeing if it's too big or too small because we can't insert at positions that don't make sense
  if(positionToInsert > lengthOfLL+1 || positionToInsert <=0){
    // Step 8: Print error message because the user gave us a position that doesn't exist in the list
    cout<<"Invalid position";
    // Step 9: Exit the function because we can't do anything with an invalid position
    return;
  }

  // Step 10: Create a counter and set it to 1 because we need to count from position 1 to find the right spot
  int i=1;
  // Step 11: Create a pointer to track the previous node and start it at head because we need to find the node before our insertion point
  Node* prevNode = head;
  // Step 12: Move through the list until we reach the node before our target position because we need to insert between two existing nodes
  while(i < positionToInsert-1){
    // Step 13: Move to the next node because we haven't reached the position before our target yet
    prevNode = prevNode->next;
    // Step 14: Add 1 to our counter because we moved one position forward in the list
    i++;
  }
  
  // Step 15: Get the current node at our target position because we need to insert our new node before this one
  Node* curr = prevNode->next;

  // Step 16: Create a new node with the given data because this is what we want to insert into the list
  Node* newNode = new Node(data);
  // Step 17: Make the new node's next pointer point to curr because the new node should come before the current node at this position
  newNode->next = curr;
  // Step 18: Make the new node's prev pointer point to prevNode because the new node should come after the previous node
  newNode->prev = prevNode;
  // Step 19: Make prevNode's next pointer point to our new node because the previous node should now point to our new node instead of curr
  prevNode->next = newNode;
  // Step 20: Make curr's prev pointer point to our new node because curr should now have our new node as its previous node instead of prevNode
  curr->prev = newNode;
}

// Time Complexity: O(n), Space Complexity: O(1)
void printLL(Node* &head){
  // Step 1: Check if the list is empty by seeing if head is NULL because we can't print anything from an empty list
  if(head == NULL){
    // Step 2: Print a message saying the list is empty because the user should know there's nothing to show
    cout<<"Linked List is empty";
    // Step 3: Exit the function because there are no nodes to print in an empty list
    return;
  }

  // Step 4: Create a temp pointer and set it to head because we need to move through the list without changing head
  Node* temp = head;
  // Step 5: Use a do-while loop because we need to print at least one node and stop when we come back to head
  do{
    // Step 6: Print the current node's data followed by a space because we want to show all the values in a readable format
    cout<<temp->data<<" ";
    // Step 7: Move temp to the next node because we need to print the next node in the circle
    temp = temp->next;
  }while(temp != head); // Step 8: Keep going until temp points back to head because that means we printed the full circle

  // Step 9: Print a newline because we want to end the output cleanly and move to the next line
  cout<<endl;
}

int main(){
  // Step 1: Create a head pointer and set it to NULL because we're starting with an empty list
  Node* head = NULL;
  // Step 2: Create a tail pointer and set it to NULL because we're starting with an empty list
  Node* tail = NULL;

  // Step 3: Insert 10 at the head because we want to add our first piece of data to the list
  InsertAtHeadCircularLL(head, tail, 10);
  // Step 4: Insert 12 at the head because we want to add this data to the front of the existing list
  InsertAtHeadCircularLL(head, tail, 12);
  // Step 5: Insert 123 at the head because we want to add this data to the front of the existing list
  InsertAtHeadCircularLL(head, tail, 123);
  // Step 6: Insert 134 at the head because we want to add this data to the front of the existing list
  InsertAtHeadCircularLL(head, tail, 134);
  // Step 7: Insert 1021 at the head because we want to add this data to the front of the existing list
  InsertAtHeadCircularLL(head, tail, 1021);

  // Step 8: Insert 777 at position 3 because we want to put this specific data at the third spot in our list
  InsertAtSpecificPos(head, tail, 777, 3);
  // Step 9: Print a label message because we want the user to know what they're looking at
  cout << "Circular Doubly Linked List: ";
  // Step 10: Print the entire list because we want to show the user all the data we inserted and how it's arranged
  printLL(head);
}