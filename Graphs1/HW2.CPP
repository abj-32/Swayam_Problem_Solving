#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void dfs(vector<vector<int>> &adj, vector<bool> &visited, int i)
    {
        visited[i] = true;

        for (int ngh : adj[i])
        {
            if (visited[ngh] == false)
            {
                dfs(adj, visited, ngh);
            }
        }

        return;
    }

    void bfs(vector<vector<int>> &adj, vector<bool> &visited, int i)
    {
        queue<int> q;
        visited[i] = true;
        q.push(i);

        while (!q.empty())
        {
            int temp = q.front();

            for (int ngh : adj[temp])
            {
                if (visited[ngh] == false)
                {
                    visited[ngh] = true;
                    q.push(ngh);
                }
            }

            q.pop();
        }
    }
    int findCircleNum(vector<vector<int>> &isConnected)
    {
        int n = isConnected.size();

        vector<vector<int>> adj(n, vector<int>());
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {

                if (i != j && isConnected[i][j] == 1)
                {
                    adj[i].push_back(j);
                }
            }
        }

        vector<bool> visited(n, false);
        int ans = 0;

        for (int i = 0; i < n; i++)
        {
            if (visited[i] == false)
            {
                ans++;
                // dfs(adj,visited,i);
                bfs(adj, visited, i);
                // ans++;
            }
        }

        return ans;
    }
};