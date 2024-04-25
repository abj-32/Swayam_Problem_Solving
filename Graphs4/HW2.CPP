#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isBipartite(vector<vector<int>> &graph)
    {
        int n = graph.size();
        vector<int> color(n + 1, -1);

        for (int i = 0; i < n; i++)
        {
            if (color[i] != -1)
            {
                continue;
            }

            else if (isCMP_BP(i, graph, color) == false)
            {
                return false;
            }
        }

        return true;
    }

    bool isCMP_BP(int src, vector<vector<int>> &graph, vector<int> &color)
    {
        queue<int> q;
        q.push(src);
        color[src] = 1;

        while (!q.empty())
        {
            int node = q.front();
            q.pop();

            for (auto ngh : graph[node])
            {
                if (color[ngh] == -1)
                {
                    color[ngh] = !color[node];
                    q.push(ngh);
                }

                else if (color[ngh] != !color[node])
                {
                    return false;
                }
            }
        }

        return true;
    }
};