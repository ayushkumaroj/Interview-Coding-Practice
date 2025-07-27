#include<iostream>
using namespace std;
#include<math.h>
#include<vector>

// TC: O(N) , SC: O(N)
void Method1(vector<int>arr){
  // Step 1: Calculate the size of the input array (n)
  int n = arr.size();
  // Step 2: Calculate m (original range of values is 1 to m)
  int m = n - 2;

  // Step 3: Create a frequency array of size m+1 (index 0 unused)
  // Why? To keep track of which numbers have appeared
  vector<int>freq(m+1, 0);

  cout<<"Two repeating elem are: ";
  // Step 4: Traverse the input array
  for(int i=0; i<n; i++){
    // Step 6: Get the current value
    int val = arr[i];

    // Step 7: Check if this value was seen before
    if(freq[val] == 1){
      // If yes, this is a repeating element → print it
      cout<<val<<" ";
    }else{
      // Step 8: If not seen before, mark it as seen by setting freq[val] = 1
      freq[val] = 1;
    }

  }
}

// TC: O(N) , SC: O(1)
void Method2(vector<int>&arr){
  // Step 0: Find total size of array (n = m + 2 because two numbers repeat)
  int n = arr.size();
  //Original range of values (1 to m)
  int m = n-2;

  // Step 1: Calculate expected sum of first m natural numbers
  // Formula for sum = m*(m+1)/2
  int S_actual = m*(m+1)/2;
  // Step 1.1: Calculate expected product of first m natural numbers
  // Start with 1 and multiply all numbers from 1 to m
  int P_actual = 1;
  for(int i=1; i<=m; i++){
    P_actual = P_actual * i;
  }

  // Step 2: Calculate sum and product of all elements in the given array
  int S_array = 0;
  int p_array = 1;
  for(int i=0; i<n; i++){
    S_array = S_array + arr[i]; // Add to sum
    p_array = p_array * arr[i]; // Multiply to product
  }

  // Step 3: Let x and y be the two repeating numbers
  // Compute:
  // x + y = (sum of array) - (expected sum)
  // x * y = (product of array) / (expected product)
  int x_plus_y = S_array - S_actual;
  int x_times_y = p_array / P_actual;

  // Step 4: Apply quadratic formula to find x and y
  // Formula: (x - y)^2 = (x + y)^2 - 4 * (x * y)
  int temp = sqrt(x_plus_y * x_plus_y - 4 * x_times_y);

  // Step 5: Find first repeating number x
  // x = (x + y + sqrt(...)) / 2
  int x = (x_plus_y + temp)/2;

  // Step 6: Find second repeating number y
  // y = (x + y) - x
  int y = x_plus_y - x;

  // Step 7: Print the two repeating numbers
  cout<<"The two repeating elem are: "<<x<<" "<<y<<endl;
} 


//TC: O(N), SC: O(1)
void Method3(vector<int>arr){
  int n = arr.size(); // Total size of array (n = m + 2)
  int m = n - 2;     // Original range is 1 to m

  int XOR = 0;     // Will hold XOR of all array elements and numbers from 1 to m
  int x = 0, y=0;  // Two repeating elements we need to find
  int set_bit_no; // Position of the rightmost set bit where x and y differ

  // Step 1: XOR all elements of the array
  // This will help us later to eliminate duplicate values
  for(int i=0; i<n;  i++){
    XOR = XOR ^ arr[i];
  }

  // Step 2: XOR the result with all numbers from 1 to m
  // After this, XOR will contain (x ^ y) because all other elements cancel out
  for(int i=1; i<=m; i++){
    XOR = XOR^i;
  }

  // Step 3: Find the rightmost set bit in XOR (bit where x and y differ)
  // This helps us separate x and y into two different groups
  set_bit_no = XOR & ~(XOR-1);

  // Step 4: Divide the array elements into two sets based on the set_bit_no
  // XOR elements in each group separately
  for(int i=0; i<n; i++){
    if(arr[i] & set_bit_no){
      x = x ^ arr[i]; // Group where set_bit is 1
    }
    else{
      y = y ^ arr[i]; // Group where set_bit is 0
    }
  }

  // Step 5: Divide numbers from 1 to m into two sets and XOR similarly
  for(int i=1; i<=m; i++){
    if(i & set_bit_no){
      x = x^i; // Group where set_bit is 1
    }
    else{
      y = y^i; // Group where set_bit is 0
    }
  }
  cout<<"Two repeating elem are: "<<x <<" "<<y<<endl;
}


int main(){
  vector<int>arr{2,4,3,1,2,5,4};
  Method3(arr);
}