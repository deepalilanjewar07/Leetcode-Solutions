/*
LeetCode 1631

Problem:
Path With Minimum Effort

Topic:
Graph, Dijkstra's Algorithm, Priority Queue

Approach:
Treat each cell as a graph node.

The effort of a path is defined as the maximum absolute
height difference between adjacent cells along that path.

Use Dijkstra's algorithm:
- Each state stores the minimum effort required to reach
  a cell.
- Always expand the cell with the smallest current effort.
- Relax neighboring cells by taking the maximum of the
  current effort and the new edge cost.

Time Complexity: O(m × n × log(m × n))
Space Complexity: O(m × n)
*/

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {

        int m = heights.size();
        int n = heights[0].size();

        vector<vector<int>> effort(m, vector<int>(n, INT_MAX));

        priority_queue<
            vector<int>,
            vector<vector<int>>,
            greater<vector<int>>
        > pq;

        effort[0][0] = 0;
        pq.push({0, 0, 0});

        vector<pair<int, int>> dir = {
            {1, 0}, {-1, 0}, {0, 1}, {0, -1}
        };

        while (!pq.empty()) {

            auto cur = pq.top();
            pq.pop();

            int diff = cur[0];
            int x = cur[1];
            int y = cur[2];

            if (x == m - 1 && y == n - 1)
                return diff;

            for (auto &d : dir) {

                int nx = x + d.first;
                int ny = y + d.second;

                if (nx >= 0 && ny >= 0 &&
                    nx < m && ny < n) {

                    int newEffort = max(
                        diff,
                        abs(heights[x][y] - heights[nx][ny])
                    );

                    if (newEffort < effort[nx][ny]) {
                        effort[nx][ny] = newEffort;
                        pq.push({newEffort, nx, ny});
                    }
                }
            }
        }

        return 0;
    }
};
