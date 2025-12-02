#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

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

// Insert node at the end
void insert(Node*& head, int value) {
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

// Print Linked List
void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

// Time Complexity: O(N) because we visit each element of the array once to create a node.
// Space Complexity: O(N) because we create a new node in memory for each element of the array.
Node* convertArrToLL(vector<int>arr){
	// Step 1: Get the number of items in the array because we need to know how many times to loop and if the array is empty.
    int n = arr.size();
	// Step 2: Check if the array is empty because if it is, we should return nothing (NULL) to show there is no list.
    if(n == 0){
        return NULL;
    }
	// Step 3: Create the first node of the list using the first item from the array because every linked list needs a starting point,
    //  which we call the 'head'.
    Node* head = new Node(arr[0]);
	// Step 4: Create a temporary pointer 'temp' and point it to the 'head' because we need a pointer that can move through the list to 
    // add new nodes, without losing the original 'head'.
    Node* temp = head;

	// Step 5: Start a loop from the second item of the array to the end because we have already used the first item to create the head.
    for(int i=1; i<n; i++){
		// Step 6: Create a new node with the current array item and link it to the end of our list because this adds the next item in the sequence.
        temp->next = new Node(arr[i]);
		// Step 7: Move the 'temp' pointer to this new node because 'temp' must always point to the last node in the list so we can add the next one.
        temp = temp->next;
    }
	// Step 8: Return the 'head' of the new list because this is the starting point that allows us to access the entire list.
    return head;
}

// Time Complexity: O(N1 + N2 + (N1+N2)log(N1+N2)) because we first loop through both lists (N1+N2), then sort the combined array, which
//  is the most time-consuming part.
// Space Complexity: O(N1 + N2) because we create an array and a new linked list that hold all the elements from both original lists.
Node* mergeListsSortAndMerge(Node* list1, Node* list2){
    // Step 1: Create an empty array (vector) named 'arr' because we need a place to store all the numbers from both lists together.
    vector<int>arr;
    // Step 2: Create a temporary pointer 'temp1' for list1 because we need to go through list1 without losing its starting point.
    Node* temp1 = list1;
    // Step 3: Create a temporary pointer 'temp2' for list2 because we need to go through list2 without losing its starting point.
    Node* temp2 = list2;

    // Step 4: Loop through the first list until we reach the end because we need to copy every number from list1.
    while(temp1 != NULL){
        // Step 5: Add the number from the current node of list1 into our array because we are collecting all the values in one place.
        arr.push_back(temp1->data);
        // Step 6: Move 'temp1' to the next node in list1 because we need to process the next number in the list.
        temp1 = temp1->next;
    }

    // Step 7: Loop through the second list until we reach the end because we need to copy every number from list2 as well.
    while(temp2 != NULL){
        // Step 8: Add the number from the current node of list2 into our array because we are still collecting all values.
        arr.push_back(temp2->data);
        // Step 9: Move 'temp2' to the next node in list2 because we need to process the next number in the list.
        temp2 = temp2->next;
    }

    // Step 10: Sort the array from the smallest to the largest number because the goal is to create a single merged and sorted list.
    sort(arr.begin(), arr.end());
    // Step 11: Call the function to turn the sorted array back into a linked list because the final result must be a linked list, not an array.
    Node* head = convertArrToLL(arr);
    // Step 12: Return the head of the new, sorted list because this is the starting point of our final merged list.
    return head;
}

// Time Complexity: O(N1 + N2) because we visit each node from both lists only once.
// Space Complexity: O(1) because we are not creating new nodes for the data; we are just rearranging the pointers of the existing nodes.
Node* mergeListsTwoPointer(Node* list1, Node* list2){
    // Step 1: Create a temporary pointer 'temp1' for list1 because we need to move through list1 without losing the original starting point.
    Node* temp1 = list1;
    // Step 2: Create a temporary pointer 'temp2' for list2 because we need to move through list2 without losing its original starting point.
    Node* temp2 = list2;
    // Step 3: Create a new placeholder node called 'dummyNode' because it gives us a fixed starting point for our new merged list, which
    //  simplifies the code.
    Node* dummyNode = new Node(-1);
    // Step 4: Create a 'temp' pointer and point it to the dummy node because 'temp' will be used to build the new list by connecting nodes to it.
    Node* temp = dummyNode;

    // Step 5: Start a loop that continues as long as there are nodes in both list1 and list2 because we need to compare them.
    while(temp1 != NULL && temp2 != NULL){
        // Step 6: Check if the number in the current node of list1 is smaller than the number in list2 because we want to add the smaller number to
        //  our merged list first.
        if(temp1->data < temp2->data){
            // Step 7: Link the smaller node (temp1) to the end of our new list because it's the next in sorted order.
            temp->next = temp1;
            // Step 8: Move the 'temp' pointer to the node we just added because 'temp' must always point to the last node of the merged list.
            temp = temp1;
            // Step 9: Move 'temp1' to the next node in its list because we have now used the current node.
            temp1 = temp1->next;
        }
        // Step 10: This part runs if list2's number is smaller or equal because we need to handle that case too.
        else{
            // Step 11: Link the smaller node (temp2) to the end of our new list because it's the next in sorted order.
            temp->next = temp2;
            // Step 12: Move the 'temp' pointer to the node we just added because 'temp' must always point to the last node of the merged list.
            temp = temp2;
            // Step 13: Move 'temp2' to the next node in its list because we have now used the current node.
            temp2 = temp2->next;
        }
    }

    // Step 14: Check if list1 still has nodes left because the while loop stops when one list becomes empty, and the other might still have nodes.
    if(temp1 != NULL){
        // Step 15: Attach the entire rest of list1 to the end of our merged list because all its remaining nodes are already sorted and are larger
        //  than what we have so far.
        temp->next = temp1;
    // Step 16: If list1 is empty, check list2 because the remaining nodes must be in list2.
    }else{
        // Step 17: Attach the entire rest of list2 to the end of our merged list because these nodes are sorted and larger than the merged part.
        temp->next = temp2;
    }
    // Step 18: Return the node that comes right after our dummy node because the dummy node was just a placeholder, and the real merged list starts after it.
    return dummyNode->next;
}

int main() {
    Node* list1 = NULL;
    Node* list2 = NULL;

    // Create first sorted linked list: 1 -> 3 -> 5
    insert(list1, 1);
    insert(list1, 3);
    insert(list1, 5);

    // Create second sorted linked list: 2 -> 4 -> 6
    insert(list2, 2);
    insert(list2, 4);
    insert(list2, 6);

    cout << "List 1: ";
    printList(list1);

    cout << "List 2: ";
    printList(list2);

    // Merge using Sort and Merge Approach
    Node* merged1 = mergeListsSortAndMerge(list1, list2);
    cout << "\nMerged List (Sort and Merge): ";
    printList(merged1);

    // Merge using Two Pointer Approach
    Node* merged2 = mergeListsTwoPointer(list1, list2);
    cout << "Merged List (Two Pointer): ";
    printList(merged2);

    return 0;
}


