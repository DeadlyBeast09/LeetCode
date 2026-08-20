class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {

        unordered_map<int, unordered_set<int>> mp;

        for (auto &seat : reservedSeats) {
            mp[seat[0]].insert(seat[1]);
        }

        int ans = 2 * (n - mp.size());

        for (auto &[row, seats] : mp) {

            bool left = true;    // 2-5
            bool middle = true;  // 4-7
            bool right = true;   // 6-9

            for (int j = 2; j <= 5; j++) {
                if (seats.count(j)) {
                    left = false;
                    break;
                }
            }

            for (int j = 4; j <= 7; j++) {
                if (seats.count(j)) {
                    middle = false;
                    break;
                }
            }

            for (int j = 6; j <= 9; j++) {
                if (seats.count(j)) {
                    right = false;
                    break;
                }
            }

            if (left && right)
                ans += 2;
            else if (left || middle || right)
                ans += 1;
        }

        return ans;
    }
};

/*class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, int> mp;

        // Store reserved seats for each row using a bitmask
        for (auto &seat : reservedSeats) {
            int row = seat[0];
            int col = seat[1];

            mp[row] |= (1 << col);
        }

        // Rows without any reservation can fit 2 families
        int ans = 2 * (n - mp.size());

        for (auto &[row, mask] : mp) {
            bool left  = true;  // seats 2-5
            bool middle = true; // seats 4-7
            bool right = true;  // seats 6-9

            // Check seats 2,3,4,5
            if (mask & (1 << 2) ||
                mask & (1 << 3) ||
                mask & (1 << 4) ||
                mask & (1 << 5))
                left = false;

            // Check seats 4,5,6,7
            if (mask & (1 << 4) ||
                mask & (1 << 5) ||
                mask & (1 << 6) ||
                mask & (1 << 7))
                middle = false;

            // Check seats 6,7,8,9
            if (mask & (1 << 6) ||
                mask & (1 << 7) ||
                mask & (1 << 8) ||
                mask & (1 << 9))
                right = false;

            if (left && right)
                ans += 2;
            else if (left || middle || right)
                ans += 1;
        }

        return ans;
    }
};*/