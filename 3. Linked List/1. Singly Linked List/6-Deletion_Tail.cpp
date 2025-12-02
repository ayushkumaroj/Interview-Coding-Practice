#include<iostream>
using namespace std;

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

  ~Node(){
    cout<<"Deleted value "<<this->data;
  }
};

void insertAtHead(Node* &head, int data){
  if(head == NULL){
    Node* newNode = new Node(data);
    head = newNode;
  }

  Node* newNode = new Node(data);
  newNode->next = head;
  head = newNode;
}

//Cal lenght of ll
int LengthLinkedList(Node* &head){
  int len  = 0;
  Node* temp = head;

  while(temp != NULL){
    len++;
    temp = temp->next;
  }

  return len;
}
void DeleteTail(Node* &head, Node* &tail){
  int i = 1;
  //Find prev node 
  int TotalSize = LengthLinkedList(head);
  Node* prev = head;
  while(i < TotalSize-1){
    prev = prev->next;
    i++;
  }

  prev->next = NULL;
  Node* temp = tail;
  tail = prev;
  delete temp;
  return;
}

void PrintLL(Node* &head){
  Node* temp = head;
  while(temp != NULL){
    cout<<temp->data<<" ";
    temp = temp->next;
  }
}

int main(){
  Node* head = new Node(10);
  Node* tail = head;

  insertAtHead(head, 20);
  insertAtHead(head, 30);
  insertAtHead(head, 40);
  insertAtHead(head, 50);

  PrintLL(head);
  cout<<endl;
  DeleteTail(head, tail);
  cout<<endl;
  PrintLL(head);
}