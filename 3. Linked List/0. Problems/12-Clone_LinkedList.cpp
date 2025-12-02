#include<iostream>
using namespace std;
#include<unordered_map>

class Node{
    public:
    int data;
    Node* next;
    Node* random;

    Node(){
        this->data = 0;
        this->next = NULL;
        this->random = NULL;
    }

    Node(int data){
        this->data = data;
        this->next = NULL;
        this->random = NULL;
    }
};

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

// Function to print linked list along with random pointers
void print(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << "Node data: " << temp->data;
        if (temp->random != NULL) {
            cout << ", Random points to: " << temp->random->data;
        } else {
            cout << ", Random points to: NULL";
        }
        cout << endl;
        temp = temp->next;
    }
    cout << endl;
}

// Function: find
// Approach: Two Pointer Traversal
// Time Complexity: O(n) because we might traverse the entire list to find node x , Space Complexity: O(1)
Node* find(Node* curr1, Node* curr2, Node* x){
    // Step 1: Check if x is NULL because if we're looking for NULL, we should return NULL immediately
    if(x == NULL){
        return NULL;
    }

    // Step 2: Keep moving both curr1 and curr2 forward until curr1 reaches node x because we need to find the same position in both lists
    while(curr1 != x){
        curr1 = curr1->next;
        curr2 = curr2->next;
    }

    // Step 3: Return curr2 because when curr1 found x, curr2 is at the matching position in the second list
    return curr2;
}

// Approach: Find Method (Linear Search for Random Pointers)
// Time Complexity: O(n²) because for each node we search through the list to find random pointer
// Space Complexity: O(1) because we don't use extra data structures, only pointer variables
Node* cloneUsingFind(Node* head){
    // Step 1: Create a dummy node with value 0 because we need a starting point to build our new list
    Node* headCopy = new Node(0);
    
    // Step 2: Set tailCopy to point to headCopy because we need to track the end of our new list as we build it
    Node* tailCopy = headCopy;
    
    // Step 3: Set temp to head because we need to walk through the original list without losing the head pointer
    Node* temp = head;

    // Step 4: Clone all nodes without random pointers first because we need the structure before we can set random connections
    while(temp != NULL){
        // Step 5: Create new node and attach it to the end because we're building the clone list step by step
        tailCopy->next = new Node(temp->data);
        
        // Step 6: Move tailCopy to the new node because this new node is now the end of our list
        tailCopy = tailCopy->next;
        
        // Step 7: Move temp to next original node because we need to process all nodes in the original list
        temp = temp->next;
    };

    // Step 8: Save the dummy node in tailCopy because we need to delete it after removing it from the list
    tailCopy = headCopy;
    
    // Step 9: Move headCopy to the real first node because we don't want the dummy node in our final result
    headCopy = headCopy->next;
    
    // Step 10: Delete the dummy node because we don't need it anymore and want to free memory
    delete tailCopy;

    // Step 11: Reset temp to head because we need to traverse the original list again for random pointers
    temp = head;
    
    // Step 12: Reset tailCopy to headCopy because we need to traverse the clone list along with the original
    tailCopy = headCopy;

    // Step 13: Set random pointers for each cloned node because the clone needs the same random connections as original
    while(temp != NULL){
        // Step 14: Use find function to get the matching random node in clone list because we need to map original random to clone random
        tailCopy->random = find(head, headCopy, temp->random);
        
        // Step 15: Move temp to next original node because we need to process random pointers for all nodes
        temp = temp->next;
        
        // Step 16: Move tailCopy to next clone node because we need to set random pointer for each clone node
        tailCopy = tailCopy->next;
    }

    // Step 17: Return headCopy because this is the head of our completed cloned list
    return headCopy;
}


// Approach: Hash Map Method (Store Original to Clone Mapping)
// Time Complexity: O(n) because we traverse the list a few times but each lookup/insert in map is O(1)
// Space Complexity: O(n) because we store mapping for every node in the hash map
Node* cloneUsingMap(Node* head){
    // Step 1: Create a dummy node with value 0 because we need a starting point to build our new list
    Node* headCopy = new Node(0);
    
    // Step 2: Set tailCopy to point to headCopy because we need to track the end of our new list as we build it
    Node* tailCopy = headCopy;
    
    // Step 3: Set temp to head because we need to walk through the original list without losing the head pointer
    Node* temp = head;

    // Step 4: Clone all nodes without random pointers first because we need the structure before we can set random connections
    while(temp != NULL){
        // Step 5: Create new node and attach it to the end because we're building the clone list step by step
        tailCopy->next = new Node(temp->data);
        
        // Step 6: Move tailCopy to the new node because this new node is now the end of our list
        tailCopy = tailCopy->next;
        
        // Step 7: Move temp to next original node because we need to process all nodes in the original list
        temp = temp->next;
    };

    // Step 8: Save the dummy node in tailCopy because we need to delete it after removing it from the list
    tailCopy = headCopy;
    
    // Step 9: Move headCopy to the real first node because we don't want the dummy node in our final result
    headCopy = headCopy->next;
    
    // Step 10: Delete the dummy node because we don't need it anymore and want to free memory
    delete tailCopy;

    // Step 11: Reset temp to head because we need to traverse the original list again to fill the map
    temp = head;
    
    // Step 12: Reset tailCopy to headCopy because we need to traverse the clone list to fill the map
    tailCopy = headCopy;
    // Step 13: Create hash map to store original node to clone node mapping because we need fast lookup for random pointers
    unordered_map<Node*, Node*>m;
    
    // Step 14: Fill the map with original to clone node pairs because we need to know which clone node matches each original node
    while(temp != NULL){
        // Step 15: Map original node to its clone node because this gives us instant lookup later
        m[temp] = tailCopy;
        // Step 16: Move tailCopy to next clone node because we need to map all nodes
        tailCopy = tailCopy->next;
        // Step 17: Move temp to next original node because we need to map all nodes
        temp = temp->next;
    }

    // Step 18: Reset temp to head because we need to traverse original list again for setting random pointers
    temp = head;
    // Step 19: Reset tailCopy to headCopy because we need to traverse clone list to set random pointers
    tailCopy = headCopy;

    // Step 20: Set random pointers using the map because now we can quickly find the clone node for any original node
    while(temp != NULL){
        // Step 21: Set clone node's random to the mapped clone of original's random because this recreates the same random structure
        tailCopy->random = m[temp->random];
        
        // Step 22: Move tailCopy to next clone node because we need to set random for all clone nodes
        tailCopy = tailCopy->next;
        
        // Step 23: Move temp to next original node because we need to process all original nodes
        temp = temp->next;
    }
    // Step 24: Return headCopy because this is the head of our completed cloned list
    return headCopy;
}


// Approach: Interweaving Method (Merge Original and Clone, Then Separate)
// Time Complexity: O(n) because we traverse the list a few times but each pass is linear
// Space Complexity: O(1) because we don't use extra data structures, only rearrange pointers
Node* cloneUsingMerge(Node* head){
    // Step 1: Check if head is NULL because if original list is empty, clone should also be empty
    if(head == NULL){
        return NULL;
    }
    
    // Step 2: Create a dummy node with value 0 because we need a starting point to build our new list
    Node* headCopy = new Node(0);
    // Step 3: Set tailCopy to point to headCopy because we need to track the end of our new list as we build it
    Node* tailCopy = headCopy;
    // Step 4: Set temp to head because we need to walk through the original list without losing the head pointer
    Node* temp = head;

    // Step 5: Clone all nodes without random pointers first because we need the structure before we can merge lists
    while(temp != NULL){
        // Step 6: Create new node and attach it to the end because we're building the clone list step by step
        tailCopy->next = new Node(temp->data);
        
        // Step 7: Move tailCopy to the new node because this new node is now the end of our list
        tailCopy = tailCopy->next;
        
        // Step 8: Move temp to next original node because we need to process all nodes in the original list
        temp = temp->next;
    };

    // Step 9: Save the dummy node in tailCopy because we need to delete it after removing it from the list
    tailCopy = headCopy;
    // Step 10: Move headCopy to the real first node because we don't want the dummy node in our final result
    headCopy = headCopy->next;
    // Step 11: Delete the dummy node because we don't need it anymore and want to free memory
    delete tailCopy;
    // Step 12: Reset temp to head because we need to traverse the original list again for merging
    temp = head;
    
    // Step 13: Reset tailCopy to headCopy because we need to traverse the clone list for merging
    tailCopy = headCopy;

    // Step 14: Set up pointers for merging the two lists because we need to interweave original and clone nodes
    Node* curr1 = head;
    Node* curr2 = headCopy;
    Node* future1 = NULL;
    Node* future2 = NULL;
    
    // Step 15: Merge original and clone lists by interweaving because this puts each clone node right after its original
    while(curr1 != NULL){
        // Step 16: Save the next original node because we're about to change curr1's next pointer
        future1 = curr1->next;
        
        // Step 17: Save the next clone node because we're about to change curr2's next pointer
        future2 = curr2->next;
        
        // Step 18: Point original node to its clone because we want original->clone->next_original pattern
        curr1->next = curr2;
        
        // Step 19: Point clone node to next original because this completes the interweaving pattern
        curr2->next = future1;
        
        // Step 20: Move curr1 to next original node because we need to process all original nodes
        curr1 = future1;
        
        // Step 21: Move curr2 to next clone node because we need to process all clone nodes
        curr2 = future2;
    }

    // Step 22: Set curr1 to head to start setting random pointers because now we can use the interweaved structure
    curr1 = head;
    
    // Step 23: Set random pointers for clone nodes using interweaved structure because each clone is right after its original
    while(curr1 != NULL){
        // Step 24: Get the clone node which is right after original because of our interweaving
        curr2 = curr1->next;
        
        // Step 25: Check if original has random pointer because we only set clone's random if original has one
        if(curr1->random != NULL){
            // Step 26: Set clone's random to original's random's next because the clone of random node is right after the random node
            curr2->random = curr1->random->next;
        }
        
        // Step 27: Move curr1 to next original node because we skip the clone node to get to next original
        curr1 = curr2->next;
    }

    // Step 28: Set curr1 to head to start separating the lists because we need to restore original structure and extract clone
    curr1 = head;
    // Step 29: Separate the interweaved lists back to original and clone because we don't want them connected anymore
    while(curr1->next != NULL){
        // Step 30: Save the next node (which could be clone or original) because we're about to change connections
        future1 = curr1->next;
        
        // Step 31: Skip one node to reconnect properly because we want to remove the interweaving
        curr1->next = future1->next;
        
        // Step 32: Move curr1 to the node we just connected to because we need to process all connections
        curr1 = future1;
    }
    
    // Step 33: Return headCopy because this is the head of our completed separated clone list
    return headCopy;
}

int main() {
    Node* head = NULL;

    // Insert nodes
    insert(head, 1);
    insert(head, 2);
    insert(head, 3);
    insert(head, 4);

    // Assign random pointers manually
    head->random = head->next->next;        // 1 -> 3
    head->next->random = head;              // 2 -> 1
    head->next->next->random = head->next;  // 3 -> 2
    head->next->next->next->random = NULL;  // 4 -> NULL

    cout << "Original Linked List:" << endl;
    print(head);

    // Clone using Find method
    Node* cloneFind = cloneUsingFind(head);
    cout << "Cloned Linked List (Using Find):" << endl;
    print(cloneFind);

    // Clone using Map method
    Node* cloneMap = cloneUsingMap(head);
    cout << "Cloned Linked List (Using Map):" << endl;
    print(cloneMap);

    // Clone using Merge method
    Node* cloneMerge = cloneUsingMerge(head);
    cout << "Cloned Linked List (Using Merge):" << endl;
    print(cloneMerge);

    return 0;
}