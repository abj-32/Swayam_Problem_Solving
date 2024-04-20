#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void dfs(vector<vector<char>> &board, vector<vector<bool>> &visited, int r, int c)
    {

        if (r < 0 || c < 0 || r >= board.size() || c >= board[0].size() || visited[r][c] == true || board[r][c] == 'X')
        {
            return;
        }

        visited[r][c] = true;

        dfs(board, visited, r + 1, c);
        dfs(board, visited, r, c + 1);
        dfs(board, visited, r - 1, c);
        dfs(board, visited, r, c - 1);
    }
    void solve(vector<vector<char>> &board)
    {
        int m = board.size();
        int n = board[0].size();

        vector<vector<bool>> visited(m, vector<bool>(n, false));

        for (int i = 0; i < m; i++)
        {

            if (board[i][0] == 'O' && visited[i][0] == false)
            {
                dfs(board, visited, i, 0);
            }

            if (board[i][n - 1] == 'O' && visited[i][n - 1] == false)
            {
                dfs(board, visited, i, n - 1);
            }
        }

        for (int i = 0; i < n; i++)
        {

            if (board[0][i] == 'O' && visited[0][i] == false)
            {
                dfs(board, visited, 0, i);
            }

            if (board[m - 1][i] == 'O' && visited[m - 1][i] == false)
            {
                dfs(board, visited, m - 1, i);
            }
        }

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (visited[i][j] == false && board[i][j] == 'O')
                {
                    board[i][j] = 'X';
                }
            }
        }
    }
};