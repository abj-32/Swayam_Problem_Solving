#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minimumEffortPath(vector<vector<int>> &heights)
    {
        int m = heights.size();
        int n = heights[0].size();

        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

        dist[0][0] = 0;
        pq.push({0, {0, 0}});

        vector<vector<int>> dir = {{-1, 0}, {0, +1}, {1, 0}, {0, -1}};

        while (!pq.empty())
        {

            int diff = pq.top().first;
            int r = pq.top().second.first;
            int c = pq.top().second.second;
            pq.pop();

            if (r == m - 1 && c == n - 1)
            {
                return diff;
            }

            for (auto it : dir)
            {
                int nrow = r + it[0];
                int ncol = c + it[1];

                if (nrow >= 0 && ncol >= 0 && nrow < m && ncol < n)
                {

                    int newdiff = max(abs(heights[r][c] - heights[nrow][ncol]), diff);

                    if (newdiff < dist[nrow][ncol])
                    {
                        dist[nrow][ncol] = newdiff;
                        pq.push({newdiff, {nrow, ncol}});
                    }
                }
            }
        }

        return 0;
    }
};