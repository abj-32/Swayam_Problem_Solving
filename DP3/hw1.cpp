#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
int solve(int idx,int tgt,vector<int>&coins,vector<vector<int>>&dp)
{
    if(idx==coins.size()-1)
    {
        if(tgt%coins[idx]==0)
        {
            return dp[idx][tgt]=tgt/coins[idx];
        }

        return dp[idx][tgt]=1e9;
    }
    if(tgt==0)
    {
        return 0;
    }

    if(dp[idx][tgt]!=-1)
    {
        return dp[idx][tgt];
    }

    int not_pick=0+solve(idx+1,tgt,coins,dp);
    int pick=1e9;
    if(coins[idx]<=tgt)
    {
        pick=1+solve(idx,tgt-coins[idx],coins,dp);
    }

    return dp[idx][tgt]=min(pick,not_pick);
}
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        int ans=0;
        vector<vector<int>>dp(n+1,vector<int>(amount+1,-1));
        ans=solve(0,amount,coins,dp);
        if(ans>=1e9)
        {
            return -1;
        }

        return ans;
    }
};
