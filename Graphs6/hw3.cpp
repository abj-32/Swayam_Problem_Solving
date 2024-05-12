#include <bits/stdc++.h>
using namespace std;

class DisjointSet
{
public:
    vector<int> rank, parent, size;
    DisjointSet(int n)
    {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int find(int node)
    {
        if (node == parent[node])
            return node;
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

vector<int> findRedundantDirectedConnection(vector<vector<int>> &edges)
{

    int n = edges.size();

    DisjointSet dsu(n + 1);

    vector<int> path(n + 1, -1);

    int x = 0;
    int y = -1;
    for (int i = 0; i < n; i++)
    {
        if (path[edges[i][1]] != -1)
        {
            x = path[edges[i][1]];
            y = i;
            break;
        }
        path[edges[i][1]] = i;
    }

    for (int j = 0; j < n; j++)
    {
        if (j == y)
            continue;

        int pu = dsu.find(edges[j][0]);
        int pv = dsu.find(edges[j][1]);
        if (pu == pv)
        {
            if (y == -1)
                return edges[j];
            return edges[x];
        }
        dsu.unionRnk(pu, pv);
    }
    return edges[y];
}