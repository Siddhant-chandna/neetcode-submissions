
class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();

        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));

        // {effort, row, col}
        priority_queue<
            tuple<int, int, int>,
            vector<tuple<int, int, int>>,
            greater<tuple<int, int, int>>
        > pq;

        dist[0][0] = 0;
        pq.push({0, 0, 0});

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        while (!pq.empty()) {
            auto [effort, r, c] = pq.top();
            pq.pop();

            // Ignore outdated entries
            if (effort > dist[r][c])
                continue;

            // Destination reached
            if (r == n - 1 && c == m - 1)
                return effort;

            for (int k = 0; k < 4; k++) {
                int nr = r + dr[k];
                int nc = c + dc[k];

                if (nr < 0 || nr >= n ||
                    nc < 0 || nc >= m)
                    continue;

                int newEffort = max(
                    effort,
                    abs(heights[r][c] - heights[nr][nc])
                );

                if (newEffort < dist[nr][nc]) {
                    dist[nr][nc] = newEffort;
                    pq.push({newEffort, nr, nc});
                }
            }
        }

        return 0;
    }
};
