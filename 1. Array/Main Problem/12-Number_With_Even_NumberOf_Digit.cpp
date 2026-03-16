#include<iostream>     
using namespace std;
#include<vector>       
#include<string>      
#include<math.h>      

//Approach 1: Digit Count Approach using Iterative Division
// Time Complexity: O(N * D), where D is the average number of digits per number
// Space Complexity: O(1)

//Digit Count Approch (TC: O(N*D), SC: O(1))
int UsingCount(vector<int>arr){
  // Step 1: This will store the count of numbers with even digits.
  int result = 0;

  // Step 2: Loop through every number in the array.
  for(int i=0; i<arr.size(); i++){
    int nums = arr[i]; // Current number.
    int count = 0; // To store the number of digits for this number.

    // Step 3: Count digits in the number.
    // Reason: We keep dividing the number by 10 until it becomes 0.
    // Each division removes one digit, so count increases.
    while(nums){
      count++; // Increase digit count.
      nums = nums/10; // Remove last digit.
    }

    // Step 4: Check if digit count is even.
    // Reason: If count % 2 == 0, then it has even digits (like 22 → 2 digits).
    if(count % 2 == 0){
      result++;
    }
  }
  // Step 5: Return the total count of numbers with even number of digits.
  return result;
}


//Approach 2: Converting to string, then counting length
// Time Complexity: O(N * D), where D is the number of
// digits (due to to_string)
// Space Complexity: O(D), for string conversion

// Using Converting to string (TC: O(N*Digit), SC: O(Digit))
int ConverToString(vector<int>arr){
  // Step 1: To store how many numbers have even digits.
  int result = 0;

  // Step 2: Loop through each number in the array.
  for(int i=0; i<arr.size(); i++){
    int nums = arr[i]; // Extract current number.
    
    // Step 3: Convert the number to a string.
    // Reason: In string form, counting digits is easy using string length.
    string s = to_string(nums);
    
    // Step 4: Check if the string length (number of digits) is even.
    // Reason: If length % 2 == 0 → number has even digits.
    if(s.length() % 2 == 0){
      // If even, increase the count.
      result++;
    }
  }
  // Step 5: Return the total count of numbers with even digits.
  return result;
}

//Approach 3: Using floor and log of number
// Time Complexity: O(N)
// Space Complexity: O(1)

// Using floor and log of number (TC: O(N), SC: O(1))
int UsingFloor(vector<int>arr){
  // Step 1: To store count of numbers with even digits.
  int result = 0;

  // Step 2: Loop through every number in the array.
  for(int i=0; i<arr.size(); i++){
    int num = arr[i]; // Current number.
    
    // Step 3: Count digits using logarithm base 10.
    // Reason: log10(num) gives the position of the highest digit.
    // Adding 1 gives total digits.
    int count = floor(log(num)) + 1;

    // Step 4: Check if digit count is even.
    // Reason: If count % 2 == 0 → the number has even digits.
    if(count % 2 == 0){
      result++;
    }
  }
  // Step 5: Return the total count of numbers with even digits.
  return result;  // return final count
}

//Approach 4: Using question constraints (only check ranges with even digit counts)
// Time Complexity: O(N)
// Space Complexity: O(1)

// Using question constraints (TC: O(N), SC: O(1))
int UsingQuesConstraint(vector<int>arr){
  // Step 1: To store the count of numbers with even digits.
  int result = 0;

  // Step 2: Loop through every number in the array.
  for(int i=0; i<arr.size(); i++){
    int nums = arr[i]; // Current number.

    // Step 3: Check if number has 2 digits.
    // Reason: Numbers between 10 and 99 have 2 digits (even).
    if(nums >= 10 && nums <= 99){
      result++;
    }

    // Step 4: Check if number has 4 digits.
    // Reason: Numbers between 1000 and 9999 have 4 digits (even).
    else if(nums >= 1000 && nums <= 9999){
      result++;
    }
    // Step 5: Check if number is 100000 (6 digits).
    // Reason: Only 100000 has 6 digits in the given range.
    else if(nums == 100000){
      result++;
    }
  }
  // Step 6: Return the total count.
  return result;  // return final count
}

int main(){
  // input array
  vector<int>arr{12, 345, 2, 6, 7896};

  // calling all four approaches
  int ans1 = UsingCount(arr);
  int ans2 = ConverToString(arr);
  int ans3 = UsingFloor(arr);
  int ans4 = UsingQuesConstraint(arr);

  // displaying result using the last approach
  cout<<"Total number with even number of digit are: "<<ans4<<endl;

  return 0;
}
