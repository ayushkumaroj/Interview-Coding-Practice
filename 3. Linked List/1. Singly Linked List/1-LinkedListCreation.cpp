#include<iostream>
using namespace std;

// Step 1: Define a Node class to represent each element in the linked list
class Node{
  public:
  int data;  // Step 2: Each node stores an integer value
  Node* next;// Step 3: Each node has a pointer that points to the next node in the list

  // Step 4: Default constructor initializes data to 0 and next to NULL
  Node(){
    this->data = 0;
    this->next = NULL;
  }
  
  // Step 5: Parameterized constructor initializes data with a given value and next to NULL
  Node(int data){
    this->data = data;
    this->next = NULL;
  }
};

// Function: To print all the elements of the linked list starting from the first node.
// TC: O(n) Because we visit each node exactly once., 
// SC: O(1) Because we only use one extra pointer (temp) for traversal.
void printLL(Node* first){
  // Step 6: Create a temporary pointer 'temp' to start traversal from the first node
  Node* temp = first;
  // Step 7: Traverse the linked list until we reach the end (NULL)
  while(temp  != NULL){
    // Step 8: Print the data of the current node
    cout<<temp->data<<" ";
    // Step 9: Move to the next node by updating 'temp'
    temp = temp->next;
  }
}

int main(){
  // Step 10: Create five nodes dynamically using the Node class
  Node* first = new Node(10);  // First node with data = 10
  Node* second = new Node(20); // Second node with data = 20
  Node* third = new Node(30);  // Third node with data = 30
  Node* fourth = new Node(40); // Fourth node with data = 40
  Node* fifth = new Node(50);  // Fifth node with data = 50

  // Step 11: Connect the nodes to form a linked list
  first->next = second; // First node points to second node
  second->next = third; // Second node points to third node
  third->next = fourth; // Third node points to fourth node
  fourth->next = fifth; // Fourth node points to fifth node
  // Fifth node's next is already NULL, so this is the end of the list

  // Step 12: Print a message and call the function to display the linked list
  cout<<"Printing the LL"<<endl;
  printLL(first); // Pass the head (first node) to the print function
}