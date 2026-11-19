class Solution {
public:
    // Method 3 (Space Optimised Tabulation)
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        if(n==2) return max(nums[0],nums[1]);
        vector<int> dp(3);
        dp[0] = nums[0];
        dp[1] = max(nums[0],nums[1]);
        for(int i=2;i<n;i++){
            dp[2] = max(nums[i]+dp[0],dp[1]);
            dp[0] = dp[1];
            dp[1] = dp[2];
        }
        return dp[2];
    }

    // // Method 2 (Tabulation)
    // int rob(vector<int>& nums) {
    //     int n = nums.size();
    //     vector<int> dp(n);
    //     dp[0] = nums[0];
    //     if(n > 1) dp[1] = max(nums[0],nums[1]);
    //     for(int i=2;i<n;i++){
    //         dp[i] = max(nums[i]+dp[i-2],dp[i-1]);
    //     }
    //     return dp[n-1];
    // }

    // // Method 1 (Memoisation)
    // int chori(int idx, vector<int>& arr, vector<int>& dp) { // idx -> 0 to n-1
    //     int n = arr.size();
    //     if(idx >= n) return 0;
    //     if(dp[idx] != -1) return dp[idx];
    //     int pick = arr[idx] + chori(idx+2,arr,dp);
    //     int skip = chori(idx+1,arr,dp);
    //     return dp[idx] = max(pick,skip);
    // }
    // int rob(vector<int>& arr) {
    //     int n = arr.size();
    //     vector<int> dp(n,-1);
    //     return chori(0,arr,dp);
    // }
};
