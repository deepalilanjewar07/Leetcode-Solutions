/*
LeetCode 743

Problem:
Network Delay Time

Topic:
Graph, Dijkstra's Algorithm, Priority Queue

Approach:
Represent the network as an adjacency list where each edge
contains the destination node and transmission time.

Use Dijkstra's algorithm to compute the shortest time from
the source node to every other node.

The answer is the maximum shortest distance among all nodes.
If any node is unreachable, return -1.

Time Complexity: O((V + E) log V)
Space Complexity: O(V + E)
*/

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        vector<vector<pair<int, int>>> graph(n + 1);

        for (auto &edge : times) {
            graph[edge[0]].push_back({edge[1], edge[2]});
        }

        vector<int> dist(n + 1, INT_MAX);

        priority_queue<
            pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>>
        > pq;

        dist[k] = 0;
        pq.push({0, k});

        while (!pq.empty()) {

            auto [time, node] = pq.top();
            pq.pop();

            if (time > dist[node])
                continue;

            for (auto &[next, wt] : graph[node]) {

                if (dist[next] > time + wt) {

                    dist[next] = time + wt;
                    pq.push({dist[next], next});
                }
            }
        }

        int ans = 0;

        for (int i = 1; i <= n; i++) {

            if (dist[i] == INT_MAX)
                return -1;

            ans = max(ans, dist[i]);
        }

        return ans;
    }
};
