#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to detect cycle in a directed graph.
    bool dfs(vector<int> adj[], int visited[], int path[], int node)
    {
        visited[node] = 1;
        path[node] = 1;

        for (auto ngh : adj[node])
        {
            if (visited[ngh] == false)
            {
                if (dfs(adj, visited, path, ngh) == true)
                {
                    return true;
                }
            }

            else if (path[ngh] == 1)
            {
                return true;
            }
        }

        path[node] = 0;
        return false;
    }
    bool isCyclic(int V, vector<int> adj[])
    {
        int visited[V] = {0};
        int path[V] = {0};

        for (int i = 0; i < V; i++)
        {
            if (visited[i] == false)
            {
                if (dfs(adj, visited, path, i) == true)
                {
                    return true;
                }
            }
        }

        return false;
    }
};