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

// Time Complexity: O(N) because we travel through the list twice in separate loops, once to find unique values and once to rewrite the list.
// Space Complexity: O(U) where U is the number of unique nodes, because we store all the unique values in an extra vector.
Node* removeDuplicatesWithExtraSpace(Node* head){
    // Step 1: Check if the list has 0 or 1 nodes because if so, there can't be any duplicates to remove.
    if(head == NULL || head->next == NULL){
        return head;
    }

    // Step 2: Create a vector 'ans' because we will use it to store only the unique numbers from the list.
    vector<int>ans;
    // Step 3: Add the first node's number to our vector because the first item is always unique to start with.
    ans.push_back(head->data);

    // Step 4: Create a 'curr' pointer starting from the second node because we need to check the rest of the list for duplicates.
    Node* curr = head->next;
    // Step 5: Loop through the rest of the list until we reach the end.
    while(curr != NULL){
        // Step 6: Since the list is sorted, we only need to check if the current number is different from the last unique number we saved.
        if(ans[ans.size()-1] != curr->data){
            // Step 7: If the number is different, add it to our vector because it's a new unique number.
            ans.push_back(curr->data);
        }
        // Step 8: Move to the next node because we need to check every node in the list.
        curr = curr->next;
    }

    // Step 9: Reset 'curr' to the head and create an index because we are now going to modify the original list using the unique numbers from our vector.
    curr = head;
    size_t index = 0;
    Node* prev = NULL;
    // Step 10: Loop as long as there are unique numbers in our vector to process.
    while(index < ans.size()){
        // Step 11: Update the node's data with the unique value from the vector at the current index.
        curr->data = ans[index];
        // Step 12: Move to the next unique number and the next node. Keep track of 'prev' because we need to know where the new list ends.
        index++;
        prev = curr;
        curr = curr->next;
    }
    // Step 13: Set the 'next' of the new last node to NULL because this cuts off any leftover duplicate nodes at the end of the original list.
    prev->next = NULL;
    // Step 14: Return the head of the modified list.
    return head;
}

// Time Complexity: O(N) because we travel through the list only one time to find and remove duplicates.
// Space Complexity: O(1) because we are modifying the list directly and only use a couple of extra pointers.
Node* removeDuplicatesInPlace(Node* head){
    // Step 1: Check if the list has 0 or 1 nodes because there can't be any duplicates in that case.
    if(head == NULL || head->next == NULL){
        return head;
    }

    // Step 2: Create a 'curr' pointer starting at the second node because this is the first node we will check for being a duplicate.
    Node* curr = head->next;
    // Step 3: Create a 'prev' pointer starting at the first node because it will point to the last known unique node.
    Node* prev = head;

    // Step 4: Loop through the list with the 'curr' pointer until it reaches the end.
    while(curr != NULL){
        // Step 5: Check if the current node's number is the same as the previous unique node's number.
        if(curr->data == prev->data){
            // Step 6: If it is a duplicate, skip the 'curr' node by pointing 'prev->next' to the node after 'curr'.
            prev->next = curr->next;
            // Step 7: Delete the duplicate 'curr' node to free up its memory
            delete curr;
            // Step 8: Update 'curr' to be the node after the one we just deleted because we need to continue checking from there.
            curr = prev->next;
        }else{
            // Step 9: If it's not a duplicate, move both 'prev' and 'curr' one step forward because 'curr' is now the last known unique node.
            prev = prev->next;
            curr = curr->next;
        }
    }
    // Step 10: Return the head of the list because we have now removed all duplicates.
    return head;
}

// Function to insert a node at the end
Node* insert(Node* head, int value) {
    Node* newNode = new Node(value);
    if (head == nullptr) {
        return newNode;
    }

    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

// Function to print the linked list
void print(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Main function
int main() {
    Node* head = nullptr;

    // Inserting nodes
    head = insert(head, 1);
    head = insert(head, 2);
    head = insert(head, 2);
    head = insert(head, 3);
    head = insert(head, 3);
    head = insert(head, 4);

    cout << "Original list: ";
    print(head);

    // Remove duplicates using extra space
    head = removeDuplicatesWithExtraSpace(head);
    cout << "After removeDuplicatesWithExtraSpace: ";
    print(head);

    // Insert duplicates again for testing in-place removal
    head = insert(head, 4);
    head = insert(head, 5);
    head = insert(head, 5);
    cout << "List before removeDuplicatesInPlace: ";
    print(head);

    head = removeDuplicatesInPlace(head);
    cout << "After removeDuplicatesInPlace: ";
    print(head);

    return 0;
}