#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int m;
    int n;
    bool dfs(vector<vector<int>> &grid, vector<vector<bool>> &visited, int r, int c)
    {
        visited[r][c] = true;

        if (r == m - 1 && c == n - 1)
        {
            return true;
        }

        if (grid[r][c] == 1 && c + 1 < n && (grid[r][c + 1] == 1 || grid[r][c + 1] == 3 || grid[r][c + 1] == 5) && visited[r][c + 1] == false)
        {
            if (dfs(grid, visited, r, c + 1))
            {
                return true;
            }
        }

        if (grid[r][c] == 1 && c - 1 >= 0 && (grid[r][c - 1] == 1 || grid[r][c - 1] == 4 || grid[r][c - 1] == 6) && visited[r][c - 1] == false)
        {
            if (dfs(grid, visited, r, c - 1))
            {
                return true;
            }
        }

        if (grid[r][c] == 2 && r + 1 < m && (grid[r + 1][c] == 2 || grid[r + 1][c] == 5 || grid[r + 1][c] == 6) && visited[r + 1][c] == false)
        {
            if (dfs(grid, visited, r + 1, c))
            {
                return true;
            }
        }

        if (grid[r][c] == 2 && r - 1 >= 0 && (grid[r - 1][c] == 4 || grid[r - 1][c] == 3 || grid[r - 1][c] == 2) && visited[r - 1][c] == false)
        {
            if (dfs(grid, visited, r - 1, c))
            {
                return true;
            }
        }

        if (grid[r][c] == 3 && r + 1 < m && (grid[r + 1][c] == 2 || grid[r + 1][c] == 5 || grid[r + 1][c] == 6) && visited[r + 1][c] == false)
        {
            if (dfs(grid, visited, r + 1, c))
            {
                return true;
            }
        }

        if (grid[r][c] == 3 && c - 1 >= 0 && (grid[r][c - 1] == 1 || grid[r][c - 1] == 4 || grid[r][c - 1] == 6) && visited[r][c - 1] == false)
        {
            if (dfs(grid, visited, r, c - 1))
            {
                return true;
            }
        }

        if (grid[r][c] == 4 && r + 1 < m && (grid[r + 1][c] == 2 || grid[r + 1][c] == 5 || grid[r + 1][c] == 6) && visited[r + 1][c] == false)
        {
            if (dfs(grid, visited, r + 1, c))
            {
                return true;
            }
        }

        if (grid[r][c] == 4 && c + 1 < n && (grid[r][c + 1] == 1 || grid[r][c - 1] == 5 || grid[r][c - 1] == 3) && visited[r + 1][c] == false)
        {
            if (dfs(grid, visited, r, c + 1))
            {
                return true;
            }
        }

        if (grid[r][c] == 5 && r - 1 >= 0 && (grid[r - 1][c] == 2 || grid[r - 1][c] == 3 || grid[r - 1][c] == 4) && visited[r - 1][c] == false)
        {
            if (dfs(grid, visited, r - 1, c))
            {
                return true;
            }
        }

        if (grid[r][c] == 5 && c - 1 >= 0 && (grid[r][c - 1] == 1 || grid[r][c - 1] == 4 || grid[r][c - 1] == 6) && visited[r][c - 1] == false)
        {
            if (dfs(grid, visited, r, c - 1))
            {
                return true;
            }
        }

        if (grid[r][c] == 6 && r + 1 < m && (grid[r + 1][c] == 2 || grid[r + 1][c] == 3 || grid[r + 1][c] == 4) && visited[r + 1][c] == false)
        {
            if (dfs(grid, visited, r + 1, c))
            {
                return true;
            }
        }

        if (grid[r][c] == 6 && c + 1 < n && (grid[r][c + 1] == 1 || grid[r][c + 1] == 5 || grid[r][c + 1] == 3) && visited[r][c + 1] == false)
        {
            if (dfs(grid, visited, r, c + 1))
            {
                return true;
            }
        }

        return false;
    }
    bool hasValidPath(vector<vector<int>> &grid)
    {
        m = grid.size();
        n = grid[0].size();

        vector<vector<bool>> visited(m, vector<bool>(n, false));

        return dfs(grid, visited, 0, 0);
    }
};
