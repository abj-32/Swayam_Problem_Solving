#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        int culmul = 1;
        int maxi = INT_MIN;
        for (int i = 0; i < nums.size(); i++)
        {
            culmul = culmul * nums[i];
            maxi = max(culmul, maxi);
            if (culmul == 0)
            {
                culmul = 1;
            }
        }
        culmul = 1;
        for (int i = nums.size() - 1; i >= 0; i--)
        {
            culmul = culmul * nums[i];
            maxi = max(culmul, maxi);
            if (culmul == 0)
            {
                culmul = 1;
            }
        }
        return maxi;
    }
};