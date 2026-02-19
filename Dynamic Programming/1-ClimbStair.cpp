#include<iostream>
using namespace std;
#include<vector>

// Count ways to reach the nth stair. A person can climb 1 or 2 stair at a time

int countWaysRec(int n){
    if(n==0 || n==1){
        return 1;
    }

    int totalWays = countWaysRec(n-1) + countWaysRec(n-2);
    return totalWays;
}


int countWaysMemo(int n, vector<int>&dp){
    if(n==0 || n==1){
        return 1;
    }

    if(dp[n] != -1){
        return dp[n];
    }

    dp[n] = countWaysMemo(n-1, dp) + countWaysMemo(n-2, dp);
    return dp[n];
}

int countWaysTabu(int n){
    vector<int>dp(n+1, 0);

    dp[0] = 1;
    dp[1] = 1;

    for(int i=2; i<=n; i++){
        dp[i] = dp[i-1] + dp[i-2];
    }

    return dp[n];

}

int main(){
    int n = 50;

    cout<<"Using Tabulation: "<<countWaysTabu(n)<<endl;

    vector<int>dp(n+1, -1);
    cout<<"Using Memoization: "<<countWaysMemo(n, dp)<<endl;

    cout<<"Using Recursion: "<<countWaysRec(n)<<endl;
}