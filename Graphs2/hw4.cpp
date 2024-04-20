#include <bits/stdc++.h>
using namespace std;

// #include "solution.h"
vector<vector<int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {-1, -1}, {1, -1}, {-1, 1}, {1, 1}};
bool insideCircle(int i, int j, int N, int r, vector<int> &cx, vector<int> &cy)
{
    for (int i = 0; i < N; i++)
    {
        int dx = abs(i - cx[i]);
        int dy = abs(j - cy[i]);

        int dis = dx * dx + dy * dy;
        if (dis <= r * r)
        {
            return false;
            break;
        }
    }

    return true;
}

bool dfs(int i, int j, int x, int y, int N, int r, vector<int> &cx, vector<int> &cy, vector<vector<bool>> &visited)
{
    if (i < 0 || j < 0 || i > x || j > y)
    {
        return false;
    }

    visited[i][j] = true;

    if (i == x && j == y)
    {
        return true;
    }

    if (insideCircle(i, j, N, r, cx, cy) == true)
    {
        return false;
    }

    for (auto it : dir)
    {
        int newi = i + it[0];
        int newj = j + it[1];

        if (visited[newi][newj] == false)
        {
            if (dfs(newi, newj, x, y, N, r, cx, cy, visited) == true)
            {
                return true;
            }
        }
    }

    return false;
}

string Solution::solve(int x, int y, int N, int r, vector<int> &cx, vector<int> &cy)
{
    vector<vector<bool>> visited(x + 1, vector<bool>(y + 1, false));

    if (dfs(0, 0, x, y, N, r, cx, cy, visited) == true)
    {
        return "YES";
    }

    return "NO";
}
