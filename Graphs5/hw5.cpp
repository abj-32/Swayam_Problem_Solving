#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int dijkstra(int n, vector<vector<pair<int, int>>> &graph, int src, int k)
    {
        vector<bool> visited(n, false);
        vector<int> dist(n, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        pq.push({0, src});
        dist[src] = 0;
        int ans = 0;

        while (!pq.empty())
        {
            int cnode = pq.top().second;
            int wt = pq.top().first;
            pq.pop();

            if (visited[cnode] == true)
            {
                continue;
            }

            visited[cnode] = true;

            if (wt > k)
            {
                break;
            }

            for (auto ngh : graph[cnode])
            {
                int nghnode = ngh.first;
                int val = ngh.second;

                int newwt = val + wt;
                if (newwt < dist[nghnode])
                {
                    dist[nghnode] = newwt;
                    pq.push({newwt, nghnode});
                }
            }
        }

        for (int i = 0; i < n; i++)
        {
            if (dist[i] <= k)
            {
                ans++;
            }
        }
        return ans;
    }

    int findTheCity(int n, vector<vector<int>> &edges, int distanceThreshold)
    {
        vector<vector<pair<int, int>>> graph(n);

        for (int i = 0; i < edges.size(); i++)
        {
            int frm = edges[i][0];
            int to = edges[i][1];
            int rd = edges[i][2];
            graph[frm].push_back({to, rd});
            graph[to].push_back({frm, rd});
        }

        int mini = INT_MAX;
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            int val = dijkstra(n, graph, i, distanceThreshold);
            if (val <= mini)
            {
                mini = val;
                ans = i;
            }
        }

        return ans;
    }
};