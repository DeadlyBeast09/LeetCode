class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        map<int,int> mp;
        int i=0,j=0;
        int n = nums.size();
        int maxi = 0;
        while(j<n){
            mp[nums[j]]++;
            if(mp[nums[j]]<=k) {maxi=max(maxi,j-i+1);j++;continue;}
            else{
                
                while(mp[nums[j]] > k){
                    mp[nums[i]]--;
                    i++;
                }
                j++;
            }
        }
        return maxi;
    }
};