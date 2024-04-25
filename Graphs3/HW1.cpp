#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int bfs(vector<vector<pair<int, int>>> &adj, int n, int src, int dst)
    {
        vector<int> dis(n + 1, INT_MAX);
        deque<int> dq;

        dq.push_back({src});
        dis[src] = 0;

        while (!dq.empty())
        {
            int node = dq.front();
            dq.pop_front();

            for (auto it : adj[node])
            {
                int v = it.first;
                int wt = it.second;

                if (dis[node] + wt < dis[v])
                {
                    dis[v] = dis[node] + wt;

                    if (wt == 1)
                    {
                        dq.push_back(v);
                    }
                    else
                    {
                        dq.push_front(v);
                    }
                }
            }
        }

        return dis[dst] == INT_MAX ? -1 : dis[dst];
    }

    int minimumEdgeReversal(vector<vector<int>> &edges, int n, int src, int dst)
    {
        vector<vector<pair<int, int>>> adj(n + 1);

        for (auto it : edges)
        {
            int u = it[0];
            int v = it[1];

            adj[u].push_back({v, 0});
            adj[v].push_back({u, 1});
        }

        return bfs(adj, n, src, dst);
    }
};