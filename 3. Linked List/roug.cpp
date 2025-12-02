#include<iostream>
using namespace std;
#include<stack>
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

Node* getMid(Node* head){
    Node* slow = head;
    Node* fast = head->next;

    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next;
    }

    return slow;
}

void moveNode(Node* source, Node* dest){
    if(source == NULL){
        return;
    }

    Node* newNode = source;
    source = source->next;
    newNode->next = dest;
    dest = newNode;

}

void AlternatreSplit(Node* head){
    Node* firstList = NULL;
    Node* secondList = NULL;

    bool addToList = true;

    while(head != NULL){
        if(addToList){
            moveNode(head, firstList);
        }else{
            moveNode(head, secondList);
        }

        addToList = !addToList;
    }
}