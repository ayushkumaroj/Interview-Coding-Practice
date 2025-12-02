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

//Using an array (vector) – changes only the data values.
// Time Complexity: O(n) - we go through the list twice
// Space Complexity: O(n) - we store all values in a vector
Node* ReverseListWithVector(Node* &head){
  // Step 1: Create an empty vector called 'ans' because we need a place to store all the data values from the linked list in order
  vector<int>ans;
  // Step 2: Create a pointer 'temp' and point it to head because we don't want to lose the original head pointer while we move through the list
  Node* temp = head;
  // Step 3: Start a while loop that continues as long as temp is not NULL because we need to visit every node in the linked list to collect all data values
  while(temp != NULL){
    // Step 4: Add the current node's data to the end of our vector because we want to store all values in the same order they appear in the list
    ans.push_back(temp->data);
    // Step 5: Move temp to the next node because we need to continue moving forward through the list to get all data values
    temp = temp->next;
  }
  // Step 6: Create an integer 'i' and set it to the last index of our vector because we want to start reading values from the end of the vector backwards
  int i = ans.size()-1;
  // Step 7: Reset temp back to head because we need to go through the linked list again but this time to change the data values
  temp = head;
  // Step 8: Start another while loop that continues as long as temp is not NULL because we need to visit every node again to put the reversed data back
  while(temp != NULL){
    // Step 9: Replace the current node's data with the value from our vector at position i because we want to put the last collected value into the first node
    temp->data = ans[i];
    // Step 10: Decrease i by 1 because we want to move backwards through our vector to get the next value in reverse order
    i--;
    // Step 11: Move temp to the next node because we need to continue through the list to change all remaining data values
    temp = temp->next;
  }
  // Step 12: Return head because the caller needs the pointer to the start of the now-reversed linked list
  return head;
}

// Iterative method – changes the next pointers.
// Time Complexity: O(n) - we go through the list once
// Space Complexity: O(1) - we only use a few extra pointers
Node* ReverseListIterative(Node* head){
  // Step 1: Create a pointer 'curr' and set it to head because we need to keep track of the current node we are working on
  Node* curr = head;
  // Step 2: Create a pointer 'prev' and set it to NULL because the first node will become the last node and should point to nothing
  Node* prev = NULL;
  // Step 3: Create a pointer 'future' and set it to NULL because we need a place to temporarily store the next node before we lose it
  Node* future = NULL;
  // Step 4: Start a while loop that continues as long as curr is not NULL because we need to reverse every single node in the list
  while(curr != NULL){
    // Step 5: Store curr's next pointer in future because we are about to change curr's next pointer and don't want to lose the rest of the list
    future = curr->next;
    // Step 6: Point curr's next to prev because we want to reverse the direction of this connection
    curr->next = prev;
    // Step 7: Move prev to curr because curr will become the previous node for the next iteration
    prev = curr;
    // Step 8: Move curr to future because we need to continue with the next node in the original list
    curr = future;
  }
  // Step 9: Set head to prev because after the loop ends, prev points to what was the last node and is now the first node of the reversed list
  head = prev;
  // Step 10: Return head because the caller needs the pointer to the start of the reversed linked list
  return head;
}

// Using Recursion
// Time Complexity: O(n) - we visit each node once through recursion
// Space Complexity: O(n) - recursion uses the call stack which stores n function calls
Node* Reverse(Node* curr, Node* prev){
  // Step 1: Base case - Check if curr is NULL because this means we have reached the end of the list and prev now points to the new head
  if(curr == NULL){
    // Step 2: Return prev because it points to what was the last node and is now the first node of the reversed list
    return prev;
  }
  // Step 3: Store curr's next pointer in future because we are about to change curr's next and need to remember where the rest of the list is
  Node* future = curr->next;
  // Step 4: Point curr's next to prev because we want to reverse this connection just like in the iterative method
  curr->next = prev;
  // Step 5: Call Reverse recursively with future and curr because we need to continue reversing the rest of the list with updated pointers
  return Reverse(future, curr);
}
// Recursive method – changes the next pointers via recursion.
// Time Complexity: O(n) - the helper function visits each node once
// Space Complexity: O(n) - recursion uses the call stack
Node* ReverseRecursive(Node* head){
  // Step 1: Create a pointer 'curr' and set it to head because the helper function needs to know which node to start reversing from
  Node* curr = head;
  // Step 2: Create a pointer 'prev' and set it to NULL because the first node will become the last node and should point to nothing
  Node* prev = NULL;
  // Step 3: Call the helper function Reverse with curr and prev because we need to start the recursive process with the correct starting values
  return Reverse(curr, prev);
}

// Print linked list
void printList(Node* head) {
    Node* temp = head;
    while(temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main() {
    Node* head = NULL;

    // Insert elements
    insertNodeHead(head, 5);
    insertNodeHead(head, 4);
    insertNodeHead(head, 3);
    insertNodeHead(head, 2);
    insertNodeHead(head, 1);

    cout << "Original List: ";
    printList(head);

    // Method 1: Using vector
    head = ReverseListWithVector(head);
    cout << "Reversed with Vector: ";
    printList(head);

    // Method 2: Iterative
    head = ReverseListIterative(head);
    cout << "Reversed Iteratively: ";
    printList(head);

    // Method 3: Recursive
    head = ReverseRecursive(head);
    cout << "Reversed Recursively: ";
    printList(head);

    return 0;
}