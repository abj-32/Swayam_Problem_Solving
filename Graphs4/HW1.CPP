#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int kosaraju(int V, vector<vector<int>> &adj)
    {
        // vector<vector<int>> adj(V,vector<int>());
        vector<vector<int>> radj(V, vector<int>());

        vector<bool> visited(V, false);
        stack<int> st;

        int ans = 0;

        for (int i = 0; i < V; i++)
        {
            if (visited[i] == false)
            {
                dfs(i, st, adj, visited);
            }
        }

        for (int i = 0; i < V; i++)
        {
            visited[i] = false;
            for (auto ngh : adj[i])
            {
                radj[ngh].push_back(i);
            }
        }

        while (!st.empty())
        {
            int temp = st.top();
            st.pop();

            if (visited[temp] == false)
            {
                ans++;
                DFSforSCC(temp, radj, visited);
            }
        }

        return ans;
    }

    void dfs(int node, stack<int> &st, vector<vector<int>> &adj, vector<bool> &visited)
    {
        visited[node] = true;

        for (auto ngh : adj[node])
        {
            if (visited[ngh] == false)
            {
                dfs(ngh, st, adj, visited);
            }
        }

        st.push(node);
    }

    void DFSforSCC(int node, vector<vector<int>> &adj, vector<bool> &visited)
    {
        // temp.push_back(node);
        visited[node] = true;

        for (auto ngh : adj[node])
        {
            if (visited[ngh] == false)
            {
                DFSforSCC(ngh, adj, visited);
            }
        }
    }
};