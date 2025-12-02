#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

class Node{
    public:
    int data;
    Node* next;
    Node* bottom;

    Node(int data){
        this->data = data;
        this->next = NULL;
        this->bottom = NULL;
    }

};


// Time Complexity: O(N) because we go through each item in the array one time to create a new node.
// Space Complexity: O(N) because we create a new node in the computer's memory for each item in the array.
Node* convertArrtoLL(vector<int> arr){
    int n = arr.size();
    if(n == 0){
        return NULL;
    }
    
    Node* head = new Node(arr[0]);
    Node* temp = head;
    for(int i = 1; i < n; i++){
        Node* newNode = new Node(arr[i]);
        temp->bottom = newNode;
        temp = temp->bottom;
    }
    return head;
}

// Time Complexity: O(N * log(N)) because collecting N items is fast, but sorting them is the most time-consuming step.
// Space Complexity: O(N) because we create an array and then a new list, both of which store all N nodes from the original structure.
Node* flattenUsingArray(Node* root){
    // Step 1: Create an empty array called 'arr' because we need a simple place to store all the numbers from the complex list structure.
    vector<int>arr;
    // Step 2: Create a temporary pointer 'temp' that starts at the root because we will use it to move sideways (right) across the main list.
    Node* temp = root;
    
    // Step 3: Loop as long as 'temp' is not at the end of the main horizontal list because we need to visit each vertical list.
    while(temp != NULL){
        // Step 4: Create a second pointer 'temp2' starting at the current main node because we will use this to move down the vertical list.
        Node* temp2 = temp;
        // Step 5: Loop as long as 'temp2' is not at the end of the vertical list because we need to collect all numbers in it.
        while(temp2 != NULL){
            // Step 6: Add the number from the current node to our array because we are gathering all numbers in one place.
            arr.push_back(temp2->data);
            // Step 7: Move the 'temp2' pointer down to the next node in the vertical list because we need to get the next number.
            temp2 = temp2->bottom;
        }
        // Step 8: Move the main pointer 'temp' to the next node on the right because we have finished with the current vertical list and need
        // to move to the next one.
        temp = temp->next;
    }

    // Step 9: Sort the array from smallest to largest because the goal is to create a single, completely sorted list.
    sort(arr.begin(), arr.end());
    // Step 10: Use the helper function to build a new, simple downward list from our sorted array because the final output must be a linked list.
    Node* head = convertArrtoLL(arr);
    // Step 11: Return the head of this new list because it's the starting point of our final, flattened, and sorted result.
    return head;
}


Node* merge(Node* list1, Node* list2){
    Node* dummyNode = new Node(-1);
    Node* temp = dummyNode;

    while(list1 != NULL && list2 != NULL){
        if(list1->data < list2->data){
            temp->bottom = list1;
            temp = list1;
            list1 = list1->bottom;
        }
        else{
            temp->bottom = list2;
            temp = list2;
            list2 = list2->bottom;
        }
        temp->next = NULL;
    }
    
    if(list1 != NULL){
        temp->bottom = list1;
    }
    else{
        temp->bottom = list2;
    }

    if(dummyNode->bottom != NULL){
        dummyNode->bottom->next = NULL;
    }

    return dummyNode->bottom;
}

// Time Complexity: O(Total Nodes) because this approach merges lists in a way similar to merge sort, visiting each node a constant number of times.
// Space Complexity: O(Number of horizontal lists) because of the memory used by the computer to handle the recursive calls.
Node* flattenUsingMerge(Node* root){
    // Step 1: Check if the list is empty or has only one vertical list because if so, it's already flattened and we can return it. This is our base case.
    if(root == NULL || root->next == NULL){
        return root;
    }
    
    // Step 2: Call the same function for the rest of the list (to the right) because we need to flatten that part first, working from the end backwards.
    Node* mergeHead = flattenUsingMerge(root->next);
    // Step 3: Merge the current vertical list ('root') with the already flattened list from the right ('mergeHead') because this combines them into one sorted list.
    root = merge(root, mergeHead);
    // Step 4: Return the newly merged list because it is the flattened result up to this point.
    return root;
}

void insert(Node*& root, vector<int> arr){
    Node* newVerticalList = convertArrtoLL(arr);
    if(root == NULL){
        root = newVerticalList;
        return;
    }

    Node* temp = root;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newVerticalList;
}



void printList(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout << temp->data << " -> ";
        temp = temp->bottom;
    }
    cout << "NULL" << endl;
}

int main(){
    Node* root = NULL;

    // Example vertical lists
    insert(root, {5, 7, 8, 30});
    insert(root, {10, 20});
    insert(root, {19, 22, 50});
    insert(root, {28, 35, 40, 45});

    cout << "Original Structure (Vertical Lists):\n";
    Node* temp = root;
    while(temp != NULL){
        printList(temp);
        temp = temp->next;
    }

    // Flatten using array
    Node* flatArray = flattenUsingArray(root);
    cout << "\nFlattened List (Using Array):\n";
    printList(flatArray);

    // Flatten using merge
    Node* flatMerge = flattenUsingMerge(root);
    cout << "\nFlattened List (Using Merge):\n";
    printList(flatMerge);

    return 0;
}