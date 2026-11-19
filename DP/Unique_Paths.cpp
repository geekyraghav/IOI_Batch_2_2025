class Solution {
public:
    // // Method 3.2 (Space Optimised Tabulation)
    // int uniquePaths(int m, int n) {
    //     vector<vector<int>> dp(2,vector<int>(n,1));
    //     for(int i=1;i<=m-1;i++){ // m-1 times
    //         if(i%2 == 1){ // 1st row fill
    //             for(int j=1;j<n;j++){
    //                 dp[1][j] = dp[1][j-1] + dp[0][j];
    //             }
    //         }
    //         else{ // 0th row fill
    //             for(int j=1;j<n;j++){
    //                 dp[0][j] = dp[0][j-1] + dp[1][j];
    //             }
    //         }
    //     }
    //     return max(dp[0][n-1],dp[1][n-1]);
    // }

    // Method 3.1 (Space Optimised Tabulation)
    int uniquePaths(int m, int n) {
        if(n > m) swap(m,n);
        vector<vector<int>> dp(2,vector<int>(n,1));
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                dp[1][j] = dp[0][j] + dp[1][j-1];
            }
            dp[0] = dp[1]; // oth row me 1st row copy kardo
        }
        return dp[1][n-1];
    }

    // // Method 2 (Tabulation)
    // int uniquePaths(int m, int n) {
    //     vector<vector<int>> dp(m,vector<int>(n));
    //     for(int i=0;i<m;i++){
    //         for(int j=0;j<n;j++){
    //             if(i==0 or j==0) dp[i][j] = 1;
    //             else dp[i][j] = dp[i-1][j] + dp[i][j-1];
    //         }
    //     }
    //     return dp[m-1][n-1];
    // }

    // // Method 1 (Memoization)
    // int paths(int m, int n, vector<vector<int>>& dp){ // m = 0 to m-1, n = 0 to n-1
    //     if(m==0 or n==0) return 1;
    //     if(dp[m][n] != -1) return dp[m][n];
    //     return dp[m][n] = paths(m-1,n,dp) + paths(m,n-1,dp);
    // }
    // int uniquePaths(int m, int n) {
    //     vector<vector<int>> dp(m,vector<int>(n,-1));
    //     return paths(m-1,n-1,dp);
    // }
};
