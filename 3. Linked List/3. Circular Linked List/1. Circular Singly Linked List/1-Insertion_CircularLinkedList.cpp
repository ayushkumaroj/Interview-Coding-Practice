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
};

// Function To insert Node At head
// Time Complexity: O(1) - Only need to change a few pointers no matter how big the list is, Space Complexity: O(1) - Only creates one new node
void InsertAtHead(Node* &head, Node* &tail, int data){
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

// Function to insert Node at Tail
// Time Complexity: O(1) - Direct access to tail pointer, Space Complexity: O(1) - Only creates one new node
void InsertAtTail(Node* &head, Node* &tail, int data){
  // Step 1: Check if head is NULL because if list is empty we need same setup as InsertAtHead.
  if(head == NULL){
    // Step 2: Create new node with given data because we need something to put in our empty list.
    Node* newNode = new Node(data);
    // Step 3: Set head to point to new node because head should point to first (and only) item.
    head = newNode;
    // Step 4: Set tail to point to new node because tail should point to last (and only) item.
    tail = newNode;
    // Step 5: Make tail connect back to head because circular lists always connect end to beginning.
    tail->next = head;
    // Step 6: Return immediately because we finished handling the empty list case.
    return;
  }

  // Step 7: Create new node with given data because this will become our new last item.
  Node* newNode = new Node(data);

  // Step 8: Connect current tail's next to new node because current last item should point to new last item.
  tail->next = newNode;

  // Step 9: Update tail to point to new node because new node is now the actual last item.
  tail = newNode;

  // Step 10: Connect new tail back to head because in circular lists the last node must always point to first node.
  tail->next = head;
}

// Function to find length of circular linked list
// Time Complexity: O(n) - Must visit every single node to count them all, Space Complexity: O(1) - Only uses simple counter variables
int findLength(Node* &head, Node* &tail){
  // Step 1: Check if head is NULL because if list is empty then length is 0.
  if(head == NULL){
    // Step 2: Return 0 immediately because empty list has no nodes to count.
    return 0;
  }

  // Step 3: Create temp pointer starting at head because we need to walk through list without losing head pointer.
  Node* temp = head;
  // Step 4: Create counter variable starting at 0 because we haven't counted any nodes yet.
  int len = 0;

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

// Function to insert at specific position
// Time Complexity: O(n) - Might need to walk through most of list to find position, Space Complexity: O(1) - Only one new node
void insertAtSpecificPosition(Node* &head, Node* &tail, int data, int position){
  // Step 1: Check if head is NULL because if list is empty we just create first node regardless of position.
  if(head == NULL){
    // Step 2: Create new node with given data because we need something to put in our empty list.
    Node* newNode = new Node(data);
    // Step 3: Set head to point to new node because head should point to first (and only) item.
    head = newNode;
    // Step 4: Set tail to point to new node because tail should point to last (and only) item.
    tail = newNode;
    // Step 5: Make tail connect back to head because circular lists always connect end to beginning.
    tail->next = head;
    // Step 6: Return immediately because we finished creating the first node.
    return;
  }

  // Step 7: Check if position is 0 because position 0 means "at the beginning" which is same as insert at head.
  if(position == 0){
    // Step 8: Call InsertAtHead function because it already knows how to handle putting things at beginning.
    InsertAtHead(head, tail, data);
    // Step 9: Return immediately because InsertAtHead did all the work for us.
    return;
  }

  // Step 10: Get length of list by calling findLength because we need to know if position is at the end.
  int len = findLength(head, tail);

  // Step 11: Check if position equals length because that means "at the end" which is same as insert at tail.
  if(position == len){
    // Step 12: Call InsertAtTail function because it already knows how to handle putting things at end.
    InsertAtTail(head, tail, data);
    // Step 13: Return immediately because InsertAtTail did all the work for us.
    return;
  }

  // Step 14: Create counter starting at 1 because we need to move through positions starting from position 1.
  int i = 1;
  // Step 15: Create pointer starting at head because we need to walk to the right position.
  Node* prev = head;
  // Step 16: Keep moving forward until we reach the position where we want to insert because we need to insert between two existing nodes.
  while(i < position){
    // Step 17: Move to next node because we haven't reached the right spot yet.
    prev = prev->next;
    // Step 18: Add 1 to counter because we moved one position forward.
    i++;
  }

  // Step 19: Find the node currently at our target position because we need to insert right before it.
  Node* curr = prev->next;
  // Step 20: Create new node with given data because this is what we want to insert.
  Node* newNode = new Node(data);
  // Step 21: Connect new node's next to curr because new node should point forward to what comes after it.
  newNode->next = curr;
  // Step 22: Connect prev's next to new node because prev should now point to our inserted node.
  prev->next = newNode;
}

// Function to Print Circular LL
// Time Complexity: O(n) - Must visit every node once to print them all, Space Complexity: O(1) - Only uses one pointer variable
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

// Main Function
int main(){
  // Step 1: Create head pointer and set to NULL because we're starting with completely empty list.
  Node* head = NULL;
  // Step 2: Create tail pointer and set to NULL because we're starting with completely empty list.
  Node* tail = NULL;

  // Step 3: Insert 10 at head because we want to add it as first item in list.
  InsertAtHead(head, tail, 10);
  // Step 4: Insert 20 at head because we want to add it at beginning, pushing 10 to second position.
  InsertAtHead(head, tail, 20);
  // Step 5: Insert 30 at head because we want to add it at beginning, making it the new first item.
  InsertAtHead(head, tail, 30);
  // Step 6: Insert 40 at head because we want to add it at beginning, making it the new first item.
  InsertAtHead(head, tail, 40);

  // Step 7: Insert 1000 at position 2 because we want to put it as third item in list (positions start from 0).
  insertAtSpecificPosition(head, tail, 1000, 2);

  // Step 8: Print the entire circular list because we want to see what our final list looks like.
  print(head);
}