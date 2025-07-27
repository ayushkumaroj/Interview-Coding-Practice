#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
#include<unordered_map>

//Brute Force (TC: O(N^2) , SC: O(N))
void BruteForce(vector<int>&arr){
  vector<int>result;
  for(int i=0; i<arr.size(); i++){
    int count = 0;
    for(int j=0; j<arr.size(); j++){
      if(arr[j] < arr[i]){
        count++;
      }
    }
    result.push_back(count);
  }

  cout<<"Number of elem smaller then current are: ";
  for(int i=0; i<result.size(); i++){
    cout<<result[i]<<" ";
  }
}

//Using Sort + Hashmap (TC: O(nlogn), SC: O(n))
void usingSortAndHashmap(vector<int>arr){
  //create a copy of array
  vector<int>sorted = arr;

  //sort array
  sort(sorted.begin(), sorted.end());

  //store first occurance index of each element
  unordered_map<int,int>count;
  for(int i=0; i<sorted.size(); i++){
    int element = sorted[i];
    if(count.find(element) == count.end()){
      count[element] = i; // i=number of element smaller then 'element'
    }
  }

  //Buid result using original array
  vector<int>result;
  for(int i=0; i<arr.size(); i++){
    int element = arr[i];
    result.push_back(count[element]);
  }

  //Print the result
  for(int i=0; i<result.size(); i++){
    cout<<result[i]<<" ";
  }
}

// Using Question Constraint (TC: O(N), SC: O(N))
void usingConstraint(vector<int>arr){
  //create count array of size 101 and initialize with 0
  vector<int>count(101, 0);

  //count freq of each elem in array
  for(int i=0; i<arr.size(); i++){
    int elem = arr[i];
    count[elem]++;
  }

  //Build prefix sum
  //count[i] now become number of elem less then or equal to i
  for(int i=1; i<=100; i++){
    count[i] = count[i] + count[i-1];
  }

  //Use prefix sum to find ans
  vector<int>result;
  for(int i=0; i<arr.size(); i++){
    int element = arr[i];
    if(element == 0){
      //no elem is less then 0
      result.push_back(0);
    }else{
      //elem less then current elem
      result.push_back(count[element-1]);
    }
  }
  //Print the elem
}



int main() {
  vector<int>arr{8,1,2,2,3};

  usingSortAndHashmap(arr);
   

  return 0;
}
