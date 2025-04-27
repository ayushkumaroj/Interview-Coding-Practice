// ------------------------------------------------------------------
// 🔍 Problem Title: Find data is Present in the LL or Not
// 📌 Problem Statement:
//     Brief explanation of the problem.
//     Input: 
//     Output: ...
// ------------------------------------------------------------------

#include<iostream>
using namespace std;
#include<vector>

class Node{
  public:
  int data;
  Node* next;

  //constructor
  Node(int data){
    this->data = data;
    this->next = NULL;
  }
};

void insertAthead(Node* &head, int data){
  //create a newNode
  Node* newNode = new Node(data);
  //head ka next ko NULL sai point kro
  newNode->next = head;
  //head ko update kro
  head = newNode;
}

int serchData(Node* &head, int target){
  Node* temp = head;
  while(temp != NULL){
    if(temp->data == target){
      return true;
    }
    temp = temp->next;
  }
  return false;
}

int main() {
  int n, data, target;
  cout<<"Enter the Number of Node: ";
  cin>>n;

  Node* head = NULL;

  cout<<"Enter the Node value: ";
  for(int i=0; i<n; i++){
    cin>>data;
    insertAthead(head, data);
  }

  cout<<"Enter the target to find: ";
  cin>>target;

  int result = serchData(head, target);

  if(result){
    cout<<"Target"<<" "<<target<<" "<<"Found in the LL";
  }
  else{
    cout<<"Target"<<" "<<target<<" "<<"Not found in LL";
  }

  return 0;
}
