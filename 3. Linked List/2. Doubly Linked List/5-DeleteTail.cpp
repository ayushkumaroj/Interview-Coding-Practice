#include<iostream>
using namespace std;

class Node{
  public:
  int data;
  Node* next;
  Node* prev;

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

void insertAtHead(Node* &head, Node* &tail, int data){
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

void DeleteTail(Node* &head, Node* &tail){
  if(head == NULL){
    cout<<"Noting to delete";
    return;
  }

  Node* temp = tail;
  tail = tail->prev;
  temp->prev = NULL;
  tail->next = NULL;
  delete temp;
  return;
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

  insertAtHead(head, tail , 20);
  insertAtHead(head, tail , 30);
  insertAtHead(head, tail , 40);
  insertAtHead(head, tail , 50);

  DeleteTail(head, tail);
  printLL(head);
}