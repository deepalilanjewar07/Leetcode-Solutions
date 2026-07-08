/*
LeetCode 778

Problem:
Swim in Rising Water

Topic:
Graph, Dijkstra's Algorithm, Priority Queue

Approach:
Treat each cell as a graph node.

The cost of a path is the maximum elevation encountered
along that path.

Use Dijkstra's algorithm:
- Always process the cell with the minimum current cost.
- The answer is the minimum possible maximum elevation
  required to reach the bottom-right cell.

Time Complexity: O(n² log n)
Space Complexity: O(n²)
*/

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {

        int n = grid.size();

        priority_queue<
            vector<int>,
            vector<vector<int>>,
            greater<vector<int>>
        > pq;

        vector<vector<int>> visited(n, vector<int>(n, false));

        pq.push({grid[0][0], 0, 0});

        vector<pair<int, int>> dir = {
            {1, 0}, {-1, 0}, {0, 1}, {0, -1}
        };

        while (!pq.empty()) {

            auto cur = pq.top();
            pq.pop();

            int time = cur[0];
            int x = cur[1];
            int y = cur[2];

            if (visited[x][y])
                continue;

            visited[x][y] = true;

            if (x == n - 1 && y == n - 1)
                return time;

            for (auto& d : dir) {

                int nx = x + d.first;
                int ny = y + d.second;

                if (nx >= 0 && ny >= 0 &&
                    nx < n && ny < n &&
                    !visited[nx][ny]) {

                    pq.push({
                        max(time, grid[nx][ny]),
                        nx,
                        ny
                    });
                }
            }
        }

        return -1;
    }
};
