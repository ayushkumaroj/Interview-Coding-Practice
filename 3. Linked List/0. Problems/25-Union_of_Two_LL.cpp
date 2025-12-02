
#include<iostream>
using namespace std;
#include<unordered_set>
#include<set>

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

// Time Complexity: O(N1*log(K) + N2*log(K)) where K is the number of unique elements. This is because inserting N1 and N2 items into a
//  set takes logarithmic time for each item.
// Space Complexity: O(N1 + N2) because in the worst case, the set and the new list will store all elements from both original lists.
Node* findUnion(Node* head1, Node* head2){
    // Step 1: Create an empty set 's' because a set automatically handles duplicates and keeps elements sorted for us.
    set<int>s;

    // Step 2: Create a 'temp1' pointer for head1 because we need to go through the first list without changing where it starts.
    Node* temp1 = head1;
    // Step 3: Loop through the first list until it's finished because we need to add every number from it to our set.
    while(temp1 != NULL){
        // Step 4: Add the number from the current node into the set because the set will only keep the unique numbers.
        s.insert(temp1->data);
        // Step 5: Move 'temp1' to the next node because we need to process the rest of the list.
        temp1 = temp1->next;
    }

    // Step 6: Create a 'temp2' pointer for head2 because we need to go through the second list without losing its starting point.
    Node* temp2 = head2;
    // Step 7: Loop through the second list until it ends because we also need to add all of its numbers to the set.
    while(temp2 != NULL){
        // Step 8: Add the number from the current node into the set because if the number is already there, the set will ignore it.
        s.insert(temp2->data);
        // Step 9: Move 'temp2' to the next node because we need to look at every number in this list.
        temp2 = temp2->next;
    }

    // Step 10: Create a dummyNode to be a temporary start for our new list because it makes adding nodes much simpler.
    Node* dummyNode = new Node(-1);
    // Step 11: Create a 'temp' pointer and point it to the dummyNode because we will use this to build the new list.
    Node* temp = dummyNode;
    // Step 12: Loop through every number stored in our set because these are the unique numbers we need for our final union list.
    for(int data: s){
        // Step 13: Create a new node with the number from the set and attach it to our list because we are converting the set back into a linked list.
        temp->next = new Node(data);
        // Step 14: Move the 'temp' pointer to the new node we just added because the next node needs to be linked after this one.
        temp = temp->next;
    }
    // Step 15: Create a 'result' pointer to the actual start of the new list because dummyNode is just a placeholder we don't need.
    Node* result = dummyNode->next;
    // Step 16: Delete the dummyNode because we are done using it and want to prevent memory leaks.
    delete dummyNode;
    // Step 17: Return the final result list because this list contains all the unique numbers from both original lists.
    return result;
}

