#include <iostream>
#include <vector>
using namespace std;


int maxKnapsackValue(vector<int>&values, vector<int>&weights, int knapsackCapacity, int totalItems){
    if (totalItems == 0 || knapsackCapacity == 0) {
        return 0;
    }

    int currentItemWeight = weights[totalItems - 1];
    int currentItemValue  = values[totalItems - 1];

    int valueIfExcluded =  maxKnapsackValue(values,weights, knapsackCapacity, totalItems - 1);

    int valueIfIncluded = 0;

    if (currentItemWeight <= knapsackCapacity) {
        valueIfIncluded =  currentItemValue + maxKnapsackValue(values, weights, knapsackCapacity - currentItemWeight, totalItems - 1);
    }

    return max(valueIfIncluded, valueIfExcluded);
}

int main() {

    vector<int> values  = {15, 14, 10, 45, 30};
    vector<int> weights = {2, 5, 1, 3, 4};

    int knapsackCapacity = 7;
    int totalItems = values.size();

    cout << maxKnapsackValue(values, weights, knapsackCapacity, totalItems);

    return 0; 
}
