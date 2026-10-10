class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1,
                               vector<int>& nums2,
                               int k1, int k2) {
        long long k = (long long)k1 + k2;
        vector<int> freq(100001, 0);
        long long total = 0;

        for (int i = 0; i < nums1.size(); i++) {
            int d = abs(nums1[i] - nums2[i]);
            freq[d]++;
            total += d;
        }

        if (total <= k) return 0;

        for (int d = 100000; d > 0 && k > 0; d--) {
            if (freq[d] == 0) continue;

            int next = d - 1;
            long long need = freq[d];

            if (k >= need) {
                freq[next] += freq[d];
                freq[d] = 0;
                k -= need;
            } else {
                // Reduce k differences from d to d-1.
                freq[d] -= k;
                freq[next] += k;
                k = 0;
            }
        }

        long long ans = 0;

        for (int d = 1; d <= 100000; d++) {
            ans += 1LL * d * d * freq[d];
        }

        return ans;
    }
};