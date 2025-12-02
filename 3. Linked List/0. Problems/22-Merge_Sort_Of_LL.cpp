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

// Time Complexity: O(N) because we go through the list about half way, which is proportional to its total length N.
// Space Complexity: O(1) because we only create two new pointers ('slow' and 'fast'), and this doesn't change no matter how long the list is.
Node* findMid(Node* head){
    // Step 1: Create a pointer called 'slow' and make it point to the start of the list because we need a pointer that will move one step at a time.
    Node* slow = head;
    // Step 2: Create a pointer called 'fast' and make it point to the second item in the list because we need another pointer that moves twice
    //  as fast as 'slow'.
    Node* fast = head->next;

    // Step 3: Start a loop that keeps running as long as the 'fast' pointer has not reached the end of the list because this is how we move through
    //  the list to find the middle.
    while(fast != NULL && fast->next != NULL){
        // Step 4: Move the 'slow' pointer one step forward because it needs to travel at half the speed of the 'fast' pointer.
        slow = slow->next;
        // Step 5: Move the 'fast' pointer two steps forward because this makes it travel twice as fast as 'slow', ensuring it reaches the end while
        //  'slow' is in the middle.
        fast = fast->next->next;
    }
    // Step 6: Return the 'slow' pointer because when the 'fast' pointer reaches the end, the 'slow' pointer will be at the middle of the list.
    return slow;
}

// Time Complexity: O(N1 + N2) where N1 and N2 are the lengths of the two lists because we have to look at every item in both lists one time to combine them.
// Space Complexity: O(1) because we are just moving the links of the existing nodes, not creating a whole new list with new nodes.
Node* merge(Node* list1, Node* list2){
    Node* temp1 = list1;
    Node* temp2 = list2;
    Node* dummyNode = new Node(0);
    Node* temp = dummyNode;

    while(temp1 != NULL && temp2 != NULL){
        if(temp1->data < temp2->data){
            temp->next = temp1;
            temp = temp1;
            temp1 = temp1->next;
        }
        else{
            temp->next = temp2;
            temp = temp2;
            temp2 = temp2->next;
        }
    }

    if(temp1 != NULL){
        temp->next = temp1;
    } else {
        temp->next = temp2;
    }

    return dummyNode->next;
}

// Time Complexity: O(N log N) because we split the list in half (log N) and then merge the pieces together (N), which is very efficient for sorting.
// Space Complexity: O(log N) because the function calls itself for smaller lists, and the depth of these calls is based on log N.
Node* MergeSort(Node* head){
    // Step 1: Check if the list is empty or has only one item because a list with zero or one item is already sorted by default.
    if(head == 0 || head->next ==0){
        return head;
    }

    // Step 2: Find the middle item of the current list because the first step of merge sort is to divide the problem into two smaller halves.
    Node* mid = findMid(head);
    // Step 3: Create a 'left' pointer that points to the start of the list because this will be the head of our first half.
    Node* left = head;
    // Step 4: Create a 'right' pointer that points to the item *after* the middle because this will be the head of our second half.
    Node* right = mid->next;
    // Step 5: Break the list into two parts by setting the 'next' of the middle item to nothing because this separates the left and right halves.
    mid->next = 0;

    // Step 6: Call MergeSort on the left half of the list because we need to keep splitting and sorting this half until it's fully sorted.
    left = MergeSort(left);
    // Step 7: Call MergeSort on the right half of the list because we also need to sort this half completely.
    right = MergeSort(right);

    // Step 8: Merge the now-sorted left and right halves back together because the final step is to combine the sorted smaller lists into one larger sorted list.
    Node* mergeLL = merge(left, right);
    // Step 9: Return the head of the newly merged and sorted list because this is the final result.
    return mergeLL;
}


