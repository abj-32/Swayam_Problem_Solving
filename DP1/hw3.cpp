#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int sqrsum(int idx, int n, vector<int> &sqr, vector<vector<int>> &dp)
    {
        if (n == 0)
        {
            return 0;
        }

        if (idx >= sqr.size() || n < 0)
        {
            return 1e7;
        }

        if (dp[idx][n] != -1)
        {
            return dp[idx][n];
        }

        int x = 1 + sqrsum(idx, n - sqr[idx], sqr, dp);
        int y = sqrsum(idx + 1, n, sqr, dp);

        return dp[idx][n] = min(x, y);
    }
    int numSquares(int n)
    {
        vector<int> sqr;
        int i = 1;
        while (i * i <= n)
        {
            sqr.push_back(i * i);
            i++;
        }
        vector<vector<int>> dp(sqr.size() + 1, vector<int>(n + 1, -1));

        // return sqrsum(0,n,sqr,dp);
    }
};