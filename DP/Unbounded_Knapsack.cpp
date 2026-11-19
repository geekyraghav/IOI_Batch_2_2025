class Solution {
  public:
    int maxLoot(int c, int n, vector<int> &val, vector<int> &wt, vector<vector<int>>& dp) { 
            if(n < 0) return 0;
            if(dp[n][c] != -1) return dp[n][c];
            int skip = maxLoot(c,n-1,val,wt,dp);
            if(c-wt[n] < 0) return dp[n][c] = skip; // IMPORTANT
            int pick = val[n] + maxLoot(c-wt[n],n,val,wt,dp);
            return dp[n][c] = max(pick,skip);
        }
    int knapSack(vector<int>& val, vector<int>& wt, int c) {
        int n = wt.size();
        vector<vector<int>> dp(n,vector<int>(c+1,-1));
        return maxLoot(c,n-1,val,wt,dp); // idx -> n-1 to 0, c -> c to 0
    }
};
