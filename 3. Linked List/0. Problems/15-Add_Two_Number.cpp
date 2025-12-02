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

Node* Reverse(Node* head){
    Node* prev = NULL;
    Node* curr = head;
    Node* future = NULL;

    while(curr != NULL){
        future = curr->next;
        curr->next = prev;
        prev = curr;
        curr = future;
    }

    return prev;
}

// Time Complexity: O(N + M) because we have to go through both lists to add them. (N and M are the lengths of the lists).
// Space Complexity: O(max(N, M)) because we create a new list to store the answer, which will be about the size of the longer input list.
Node* AddTwoNumbers(Node* head1, Node* head2) {
    // Step 1: Flip the first number's list around because we need to start adding from the last digit (the ones place), just like we do on paper.
    head1 = Reverse(head1);
    // Step 2: Flip the second number's list for the same reason, to make addition easier by starting from the end.
    head2 = Reverse(head2);

    // Step 3: Create pointers to move through the lists because we don't want to change the original head pointers yet.
    Node* curr1 = head1;
    Node* curr2 = head2;
    // Step 4: Create a temporary starting node for our answer list because it makes adding the first real digit much simpler.
    Node* dummyHead = new Node(0);
    // Step 5: Create a pointer to build the answer list because we will add new digit nodes after this one.
    Node* curr3 = dummyHead;

    // Step 6: Create a variable 'sum' to hold the total of two digits and the carry because we need a place to do our temporary math.
    int sum = 0;
    // Step 7: Create a variable 'carry' and set it to 0 because we need to track the number that gets carried over to the next column in addition.
    int carry = 0;

    // Step 8: Start a loop that runs as long as both lists still have digits because we are adding the parts of the numbers that overlap.
    while (curr1 && curr2) {
        // Step 9: Add the digits from both numbers and any leftover carry because this is the basic math for one column of addition.
        sum = curr1->data + curr2->data + carry;
        // Step 10: Create a new node with just the last digit of the sum (e.g., for 15, we use 5) because this is the digit that belongs in the current result column.
        curr3->next = new Node(sum % 10);
        // Step 11: Move to the next digit in each of the input numbers because we are done with the current ones.
        curr1 = curr1->next;
        curr2 = curr2->next;
        // Step 12: Move the answer list's pointer forward because we need to be ready to attach the next digit.
        curr3 = curr3->next;
        // Step 13: Calculate the new carry for the next column (e.g., for 15, the carry is 1) because this value needs to be added to the next set of digits.
        carry = sum / 10;
    }

    // Step 14: Start a loop to handle any leftover digits in the first number because the first number might be longer than the second.
    while (curr1 != NULL) {
        // Step 15: Add the leftover digit and the carry because we need to finish the addition for the rest of this longer number.
        sum = curr1->data + carry;
        // Step 16: Create a new node with the last digit of the sum and add it to our answer list.
        curr3->next = new Node(sum % 10);
        // Step 17: Move to the next digits in the first list and the answer list.
        curr1 = curr1->next;
        curr3 = curr3->next;
        // Step 18: Calculate the new carry.
        carry = sum / 10;
    }

    // Step 19: Start another loop for leftover digits in the second number because the second number could also have been the longer one.
    while (curr2 != NULL) {
        // Step 20: Add the leftover digit and the carry.
        sum = curr2->data + carry;
        // Step 21: Create a new node with the last digit of the sum and add it to our answer list.
        curr3->next = new Node(sum % 10);
        // Step 22: Move to the next digits in the second list and the answer list.
        curr2 = curr2->next;
        curr3 = curr3->next;
        // Step 23: Calculate the new carry.
        carry = sum / 10;
    }

    // Step 24: Start a loop that runs if there is a final carry at the end (like when 99 + 1 = 100) because we need to add a new digit for this carry.
    while (carry != 0) {
        // Step 25: Create a new node with the carry amount.
        curr3->next = new Node(carry % 10);
        // Step 26: Move the answer list pointer forward.
        curr3 = curr3->next;
        // Step 27: Update the carry in case it's a number larger than 9.
        carry = carry / 10;
    }

    // Step 28: Flip the answer list back to the correct order because we built it backwards (from ones place to the highest place). We use '->next' 
    // to skip the temporary starting node.
    dummyHead = Reverse(dummyHead->next);

    // Step 29: Check for any leading zeros in the final answer because a result like '052' should just be '52'.
    while (dummyHead->data == 0 && dummyHead->next != NULL) {
        // Step 30: Remove the leading zero by moving the head to the next node because it is not needed.
        dummyHead = dummyHead->next;
    }

    // Step 31: Return the final, correct head of the answer list because this is the result of the addition.
    return dummyHead;
}

// Function to insert a node at the end
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

// Function to print the linked list
void print(Node* head) {
    while (head != NULL) {
        cout << head->data;
        if (head->next != NULL) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

// Main function
int main() {
    Node* head1 = NULL;
    Node* head2 = NULL;

    // First number: 0 -> 0 -> 3 -> 1 -> 1 -> 2
    cout << "Enter digits of first number (end with -1): ";
    int val;
    while (true) {
        cin >> val;
        if (val == -1) break;
        insert(head1, val);
    }

    // Second number: 0 -> 0 -> 0 -> 2 -> 3 -> 7 -> 1
    cout << "Enter digits of second number (end with -1): ";
    while (true) {
        cin >> val;
        if (val == -1) break;
        insert(head2, val);
    }

    cout << "First Number: ";
    print(head1);

    cout << "Second Number: ";
    print(head2);

    Node* result = AddTwoNumbers(head1, head2);

    cout << "Sum: ";
    print(result);

    return 0;
}
