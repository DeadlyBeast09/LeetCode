class Solution {
    int dp[301][5001];
    int helper(int n,int amount,vector<int> &coins){
        if(amount == 0) return 1;
        if(n==0) return 0;
        if(dp[n][amount]!=-1) return dp[n][amount];
        if(coins[n-1] <= amount){
            return dp[n][amount] = helper(n,amount-coins[n-1],coins) + helper(n-1,amount,coins);
        }
        return dp[n][amount]=helper(n-1,amount,coins);
    }
public:
    int change(int amount, vector<int>& coins) {
        memset(dp,-1,sizeof(dp));
        int n = coins.size();
        return helper(n,amount,coins);
    }
};