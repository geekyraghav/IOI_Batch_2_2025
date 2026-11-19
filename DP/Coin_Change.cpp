class Solution {
public:
    long long solve(int i, int sum, vector<int>& coins, vector<vector<int>>& dp){ 
        if(i == coins.size()){
            if(sum != 0) return INT_MAX;
            else return 0;
        }
        if(dp[i][sum] != -1) return dp[i][sum];
        long long skip = solve(i+1,sum,coins,dp);
        if(sum - coins[i] < 0) return dp[i][sum] = skip;
        long long pick = 1 + solve(i,sum-coins[i],coins,dp);
        return dp[i][sum] = min(skip,pick);
    }
    int coinChange(vector<int>& coins, int sum) {
        int n = coins.size();
        vector<vector<int>> dp(n,vector<int>(sum+1,-1));
        long long ans = solve(0,sum,coins,dp);
        return (ans == INT_MAX) ? -1 : ans;
    }
};
