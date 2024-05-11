#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int lcs(string &s1, string &s2, int i, int j, vector<vector<int>> &dp)
    {

        if (i == s1.size() || j == s2.size())
        {
            return 0;
        }

        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }

        if (s1[i] == s2[j])
        {
            return dp[i][j] = 1 + lcs(s1, s2, i + 1, j + 1, dp);
        }

        return dp[i][j] = max(lcs(s1, s2, i + 1, j, dp), lcs(s1, s2, i, j + 1, dp));
    }
    int longestCommonSubsequence(string text1, string text2)
    {

        if (text1.size() == 0 || text2.size() == 0)
        {
            return 0;
        }

        int n1 = text1.size();
        int n2 = text2.size();

        vector<vector<int>> dp(n1, vector<int>(n2, -1));

        return lcs(text1, text2, 0, 0, dp);
    }
};