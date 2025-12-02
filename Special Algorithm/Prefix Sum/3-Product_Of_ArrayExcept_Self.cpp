#include<iostream>
using namespace std;
#include<vector>

vector<int> usingDivision(vector<int>& nums) {
    int n = nums.size();
    int product = 1;
    int prod2 = 1;
    int nozero = 0;

    for(int i=0; i<n; i++){
        if(nums[i] == 0){
            nozero++;
        }
        if(nums[i] != 0){
            prod2 = prod2 * nums[i];
        }

        product = product * nums[i];
    }

    if(nozero > 1){
        prod2 = 0;
    }

    for(int i=0; i<n; i++){
        if(nums[i] == 0){
            nums[i] = prod2;
        }
        else{
            nums[i] = product/nums[i];
        }
    }
    return nums;
}

// Approach 3: Using prefix, suffix and answer arrays separately
vector<int> usingPrefixSuffixAns(vector<int>& nums) {
    int n = nums.size();
    vector<int>prefixProd(n);
    vector<int>sufixProd(n);
    vector<int>ans(n);

    //build prefix product array
    int prod = nums[0];
    prefixProd[0] = 1;
    for(int i=1; i<n; i++){
        prefixProd[i] = prod;
        prod = prod * nums[i];
    }
    
    //build suffix product array
    prod = nums[n-1];
    sufixProd[n-1] = 1;
    for(int i=n-2; i>=0; i--){
        sufixProd[i] = prod;
        prod = prod * nums[i];
    }
    //build ans array
    for(int i=0; i<n; i++){
        ans[i] = prefixProd[i] * sufixProd[i];
    }
    return ans;
}

vector<int> usingTwoArrays(vector<int>& nums) {
    int n = nums.size();
    vector<int>prefixProd(n);
    vector<int>sufixProd(n);
    //build prefix product array
    int prod = nums[0];
    prefixProd[0] = 1;
    for(int i=1; i<n; i++){
        prefixProd[i] = prod;
        prod = prod * nums[i];
    }
    //build suffix product array
    prod = nums[n-1];
    sufixProd[n-1] = 1;
    for(int i=n-2; i>=0; i--){
        sufixProd[i] = prod;
        prod = prod * nums[i];
    }
    //prefixprod[i] = prefixprod[i] * sufixprod[i]
    for(int i=0; i<n; i++){
        prefixProd[i] = prefixProd[i] * sufixProd[i];
    }
    return prefixProd;
}

vector<int> usingSingleArray(vector<int>& nums) {
    int n = nums.size();
    vector<int>prefixProd(n);
    //build prefix product array
    int prod = nums[0];
    prefixProd[0] = 1;
    for(int i=1; i<n; i++){
        prefixProd[i] = prod;
        prod = prod * nums[i];
    }
    //build suffix product array
    prod = nums[n-1];
    for(int i=n-2; i>=0; i--){
        prefixProd[i] = prefixProd[i] * prod;
        prod = prod * nums[i];
    }
    return prefixProd;
}

// Main function to test all approaches
int main() {
    vector<int> nums = {1, 2, 3, 4};

    vector<int> res1 = usingSingleArray(nums);
    cout << "Approach 1 (SingleArray): ";
    for(int x : res1) cout << x << " ";
    cout << endl;

    nums = {1, 2, 3, 4};
    vector<int> res2 = usingTwoArrays(nums);
    cout << "Approach 2 (TwoArrays): ";
    for(int x : res2) cout << x << " ";
    cout << endl;

    nums = {1, 2, 3, 4};
    vector<int> res3 = usingPrefixSuffixAns(nums);
    cout << "Approach 3 (PrefixSuffixAns): ";
    for(int x : res3) cout << x << " ";
    cout << endl;

    nums = {1, 2, 3, 4};
    vector<int> res4 = usingDivision(nums);
    cout << "Approach 4 (Division): ";
    for(int x : res4) cout << x << " ";
    cout << endl;

    return 0;
}
