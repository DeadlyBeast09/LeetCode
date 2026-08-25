class Solution {
    int dp[301][301];
    int helper(vector<vector<char>> &matrix,int row,int col,int m,int n){
        if(row >= m || col >= n) return 0;
        if(matrix[row][col]=='0') return 0;
        if (dp[row][col]!=-1) return dp[row][col];
        int right = helper(matrix,row,col+1,m,n);
        int down = helper(matrix,row+1,col,m,n);
        int diagonal = helper(matrix,row+1,col+1,m,n);
        
       return dp[row][col] = 1 + min({right,down,diagonal});
    }
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        memset(dp,-1,sizeof(dp));
        int side = 0;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                side = max(side,helper(matrix,i,j,m,n));
            }
        }
        return side * side;

    }
};