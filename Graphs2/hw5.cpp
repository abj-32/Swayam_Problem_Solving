#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void dfs(vector<vector<char>> &grid, vector<vector<bool>> &visited, int r, int c)
    {

        if (r < 0 || c < 0 || r >= grid.size() || c >= grid[0].size())
        {
            return;
        }

        if (visited[r][c] == true)
        {
            return;
        }

        if (grid[r][c] == '0')
        {
            return;
        }

        visited[r][c] = true;

        dfs(grid, visited, r + 1, c);
        dfs(grid, visited, r, c + 1);
        dfs(grid, visited, r - 1, c);
        dfs(grid, visited, r, c - 1);
        //    dfs(grid,visited,r-1,c-1);
        //    dfs(grid,visited,r+1,c-1);
        //    dfs(grid,visited,r-1,c+1);
        //    dfs(grid,visited,r+1,c+1);

        return;
    }
    int numIslands(vector<vector<char>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<bool>> visited(m, vector<bool>(n, false));

        int ans = 0;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {

                if (visited[i][j] == false && grid[i][j] == '1')
                {
                    ans++;
                    dfs(grid, visited, i, j);
                }
            }
        }

        return ans;
    }
};