class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {

        int m = heights.size();
        int n = heights[0].size();

        // dist[r][c] = minimum effort required to reach (r,c)
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));

        priority_queue<
            pair<int, pair<int,int>>,
            vector<pair<int, pair<int,int>>>,
            greater<pair<int, pair<int,int>>>
        > pq;

        // {effort, {row, col}}
        pq.push({0, {0, 0}});
        dist[0][0] = 0;

        int d_r[4] = {-1, 0, 1, 0};
        int d_c[4] = {0, 1, 0, -1};

        while (!pq.empty()) {

            auto it = pq.top();
            pq.pop();

            int effort = it.first;
            int row = it.second.first;
            int col = it.second.second;

            // If we reached destination, this is optimal
            if (row == m - 1 && col == n - 1)
                return effort;

            // Ignore outdated heap entries
            if (effort > dist[row][col])
                continue;

            for (int i = 0; i < 4; i++) {

                int n_r = row + d_r[i];
                int n_c = col + d_c[i];

                if (n_r >= 0 && n_r < m &&
                    n_c >= 0 && n_c < n) {

                    int edgeEffort =
                        abs(heights[n_r][n_c] - heights[row][col]);

                    int newEffort = max(effort, edgeEffort);

                    if (newEffort < dist[n_r][n_c]) {

                        dist[n_r][n_c] = newEffort;

                        pq.push({
                            newEffort,
                            {n_r, n_c}
                        });
                    }
                }
            }
        }

        return 0;
    }
};