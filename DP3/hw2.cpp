#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(int idx, int amt, vector<int> &coins, vector<vector<int>> &dp)
    {
        if (idx == coins.size() - 1)
        {
            return (amt % coins[idx] == 0);
        }

        if (dp[idx][amt] != -1)
        {
            return dp[idx][amt];
        }

        int not_pick = solve(idx + 1, amt, coins, dp);
        int pick = 0;
        if (coins[idx] <= amt)
        {
            pick = solve(idx, amt - coins[idx], coins, dp);
        }

        return dp[idx][amt] = pick + not_pick;
    }
    int change(int amount, vector<int> &coins)
    {
        int n = coins.size();
        vector<vector<int>> dp(n + 1, vector<int>(amount + 1, -1));

        // int sum=0;
        // for(int i=0;i<n;i++)
        // {
        //     sum=sum+coins[i];
        // }

        return solve(0, amount, coins, dp);
    }
};