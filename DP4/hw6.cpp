#include<bits/stdc++.h>
using namespace std;

class Solution {
public: 
    int solve(int i,int j,vector<vector<int>> &dp,vector<vector<int>> &grid)
    {
        if(i==0 && j==0 )
        {
            return dp[i][j]=grid[i][j];
        }

        if(i<0 || j<0)
        {
            return INT_MAX;
        }

        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }

        int down=solve(i-1,j,dp,grid);
        int right=solve(i,j-1,dp,grid);

        return dp[i][j]=grid[i][j]+min(down,right);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        //return solve(m-1,n-1,dp,grid);

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==0 && j==0)
                {
                    dp[i][j]=grid[0][0];
                }

                else{
                    int down=grid[i][j];
                    int right=grid[i][j];

                    if(i>0)
                    down+=dp[i-1][j];
                    else down+=100000;

                    if(j>0)
                    right+=dp[i][j-1];
                    else
                    right+=100000;


                    dp[i][j]=min(down,right);
                }
            }
        }

        return dp[m-1][n-1];
    }
};