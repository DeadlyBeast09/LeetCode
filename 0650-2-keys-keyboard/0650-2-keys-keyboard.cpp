class Solution {
    int helper(int cur, int x, int n) {
// clipboard = x, current state = cur
        if (cur > n)
            return 1e9;

        if (cur == n)
            return 0;

        int copy = 1e9;

        
        if (x != cur)
            copy = 1 + helper(cur, cur, n);

        int paste = 1e9;

        if (x > 0)
            paste = 1 + helper(cur + x, x, n);

        return min(copy, paste);
    }

public:
    int minSteps(int n) {

        if (n == 1)
            return 0;

        return helper(1, 0, n);
    }
};