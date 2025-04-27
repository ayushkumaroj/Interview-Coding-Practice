#include<iostream>
using namespace std;
#include<vector>

int main(){
  vector<int>arr{1,2,3,4,5,6,7};
  cout<<"Size1 is: "<<arr.size()<<endl;
  for(int i=0; i<arr.size()-1; i++){
    cout<<arr[i]<<" ";
  }
  cout<<endl;

  int size2 = arr.size()-1;
  cout<<"Size 2 is: "<<size2<<endl;
  for(int i=0; i<size2; i++){
    cout<<arr[i]<<" ";
  }
}