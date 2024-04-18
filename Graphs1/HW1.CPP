#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void dfs(vector<vector<int>> &adj, vector<bool> &visited, int src, int dstn, bool &flag)
    {
        if (flag == true)
        {
            return;
        }

        visited[src] = true;

        if (src == dstn)
        {
            flag = true;
            return;
        }

        for (int ngh : adj[src])
        {
            if (visited[ngh] == false)
            {
                dfs(adj, visited, ngh, dstn, flag);
            }
        }

        return;
    }
    bool validPath(int n, vector<vector<int>> &edges, int source, int destination)
    {
        vector<vector<int>> adj(n, vector<int>());

        if (source == destination && edges.size() == 0)
        {
            return true;
        }
        int sz = edges.size();
        for (int i = 0; i < sz; i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }

        // for(int i=0;i<adj[source].size();i++){
        //     if(adj[source][i]==destination){
        //         return true;
        //         break;
        //     }
        // }

        vector<bool> visited(n, false);
        bool flag = false;
        dfs(adj, visited, source, destination, flag);

        return flag;
    }
};