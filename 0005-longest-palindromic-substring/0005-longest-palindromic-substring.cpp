class Solution {
    bool dp[1001][1001];
    bool palindrome(int i,int j,string &s){
        if(i>=j) return true;
        if(dp[i][j]) return true;
        if(s[i]!=s[j]) return dp[i][j] = false;
        return dp[i][j] = palindrome(i+1,j-1,s);
    }
public:
    string longestPalindrome(string s) {
        int n = s.size();
        memset(dp,false,sizeof(dp));
        string ans;
        int maxi = 0;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(palindrome(i,j,s)){
                    if(maxi < j-i+1){
                        maxi = j-i+1;
                        ans = s.substr(i,j-i+1);
                    }
                }
            }
        }
        return ans;
    }
};