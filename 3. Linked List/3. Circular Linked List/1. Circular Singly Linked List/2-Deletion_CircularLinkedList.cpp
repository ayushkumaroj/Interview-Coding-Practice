#include<iostream>
using namespace std;

class Node{
  public:
  int data;
  Node* next;

  // Step 1: Create a default constructor that sets everything to safe starting values because we need a way to make empty nodes without crashing.
  Node(){
    // Step 2: Set data to 0 because we need some default number value when no data is given.
    this->data = 0;
    // Step 3: Set next pointer to NULL because this node doesn't connect to anything yet and NULL means "nothing".
    this->next = NULL;
  }

  // Step 4: Create a constructor that takes data as input because we often want to create a node with specific data right away.
  Node(int data){
    // Step 5: Store the given data in this node because that's what we want this node to hold.
    this->data = data;
    // Step 6: Set next to NULL because this new node doesn't connect forward to anything yet.
    this->next = NULL;
  }

  // Step 7: Create destructor that prints when node is deleted because we want to see which values are being removed from memory.
  ~Node(){
    // Step 8: Print the data of node being deleted because this helps us track what's happening during deletion operations.
    cout<<"Deleted value "<<this->data<<endl;
  }
};

// Time: O(1) - Only need to change a few pointers no matter how big the list is, Space: O(1) - Only creates one new node
void insertAtHead(Node* &head, Node* &tail, int data){
  // Step 1: Check if head is NULL to see if list is completely empty because empty circular lists need special setup.
  if(head == NULL){
    // Step 2: Create a new node with the given data because we need something to put in our empty list.
    Node* newNode = new Node(data);
    // Step 3: Make head point to our new node because head should always point to the first item.
    head = newNode;
    // Step 4: Make tail point to our new node too because in a list with only one item, head and tail point to same thing.
    tail = newNode;
    // Step 5: Make tail's next point back to head because in circular lists the last node must connect back to first node.
    tail->next = head;
    // Step 6: Return immediately because we're done setting up the first node in circular list.
    return;
  }

  // Step 7: Create a new node with given data because this will become our new first item.
  Node* newNode = new Node(data);
  // Step 8: Make new node's next pointer point to current head because new node needs to connect to what used to be first.
  newNode->next = head;
  // Step 9: Change head to point to new node because new node is now the actual first item in list.
  head = newNode;
  // Step 10: Make tail's next point to new head because in circular lists tail must always connect back to current head.
  tail->next = head;
}

// Time: O(n) - Must visit every single node to count them all, Space: O(1) - Only uses simple counter variables
int LengthLinkedList(Node* &head){
  // Step 1: Check if head is NULL because if list is empty then length is 0.
  if(head == NULL){
    // Step 2: Return 0 immediately because empty list has no nodes to count.
    return 0;
  }

  // Step 3: Create counter variable starting at 0 because we haven't counted any nodes yet.
  int len = 0;
  // Step 4: Create temp pointer starting at head because we need to walk through list without losing head pointer.
  Node* temp = head;
  // Step 5: Use do-while loop because we need to count at least the first node before checking if we're back to head.
  do{
    // Step 6: Add 1 to our counter because we found another node to count.
    len++;
    // Step 7: Move temp to next node because we need to keep walking through the circular list.
    temp = temp->next;
  }while(temp != head); // Step 8: Keep going until we come back to head because that means we've seen all nodes in circular list.
  // Step 9: Return the final count because that's how many nodes we found.
  return len;
}

// Delete Head Node from Circular LL
// Time: O(1) - Only need to change a few pointers, Space: O(1) - No new memory needed
void DeleteHeadCircularLL(Node* &head, Node* &tail){
  // Step 1: Check if head is NULL because if list is empty we have nothing to delete and should avoid crashing.
  if(head == NULL){
    // Step 2: Print message to user because they tried to delete from empty list and should know why nothing happened.
    cout<<"Cannot delete, LL is empty";
    // Step 3: Return immediately because we cannot delete anything from empty list.
    return;
  }

  // Step 4: Check if head equals tail because this means list has only one node and needs special handling.
  if(head == tail){
    // Step 5: Delete the single node because we're removing the only item in list.
    delete head;
    // Step 6: Set head to NULL because list is now completely empty.
    head = NULL;
    // Step 7: Set tail to NULL because list is now completely empty.
    tail = NULL;
    // Step 8: Return immediately because deletion of single node is complete.
    return;
  }

  // Step 9: Save current head in temp pointer because we will need to delete this node after we fix all the connections.
  Node* temp = head;
  // Step 10: Move head pointer to the next node because the second node will become the new first node.
  head = head->next;
  // Step 11: Make tail's next point to new head because in circular lists tail must always connect back to head.
  tail->next = head;
  // Step 12: Set old head's next to NULL because we want to completely disconnect the deleted node from list.
  temp->next = NULL;
  // Step 13: Delete the old head node because we need to free up memory and prevent memory leaks.
  delete temp;
}

// Delete Tail Node from Circular LL
// Time: O(n) - Need to find the node before tail, Space: O(1) - No new memory needed
void DeleteTailCircularLL(Node* &head, Node* &tail){
  // Step 1: Check if head is NULL because if list is empty we have nothing to delete and should avoid crashing.
  if(head == NULL){
    // Step 2: Print message to user because they tried to delete from empty list and should know why nothing happened.
    cout<<"Cannot delete , LL is empty";
    // Step 3: Return immediately because we cannot delete anything from empty list.
    return;
  }

  // Step 4: Check if head equals tail because this means list has only one node and needs special handling.
  if(head == tail){
    // Step 5: Delete the single node because we're removing the only item in list.
    delete head;
    // Step 6: Set head to NULL because list is now completely empty.
    head = NULL;
    // Step 7: Set tail to NULL because list is now completely empty.
    tail = NULL;
    // Step 8: Return immediately because deletion of single node is complete.
    return;
  }

  // Step 9: Start from head to find the node before tail because we need to update its next pointer.
  Node* prev = head;
  // Step 10: Keep moving until we find the node that points to tail because that's the node before tail.
  while(prev->next != tail){
    // Step 11: Move to next node because we haven't found the node before tail yet.
    prev = prev->next;
  }

  // Step 12: Make prev point directly to head because in circular lists when we remove tail, the new tail should connect to head.
  prev->next = head;
  // Step 13: Delete the current tail node because we need to free up memory and prevent memory leaks.
  delete tail;
  // Step 14: Update tail pointer to prev because prev is now the new last node in list.
  tail = prev;
}

// Delete Node at Specific Position in Circular LL
// Time: O(n) - Need to walk through list to find position, Space: O(1) - Only uses pointer variables
void DeleteSpecificNode(Node* &head, Node* &tail, int positionToDel){
  // Step 1: Check if head is NULL because if list is empty we have nothing to delete and should avoid crashing.
  if(head == NULL){
    // Step 2: Print message because user tried to delete from empty list and should know why deletion failed.
    cout<<"Linked list is empty, nothing to delete";
    // Step 3: Return immediately because we cannot delete from position that doesn't exist.
    return;
  }

  // Step 4: Get current length of list by calling LengthLinkedList because we need to check if given position actually exists.
  int sizeOfLL = LengthLinkedList(head);

  // Step 5: Check if position is less than or equal to 0 or greater than list length because these positions don't exist and would cause crashes.
  if(positionToDel <= 0 || positionToDel > sizeOfLL){
    // Step 6: Print error message because user gave invalid position and should know why deletion failed.
    cout<<"Invalid Position";
    // Step 7: Return immediately because we cannot delete from position that doesn't exist.
    return;
  }

  // Step 8: Check if position is 1 because deleting first node is special case that changes head pointer.
  if(positionToDel == 1){
    // Step 9: Call DeleteHeadCircularLL function because it already knows how to properly delete first node in circular list.
    DeleteHeadCircularLL(head, tail);
    // Step 10: Return immediately because DeleteHeadCircularLL did all the work for us.
    return;
  }

  // Step 11: Check if position equals list length because deleting last node is special case that changes tail pointer.
  if(positionToDel == sizeOfLL){
    // Step 12: Call DeleteTailCircularLL function because it already knows how to properly delete last node in circular list.
    DeleteTailCircularLL(head, tail);
    // Step 13: Return immediately because DeleteTailCircularLL did all the work for us.
    return;
  }

  // Step 14: Create counter starting at 1 because we count positions starting from 1, not 0.
  int i = 1;
  // Step 15: Create pointer starting at head because we need to walk to position before the one we want to delete.
  Node* prev = head;
  // Step 16: Keep moving forward until we reach one position before target because we need the node before deletion point.
  while(i < positionToDel-1){
    // Step 17: Move to next node because we haven't reached the right spot yet.
    prev = prev->next;
    // Step 18: Add 1 to counter because we moved one position forward.
    i++;
  }

  // Step 19: Find the node we actually want to delete because prev is pointing one position before it.
  Node* curr = prev->next;
  // Step 20: Connect prev node directly to node after curr (skip curr) because we're removing curr from the circular chain.
  prev->next = curr->next;
  // Step 21: Set curr's next to NULL because we want to completely disconnect deleted node from list.
  curr->next = NULL;
  // Step 22: Delete the curr node because we need to free up memory and prevent memory leaks.
  delete curr;
}

//Print circular Linked List
// Time: O(n) - Must visit every node once to print them all, Space: O(1) - Only uses one pointer variable
void print(Node* head){
  // Step 1: Check if head is NULL because if list is empty there's nothing to print.
  if(head == NULL){
    // Step 2: Return immediately because we cannot print anything from empty list.
    return;
  }

  // Step 3: Create temp pointer starting at head because we need to walk through list without changing head.
  Node* temp = head;
  // Step 4: Use do-while loop because we need to print at least the first node before checking if we're back to head.
  do{
    // Step 5: Print the data from current node followed by space because we want to show what's in this node.
    cout<<temp->data<<" ";
    // Step 6: Move temp to next node because we need to continue walking through rest of list.
    temp = temp->next;
  }while(temp != head); // Step 7: Keep going until we come back to head because that means we've printed all nodes in circular list.
  // Step 8: Print newline character because we want to end the output line nicely.
  cout<<endl;
}

int main(){
  // Step 1: Create head pointer and set to NULL because we're starting with completely empty list.
  Node* head = NULL;
  // Step 2: Create tail pointer and set to NULL because we're starting with completely empty list.
  Node* tail = NULL;

  // Step 3: Insert 10 at head because we want to add it as first item in list.
  insertAtHead(head, tail, 10);
  // Step 4: Insert 20 at head because we want to add it at beginning, pushing 10 to second position.
  insertAtHead(head, tail, 20);
  // Step 5: Insert 30 at head because we want to add it at beginning, making it the new first item.
  insertAtHead(head, tail, 30);
  // Step 6: Insert 40 at head because we want to add it at beginning, making it the new first item.
  insertAtHead(head, tail, 40);

  // Step 7: Delete node at position 2 because we want to remove the second item from circular list.
  DeleteSpecificNode(head, tail, 2);

  // Step 8: Print the entire circular list because we want to see what our final list looks like after deletion.
  print(head);

}