class Solution {
public:
    // Method 3 (Space Optimised Tabulation)
    int fib(int n) {
        if(n <= 1) return n;
        vector<int> dp(3);
        dp[0] = 0;
        dp[1] = 1;
        for(int i=2;i<=n;i++){
            dp[2] = dp[1] + dp[0];
            dp[0] = dp[1];
            dp[1] = dp[2];
        }
        return dp[2];
    }

    // // Method 2 (Tabulation)
    // int fib(int n) {
    //     vector<int> dp(n+1);
    //     dp[0] = 0;
    //     if(n >= 1) dp[1] = 1;
    //     for(int i=2;i<=n;i++){
    //         dp[i] = dp[i-1] + dp[i-2];
    //     }
    //     return dp[n];
    // }

    // // Method 1 (Memoization)
    // int fibo(int n, vector<int>& dp) {
    //     if(n==0 or n==1) return n;
    //     if(dp[n] != -1) return dp[n];
    //     return dp[n] = fibo(n-1,dp) + fibo(n-2,dp);
    // }
    // int fib(int n) {
    //     vector<int> dp(n+1,-1);
    //     return fibo(n,dp);
    // }
};
