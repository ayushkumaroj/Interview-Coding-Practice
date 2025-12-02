#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node() {
        this->data = 0;
        this->next = NULL;
    }

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

// Insert at head
void insertAtHead(Node*& head, Node*& tail, int data) {
    if (head == NULL) {
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
        return;
    }
    Node* newNode = new Node(data);
    newNode->next = head;
    head = newNode;
}

// Print linked list
void PrintLL(Node*& head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Print linked list
void printLL(Node*& head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}


// MoveNode function (reusable)
void MoveNode(Node*& dest, Node*& source) {
    // Stpe 1: If source list is empty, there is notging to move, so stop.
    if (source == nullptr){
      return;
    } 
    // Step 2: save the first node from the source list , this is the node we will move
    Node* newNode = source;
    //Step 3: Make a source point to the next node in its list. So we remove the first node from the source
    source = source->next;
    //Step 4: Link the moved node in front of the destination list. The moved node next will point to the current first node of destination
    newNode->next = dest;
    //Step 5: Now make the moved node the first node of the destination list
    dest = newNode;
}

// Approach 1: Toggle method
void splitAlternate(Node* head) {
    // Step 1: Create two list and Start both new list as empty
    Node* firstList = NULL;
    Node* secondList = NULL;

    //Step 2: Use a flag (true/false) to remember whose turn it is. true-> means add to firstList, false->means add to secondList
    bool addToFirstList = true;
    
    //Step 3: Keep going until all nodes from head are moved
    while (head != nullptr) {
        // Step 4: If it is firstList turn, move the node to firstList
        if(addToFirstList){
          MoveNode(firstList, head);
        }
        // Step 5: If it's second list turn, move the node to second list
        else{
          MoveNode(secondList, head);
        }              
        //Step 6: Change the turn so next node goes to the other list
        addToFirstList = !addToFirstList; // switch turn
    }

    // Step 7: Print the both list
    cout<<"First List (Alternate): ";
    printLL(firstList);
    cout<<"Second List (Alternate): ";
    printLL(secondList);
}

// Approach 2: Odd-Even hop
void splitOddEven(Node* head) {
    // Step 1: Create two list and Start both new list as empty
    Node* firstList = NULL;
    Node* secondList = NULL;

    //Step 2: Keep going until all nodes from head are moved
    while (head != NULL) {
        // Step 3: Move one Node to first List (odd position)
        MoveNode(firstList, head); // odd node
        // Step 4: If there is another node, move it to second list (even position)
        if (head != nullptr)
            MoveNode(secondList, head); // even node
    }

    //Step 5: Print the both list
    cout<<"First List (Alternate): ";
    printLL(firstList);
    cout<<"Second List (Alternate): ";
    printLL(secondList);
}

int main() {
    Node* head = NULL;
    Node* tail = NULL;

    // Insert some nodes
    insertAtHead(head, tail, 10);
    insertAtHead(head, tail, 20);
    insertAtHead(head, tail, 30);
    insertAtHead(head, tail, 40);
    insertAtHead(head, tail, 50);

    cout << "Original Linked List: ";
    PrintLL(head);

    cout << "\n--- Splitting using Alternate Method ---\n";
    splitAlternate(head);

    // Rebuild list again (since split destroys original)
    head = tail = NULL;
    insertAtHead(head, tail, 10);
    insertAtHead(head, tail, 20);
    insertAtHead(head, tail, 30);
    insertAtHead(head, tail, 40);
    insertAtHead(head, tail, 50);

    cout << "\n--- Splitting using Odd-Even Method ---\n";
    splitOddEven(head);

    return 0;
}