#include<iostream>
using namespace std;

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

// Using Two Traversal 
// TC: O(n) because we traverse the list two times , SC: O(1)
Node* findKthFromEnd(Node* &head, int k){
  // Step 1: Initialize 'len' to count the number of nodes in the linked list.
  // We need the total length to calculate the position of the k-th node from the start.
  int len = 0;

  // Step 2: Use a temporary pointer 'temp' starting from head to calculate the length.
  Node* temp = head;

  // Step 3: Loop through the list until temp becomes NULL. This way, we count every node to know the full length.
  while(temp != NULL){
    len++;              // Step 4: Increase length by 1 for each node visited.
    temp = temp->next; // Step 5: Move temp to the next node to continue counting.
  }

  // Step 6: Calculate the position of the k-th node from the start using formula: length - k + 1.
  // If we know total length and k from the end, we can find exact position from the start.
  int kPosFromStart = len-k+1;

  // Step 7: If position <= 0, then k is invalid because k > length.  We cannot find k-th from end if k is more than total nodes.
  if(kPosFromStart <= 0){
    cout<<"Invalid k (greater than length)" <<endl;
    return NULL; // Reason: No valid node to return in this case.
  }

  // Step 8: Reset temp to head to start finding the node from beginning.
  temp = head;
  // Step 9: Move temp forward until we reach the kPosFromStart node. bcz We know which node from the start corresponds to k-th from end.
  for(int i=1; i<kPosFromStart; i++){
    temp = temp->next; // Move one step at a time until we reach that node.
  }
  // Step 10: Return the node found at that position. bcz This is the node which is k-th from the end.
  return temp;
}

// More Optimized : Using One Traversal (Using two pointer Approch)
// TC: O(n) because we traverse the list once , SC: O(1)
Node* findKthFromEnd2(Node* head, int k){
  // Step 1: Create two pointers 'p' and 'q', both starting at head. bcz We'll use p to move ahead first, and q will later catch up to find the node.
  Node* fast = head;
  Node* slow = head;

  // Step 2: Move pointer 'p' k steps ahead. bcz The gap between p and q becomes k, so when p reaches the end, q will be at the answer.
  for(int i=0; i<k; i++){
    // Step 3: If p becomes NULL before k steps, k is too large.
    if(fast == NULL){
      cout<<"K is greater than the length of the Linked list"<<endl;
    }
    // Step 4: Move p one step ahead.
    fast = fast->next;
  }

  // Step 5: Move both pointers one step at a time until p reaches the end.Since p is k steps ahead, when p hits NULL, q will be k-th from the end.
  while( fast != NULL){
    fast = fast->next; // Move p forward.
    slow = slow->next; // Move q forward at the same speed.
  }

  // Step 6: Return q because it's now at the k-th node from the end. bcz This is the exact position we wanted.
  return slow;
}

int main() {
  // Step 1: Create nodes of the linked list manually for testing.
  // Reason: We need some data in the linked list to test both functions.
  Node* head = new Node(10);
  Node* second = new Node(20);
  Node* third = new Node(30);
  Node* fourth = new Node(40);
  Node* fifth = new Node(50);

  // Step 2: Link the nodes together to form the list: 10 -> 20 -> 30 -> 40 -> 50.
  // Reason: Linking nodes will make it an actual linked list.
  head->next = second;
  second->next = third;
  third->next = fourth;
  fourth->next = fifth;

  // Step 3: Choose a value for k to find the k-th node from the end.
  int k = 2;

  // Step 4: Call the first method (two traversal) and store result.
  // Reason: We want to check which node is k-th from the end using first method.
  Node* ans1 = findKthFromEnd(head, k);
  if(ans1 != NULL) {
    cout << "Using two traversals: " << ans1->data << endl;
  }

  return 0;
}
