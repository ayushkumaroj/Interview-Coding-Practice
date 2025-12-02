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

void InsertAtHead(Node* &head, Node* &tail, int data){
  if(head == NULL){
    Node* newNode = new Node(data);
    head = newNode;
    tail = newNode;
    return;
  }

  Node* newNode = new Node(data);
  newNode->next = head;
  head->prev = newNode;
  head = newNode;
}

void PrintLinkedList(Node* head){
  Node* temp = head;
  while(temp != NULL){
    cout<<temp->data<<" ";
    temp = temp->next;
  }
}


int main(){
  Node* head = new Node(10);
  Node* tail = head;

  InsertAtHead(head, tail, 20);
  InsertAtHead(head, tail, 30);
  InsertAtHead(head, tail, 40);
  InsertAtHead(head, tail, 50);

  PrintLinkedList(head);
}
