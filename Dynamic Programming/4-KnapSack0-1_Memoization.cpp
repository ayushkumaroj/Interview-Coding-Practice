#include <iostream>
#include <vector>
using namespace std;

int maxKnapsackValue(vector<int>& values, vector<int>& weights, int knapsackCapacity, int totalItems, vector<vector<int>>& dp){
    // BASE CASE
    if (totalItems == 0 || knapsackCapacity == 0) {
        return 0;
    }

    if (dp[totalItems][knapsackCapacity] != -1) {
        return dp[totalItems][knapsackCapacity];
    }

    int currentItemWeight = weights[totalItems - 1];
    int currentItemValue  = values[totalItems - 1];

    int valueIfExcluded = maxKnapsackValue(values, weights, knapsackCapacity, totalItems - 1, dp);

    int valueIfIncluded = 0;

    if (currentItemWeight <= knapsackCapacity) {
        valueIfIncluded = currentItemValue + maxKnapsackValue(values, weights, knapsackCapacity - currentItemWeight, totalItems - 1, dp);
    }

    dp[totalItems][knapsackCapacity] = max(valueIfIncluded, valueIfExcluded);

    return dp[totalItems][knapsackCapacity];
}

int main() {

    vector<int> values  = {15, 14, 10, 45, 30};
    vector<int> weights = {2, 5, 1, 3, 4};

    int knapsackCapacity = 7;
    int totalItems = values.size();

    vector<vector<int>> dp(totalItems + 1, vector<int>(knapsackCapacity + 1, -1));

    cout << maxKnapsackValue(values, weights, knapsackCapacity, totalItems, dp);

    return 0;
}
