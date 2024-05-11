#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int ways(string str, int idx, vector<int> &dp)
    {
        if (idx == str.size())
        {
            return 1;
        }

        if (str[idx] == '0')
        {
            return 0;
        }

        if (idx == str.size() - 1)
        {
            return 1;
        }

        if (dp[idx] != -1)
        {
            return dp[idx];
        }

        int ans = ways(str, idx + 1, dp);

        if ((10 * (str[idx] - '0') + str[idx + 1] - '0') <= 26)
        {
            ans += ways(str, idx + 2, dp);
        }

        return dp[idx] = ans;
        // return ans;
    }
    int numDecodings(string s)
    {
        int n = s.size();
        vector<int> dp(n + 1, -1);
        return ways(s, 0, dp);

        return dp[n];
    }
};