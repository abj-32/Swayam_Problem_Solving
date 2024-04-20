#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> nearest(vector<vector<int>> grid)
    {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> visited(m, vector<int>(n, 0));
        vector<vector<int>> ans(m, vector<int>(n, 0));

        queue<pair<pair<int, int>, int>> q;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                {
                    q.push({{i, j}, 0});
                    visited[i][j] = 1;
                }

                else
                {
                    visited[i][j] = 0;
                }
            }
        }

        // vector<vector<int>>dir={{-1,0},{0,+1},{+1,0},{0,-1}};
        int dirR[] = {-1, 0, +1, 0};
        int dirC[] = {0, +1, 0, -1};

        while (!q.empty())
        {
            int x = q.front().first.first;
            int y = q.front().first.second;
            int dist = q.front().second;
            q.pop();
            ans[x][y] = dist;

            for (int i = 0; i < 4; i++)
            {

                int nx = x + dirR[i];
                int ny = y + dirC[i];

                if (nx >= 0 && ny >= 0 && nx < m && ny < n && visited[nx][ny] == 0 && grid[nx][ny] == 0)
                {
                    visited[nx][ny] = 1;
                    q.push({{nx, ny}, dist + 1});
                }
            }
        }

        return ans;
    }
};
