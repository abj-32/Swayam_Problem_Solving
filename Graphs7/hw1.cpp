#include <bits/stdc++.h>
using namespace std;

class DisjointSet
{
public:
    vector<int> rank, parent;
    DisjointSet(int n)
    {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
        }
    }

    int find(int node)
    {
        if (node == parent[node])
        {
            return node;
        }

        return parent[node] = find(parent[node]);
    }

    void unionRnk(int u, int v)
    {
        int pu = find(u);
        int pv = find(v);
        if (pu == pv)
            return;
        if (rank[pu] < rank[pv])
        {
            parent[pu] = pv;
        }
        else if (rank[pv] < rank[pu])
        {
            parent[pv] = pu;
        }
        else
        {
            parent[pv] = pu;
            rank[pu]++;
        }
    }
};

class Solution
{
public:
    vector<int> findRedundantConnection(vector<vector<int>> &edges)
    {
        int n = edges.size();
        DisjointSet graph(n);
        vector<int> result;

        for (auto &edge : edges)
        {
            int u = edge[0], v = edge[1];
            if (graph.find(u) == graph.find(v))
            {
                result.push_back(u);
                result.push_back(v);
            }
            else
            {
                graph.unionRnk(u, v);
            }
        }

        return result;
    }
};