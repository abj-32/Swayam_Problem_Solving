#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int largestPathValue(string colors, vector<vector<int>> &edges)
    {
        int n = colors.size();
        vector<vector<int>> adj(n, vector<int>());
        vector<int> indegree(n, 0);

        for (auto it : edges)
        {
            adj[it[0]].push_back(it[1]);
            indegree[it[1]]++;
        }

        queue<int> q;
        vector<vector<int>> dp(n, vector<int>(26, 0));
        for (int i = 0; i < n; i++)
        {
            if (indegree[i] == 0)
            {
                q.push(i);
                dp[i][colors[i] - 'a'] = 1;
            }
        }

        int flag = 0;
        int ans = 0;

        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            flag++;

            ans = max(ans, dp[node][colors[node] - 'a']);

            for (auto ngh : adj[node])
            {

                for (int j = 0; j < 26; j++)
                {
                    dp[ngh][j] = max(dp[ngh][j], dp[node][j] + (colors[ngh] - 'a' == j));
                }

                indegree[ngh]--;
                if (indegree[ngh] == 0)
                {
                    q.push(ngh);
                }
            }
        }

        if (flag < n)
        {
            return -1;
        }

        return ans;
    }
};