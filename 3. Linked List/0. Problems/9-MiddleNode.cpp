#include<iostream>
using namespace std;
#include<vector>

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

void insertNodeHead(Node* &head, int data){
  if(head == NULL){
    Node* newNode = new Node(data);
    newNode->next = head;
    head = newNode;
  }

  Node* newNode = new Node(data);
  newNode->next = head;
  head = newNode;
}

// Two-pass method - first count nodes, then find middle
// Time Complexity: O(n) - we go through the list twice
// Space Complexity: O(1) - we only use a few extra variables
Node* MiddleNode(Node* &head){
  // Step 1: Create a variable 'length' and set it to 0 because we need to count how many nodes are in the linked list
  int length = 0;
  // Step 2: Create a pointer 'temp' and point it to head because we don't want to lose the original head pointer while we count nodes
  Node* temp = head;
  // Step 3: Start a while loop that continues as long as temp is not NULL because we need to visit every single node to get the total count
  while(temp != NULL){
    // Step 4: Increase length by 1 because we found another node and need to add it to our total count
    length++;
    // Step 5: Move temp to the next node because we need to continue moving forward through the list to count all nodes
    temp = temp->next;
  }
  // Step 6: Calculate middleNode by dividing length by 2 because the middle node is at position length/2 (using integer division)
  int middleNode = length/2;
  // Step 7: Reset temp back to head because we need to start from the beginning again to actually reach the middle node
  temp = head;
  // Step 8: Start a for loop from 1 to middleNode because we need to move exactly middleNode steps forward from the head
  for(int i=1; i<=middleNode; i++){
    // Step 9: Move temp to the next node because we need to advance one step closer to the middle position
    temp = temp->next;
  }
  // Step 10: Return temp because it now points to the middle node that we calculated and reached
  return temp;
}

// Fast-slow pointer method - find middle in one pass
// Time Complexity: O(n) - we go through the list once
// Space Complexity: O(1) - we only use two extra pointers
Node* MiddleNodeFastSlow(Node* head){
  // Step 1: Create a pointer 'slow' and set it to head because this pointer will move one step at a time through the list
  Node* slow = head;
  // Step 2: Create a pointer 'fast' and set it to head because this pointer will move two steps at a time through the list
  Node* fast = head;
  // Step 3: Start a while loop that continues as long as fast is not NULL and fast->next is not NULL because we need to make sure fast can take two steps without crashing
  while(fast != NULL && fast->next != NULL){
    // Step 4: Move slow forward by one step because when fast moves twice as fast, slow will end up at the middle when fast reaches the end
    slow = slow->next;
    // Step 5: Move fast forward by two steps because we want fast to travel twice as far as slow so that slow ends up in the middle
    fast = fast->next->next;
  }
  // Step 6: Return slow because when fast has reached the end by moving two steps at a time, slow will be pointing to the middle node
  return slow;
}

// Print linked list
void printList(Node* head){
  Node* temp = head;
  while(temp != NULL){
    cout << temp->data << " -> ";
    temp = temp->next;
  }
  cout << "NULL" << endl;
}

int main(){
  Node* head = NULL;

  // Insert some nodes at head
  insertNodeHead(head, 10);
  insertNodeHead(head, 20);
  insertNodeHead(head, 30);
  insertNodeHead(head, 40);
  insertNodeHead(head, 50);

  cout << "Linked List: ";
  printList(head);

  // Find middle using length method
  Node* middle1 = MiddleNode(head);
  cout << "Middle (Length method): " << middle1->data << endl;

  // Find middle using fast & slow pointer method
  Node* middle2 = MiddleNodeFastSlow(head);
  cout << "Middle (Fast-Slow pointer method): " << middle2->data << endl;

  return 0;
}