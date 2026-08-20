class Solution {
    int dp[101][101];

    int helper(int r, int c, int m, int n,
               vector<vector<int>>& obstacleGrid) {

        if (r >= m || c >= n)
            return 0;

        if (obstacleGrid[r][c] == 1)
            return 0;

        if (r == m - 1 && c == n - 1)
            return 1;

        if (dp[r][c] != -1)
            return dp[r][c];

        int down = helper(r + 1, c, m, n, obstacleGrid);
        int right = helper(r, c + 1, m, n, obstacleGrid);

        return dp[r][c] = down + right;
    }

public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        memset(dp, -1, sizeof(dp));

        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        return helper(0, 0, m, n, obstacleGrid);
    }
};