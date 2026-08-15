class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        bool check = false;
        int x = 0;
        for(auto it : nums){
            x^=it;
            if(it!=0){
                check = true;
            }
        }
        if(x!=0){
            return nums.size();
        }
        if(check){
            return nums.size()-1;
        }
        return 0;

    }
};