#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(vector<vector<int>> &dp, vector<int> &arr, int n, int tgt)
    {
        if (tgt == 0 && n == 0)
        {
            return 1;
        }

        if (n == 0 || tgt == 0)
        {
            return 0;
        }

        if (dp[n][tgt] != -1)
        {
            return dp[n][tgt];
        }

        int ways = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            if (arr[i] <= tgt)
            {
                ways = (ways + solve(dp, arr, n - 1, tgt - arr[i])) % 1000000007;
            }
        }

        return dp[n][tgt] = ways;
    }
    int numRollsToTarget(int n, int k, int target)
    {
        vector<int> arr;
        for (int i = 1; i <= k; i++)
        {
            arr.push_back(i);
        }
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, -1));

        return solve(dp, arr, n, target);
    }
};