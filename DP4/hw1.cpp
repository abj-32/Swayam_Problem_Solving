#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // int ans=0;
    int lensub(vector<int> &nums, int i, int tgt, vector<vector<int>> &dp)
    {

        if (tgt == 0)
        {
            return 0;
        }
        if (i >= nums.size())
        {
            return -1 * 1e7;
        }

        if (dp[i][tgt] != -1)
        {
            return dp[i][tgt];
        }

        if (nums[i] <= tgt)
        {
            return dp[i][tgt] = max(1 + lensub(nums, i + 1, tgt - nums[i], dp), lensub(nums, i + 1, tgt, dp));
        }

        return dp[i][tgt] = lensub(nums, i + 1, tgt, dp);
    }
    int lengthOfLongestSubsequence(vector<int> &nums, int target)
    {
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, -1));
        int ans = lensub(nums, 0, target, dp);
        if (ans <= 0)
        {
            return -1;
        }

        return ans;
    }
};