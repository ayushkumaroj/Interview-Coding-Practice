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

// Insert node at end
void insert(Node*& head, int data) {
    Node* newNode = new Node(data);
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


// Approach: Hash Map Method (Mark Visited Nodes)
// Time Complexity: O(m + n) because we traverse both lists once, where m and n are lengths of lists
// Space Complexity: O(m) because we store all nodes from first list in the hash map
Node* IntersectionHashmap(Node* headA, Node* headB){
  // Step 1: Create a map to track visited nodes because we need to remember which nodes we've seen from first list
  map<Node* , bool>visited;

  // Step 2: Set temp to headA because we need to traverse first list without losing the head pointer
  Node* temp = headA;
  
  // Step 3: Mark all nodes from first list as visited because we need to remember every node we encounter
  while(temp != NULL){
    // Step 4: Mark current node as visited because when we see this node again in second list, we know it's intersection
    visited[temp] = true;
    
    // Step 5: Move to next node because we need to mark all nodes in first list
    temp = temp->next;
  }

  // Step 6: Set temp to headB because now we need to check second list for any visited nodes
  temp = headB;
  
  // Step 7: Check each node in second list to see if we visited it before because intersection means same node appears in both lists
  while(temp != NULL){
    // Step 8: Check if current node was visited in first list because if yes, this is our intersection point
    if(visited.find(temp) != visited.end()){
      // Step 9: Return the intersecting node because this is the first common node we found
      return temp;
    }
    
    // Step 10: Move to next node because we need to check all nodes in second list
    temp = temp->next;
  }

  // Step 11: Return NULL because we checked both lists and found no common nodes
  return NULL;
}

// Function: getLength
// Approach: Simple Traversal Count
// Time Complexity: O(n) because we visit each node once to count them , // Space Complexity: O(1) 
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


// Approach: Length Difference Method (Align Starting Positions)
// Time Complexity: O(m + n) because we traverse both lists to get lengths, then traverse again to find intersection
// Space Complexity: O(1) because we only use a few pointer variables
Node* IntersectionLengthDiff(Node* headA, Node* headB){
  // Step 1: Get length of first list because we need to know how long each list is
  int len1 = getLength(headA);
  
  // Step 2: Get length of second list because we need to compare lengths to find difference
  int len2 = getLength(headB);

  // Step 3: Calculate absolute difference between lengths because we need to know how many steps to skip
  int diff = abs(len1 - len2);

  // Step 4: Set temp1 to headA because we need to traverse first list
  Node* temp1 = headA;
  
  // Step 5: Set temp2 to headB because we need to traverse second list
  Node* temp2 = headB;

  // Step 6: If first list is longer, skip ahead in first list because we want both pointers to be same distance from intersection
  if(len1 > len2){
    // Step 7: Move temp1 forward by difference amount because this aligns both pointers to same distance from end
    for(int i=0; i<diff; i++){
      temp1 = temp1->next;
    }
  }

  // Step 8: If second list is longer, skip ahead in second list because we want both pointers to be same distance from intersection
  if(len2 > len1){
    // Step 9: Move temp2 forward by difference amount because this aligns both pointers to same distance from end
    for(int i=0; i<diff; i++){
      temp2 = temp2->next;
    }
  }

  // Step 10: Move both pointers together until they meet because now they're aligned and will meet at intersection
  while(temp1 != NULL && temp2 != NULL){
    // Step 11: Check if both pointers point to same node because this means we found intersection
    if(temp1 == temp2){
      // Step 12: Return the intersecting node because both pointers are at the same location
      return temp1;
    }

    // Step 13: Move temp1 to next node because we need to check next position
    temp1 = temp1->next;
    
    // Step 14: Move temp2 to next node because we need to keep both pointers moving together
    temp2 = temp2->next;
  }
  
  // Step 15: Return NULL because we reached end without finding intersection
  return NULL;
}


// Approach: Two Pointer Cycle Method (Switch Lists When Reaching End)
// Time Complexity: O(m + n) because each pointer traverses both lists at most once
// Space Complexity: O(1) because we only use two pointer variables
Node* IntersectionTwoPointer(Node* headA, Node* headB){
  // Step 1: Check if both lists are empty because if both are NULL, there's no intersection
  if(headA == NULL && headB == NULL){
    return NULL;
  }
  
  // Step 2: Set temp1 to headA because we start first pointer at beginning of first list
  Node* temp1 = headA;
  
  // Step 3: Set temp2 to headB because we start second pointer at beginning of second list
  Node* temp2 = headB;

  // Step 4: Keep moving pointers until they meet because they will eventually meet at intersection or both become NULL
  while(temp1 != temp2){
    // Step 5: Move temp1 to next node because we need to traverse through the lists
    temp1 = temp1->next;
    
    // Step 6: Move temp2 to next node because both pointers need to move at same speed
    temp2 = temp2->next;

    // Step 7: Check if pointers are equal after moving because they might meet at intersection
    if(temp1 == temp2){
      // Step 8: Return the meeting point because this is our intersection node
      return temp1;
    }

    // Step 9: If temp1 reaches end, switch to second list because this ensures both pointers travel same total distance
    if(temp1 == NULL){
      temp1 = headB;
    }

    // Step 10: If temp2 reaches end, switch to first list because this ensures both pointers travel same total distance
    if(temp2 == NULL){
      temp2 = headA;
    }
  }

  // Step 11: Return temp1 because when loop ends, both pointers are at same location (intersection or NULL)
  return temp1;
}

// ---------------------- Main ----------------------
int main() {
    // Creating two linked lists
    Node* headA = NULL;
    Node* headB = NULL;

    // List A: 1 -> 2 -> 3
    insert(headA, 1);
    insert(headA, 2);
    insert(headA, 3);

    // List B: 9 -> 10
    insert(headB, 9);
    insert(headB, 10);

    // Common part: 30 -> 40 -> 50
    Node* common = new Node(30);
    common->next = new Node(40);
    common->next->next = new Node(50);

    // Attaching common part to both lists
    headA->next->next->next = common; // A: 1->2->3->30->40->50
    headB->next->next = common;       // B: 9->10->30->40->50

    // Using HashMap method
    Node* res1 = IntersectionHashmap(headA, headB);
    if (res1) cout << "HashMap Method: Intersection at " << res1->data << endl;

    // Using Length Difference method
    Node* res2 = IntersectionLengthDiff(headA, headB);
    if (res2) cout << "Length Difference Method: Intersection at " << res2->data << endl;

    // Using Two Pointer method
    Node* res3 = IntersectionTwoPointer(headA, headB);
    if (res3) cout << "Two Pointer Method: Intersection at " << res3->data << endl;

    return 0;
}