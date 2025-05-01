#include<iostream>
using namespace std;
#include<vector>

int main(){
  vector<int>arr{1,1,0,1,0,1,0,1};
  int size = arr.size();
  
  int countZero = 0;
  int countOne = 0;
  for(int i=0; i<size; i++){
    if(arr[i] == 0){
      countZero++;
    }
    else{
      countOne++;
    }
  }

  cout<<"The Number of Zero are: "<<countZero<<endl;
  cout<<"The Number of One are: "<<countOne<<endl;

  return 0;

}