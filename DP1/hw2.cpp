#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int jump(vector<int> &nums)
    {
        int n = nums.size();
        int cnt = 0;
        int coverage = 0, boundry_idx = 0;

        if (n == 1)
            return 0;

        for (int i = 0; i < n; i++)
        {
            coverage = max(coverage, i + nums[i]);

            if (i == boundry_idx)
            {
                boundry_idx = coverage;
                cnt++;

                if (coverage >= n - 1)
                {
                    return cnt;
                }
            }
        }

        return 0;
    }
};