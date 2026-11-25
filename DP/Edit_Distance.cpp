class Solution {
public:
    int edit(int i, int j, string& a, string& b, vector<vector<int>>& dp) {
        if(i == -1) return j+1;
        if(j == -1) return i+1;
        if(dp[i][j] != -1) return dp[i][j];
        if(a[i] == b[j]) return dp[i][j] = edit(i-1,j-1,a,b,dp);
        else{
            int insert = edit(i,j-1,a,b,dp);
            int deletion = edit(i-1,j,a,b,dp);
            int replace = edit(i-1,j-1,a,b,dp);
            return dp[i][j]  = 1 + min(insert,min(deletion,replace));
        }
    }
    int minDistance(string a, string b) {
        int m = a.length(), n = b.length();
        // i -> m-1 to 0, j -> n-1 to 0
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return edit(m-1,n-1,a,b,dp);
    }
};
