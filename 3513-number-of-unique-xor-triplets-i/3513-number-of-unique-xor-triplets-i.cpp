class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
          int n = nums.size();

        if (n <= 2) return n;

        int bits = 0;
        while ((1 << bits) <= n) bits++;

        return 1 << bits;
    }
};

// if we have numbers {1......n} then we can generate any number {0.....2^k-1} from the combination of triplets. This means total numbers unique generated equals 2^k.
// x ^ x ^ x = x (same as in given array range), x ^ x ^ y = y (same as in given array range), x ^ y ^ z (this only generate unique number).