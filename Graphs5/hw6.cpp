#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
    {
        vector<vector<pair<int, int>>> adj(n);

        for (int i = 0; i < flights.size(); i++)
        {
            int frm = flights[i][0];
            int to = flights[i][1];
            int cst = flights[i][2];
            adj[frm].push_back({to, cst});
        }

        queue<pair<int, pair<int, int>>> pq;
        pq.push({0, {src, 0}});
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;

        while (!pq.empty())
        {
            int stop = pq.front().first;
            int cnode = pq.front().second.first;
            int prc = pq.front().second.second;
            pq.pop();

            if (stop > k)
            {
                continue;
            }

            for (auto ngh : adj[cnode])
            {
                int nghnode = ngh.first;
                int newprc = ngh.second;

                if (newprc + prc < dist[nghnode] && stop <= k)
                {
                    pq.push({stop + 1, {nghnode, prc + newprc}});
                    dist[nghnode] = newprc + prc;
                }
            }
        }

        if (dist[dst] == INT_MAX)
        {
            return -1;
        }

        return dist[dst];
    }
};