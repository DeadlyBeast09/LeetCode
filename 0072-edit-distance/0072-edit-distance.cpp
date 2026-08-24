class Solution {
    int dp[501][501];
    
    int helper(int i, int j, string& word1, string& word2) {
        
        if (i == 0)
            return j;
        
        if (j == 0)
            return i;
        if(dp[i][j]!=-1) return dp[i][j];
        
        if (word1[i - 1] == word2[j - 1])
            return dp[i][j]= helper(i - 1, j - 1, word1, word2);
        
        int del = helper(i - 1, j, word1, word2);
        int ins = helper(i, j - 1, word1, word2);
        int rep = helper(i - 1, j - 1, word1, word2);
        
        return dp[i][j]= 1 + min({del, ins, rep});
    }

public:
    int minDistance(string word1, string word2) {
        memset(dp,-1,sizeof(dp));
        return helper(word1.size(), word2.size(), word1, word2);
    }
};