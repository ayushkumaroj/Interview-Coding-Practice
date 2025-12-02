#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
#include<limits.h>

//Using Merge Approch(Or Two Pointer Merge Method)
// TC = O(M+N) , SC: O(M+N)
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2){
  // Step 1: Get the size of both input arrays
  int m = nums1.size();
  int n = nums2.size();

  // Step 2: Create a new array 'temp' to store all elements from both arrays in sorted order
  vector<int>temp(m+n);

  // Step 3: Create three pointers:
  int i=0; // i -> tracks position in nums1
  int j=0; // j -> tracks position in nums2
  int k=0; // k -> tracks position in temp (merged array)

  // Step 4: Merge elements from nums1 and nums2 into temp in sorted order
  // Keep comparing elements from both arrays and pick the smaller one
  while(i<m && j<n){
    // Step 4a: If nums1[i] is smaller, add it to temp
    if(nums1[i] < nums2[j]){
        temp[k] = nums1[i];
        k++; // move to next position in temp
        i++; // move to next element in nums1
    }
    else{
        // Step 4b: If nums2[j] is smaller or equal, add it to temp
        temp[k] = nums2[j];
        k++; // move to next position in temp
        j++; // move to next element in nums2
      }
  }
  // Step 5: If any elements are left in nums1, copy them into temp
  while(i<m){
      temp[k] = nums1[i];
      k++;
      i++;
  }

  // Step 6: If any elements are left in nums2, copy them into temp
  while(j<n){
      temp[k] = nums2[j];
      k++;
      j++;
  }

  // Step 7: Now temp contains all elements in sorted order
  // Calculate total size of merged array
  int size = m+n;

  // Step 8: If size is odd, median is the middle element
  if(size%2 == 1){ //odd size
      return temp[size/2];
  }
  // Step 9: If size is even, median is the average of the two middle elements
  return (temp[size/2]+temp[(size/2)-1])/2.0;
}

//Using Two-Pointer Merge Without Extra Space
// TC: O(1), SC: O(m+n)
double findMedianSortedArrays2(vector<int>& nums1, vector<int>& nums2) {
  // Step 1: Get the sizes of both arrays
  int m = nums1.size();
  int n = nums2.size();
  // Step 2: Calculate the total size after merging both arrays
  int size = m+n;

  // Step 3: Find the positions of the two middle elements:
  // idx1 -> first middle index (used when size is even)
  // idx2 -> second middle index (or the only middle element when size is odd)
  int idx1 = (size/2)-1;
  int idx2 = (size/2);
  // Step 4: Create two variables to store these middle elements
  int element1 = -1;
  int element2 = -1;
  // Step 5: Initialize pointers for nums1 (i), nums2 (j), and merged position (k)
  int i=0;
  int j=0;
  int k=0;

  // Step 6: Merge both arrays logically WITHOUT storing them
  // Compare current elements of nums1 and nums2, pick the smaller one
  while(i<m && j<n){
      // Step 6a: nums1[i] is smaller, so this goes to merged position 'k'
      if(nums1[i] < nums2[j]){
        if(k == idx1){ // save if this is the second middle
          element1 = nums1[i];
        }
        if(k == idx2){ // save if this is the second middle
          element2 = nums1[i];
        }
        i++; // move to next element in nums1
      }
      else{
        // Step 6b: If nums2[j] is smaller or equal, check for idx1 or idx2
        if(k == idx1){
          element1 = nums2[j];
        }
        if(k == idx2){
            element2 = nums2[j];
        }
        j++; // move to next element in nums2
    }
      k++; // move merged position forward
  }
  // Step 7: If elements are still left in nums1, process them
  while(i<m){
      if(k == idx1){
          element1 = nums1[i];
      }
      if(k == idx2){
          element2 = nums1[i];
      }
      i++;
      k++;
  }
  // Step 8: If elements are still left in nums2, process them
  while(j<n){
      if(k == idx1){
          element1 = nums2[j];
      }
      if(k == idx2){
          element2 = nums2[j];
      }
      j++;
      k++;
  }
  // Step 9: Now we have element1 and element2 (the two middle elements)
  // If total size is odd, median is element2 (middle element)
  if(size%2 == 1){ //odd size
      return element2;
  }
  // Step 10: If size is even, median is the average of element1 and element2
  return (element1 + element2)/2.0;      
}

//Using Binary Search on Smaller Array
//TC: O(log(min(m,n))) , bcz binary search applied on smaller array , SC: O(1)
double findMedianSortedArrays3(vector<int>& nums1, vector<int>& nums2){
  // Step 1: Make sure nums1 is the smaller array for efficiency.
  // Why? Because binary search is applied on the smaller array → fewer iterations.
  if(nums1.size() > nums2.size()){
    return findMedianSortedArrays3(nums2, nums1);
  }

  // Step 2: Get lengths of both arrays
  int m = nums1.size(); // size of smaller array
  int n = nums2.size(); // size of larger array

  // Step 3: Define search range for binary search on nums1
  int start = 0;
  int end = m;

  // Step 4: Start the binary search loop
  while(start <= end){
    // Step 5: Partition nums1
    // Px = number of elements we take from nums1 for the left partition
    int Px = start + (end-start)/2;

    // Step 6: Partition nums2
    // Py = number of elements from nums2 for the left partition
    // Formula ensures left partition has half of total elements
    int Py = (m+n+1)/2 - Px;

    // Step 7: Define variables to store 4 border elements:
    // x1 = largest element on left side of nums1
    // x2 = largest element on left side of nums2
    // x3 = smallest element on right side of nums1
    // x4 = smallest element on right side of nums2
    int x1, x2, x3, x4;

    // Step 8: Compute x1 (last element in left partition of nums1)
    // Why Px - 1? Because Px represents the count of elements on the LEFT side,
    // so the last element on that side is at index Px - 1.
    // If Px == 0 → no element on left → use INT_MIN to represen"negative infinity".
    if(Px == 0){
      x1 = INT_MIN;
    }else{
      x1 = nums1[Px-1];
    }

    // Step 9: Compute x2 (last element in left partition of nums2)
    // Same logic: Py is the count of elements on nums2's LEFT side,
    // so the last element is at index Py - 1.
    // If Py == 0 → no element on left → use INT_MIN.
    if(Py == 0){
      x2 = INT_MIN;
    }else{
      x2 = nums2[Py-1];
    }

    // Step 10: Compute x3 (first element in right partition of nums1)
    // Why Px? Because Px elements are on the left, so right starts at Px.
    // If Px == m → nums1 has no element on the right → use INT_MAX trepresent "infinity".
    if(Px == m){
      x3 = INT_MAX;
    }else{
      x3 = nums1[Px];
    }

    // Step 11: Compute x4 (first element in right partition of nums2)
    // Same logic: Py elements are on left of nums2, so right starts at Py.
    // If Py == n → nums2 has no element on the right → use INT_MAX.
    if(Py == n){
      x4 = INT_MAX;
    }else{
      x4 = nums2[Py];
    }

    // Step 12: Check if partition is correct:
    // A valid partition means all elements in left <= all elements in right:
    // x1 <= x4 AND x2 <= x3
    if(x1 <= x4 && x2 <= x3){
      // Step 13: If total number of elements is even
      // Median = (max of left + min of right) / 2
      if((m+n)%2 == 0){
        return (max(x1,x2) + min(x3,x4))/2.0;
      }
      // Step 14: If total number of elements is odd
      // Median = max of left partition
      else{
        return max(x1,x2); 
      }
    }
    // Step 15: If x1 > x4, it means nums1 has too many elements on left → move left
    else if(x1 > x4){
      end = Px-1;
    }
    // Step 16: Otherwise, nums1 has too few elements on left → move right
    else{
      start = Px+1;
    }
  }
  return -1;
}

int main() {
    // Example input
    vector<int> nums1 = {1, 3};
    vector<int> nums2 = {2};

    // Call the function
    double median = findMedianSortedArrays2(nums1, nums2);

    // Print result
    cout << "Median of the two sorted arrays is: " << median << endl;

    return 0;
}
