#include <bits/stdc++.h>
using namespace std;

int Solution::knight(int A, int B, int C, int D, int E, int F)
{

    vector<vector<int>> grid(A + 1, vector<int>(B + 1));
    vector<vector<bool>> visited(A + 1, vector<bool>(B + 1, false));

    queue<pair<pair<int, int>, int>> q;

    q.push({{C, D}, 0});
    visited[C][D] = true;

    vector<vector<int>> dir{{-2, -1}, {-2, 1}, {2, -1}, {2, 1}, {-1, 2}, {-1, -2}, {1, 2}, {1, -2}};

    while (!q.empty())
    {

        int x = q.front().first.first;
        int y = q.front().first.second;
        int dis = q.front().second;
        q.pop();

        if (x == E && y == F)
        {
            return dis;
        }

        for (auto it : dir)
        {
            int nx = x + it[0];
            int ny = y + it[1];

            if (nx >= 1 && ny >= 1 && nx <= A && ny <= B && visited[nx][ny] == false)
            {
                visited[nx][ny] = true;
                q.push({{nx, ny}, dis + 1});
            }
        }
    }

    return -1;
}
