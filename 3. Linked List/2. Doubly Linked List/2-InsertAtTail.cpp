#include<iostream>
using namespace std;

class Node{
  public:
  int data;
  Node* prev;
  Node* next;

  Node(){
    this->data = 0;
    this->next = NULL;
    this->prev = NULL;
  }

  Node(int data){
    this->data = data;
    this->next = NULL;
    this->prev = NULL;
  }
};

void InsertAtTail(Node* &head, Node* &tail, int data){
  if(head == NULL){
    Node* newNode = new Node(data);
    head = newNode;
    tail = newNode;
    return;
  }

  Node* newNode = new Node(data);
  tail->next = newNode;
  newNode->prev = tail;
  tail = newNode;
}

void printLL(Node* &head){
  Node* temp = head;

  while(temp != NULL){
    cout<<temp->data<<" ";
    temp = temp->next;
  }
}

int main(){
  Node* head = new Node(10);
  Node* tail = head;

  InsertAtTail(head, tail, 100);
  InsertAtTail(head, tail, 300);
  InsertAtTail(head, tail, 400);
  InsertAtTail(head, tail, 1984729300);

  printLL(head);

}