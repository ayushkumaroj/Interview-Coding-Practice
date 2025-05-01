#include<iostream>     
using namespace std;
#include<vector>       
#include<string>      
#include<math.h>      

//Approach 1: Digit Count Approach using Iterative Division
// Time Complexity: O(N * D), where D is the average number of digits per number
// Space Complexity: O(1)
int UsingCount(vector<int>arr){
  int result = 0;

  for(int i=0; i<arr.size(); i++){
    int nums = arr[i];
    int count = 0;

    // count the number of digits by dividing by 10 iteratively
    while(nums){
      count++;
      nums = nums/10;
    }

    // if digit count is even, increment result
    if(count % 2 == 0){
      result++;
    }
  }

  return result;  // return final count
}

//Approach 2: Converting to string, then counting length
// Time Complexity: O(N * D), where D is the number of digits (due to to_string)
// Space Complexity: O(D), for string conversion
int ConverToString(vector<int>arr){
  int result = 0;
  for(int i=0; i<arr.size(); i++){
    // extract the array element
    int nums = arr[i];

    // convert number to string
    string s = to_string(nums);

    // check if string length is even
    if(s.length() % 2 == 0){
      // if even, increment result
      result++;
    }
  }

  // finally return the result
  return result;
}

//Approach 3: Using floor and log of number
// Time Complexity: O(N)
// Space Complexity: O(1)
int UsingFloor(vector<int>arr){
  int result = 0;
  for(int i=0; i<arr.size(); i++){
    int num = arr[i];

    // count digits using log base 10
    int count = floor(log(num)) + 1;

    // if digit count is even, increment result
    if(count % 2 == 0){
      result++;
    }
  }
  return result;  // return final count
}

//Approach 4: Using question constraints (only check ranges with even digit counts)
// Time Complexity: O(N)
// Space Complexity: O(1)
int UsingQuesConstraint(vector<int>arr){
  // In question it is given: array elements are in range 1 <= nums[i] <= 100000
  int result = 0;
  for(int i=0; i<arr.size(); i++){
    int nums = arr[i];

    // for 2-digit numbers
    if(nums >= 10 && nums <= 99){
      result++;
    }
    // for 4-digit numbers
    else if(nums >= 1000 && nums <= 9999){
      result++;
    }
    // for 6-digit number
    else if(nums == 100000){
      result++;
    }
  }
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
