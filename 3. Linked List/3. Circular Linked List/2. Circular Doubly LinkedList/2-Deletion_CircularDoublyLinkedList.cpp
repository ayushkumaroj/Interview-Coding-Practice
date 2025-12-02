#include<iostream>
using namespace std;

class Node{
  public:
  int data;
  Node* next;
  Node* prev;

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
void DeleteHeadCircularLL(Node* &head, Node* &tail){
  // Step 1: Check if the list is empty by seeing if head is NULL because we cannot delete from an empty list
  if(head == NULL){
    // Step 2: Print error message because there are no nodes to delete in an empty list
    cout<<"Nothing to delete";
    // Step 3: Exit the function because we cannot perform deletion on an empty list
    return;
  }

  // Step 4: Check if there's only one node by comparing head and tail pointers because deleting the only node requires different steps
  if(head == tail){
    // Step 5: Delete the single node from memory because we need to free up the space it was using
    delete head;
    // Step 6: Set head to NULL because the list is now empty and head should not point to deleted memory
    head = NULL;
    // Step 7: Set tail to NULL because the list is now empty and tail should not point to deleted memory
    tail = NULL;
    // Step 8: Exit the function because we're done handling the single node case
    return;
  }

  // Step 9: Create a temp pointer to store the current head because we need to remember which node to delete before changing head
  Node* temp = head;
  // Step 10: Move head to the next node because the second node will become the new first node
  head = head->next;
  // Step 11: Make the new head's prev pointer point to tail because in a circular list the head's previous node is always the tail
  head->prev = tail; // changed for cicular
  // Step 12: Make the tail's next pointer point to the new head because in a circular list the tail must always point to the head
  tail->next = head; //changed for cicular
  // Step 13: Set temp's next pointer to NULL because we want to disconnect the old head from the list before deleting it
  temp->next = NULL;
  // Step 14: Set temp's prev pointer to NULL because we want to completely disconnect the old head from the list before deleting it
  temp->prev = NULL;
  // Step 15: Delete the old head node from memory because we no longer need it and want to free up the space
  delete temp;
}

// Time Complexity: O(1), Space Complexity: O(1)
void DeleteTailCicularLL(Node* &head, Node* &tail){
  // Step 1: Check if the list is empty by seeing if head is NULL because we cannot delete from an empty list
  if(head == NULL){
    // Step 2: Print error message because there are no nodes to delete in an empty list
    cout<<"Nothing to Delete";
    // Step 3: Exit the function because we cannot perform deletion on an empty list
    return;
  }

  // Step 4: Check if there's only one node by comparing head and tail pointers because deleting the only node requires different steps
  if(head == tail){
    // Step 5: Delete the single node from memory because we need to free up the space it was using
    delete tail;
    // Step 6: Set head to NULL because the list is now empty and head should not point to deleted memory
    head = NULL;
    // Step 7: Set tail to NULL because the list is now empty and tail should not point to deleted memory
    tail = NULL;
    // Step 8: Exit the function because we're done handling the single node case
    return;
  }

  // Step 9: Create a temp pointer to store the current tail because we need to remember which node to delete before changing tail
  Node* temp = tail;
  // Step 10: Move tail to the previous node because the second-to-last node will become the new last node
  tail = tail->prev;
  // Step 11: Make the new tail's next pointer point to head because in a circular list the tail must always point to the head
  tail->next = head;
  // Step 12: Make the head's prev pointer point to the new tail because in a circular list the head's previous node is always the tail
  head->prev = tail;
  // Step 13: Set temp's next pointer to NULL because we want to disconnect the old tail from the list before deleting it
  temp->next = NULL;
  // Step 14: Set temp's prev pointer to NULL because we want to completely disconnect the old tail from the list before deleting it
  temp->prev = NULL;
  // Step 15: Delete the old tail node from memory because we no longer need it and want to free up the space
  delete temp;
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
void Delete_Specific_Position(Node* &head, Node* &tail, int positionToDelete){
  // Step 1: Get the current length of the list because we need to check if the position is valid
  int length = getLength(head);

  // Step 2: Check if position is invalid by seeing if it's too small or too big because we can't delete from positions that don't exist
  if(positionToDelete <= 0 || positionToDelete > length){
    // Step 3: Print error message because the user gave us a position that doesn't exist in the list
    cout<<"Invalid position";
    // Step 4: Exit the function because we can't do anything with an invalid position
    return;
  }

  // Step 5: Check if position is 1 because deleting position 1 means deleting the head
  if(positionToDelete == 1){
    // Step 6: Call the head deletion function because we already have a function that handles deleting the first node
    DeleteHeadCircularLL(head, tail);
    // Step 7: Exit the function because the head deletion function did all the work for us
    return;
  }

  // Step 8: Check if position equals the length because deleting the last position means deleting the tail
  if(positionToDelete == length){
    // Step 9: Call the tail deletion function because we already have a function that handles deleting the last node
    DeleteTailCicularLL(head, tail);
    // Step 10: Exit the function because the tail deletion function did all the work for us
    return;
  }

  // Step 11: Create a counter and set it to 1 because we need to count from position 1 to find the right node
  int i=1;
  // Step 12: Create a pointer to track the left node and start it at head because we need to find the node before our deletion target
  Node* left = head;
  // Step 13: Move through the list until we reach the node before our target position because we need to connect the nodes around the one we're deleting
  while(i < positionToDelete-1){
    // Step 14: Move to the next node because we haven't reached the position before our target yet
    left = left->next;
    // Step 15: Add 1 to our counter because we moved one position forward in the list
    i++;
  }
  // Step 16: Get the current node that we want to delete because this is the node at our target position
  Node* curr = left->next;
  // Step 17: Get the node after our target because we need to connect the left and right nodes together
  Node* right = curr->next;

  // Step 18: Connect the left node directly to the right node because we're removing the middle node from the chain
  left->next = right;
  // Step 19: Connect the right node directly back to the left node because we're removing the middle node from the chain
  right->prev = left;

  // Step 20: Set curr's next pointer to NULL because we want to disconnect the node from the list before deleting it
  curr->next = NULL;
  // Step 21: Set curr's prev pointer to NULL because we want to completely disconnect the node from the list before deleting it
  curr->prev = NULL;
  // Step 22: Delete the target node from memory because we no longer need it and want to free up the space
  delete curr;
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

int main() {
    // Step 1: Create a head pointer and set it to NULL because we're starting with an empty list
    Node* head = NULL;
    // Step 2: Create a tail pointer and set it to NULL because we're starting with an empty list
    Node* tail = NULL;

    // Step 3: Insert 10 at the head because we want to add our first piece of data to the list
    InsertAtHeadCircularLL(head, tail, 10);
    // Step 4: Insert 20 at the head because we want to add this data to the front, making it the new first element
    InsertAtHeadCircularLL(head, tail, 20);
    // Step 5: Insert 30 at the head because we want to add this data to the front, making it the new first element
    InsertAtHeadCircularLL(head, tail, 30);
    // Step 6: Insert 40 at the head because we want to add this data to the front, making it the new first element
    InsertAtHeadCircularLL(head, tail, 40);
    // Step 7: Insert 50 at the head because we want to add this data to the front, making it the new first element
    InsertAtHeadCircularLL(head, tail, 50);

    // Step 8: Delete the node at position 2 because we want to remove the second element from our list
    Delete_Specific_Position(head, tail, 2);
    // Step 9: Print the entire list because we want to see the result after deletion and verify our operation worked correctly
    printLL(head);
}