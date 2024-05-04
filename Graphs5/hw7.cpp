#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
class Solution
{
public:
    vector<ll> dijkstra(int n, vector<vector<pair<ll, ll>>> &graph, int src)
    {
        vector<bool> visited(n, false);
        vector<ll> dist(n, INT_MAX);
        priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;

        pq.push({0, src});
        dist[src] = 0;

        while (!pq.empty())
        {
            ll cnode = pq.top().second;
            ll wt = pq.top().first;
            pq.pop();

            if (visited[cnode] == true)
            {
                continue;
            }

            visited[cnode] = true;

            for (auto ngh : graph[cnode])
            {
                int nghnode = ngh.first;
                ll val = ngh.second;

                if (val + wt < dist[nghnode])
                {
                    dist[nghnode] = val + wt;
                    pq.push({val + wt, nghnode});
                }
            }
        }

        return dist;
    }
    vector<bool> findAnswer(int n, vector<vector<int>> &edges)
    {
        vector<vector<pair<ll, ll>>> graph(n);

        for (int i = 0; i < edges.size(); i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            graph[u].push_back({v, w});
            graph[v].push_back({u, w});
        }

        vector<ll> dist1 = dijkstra(n, graph, 0);
        vector<ll> dist2 = dijkstra(n, graph, n - 1);

        vector<bool> ans(edges.size(), false);
        for (int i = 0; i < edges.size(); i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            int d = edges[i][2];

            if (dist1[u] + dist2[v] + d == dist1[n - 1] || dist1[v] + dist2[u] + d == dist1[n - 1])
            {
                ans[i] = true;
            }
        }

        return ans;
    }
};