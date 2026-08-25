class Solution {
    int dp[20];
    int helper(int n){
        if(n<=1) return 1;
        if(dp[n]!=-1) return dp[n];
        int ans = 0;
        for(int i=1;i<=n;i++){
            int left = helper(i-1);
            int right = helper(n-i);
            ans+=left*right;
        }
        return dp[n]=ans;
    }
public:
    int numTrees(int n) {
        memset(dp,-1,sizeof(dp));
        return helper(n);
    }
};