/*
# Approch 1 : Using hashtable
1. Traverse the entrie ll from head
2. Store the address of each node in hash table bcz TC to search or nsert/add in hashtabel is only O(1), we are storing adress insted of value bcz node value can reapet but address cannot repeat
3. While storing adress, check this adress is present in the hashtable or not, if same adress found , then print there is loop in ll.  
4. TC of this approch is : O(n), SC: O(n) bcz of hash table


# Approch 2: Using cycle detection algorithm (Hase & tortoise algo || fast and slow pointer approch)
1. Initially keep slow and fast pointer head (slow pointer will move by 1 step and fast pointer will move by 2 step)
2. If after some time if slow & fast pointer point to same node..then this alogrithm says we there is a loop in  the ll. If there is no loop then slow and fast pointer pointes to null and fast->next also points to null, then there will be no loop in the ll

=> Prove
   1. In intutive way

*/

#include<iostream>
using namespace std;
#include<map>

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

//Using map 
// TC: O(N) Each node is visited once, and checking/adding in the map takes O(1) on average.
// SC: O(N) , We store each node's address in the map, so extra space grows with the number of nodes.
bool detectCycleMap(Node* head){
  // Step 1: Create a map to store nodes we have visited.
  // We need to remember every node we visit so we can check if we come back to the same node again.
  map<Node*, bool>visited;

  // Step 2: Start from the head node.
  Node* temp = head;

  // Step 3: Traverse the linked list until the end.
  // Bcz We need to check each node to see if any repeats.
  while(temp != NULL){
    // Step 4: Check if current node's address is already in map (visited).
    // Means If this node is already marked visited, we have a cycle.
    if(visited[temp] == true){
      return true; // Loop detected because we came back to a previously visited node.
    }
    // Step 5: Mark the current node as visited in the map.So next time if we see this node again, we know it's a cycle.
    visited[temp] = true;
    
    // Step 6: Move to the next node.Continue checking the rest of the linked list.
    temp = temp->next;
  }

  // Step 7: If we reach here, no cycle was detected. means We reached NULL without repeating any node.
  return false; //No loop
}

// Using cycle detection algorithm (Hase & tortoise algo || fast and slow pointer approch)
// Time Complexity: O(n)  -> Both pointers together make at most n steps in total.
// Space Complexity: O(1) -> No extra data structures, only two pointers.
bool detectCycleUsingFloyds(Node* head){
  // Step 1: Check if the linked list is empty. If there is no node, then there is no cycle.
  if(head == NULL){
    cout<<"LL is empty"<<endl;
    return false;
  }
  // Step 2: Initialize two pointers: slow and fast, both pointing to the head.
  // 'slow' moves one step at a time, 'fast' moves two steps at a time.
  Node* slow = head;
  Node* fast = head;
  
  // Step 3: Start looping while 'fast' does not reach the end (NULL). If 'fast' reaches NULL, list has no cycle because a cycle never ends.
  while(fast != NULL){
    // Step 4: Move fast pointer one step forward.
    fast = fast->next;
    // Step 5: Check if fast is not NULL before moving again.To avoid accessing next of NULL which will crash the program.
    if(fast != NULL){
      // Step 6: Move fast pointer one more step (so total 2 steps).bcz Fast always moves twice as fast as slow.
      fast = fast->next;
      // Step 7: Move slow pointer one step. Slow moves at normal speed.
      slow = slow->next;
    }
    // Step 8: Check if slow and fast meet. If there is a cycle, the faster pointer will eventually lap the slower one and meet it.
    if(slow == fast){
      return true; // Cycle found
    }
  }
  // Step 9: If loop ended, no cycle was detected. means Fast pointer reached NULL → no repetition → no cycle.
  return false;
}

void insertNodeAtHead(Node* &head, Node* &tail ,int data){
  if(head == NULL){
    Node* newNode = new Node(data);
    head = newNode;
    tail = newNode;
  }

  Node* newNode = new Node(data);
  newNode->next = head;
  head = newNode;
}

int main() {
    Node* head = new Node(100);
    Node* tail = head;

    // Create linked list: 5 -> 4 -> 3 -> 2 -> 1
    insertNodeAtHead(head, tail, 1);
    insertNodeAtHead(head, tail, 2);
    insertNodeAtHead(head, tail, 3);
    insertNodeAtHead(head, tail, 4);
    insertNodeAtHead(head, tail, 5);

    // Create a loop for testing: tail->next = head->next (point to 2nd node)
    tail->next = head->next;

    // Test Approach 1: Using map
    if (detectCycleMap(head)) {
        cout << "Loop detected using Hash Table approach" << endl;
    } else {
        cout << "No Loop (Hash Table approach)" << endl;
    }

    // Test Approach 2: Using Floyd's Algorithm
    if (detectCycleUsingFloyds(head)) {
        cout << "Loop detected using Floyd's Algorithm" << endl;
    } else {
        cout << "No Loop (Floyd's Algorithm)" << endl;
    }

    return 0;
}