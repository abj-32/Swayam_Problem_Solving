#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void bfs(int src, vector<vector<int>> &adj, vector<vector<int>> &ans, int n)
    {
        vector<int> temp;
        vector<int> visited(n, false);

        queue<int> q;
        q.push(src);
        visited[src] = true;

        while (!q.empty())
        {
            int curr = q.front();
            q.pop();

            for (int ngh : adj[curr])
            {
                if (visited[ngh] == false)
                {
                    temp.push_back(ngh);
                    q.push(ngh);
                    visited[ngh] = true;
                }
            }
        }

        sort(temp.begin(), temp.end());
        ans.push_back(temp);
    }
    vector<vector<int>> getAncestors(int n, vector<vector<int>> &edges)
    {
        vector<vector<int>> adj(n, vector<int>());
        for (int i = 0; i < edges.size(); i++)
        {
            adj[edges[i][1]].push_back(edges[i][0]);
        }

        vector<vector<int>> ans;
        for (int i = 0; i < n; i++)
        {
            bfs(i, adj, ans, n);
        }

        return ans;
    }
};