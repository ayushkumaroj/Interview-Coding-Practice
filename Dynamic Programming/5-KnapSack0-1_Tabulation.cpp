#include <iostream>
#include <vector>
using namespace std;

int maxKnapsackValue_Tabulation(vector<int>& values, vector<int>& weights, int knapsackCapacity, int totalItems){
    //Initialization : int dp[totalItems + 1][knapsackCapacity + 1];
    // or Initialization : vector<vector<int>> dp(totalItems + 1, vector<int>(knapsackCapacity + 1));
    // for (int i = 0; i <= totalItems; i++){
    //     dp[i][0] = 0;
    // }
    // for (int w = 0; w <= knapsackCapacity; w++){
    //     dp[0][w] = 0;
    // }

    vector<vector<int>> dp(totalItems + 1, vector<int>(knapsackCapacity + 1, 0));

    // 🔹 Build table bottom-up
    for (int i = 1; i <= totalItems; i++) {

        int currentItemWeight = weights[i - 1];
        int currentItemValue  = values[i - 1];

        for (int w = 1; w <= knapsackCapacity; w++) {
            int valueIfExcluded = dp[i - 1][w];

            int valueIfIncluded = 0;

            if (currentItemWeight <= w) {
                valueIfIncluded = currentItemValue + dp[i - 1][w - currentItemWeight];
            }

            dp[i][w] = max(valueIfIncluded, valueIfExcluded);
        }
    }

    return dp[totalItems][knapsackCapacity];
}

int main() {

    vector<int> values  = {15, 14, 10, 45, 30};
    vector<int> weights = {2, 5, 1, 3, 4};

    int knapsackCapacity = 7;
    int totalItems = values.size();

    cout << maxKnapsackValue_Tabulation(values,
                                        weights,
                                        knapsackCapacity,
                                        totalItems);

    return 0;
}
