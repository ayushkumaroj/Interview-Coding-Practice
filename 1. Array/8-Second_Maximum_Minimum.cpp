#include<iostream>
using namespace std;
#include<limits.h>
#include<vector>



int SecLargest(vector<int> arr) {
  // Initialize the largest and second largest elements as the smallest possible value
  int largest = INT_MIN;
  int secLargest = INT_MIN;

  // Loop through the array to find the largest element
  for (int i = 0; i < arr.size(); i++) {
      // Update largest if a larger element is found
      if (arr[i] > largest) {
          largest = arr[i];
      }
  }

  // Loop through the array again to find the second largest element
  for (int i = 0; i < arr.size(); i++) {
      // Update second largest if a value larger than secLargest is found, but not equal to the largest
      if (arr[i] > secLargest && arr[i] != largest) {
          secLargest = arr[i];
      }
  }

  // Return the second largest element
  return secLargest;
}

int secSmallest(vector<int> arr) {
  // Initialize smallest and second smallest as the largest possible value
  int smallest = INT_MAX;
  int secSmallest = INT_MAX;

  // First loop to find the smallest element
  for (int i = 0; i < arr.size(); i++) {
      if (arr[i] < smallest) {
          smallest = arr[i]; // Update smallest
      }
  }

  // Second loop to find the second smallest element
  for (int i = 0; i < arr.size(); i++) {
      // If the current element is smaller than secSmallest and not equal to smallest
      if (arr[i] < secSmallest && arr[i] != smallest) {
          secSmallest = arr[i]; // Update second smallest
      }
  }

  // Return the second smallest element
  return secSmallest;
}




int main(){
  vector<int>arr{1,2,3,4,5,6};

  int SecondLargest = SecLargest(arr);
  cout<<"The Second Largest Element is: "<<SecondLargest<<endl;

  int SecondSmallest = secSmallest(arr);
  cout<<"The Second Smallest element is: "<<SecondSmallest;
}