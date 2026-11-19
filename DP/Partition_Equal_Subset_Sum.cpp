class Solution {
public:
    bool solve(int i, int sum, vector<int>& nums, vector<vector<int>>& dp){ 
        // i -> 0 to n-1, sum -> sum to 0
        if(i == nums.size()) return (sum == 0);
        if(dp[i][sum] != -1) return dp[i][sum];
        bool skip = solve(i+1,sum,nums,dp);
        if(sum-nums[i] < 0) return dp[i][sum] = skip;
        bool pick = solve(i+1,sum-nums[i],nums,dp);
        return dp[i][sum] = skip || pick;
    }
    bool canPartition(vector<int>& nums) {
        int arraySum = 0;
        for(int ele : nums){
            arraySum += ele;
        }
        if(arraySum % 2 == 1) return false;
        int n = nums.size();
        int sum = arraySum/2;
        vector<vector<int>> dp(n,vector<int>(sum+1,-1));
        return solve(0,sum,nums,dp);
    }
};
