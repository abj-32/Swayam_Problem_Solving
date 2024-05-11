#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(int i, int j, vector<vector<int>> &dp)
    {
        if (i == dp.size() - 1 && j == dp[0].size() - 1)
            return dp[i][j] = 1;

        if (i > dp.size() - 1 || j > dp[0].size() - 1)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        int l = solve(i + 1, j, dp);
        int r = solve(i, j + 1, dp);

        return dp[i][j] = l + r;
    }
    int uniquePaths(int m, int n)
    {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return solve(0, 0, dp);
    }
};