#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findShortestCycle(int n, vector<vector<int>> &edges)
    {
        int ans = INT_MAX;
        vector<vector<int>> adj(n, vector<int>());
        for (auto it : edges)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        for (int i = 0; i < n; i++)
        {

            vector<int> parent(n, -1);
            vector<int> dist(n, INT_MAX);

            queue<int> q;
            q.push(i);
            dist[i] = 0;
            // parent[i]=i;

            while (!q.empty())
            {
                int node = q.front();
                q.pop();

                for (auto ngh : adj[node])
                {
                    if (dist[ngh] == INT_MAX)
                    {
                        dist[ngh] = 1 + dist[node];
                        parent[ngh] = node;
                        q.push(ngh);
                    }
                    else if (parent[ngh] != node && parent[node] != ngh)
                    {
                        ans = min(ans, dist[ngh] + dist[node] + 1);
                    }
                }
            }
        }

        if (ans == INT_MAX)
        {
            return -1;
        }

        return ans;
    }
};