#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int orangesRotting(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<bool>> visited(m, vector<bool>(n, false));

        queue<pair<pair<int, int>, int>> q;

        int ones = 0;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 2)
                {
                    q.push({{i, j}, 0});
                    visited[i][j] = true;
                }

                if (grid[i][j] == 1)
                {
                    ones++;
                }
            }
        }

        int ans = 0;

        vector<vector<int>> dir = {{-1, 0}, {+1, 0}, {0, -1}, {0, 1}};

        while (!q.empty())
        {
            int x = q.front().first.first;
            int y = q.front().first.second;
            int time = q.front().second;
            ans = max(ans, time);
            q.pop();

            for (auto it : dir)
            {
                int nx = x + it[0];
                int ny = y + it[1];

                if (nx >= 0 && ny >= 0 && nx < m && ny < n && visited[nx][ny] == false && grid[nx][ny] == 1)
                {
                    visited[nx][ny] = true;
                    q.push({{nx, ny}, time + 1});
                    ones--;
                }
            }
        }

        if (ones != 0)
        {
            return -1;
        }

        return ans;
    }
};