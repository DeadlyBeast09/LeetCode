class Solution {
    int dp[101];
    int helper(int i, int end, vector<int>& nums) {
        
        if (i > end)
            return 0;
        if(dp[i]!=-1) return dp[i];
        int rob = nums[i] + helper(i + 2, end, nums);
        int skip = helper(i + 1, end, nums);

        return dp[i] = max(rob, skip);
    }
    int solve(int start,int end,vector<int> &nums){
        memset(dp,-1,sizeof(dp));
        return helper(start,end,nums);
    }

public:
    int rob(vector<int>& nums) {

        int n = nums.size();
        if (n == 1)
            return nums[0];

        int case1 = solve(0, n - 2, nums);
        int case2 = solve(1, n - 1, nums);

        return max(case1, case2);
    }
};