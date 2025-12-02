#include<iostream>
using namespace std;
#include<stack>

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

//Method 1 : Reversing the Linked List
// Time Complexity: O(N + M) because we reverse both lists and then go through them once. (N and M are the lengths of the lists).
// Space Complexity: O(max(N, M)) because we create a new list to store the answer.
Node* AddTwoNumberII(Node* head1, Node* head2) {

    // Step 1: Flip the first number's list around because we need to start adding from the last digit (the ones place), just like on paper.
    head1 = Reverse(head1);
    // Step 2: Flip the second number's list for the same reason, to make addition easier by starting from the end.
    head2 = Reverse(head2);

    // Step 3: Create variables for the sum and the carry-over digit.
    int sum = 0;
    int carry = 0;
    // Step 4: Create a starting node for the answer because we'll build the final number by adding new digits in front of this one.
    Node* ans = new Node();

    // Step 5: Start a loop that runs as long as there are digits left in either list because we need to process all digits from both numbers.
    while (head1 != NULL || head2 != NULL) {
        // Step 6: Check if the first number still has a digit to add.
        if (head1 != NULL) {
            // Step 7: Add the digit to our running sum and move to the next digit.
            sum = sum + head1->data;
            head1 = head1->next;
        }

        // Step 8: Check if the second number still has a digit to add.
        if (head2 != NULL) {
            // Step 9: Add the digit to our running sum and move to the next digit.
            sum = sum + head2->data;
            head2 = head2->next;
        }

        // Step 10: Put the result digit (e.g., the '5' from a sum of 15) into the current answer node.
        ans->data = sum % 10;
        // Step 11: Figure out the carry-over for the next calculation (e.g., the '1' from a sum of 15).
        carry = sum / 10;

        // Step 12: Create a new node and put the carry in it because this node will become the next, more significant digit in our answer.
        Node* newNode = new Node(carry);
        // Step 13: Link this new 'carry' node to the front of our current answer list because this builds the number in the correct order.
        newNode->next = ans;
        // Step 14: Make this new node the new official head of the answer list.
        ans = newNode;
        // Step 15: Set the sum for the next round to be the carry because the carry must be included in the next column's addition.
        sum = carry;
    }

    // Step 16: After the loop, check if the very first node of our answer is an unneeded zero because if there was no final carry, we have an extra '0' at the front.
    if (carry == 0) {
        // Step 17: Return the node *after* the extra zero to give the correct final answer.
        return ans->next;
    } else {
        // Step 18: If there was a final carry, return the answer list as is because the first node is a meaningful digit (like the '1' in '125').
        return ans;
    }
}

//Method 2 : Using Stack
// Time Complexity: O(N + M) because we push every item from both lists to stacks and then pop them all.
// Space Complexity: O(N + M) because the stacks need to store all the digits from both lists.
Node* AddTwoNumberIIUsingStack(Node* head1, Node* head2) {
    // Step 1: Create two stacks because we need to get the digits in reverse order (ones place first) without changing the original lists.
    stack<int> s1;
    stack<int> s2;

    // Step 2: Go through the first number's list and push each digit onto the first stack because the last one in will be the first one out.
    while (head1 != NULL) {
        s1.push(head1->data);
        head1 = head1->next;
    }

    // Step 3: Do the same for the second number, pushing its digits onto the second stack.
    while (head2 != NULL) {
        s2.push(head2->data);
        head2 = head2->next;
    }

    // Step 4: Create a variable for the carry-over digit and a starting node for the answer.
    int carry = 0;
    Node* ans = new Node();

    // Step 5: Start a loop that runs as long as there are digits left in either stack because we need to add up all the digits.
    while (!s1.empty() || !s2.empty()) {
        // Step 6: Start the sum for this round with the carry from the last round.
        int sum = carry;

        // Step 7: Check if the first stack has a digit to add.
        if (!s1.empty()) {
            // Step 8: Add the top digit to the sum and then remove it from the stack because we have now used it.
            sum = sum + s1.top();
            s1.pop();
        }

        // Step 9: Check if the second stack has a digit to add.
        if (!s2.empty()) {
            // Step 10: Add the top digit to the sum and then remove it.
            sum = sum + s2.top();
            s2.pop();
        }

        // Step 11: Put the result digit (e.g., the '5' from a sum of 15) into the current answer node.
        ans->data = sum % 10;
        // Step 12: Figure out the carry-over for the next calculation (e.g., the '1' from a sum of 15).
        carry = sum / 10;

        // Step 13: Create a new node and put the carry in it because this node will become the next, more significant digit in our answer.
        Node* newNode = new Node(carry);
        // Step 14: Link this new 'carry' node to the front of our current answer list because this builds the number in the correct order.
        newNode->next = ans;
        // Step 15: Make this new node the new official head of the answer list.
        ans = newNode;
    }

    // Step 16: After the loop, check if the very first node of our answer is an unneeded zero because if there was no final carry, we have an extra '0' at the front.
    if (carry == 0) {
        // Step 17: Return the node *after* the extra zero to give the correct final answer.
        return ans->next;
    } else {
        // Step 18: If there was a final carry, return the answer list as is because the first node is a meaningful digit.
        return ans;
    }
}


// Insert a node at the end
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

// Print a linked list
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

    cout << "Enter digits of first number (end with -1): ";
    int val;
    while (true) {
        cin >> val;
        if (val == -1) break;
        insert(head1, val);
    }

    cout << "Enter digits of second number (end with -1): ";
    while (true) {
        cin >> val;
        if (val == -1) break;
        insert(head2, val);
    }

    cout << "\nFirst Number: ";
    print(head1);

    cout << "Second Number: ";
    print(head2);

    cout << "\nUsing Reverse Method:" << endl;
    Node* sum1 = AddTwoNumberII(head1, head2);
    cout << "Sum: ";
    print(sum1);

    cout << "\nUsing Stack Method:" << endl;
    Node* sum2 = AddTwoNumberIIUsingStack(head1, head2);
    cout << "Sum: ";
    print(sum2);

    return 0;
}