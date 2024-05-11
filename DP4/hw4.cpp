#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(int i, int j, vector<vector<int>> &mat, vector<vector<int>> dp)
    {

        if (i <= mat.size() - 1 && j <= mat[0].size() - 1 && mat[i][j] == 1)
            return 0;

        if (i == mat.size() - 1 && j == mat[0].size() - 1)
            return dp[i][j] = 1;

        if (i > mat.size() - 1 || j > mat[0].size() - 1)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        int l = solve(i + 1, j, mat, dp);
        int r = solve(i, j + 1, mat, dp);

        return l + r;
    }
    int uniquePathsWithObstacles(vector<vector<int>> &mat)
    {
        int m = mat.size();
        int n = mat[0].size();
        // vector<vector<int>> dp(m , vector<int>(n,-1));
        // return solve(0,0,obstacleGrid,dp);

        int dp[m][n];

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (mat[i][j] == 1)
                    dp[i][j] = 0;

                else if (i == 0 && j == 0)
                    dp[i][j] = 1;

                else
                {
                    int left = 0;
                    int right = 0;
                    if (i > 0)
                        left = dp[i - 1][j];

                    if (j > 0)
                        right = dp[i][j - 1];

                    dp[i][j] = left + right;
                }
            }
        }

        return dp[m - 1][n - 1];
    }
};