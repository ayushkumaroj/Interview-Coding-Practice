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

// Time Complexity: O(N * K) where N is the total number of items and K is the number of lists, because we repeatedly merge a growing list with the next one.
// Space Complexity: O(1) because we are only rearranging existing nodes and not using extra space that grows with the input size.
Node* mergeKListsOneByOne(vector<Node*>&arr){
    // Step 1: Get the total number of lists we need to merge because this tells us how many times we need to loop.
    int k = arr.size();
    // Step 2: Check if there are no lists to merge because if the input is empty, the result should also be empty.
    if(k == 0){
        return NULL;
    }

    // Step 3: Set the 'head' to be the very first list in our array because this will be our starting point that we merge all other lists into.
    Node* head = arr[0];
    // Step 4: Start a loop that goes from the second list to the last one because we need to merge each of them into our main 'head' list.
    for(int i=1; i<k; i++){
        // Step 5: Merge the current combined list ('head') with the next list in the array because this combines them into a single, larger sorted list.
        head = merge(head, arr[i]);
    }

    // Step 6: Return the final 'head' because after the loop finishes, it will be one single list containing all the items from all the original lists,
    //  perfectly sorted.
    return head;
}

// Time Complexity: O(N * log K) where N is the total number of items and K is the number of lists, because we split the problem in half (log K) and process
//  all N items at each step.
// Space Complexity: O(log K) because the function calls itself, and the number of calls stacked up is proportional to log K.
Node* mergeSort(vector<Node*>&arr, int start, int end){
    // Step 1: Check if the starting point is past the ending point because this means there are no lists in the current range to process.
    if(start > end){
        return NULL;
    }

    // Step 2: Check if there is only one list in the range because a single list is already considered sorted.
    if(start == end){
        return arr[start];
    }
    // Step 3: Find the middle index of the current range of lists because we need to split the group of lists into two smaller halves.
    int mid = start+(end-start)/2;
    // Step 4: Call this same function for the left half of the lists because we need to keep splitting and merging this half until it becomes one single sorted list.
    Node* left = mergeSort(arr, start, mid);
    // Step 5: Call this same function for the right half of the lists because we also need to sort and merge this half into a single list.
    Node* right = mergeSort(arr, mid+1, end);
    // Step 6: Merge the final sorted list from the left half and the final sorted list from the right half because this combines them into one larger sorted list.
    return merge(left, right);
}

// Time Complexity: O(N * log K) because it uses the efficient mergeSort helper function which follows the divide and conquer strategy.
// Space Complexity: O(log K) because the space is determined by the recursion depth of the mergeSort helper function.
Node* mergeKListsDivideAndConquer(vector<Node*>&arr){
    // Step 1: Get the total number of lists we need to merge because we need to know the full range for the sorting function.
    int k = arr.size();
    // Step 2: Check if the array of lists is empty because if there's nothing to merge, we should return nothing.
    if(k == 0){
        return NULL;
    }
    // Step 3: Call the sorting function on the entire array of lists (from start to end) because this will start the efficient process of splitting and merging them.
    Node* ans = mergeSort(arr, 0, k-1);
    // Step 4: Return the final result because this will be the single, completely sorted list.
    return ans;
}

// Insert node at the end
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

// Print linked list
void print(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    vector<Node*> lists;

    // Example: Creating 3 sorted linked lists
    Node* list1 = NULL;
    insert(list1, 1);
    insert(list1, 4);
    insert(list1, 7);

    Node* list2 = NULL;
    insert(list2, 2);
    insert(list2, 5);
    insert(list2, 8);

    Node* list3 = NULL;
    insert(list3, 3);
    insert(list3, 6);
    insert(list3, 9);

    lists.push_back(list1);
    lists.push_back(list2);
    lists.push_back(list3);

    cout << "Original Lists:" << endl;
    for (int i = 0; i < lists.size(); i++) {
        print(lists[i]);
    }

    Node* mergedList = mergeKListsDivideAndConquer(lists);
    cout << "Merged List:" << endl;
    print(mergedList);

    return 0;
}