
#include<iostream>
using namespace std;
#include<unordered_set>

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

// Time Complexity: O(N1 * N2) because for each item in the first list, we have to look through the entire second list.
// Space Complexity: O(M) because we create a new list to store the M items that are common to both lists.
Node* IntersectionBruteForce(Node* head1, Node* head2){
    // Step 1: Create a dummyNode to act as a placeholder because it makes adding the first common number to our new list easier.
    Node* dummyNode = new Node(-1);
    // Step 2: Create a 'temp' pointer and point it to dummyNode because we need a pointer to build the new list without losing the start.
    Node* temp = dummyNode;
    
    // Step 3: Create a 'temp1' pointer for head1 because we need to go through the first list without changing its starting point.
    Node* temp1 = head1;
    // Step 4: Start a loop to go through each item in the first list because we need to check every number from list1.
    while(temp1 != NULL){
        // Step 5: Create a 'temp2' pointer for head2 inside the first loop because we need to check the entire second list for every single item from the first list.
        Node* temp2 = head2;
        // Step 6: Start a second loop to go through each item in the second list because we want to compare the current number from list1 with every number from list2.
        while(temp2 != NULL){
            // Step 7: Check if the number in list1 is the same as the number in list2 because we are looking for common numbers.
            if(temp1->data == temp2->data){
                // Step 8: Create a new node with the common number and link it to our result list because we found a match and need to save it.
                temp->next = new Node(temp1->data);
                // Step 9: Move the 'temp' pointer to the new node because this is where the next common number will be added.
                temp = temp->next;
                // Step 10: Break the inner loop because we found a match for the current number and don't need to check the rest of the second list.
                break;
            }
            // Step 11: Move 'temp2' to the next item in the second list because the current numbers didn't match.
            temp2 = temp2->next;
        }
        // Step 12: Move 'temp1' to the next item in the first list because we are done checking the current number against the second list.
        temp1 = temp1->next;
    }
    // Step 13: Return the node right after our dummyNode because that is the actual start of our new list of common numbers.
    return dummyNode->next;
}

// Time Complexity: O(N1 + N2) because we go through the second list once to store its numbers, and then through the first list once to check for matches.
// Space Complexity: O(N2) because we use a hash set to store all the numbers from the second list.
Node* findIntersectionUsingSet(Node* head1, Node* head2){
    // Step 1: Create an empty set 's' because a set lets us store numbers and check very quickly if a number is already in it.
    unordered_set<int>s;

    // Step 2: Create a 'temp2' pointer for head2 because we need to go through the second list without changing its starting point.
    Node* temp2 = head2;
    // Step 3: Loop through the second list until it ends because we want to put all its numbers into our set.
    while(temp2 != NULL){
        // Step 4: Add the number from the current node of list2 into our set because this builds our collection of numbers for quick lookups.
        s.insert(temp2->data);
        // Step 5: Move 'temp2' to the next node because we need to process the next number in the list.
        temp2 = temp2->next;
    }

    // Step 6: Create a dummyNode to act as a placeholder because it makes it simple to start building our new result list.
    Node* dummyNode = new Node(-1);
    // Step 7: Create a 'temp' pointer and point it to dummyNode because we will use this pointer to add new nodes to the result list.
    Node* temp = dummyNode;

    // Step 8: Create a 'temp1' pointer for head1 because we need to go through the first list without losing its start.
    Node* temp1 = head1;
    // Step 9: Loop through the first list until it ends because we need to check each of its numbers.
    while(temp1 != NULL){
        // Step 10: Check if the current number from list1 exists in our set because this tells us if the number is common to both lists.
        if(s.find(temp1->data) != s.end()){
            // Step 11: If the number is found, create a new node for it and link it to our result list because we need to save the common number.
            temp->next = new Node(temp1->data);
            // Step 12: Move the 'temp' pointer to the new node because the next common number will be added after this one.
            temp = temp->next;
        }
        // Step 13: Move 'temp1' to the next node in the first list because we are done with the current number.
        temp1  = temp1->next;
    }
    // Step 14: Return the node right after our dummyNode because that is the real beginning of our list of common numbers.
    return dummyNode->next;
}

// ----------------Using Sorting+TwoPointer--------------
Node* findMid(Node* head){
    Node* slow = head;
    Node* fast = head->next;

    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

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
    }else{
        temp->next = temp2;
    }
    return dummyNode->next;
}

// Time Complexity: O(N log N) because we split the list in half (log N times) and merge the parts (N operations).
// Space Complexity: O(log N) because the computer needs to remember each split in the function calls.
Node* MergeSort(Node* head){
    // Step 1: Check if the list is empty or has only one node because a list with 0 or 1 items is already sorted.
    if(head == 0 || head->next ==0){
        return head;
    }

    // Step 2: Find the middle of the list because we need to split it into two halves.
    Node* mid = findMid(head);
    // Step 3: The 'left' half is from the beginning of the list to the middle because this is the first part to sort.
    Node* left = head;
    // Step 4: The 'right' half is from the node right after the middle to the end because this is the second part.
    Node* right = mid->next;
    // Step 5: Break the link between the two halves because we need to treat them as two separate lists.
    mid->next = 0;

    // Step 6: Call MergeSort on the left half because we need to keep splitting and sorting it until it's down to single nodes.
    left = MergeSort(left);
    // Step 7: Call MergeSort on the right half for the same reason.
    right = MergeSort(right);

    // Step 8: Merge the sorted left and right halves back together because this combines them into one final sorted list.
    Node* mergeLL = merge(left, right);
    // Step 9: Return the head of the newly merged and sorted list because this is our final result.
    return mergeLL;
}

//Note: This two pointer approch  will only work if both linked lists are sorted
// Time Complexity: O(N1*log(N1) + N2*log(N2)) because sorting the lists is the most time-consuming part.
// Space Complexity: O(log(N1) + log(N2)) because of the function call stack used by the sorting algorithm.
Node* IntersectionUsigSortingTwopoint(Node* head1, Node* head2){
    // Step 1: Sort the first linked list because the two-pointer method requires the lists to be in order.
    head1 = MergeSort(head1);
    // Step 2: Sort the second linked list for the same reason.
    head2 = MergeSort(head2);
    
    // Step 3: Create a dummyNode to serve as a fake start for our result list because it makes the code cleaner.
    Node* dummyNode = new Node(0);
    // Step 4: Create a 'temp' pointer to build the result list because we will add common nodes to it.
    Node* temp = dummyNode;
    
    // Step 5: Create a 'temp1' pointer for the sorted head1 because we need to move through it.
    Node* temp1 = head1;
    // Step 6: Create a 'temp2' pointer for the sorted head2 for the same reason.
    Node* temp2 = head2;
    
    // Step 7: Loop as long as there are nodes in both lists because we need to compare them.
    while(temp1 != NULL && temp2 != NULL){
        // Step 8: Check if the numbers at both pointers are the same because that means we found a common number.
        if(temp1->data == temp2->data){
            // Step 9: Create a new node with the common number and attach it to our result list because we need to save it.
            temp->next = new Node(temp1->data);
            // Step 10: Move the 'temp' pointer to the new node because the next one will be added after it.
            temp = temp->next;
            // Step 11: Move both 'temp1' and 'temp2' to their next nodes because we have processed the current common number.
            temp1 = temp1->next;
            temp2 = temp2->next;
        }

        // Step 12: Check if the number in list1 is smaller than the number in list2.
        else if(temp1->data < temp2->data){
            // Step 13: Move 'temp1' to its next node because its current number is too small to match 'temp2's number, so we need a bigger one from list1.
            temp1 = temp1->next;
        }
        // Step 14: If the number in list2 is smaller.
        else{
            // Step 15: Move 'temp2' to its next node because its current number is too small to match 'temp1's number, so we need a bigger one from list2.
            temp2 = temp2->next;
        }
    }
    // Step 16: Return the node right after our dummyNode because it is the actual start of the list of common numbers.   
    return dummyNode->next;
}

