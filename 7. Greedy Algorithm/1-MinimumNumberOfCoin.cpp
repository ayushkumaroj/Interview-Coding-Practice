#include<iostream>
using namespace std;
#include<vector>

class Solution{
    private:
    // Step 1: Declare an integer array named 'currency' with a size of 4 because we need a fixed storage space to hold the specific values of coin denominations available to us.
    int currency[4];
    // Step 2: Declare a vector named 'ans' because we need a dynamic list to store the sequence of coins we select, which allows the list to grow as we add more coins.
    // Note: A vector is a dynamic array that can resize itself automatically when an element is inserted or deleted.
    vector<int>ans;

    public:
    // Step 3: Define a constructor for the class because we need to automatically initialize our currency array with specific values whenever an object of this class is created.
    Solution(){
        // Step 4: Set the first element of the array to 10 because this is the largest denomination we have, and in a greedy algorithm, we want to process the largest values first.
        currency[0] = 10;
        // Step 5: Set the second element of the array to 5 because we are manually defining the available notes in descending order to support our optimization strategy.
        currency[1] = 5;
        // Step 6: Set the third element of the array to 2 because this is the next smallest denomination available in our currency system.
        currency[2] = 2;
        // Step 7: Set the last element of the array to 1 because this serves as a fallback to ensure we can represent any integer amount exactly.
        currency[3] = 1;
    }

    // Time Complexity: O(K) where K is the number of coins needed. We iterate through denominations effectively once (O(1) iterations), but the inner loop runs K times to push elements.
    // Space Complexity: O(K) because we store every single coin used in the 'ans' vector.
    int findMinCoin(int n){
        // Step 8: Initialize a variable 'i' to 0 because we need to start checking our currency notes from the very first index of the array, which contains the largest value.
        // Note: Array indexing in C++ is 0-based, meaning the first element is at index 0.
        int i=0;
        // Step 9: Initialize a variable 'notes' to 0 because we need a temporary holder to calculate how many coins of the current denomination fit into the remaining amount.
        int notes = 0;

        // Step 10: Start a loop that continues as long as 'n' is non-zero because we must keep breaking down the total amount until exactly nothing is left.
        // Note: In C++, any non-zero integer evaluates to 'true', so this loop runs until 'n' becomes 0.
        while(n){
            // Step 11: Divide 'n' by the current currency value because this mathematical operation tells us the maximum number of times the current note fits into the remaining amount.
            // Note: Integer division discards the decimal part, giving us only the whole number count (e.g., 23 / 10 = 2).
            notes = n/currency[i];
            // Step 12: Start an inner loop that runs for the count of 'notes' calculated because we need to physically add each individual coin to our answer list one by one.
            while(notes--){
                // Step 13: Add the current currency value to the 'ans' vector because we are recording this specific coin as part of our solution set.
                ans.push_back(currency[i]);
            }
            // Step 14: Update 'n' to the remainder of the division because we have processed the current denomination and only need to solve for the leftover amount.
            // Note: The modulo operator (%) returns the remainder after division (e.g., 23 % 10 = 3).
            n = n%currency[i];
            // Step 15: Increment 'i' by 1 because we need to move to the next largest denomination in our array to attempt to pay off the remaining balance.
            i++;
        }
        // Step 16: Return the size of the vector because the question asks for the total count of coins used, not the coins themselves.
        return ans.size();
    }
};
//    void printNotes(){
//         for(int i=0; i<ans.size(); i++){
//             cout<<ans[i]<<" ";
//         }
//         cout<<endl;
//     // 

int main(){
    int n;
    cout<<"Enter amount for which you want min number of coin: ";
    cin>>n;

    Solution obj;
    int result = obj.findMinCoin(n);

    cout<<"Minimum Notes: "<<result<<endl;
    cout<<"Notes Used: ";
    obj.printNotes();

    return 0;
}
