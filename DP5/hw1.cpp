#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int calculateMinimumHP(vector<vector<int>> &dungeon)
    {
        int n = dungeon.size();
        int m = dungeon[0].size();

        vector<vector<int>> dp(n, vector<int>(m, -1));

        if (dungeon[n - 1][m - 1] <= 0)
        {
            dp[n - 1][m - 1] = abs(dungeon[n - 1][m - 1]) + 1;
        }
        else
        {
            dp[n - 1][m - 1] = 1;
        }

        for (int i = n - 1; i >= 0; i--)
        {

            for (int j = m - 1; j >= 0; j--)
            {

                if (i == n - 1 && j == m - 1)
                {
                    continue;
                }

                int x = INT_MAX;
                int y = INT_MAX;
                if (i + 1 < n)
                {
                    x = dp[i + 1][j];
                }
                if (j + 1 < m)
                {
                    y = dp[i][j + 1];
                }

                if (dungeon[i][j] <= 0)
                {
                    dp[i][j] = abs(dungeon[i][j]) + min(x, y);
                }
                else
                {
                    dp[i][j] = max(1, min(x, y) - dungeon[i][j]);
                }
            }
        }

        return dp[0][0];
    }
};