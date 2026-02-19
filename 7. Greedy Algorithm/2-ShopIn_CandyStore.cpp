#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class CandyShop{
    private:
    // Step 1: Declare a vector 'prices' because we need a container to store the cost of each individual candy available in the shop.
    vector<int>prices;
    // Step 2: Declare an integer 'k' because we need to store the specific offer number, representing how many candies we get for free when we buy one.
    int k;

    public:
    // Step 3: Define a constructor that accepts a list of prices and the offer value because we need to initialize our shop object with the specific data for this problem instance.
    CandyShop(vector<int>p, int offerK){
        // Step 4: Assign the passed vector 'p' to our class member 'prices' because we need to save this data permanently inside the object to use it in our calculations later.
        prices = p;
        // Step 5: Assign the passed integer 'offerK' to our class member 'k' because this rule defines the logic for how many items we can skip paying for.
        k = offerK;
    }

    // Time Complexity: O(N log N) because sorting the array takes N log N time, which dominates the linear O(N) loops used for calculation.
    // Space Complexity: O(1) auxiliary space because we are only using a few variables for pointers and sums, not creating any new data structures proportional to input size.
    vector<int>minMaxCandy(){
        // Step 6: Get the total number of candies 'n' because we need the size of the list to manage our loop boundaries and pointers correctly.
        int n = prices.size();
        // Step 7: Sort the prices vector in ascending order because our greedy strategy depends on accessing the cheapest and most expensive candies easily at the ends of the array.
        // Note: Sorting arranges elements from smallest to largest (e.g., [1, 2, 3, 4]), allowing us to pick minimal costs from the start and maximal costs from the end.
        sort(prices.begin(), prices.end());

        // Step 8: Initialize 'min_amount' to 0 because we need a variable to accumulate the minimum possible cost, starting from zero before any purchases.
        int min_amount = 0;
        // Step 9: Initialize 'max_amount' to 0 because we need a separate variable to accumulate the maximum possible cost.
        int max_amount = 0;

        // Step 10: Initialize 'start' to 0 because for the minimum cost, we want to start buying the cheapest candies located at the beginning of the sorted array.
        int start = 0;
        // Step 11: Initialize 'end' to n-1 because this pointer represents the most expensive candies at the back of the array, which we will try to get for free.
        int end = n-1;

        // Step 12: Start a loop that runs while the start pointer is less than or equal to the end pointer because we must continue until all candies are either bought or taken for free.
        while(start <= end){
            // Step 13: Add the price of the candy at 'start' to 'min_amount' because to minimize cost, we must pay for the cheapest available candy.
            min_amount = min_amount+prices[start];
            // Step 14: Increment the start pointer because we have successfully purchased this candy and need to move to the next cheapest one.
            start++;
            // Step 15: Move the end pointer back by 'k' positions because the offer allows us to take 'k' candies for free, so we pick the most expensive ones (at the end) to avoid paying for them.
            end = end-k;
        }

        // Step 16: Reset 'start' to n-1 because for calculating the maximum cost, we need to start buying from the most expensive candies at the end of the array.
        start = n-1;
        // Step 17: Reset 'end' to 0 because this pointer will now represent the cheapest candies at the beginning, which we will treat as the "free" items to maximize our spending.
        end = 0;

        // Step 18: Start a loop that runs while the start pointer is greater than or equal to the end pointer because we are traversing backwards and must ensure all items are accounted for.
        while(start >= end){
            // Step 19: Add the price of the candy at 'start' to 'max_amount' because to maximize cost, we are forced to pay for the most expensive available candy.
            max_amount = max_amount + prices[start];
            // Step 20: Decrement the start pointer because we have processed the current most expensive candy and need to move backwards to the next expensive one.
            start--;
            // Step 21: Move the end pointer forward by 'k' positions because we use our free allowance on the cheapest candies (at the front) so we are forced to pay for the expensive ones.
            end = end + k;
        }

        // Step 22: Return a vector containing both calculated values because the problem requires us to output both the minimum and maximum spending amounts.
        return {min_amount, max_amount};
    }
};

int main(){
    // Step 23: Create a vector of integers representing candy prices because this serves as the input data for our test case.
    vector<int>prices = {3,2,1,4};
    
    // Step 24: Define an integer 'k' as 2 because this sets the rule that for every 1 candy bought, 2 are free.
    int k = 2;

    // Step 25: Instantiate an object of the CandyShop class passing our data because this sets up the environment to solve the problem with the given inputs.
    CandyShop shop(prices, k);

    // Step 26: Call the minMaxCandy function and store the result because we need to execute the logic and capture the returned minimum and maximum costs.
    vector<int>result = shop.minMaxCandy();

    // Step 27: Print the minimum amount calculated because we need to display the first part of the solution to the user.
    cout<<"Minimum amount: "<<result[0]<<endl;
    
    // Step 28: Print the maximum amount calculated because we need to display the second part of the solution to the user.
    cout<<"Maximum amount: "<<result[1]<<endl;

    // Step 29: Return 0 because the main function must return an integer to indicate that the program executed successfully without errors.
    return 0;
}