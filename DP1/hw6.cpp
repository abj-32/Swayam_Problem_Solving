#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int robbery(vector<int> &arr)
    {
        int k = arr.size();
        int prev = arr[0];
        int prev2 = 0;

        for (int i = 1; i < k; i++)
        {
            int take = arr[i];
            if (i > 1)
                take += prev2;

            int not_take = 0 + prev;

            int curr = max(take, not_take);
            prev2 = prev;
            prev = curr;
        }

        return prev;
    }
    int rob(vector<int> &nums)
    {

        int n = nums.size();
        vector<int> temp1, temp2;
        if (n == 1)
        {
            return nums[0];
        }

        if (n == 2)
        {
            return max(nums[0], nums[1]);
        }

        for (int i = 0; i < n; i++)
        {
            if (i != n - 1)
            {
                temp1.push_back(nums[i]);
            }

            if (i != 0)
            {
                temp2.push_back(nums[i]);
            }
        }

        return max(robbery(temp1), robbery(temp2));
    }
};