#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int lis(vector<int> &nums, int idx, int previdx, vector<vector<int>> &dp)
    {

        if (idx == nums.size())
        {
            return 0;
        }

        if (previdx == -1)
        {
            int x = 1 + lis(nums, idx + 1, idx, dp);
            int y = lis(nums, idx + 1, previdx, dp);

            return max(x, y);
        }

        if (dp[idx][previdx] != -1)
        {
            return dp[idx][previdx];
        }

        int take = 0;
        if (nums[idx] > nums[previdx])
        {
            take = 1 + lis(nums, idx + 1, idx, dp);
        }

        int not_take = lis(nums, idx + 1, previdx, dp);

        return dp[idx][previdx] = max(take, not_take);
    }
    int lengthOfLIS(vector<int> &nums)
    {

        int n = nums.size();
        // vector<vector<int>> dp(n,vector<int>(n,-1));
        // int previdx=-1;
        int ans = 1;
        // return lis(nums,0,previdx,dp);

        vector<int> dp1D(n, 0);
        dp1D[0] = 1;

        for (int i = 1; i < n; i++)
        {

            int maxprevLis = 0;

            for (int j = 0; j <= i - 1; j++)
            {

                if (nums[i] > nums[j])
                {
                    maxprevLis = max(maxprevLis, dp1D[j]);
                }
            }

            dp1D[i] = maxprevLis + 1;
            ans = max(ans, dp1D[i]);
        }

        return ans;
    }
};