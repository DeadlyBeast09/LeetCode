class Solution {
    int dp[21][21];
    int helper(int i, int j, vector<int>& nums) {
        if (i == j)
            return nums[i];
        if(dp[i][j]!=-1) return dp[i][j];
        int takeLeft = nums[i] - helper(i + 1, j, nums);
        int takeRight = nums[j] - helper(i, j - 1, nums);
        // max diffreence
        return dp[i][j]=max(takeLeft, takeRight);
    }

public:
    bool predictTheWinner(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return helper(0, nums.size() - 1, nums) >= 0;
    }
};