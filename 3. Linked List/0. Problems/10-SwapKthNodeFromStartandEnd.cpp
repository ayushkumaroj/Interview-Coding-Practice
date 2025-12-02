#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    // default constructor
    Node() {
        data = 0;       // ❌ earlier you wrote int data = 0 (that redeclared a local variable)
        next = NULL;    // same mistake
    }

    // parameterized constructor
    Node(int data) {
        this->data = data;  // use this-> to assign correctly
        next = NULL;
    }
};

// Function: getLength
// Approach: Simple Traversal Count
// Time Complexity: O(n) because we visit each node once to count them
// Space Complexity: O(1) because we only use a counter variable
int getLength(Node* head){
  // Step 1: Initialize length counter to 0 because we start counting from zero nodes
  int len = 0;
  
  // Step 2: Set temp to head because we need to traverse the list without losing head pointer
  Node* temp = head;
  
  // Step 3: Count each node by traversing the entire list because we need total length
  while(temp != NULL){
    // Step 4: Increase counter by 1 because we found another node in the list
    len++;
    
    // Step 5: Move to next node because we need to count every node in the list
    temp = temp->next;
  }
  
  // Step 6: Return total count because this is the length we calculated
  return len;
}


// Approach: Two Pass Method (First Pass for Length, Second Pass to Find Nodes)
// Time Complexity: O(n) because we traverse the list twice - once for length and once to find nodes
// Space Complexity: O(1) because we only use a few pointer variables
Node* swapNodeTwoPass(Node* head, int k){
  // Step 1: Get total length of linked list because we need to calculate position from end
  int lengthOfLL = getLength(head);

  // Step 2: Set k1 to k because k1 represents kth node from beginning (1-indexed)
  int k1 = k;
  
  // Step 3: Calculate k2 as length-k+1 because this gives us kth node from end (1-indexed)
  int k2 = lengthOfLL-k+1;

  // Step 4: Check if k is greater than list length because we can't swap if k is out of bounds
  if(k1 > lengthOfLL){
    return head;
  }

  // Step 5: Check if k1 equals k2 because if they're same node, no swap needed
  if(k1 == k2){
    return head;
  }

  // Step 6: Set k1Node to head because we need to find kth node from beginning
  Node* k1Node = head;
  
  // Step 7: Move k1Node to kth position from beginning because we need to reach the exact node to swap
  while(k1 > 1){
    k1Node = k1Node->next;
    k1--;
  }

  // Step 8: Set k2Node to head because we need to find kth node from end
  Node* k2Node = head;
  
  // Step 9: Move k2Node to kth position from end because we need to reach the exact node to swap
  while(k2 > 1){
    k2Node = k2Node->next;
    k2--;
  }

  // Step 10: Swap the data values of both nodes because we want to exchange their contents
  swap(k1Node->data, k2Node->data);
  
  // Step 11: Return head because the list structure remains same, only data is swapped
  return head;
}


// Approach: One Pass Two Pointer Method (Find Both Nodes in Single Traversal)
// Time Complexity: O(n) because we traverse the list only once
// Space Complexity: O(1) because we only use a few pointer variables
Node* swapNodeOnePass(Node* head, int k){
  // Step 1: Initialize person1 to NULL because we haven't found kth node from beginning yet
  Node* person1 = NULL;
  
  // Step 2: Initialize person2 to NULL because we haven't found kth node from end yet
  Node* person2 = NULL;

  // Step 3: Set temp to head because we need to traverse the list to find both nodes
  Node* temp = head;

  // Step 4: Traverse the entire list to find both kth nodes simultaneously because we want single pass efficiency
  while(temp != NULL){
    // Step 5: Move person2 forward if it's been initialized because person2 needs to stay k steps behind person1
    if(person2 != NULL){
      person2 = person2->next;
    }

    // Step 6: Decrease k by 1 because we're counting down to find kth position
    k--;
    
    // Step 7: When k becomes 0, we found kth node from beginning because we've moved k steps from start
    if(k == 0){
      // Step 8: Set person1 to current temp because this is kth node from beginning
      person1 = temp;
      
      // Step 9: Set person2 to head because now person2 will stay k steps behind temp, making it kth from end
      person2 = head;
    }
    
    // Step 10: Move temp to next node because we need to continue traversing until end
    temp = temp->next;
  }

  // Step 11: Swap the data values of both nodes because we found both kth nodes and want to exchange their contents
  swap(person1->data, person2->data);
  
  // Step 12: Return head because the list structure remains same, only data is swapped
  return head;
}

// ✅ Insert at end
void insert(Node* &head, int value) {
    Node* newNode = new Node(value);
    if (head == NULL) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}


void print(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}


int main() {
    Node* head = NULL;

    // Inserting nodes
    insert(head, 10);
    insert(head, 20);
    insert(head, 30);
    insert(head, 40);
    insert(head, 50);

    cout << "Original List: ";
    print(head);

    // Swap using Two Pass method
    head = swapNodeTwoPass(head, 2);
    cout << "After swapping 2nd node from start and end (TwoPass): ";
    print(head);

    // Swap using One Pass method
    head = swapNodeOnePass(head, 2);
    cout << "After swapping 2nd node again (OnePass): ";
    print(head);

    return 0;
}
