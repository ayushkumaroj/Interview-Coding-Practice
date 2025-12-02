#include<iostream>
using namespace std;

class Node{
  public:
  int data;
  Node* prev;
  Node* next;
};

void print(Node* &head){
  Node* temp = head;
  while(temp != NULL){
    cout<<temp->data<<" ";
    temp = temp->next;
  }
}

int getLength(Node* &head){
  Node* temp = head;
  int len = 1;

  while(temp->next != NULL){
   len = len+1;
   temp = temp->next;
  }
  return len;
}