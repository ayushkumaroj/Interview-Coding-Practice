#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
#include<unordered_map>

//Brute Force (TC: O(N^2) , SC: O(N))
void BruteForce(vector<int>&arr){
  // Step 1: Create a result vector to store the count for each element.
  vector<int>result;
  // Step 2: Loop through each element in the array.
  for(int i=0; i<arr.size(); i++){
    int count = 0;// To count elements smaller than arr[i]

    // Step 3: Compare arr[i] with every other element in the array.
    for(int j=0; j<arr.size(); j++){
      if(arr[j] < arr[i]){
        count++; // Increment count if arr[j] is smaller.
      }
    }
    // Step 4: After inner loop, push count into the result vector.
    result.push_back(count);
  }

  // Step 5: Print the result vector.
  cout<<"Number of elem smaller then current are: ";
  for(int i=0; i<result.size(); i++){
    cout<<result[i]<<" ";
  }
}


//Using Sort + Hashmap (TC: O(nlogn), SC: O(n))
void usingSortAndHashmap(vector<int>arr){
  // Step 1: Create a copy of the original array.
  // This will be sorted to find the positions of elements.
  vector<int>sorted = arr;

  // Step 2: Sort the copied array in ascending order.
  sort(sorted.begin(), sorted.end());

  // Step 3: Create a hashmap to store the first occurrence index of each element in the sorted array.
  // This index represents the count of elements smaller than the key.
  unordered_map<int,int>count;

  // Step 4: Fill the hashmap.
  for(int i=0; i<sorted.size(); i++){
    int element = sorted[i];
    // If this element is not already in the map, store its index.
    // (Index = number of smaller elements)
    if(count.find(element) == count.end()){
      count[element] = i; // i=number of element smaller then 'element'
    }
  }

  // Step 5: Build the result for the original array using the hashmap.
  vector<int>result;
  for(int i=0; i<arr.size(); i++){
    int element = arr[i];
    result.push_back(count[element]);
  }

  // Step 6: Print the result array.
  for(int i=0; i<result.size(); i++){
    cout<<result[i]<<" ";
  }
}


// Using Question Constraint (TC: O(N), SC: O(N))
void usingConstraint(vector<int>arr){
  // Step 1: Create a count array of size 101 (since 0 <= arr[i] <= 100) and initialize with 0.
  vector<int>count(101, 0);

  // Step 2: Count the frequency of each element in the array.
  for(int i=0; i<arr.size(); i++){
    int elem = arr[i];
    count[elem]++;
  }

  // Step 3: Convert the count array into a prefix sum array.
  // Now, count[i] will store the number of elements <= i.
  for(int i=1; i<=100; i++){
    count[i] = count[i] + count[i-1];
  }

  // Step 4: Build the result array.
  vector<int>result;
  for(int i=0; i<arr.size(); i++){
    int element = arr[i];

    // If element is 0, there are no smaller elements.
    if(element == 0){
      //no elem is less then 0
      result.push_back(0);
    }else{
      // count[element - 1] gives number of elements strictly smaller than current element.
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
