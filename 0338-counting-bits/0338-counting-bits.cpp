class Solution {

    int dp[100001];

    int count(int n) {

        if (n == 0)
            return 0;

        if (dp[n] != -1)
            return dp[n];

        return dp[n] = count(n >> 1) + (n & 1);
    }

public:
    vector<int> countBits(int n) {

        memset(dp, -1, sizeof(dp));

        vector<int> ans;

        for (int i = 0; i <= n; i++) {
            ans.push_back(count(i));
        }

        return ans;
    }
};