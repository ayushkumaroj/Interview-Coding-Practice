#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;

//Brute Force (TC: O(N^2), SC: O(N))
void BruteForce(vector<int>& arr) {
    vector<int> result;
    for(int i = 0; i < arr.size(); i++) {
        int count = 0;
        for(int j = 0; j < arr.size(); j++) {
            if(arr[j] < arr[i]) {
                count++;
            }
        }
        result.push_back(count);
    }
    cout << "Number of elements smaller than the current element are: ";
    for(int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;
}
/*
- Sort the input array
- But here is one problem, that position of element changed
- To fix this we will use hasmap that will store key as element and index is my value
- Then traverse the entire input array, and maintain the resultant array
*/

//Using Sort + Hashmap (TC: O(nlogn), SC: O(n))
void UsingSortAndHashmap(vector<int>arr){
   //Create a copy of array
   vector<int>sorted = arr;
   //sort array
   sort(sorted.begin(), sorted.end());
   //store first occurance index of each element
   unordered_map<int,int>count;
   for(int i=0; i<sorted.size(); i++){
    int element = sorted[i];
    if(count.find(element) == count.end()){
        count[element] = i;// i = number of elements 
        // smaller than 'element'
    }
   }
   //Build result using original array
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

//Using Qusetion Constraint (TC: O(N), SC: O(N))
void usingConstraint(vector<int>arr){
    //create count array of size of 101 initialize with 0
    vector<int>count(101,0);
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
    //use prefix sum to find ans
    vector<int>result;
    for(int i=0; i<arr.size(); i++){
        int elem = arr[i];
        if(elem == 0){
            result.push_back(0); //no elem is less then 0
        }
        else{
            result.push_back(count[elem-1]); //elem less then current elem
        }
    }
    //print the result
}


int main() {
    vector<int> arr{8, 1, 2, 2, 3};
    BruteForce(arr);
    UsingSortAndHashmap(arr);
}
