class Solution {
public:
    int lcs(int i, int j, string& a, string& b, vector<vector<int>>& dp) { 
        if(i<0 or j<0) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        if(a[i] == b[j]) return dp[i][j] = 1 + lcs(i-1,j-1,a,b,dp);
        return dp[i][j] = max(lcs(i,j-1,a,b,dp),lcs(i-1,j,a,b,dp));
    }
    int longestCommonSubsequence(string a, string b) {
        int m = a.length(), n = b.length();
        // i -> m-1 to 0, j -> n-1 to 0
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return lcs(m-1,n-1,a,b,dp);
    }
};
