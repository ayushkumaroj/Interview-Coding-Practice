#include<iostream>
using namespace std;
#include<vector>
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

// Time Complexity: O(N*N) because for each node, we might have to look through all the other nodes that come after it.
// Space Complexity: O(N) because we create a new list ('ans') to store the result, and its size will be the same as the original list.
vector<int> nextGreaterNodeBruteForce(Node* head){
    // Step 1: Create an empty list named 'ans' because this is where we will store our final answers.
    vector<int>ans;
    // Step 2: Create a 'curr' pointer to the head because we need to go through the list one node at a time.
    Node* curr = head;

    // Step 3: Loop through the list with the 'curr' pointer until we reach the end because we need to find an answer for every single node.
    while(curr != NULL){
        // Step 4: Create another pointer 'AnotherNode' starting at the node right after 'curr' because we need to search for a bigger number in the rest of the list.
        Node* AnotherNode = curr->next;
        // Step 5: Start a second loop to search for a greater value because we need to check each following node.
        // Step 6: Keep looping as long as we haven't reached the end and the other node's value is smaller or equal to our current node's value.
        while(AnotherNode != NULL && AnotherNode->data <= curr->data){
            // Step 7: Move 'AnotherNode' to the next node because the current one is not the answer we are looking for.
            AnotherNode = AnotherNode->next;
        }
        // Step 8: Check if 'AnotherNode' is not NULL because if it's not, it means our search loop found a node with a bigger value.
        if(AnotherNode != NULL){
            // Step 9: Add the bigger value to our answer list because we found the next greater node.
            ans.push_back(AnotherNode->data);
        }else{
            // Step 10: If 'AnotherNode' is NULL, it means we reached the end without finding a bigger value, so we add 0 to our answer list.
            ans.push_back(0);
        }
        // Step 11: Move 'curr' to the next node because we are done finding the answer for the current node and need to move to the next one.
        curr = curr->next;
    }
    // Step 12: Return the 'ans' list because it now contains all the results.
    return ans;
}

// Time Complexity: O(N) because we go through the list twice in separate loops, not nested loops. Each item is pushed and popped from the stack only once.
// Space Complexity: O(N) because we create a vector and a stack that can store up to N items from the original list.
vector<int>NextGreaterUsingStack(Node* head){
    // Step 1: Create an empty vector named 'values' because it's easier to work with indices and go backwards with a vector than a linked list.
    vector<int>values;

    // Step 2: Create a 'curr' pointer to go through the linked list because we need to copy its data.
    Node* curr = head;
    // Step 3: Loop through the entire linked list because we need to copy every single number into our vector.
    while(curr != NULL){
        // Step 4: Add the number from the node into our 'values' vector.
        values.push_back(curr->data);
        // Step 5: Move 'curr' to the next node to process the rest of the list.
        curr = curr->next;
    }

    // Step 6: Get the total number of items because we need it for our loop and to create the answer vector.
    int n = values.size();
    // Step 7: Create the 'ans' vector and fill it with zeros because this is where we will store our final answers. Starting with 0 handles cases
    //  where no greater number is found.
    vector<int>ans(n, 0);
    // Step 8: Create an empty stack 'st' because it will help us keep track of numbers that could be the "next greater" for other numbers. We will
    //  store indices in it.
    stack<int>st;

    // Step 9: Loop backwards from the last item to the first because this lets us know what numbers are to the right of our current number.
    for(int i=n-1; i>=0; i--){
        // Step 10: Check the indices in the stack because they represent numbers to the right of our current number.
        while(!st.empty()){
            // Step 11: If the number on top of the stack is smaller or equal to our current number, it can't be a 'next greater' number for us or
            //  anything to our left, so we remove it.
            if(values[st.top()] <= values[i]){
                st.pop();
            }else{
                // Step 12: If the number on top of the stack is bigger, we have found our answer, so we can stop looking.
                break;
            }
        }

        // Step 13: After the inner loop, if the stack is not empty, it means we found the index of the next greater number.
        if(!st.empty()){
            // Step 14: Store the greater number in our answer list at the current position.
            ans[i] = values[st.top()];
        }
        // Step 15: Push the index of our current number onto the stack because it might be the 'next greater' number for the items we will see next (to the left).
        st.push(i);
    }
    // Step 16: Return the 'ans' vector because it is now filled with the correct answers.
    return ans;

}

void insertNode(Node*& head, int data) {
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

void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void printVector(const vector<int>& vec) {
    for (int val : vec) {
        cout << val << " ";
    }
    cout << endl;
}

int main() {
    Node* head = NULL;
    int n;

    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        insertNode(head, val);
    }

    cout << "\nOriginal Linked List: ";
    printList(head);

    // Brute Force Result
    vector<int> bruteResult = nextGreaterNodeBruteForce(head);
    cout << "Next Greater Node (Brute Force): ";
    printVector(bruteResult);

    // Optimized Stack Result
    vector<int> stackResult = NextGreaterUsingStack(head);
    cout << "Next Greater Node (Using Stack): ";
    printVector(stackResult);

    return 0;
}