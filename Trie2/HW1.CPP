#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int countTriplets(vector<int> &arr)
    {
        int n = arr.size();
        int ans = 0;
        if (n < 2)
        {
            return 0;
        }

        for (int i = 0; i < n - 1; i++)
        {
            int k = arr[i];

            for (int j = i + 1; j < n; j++)
            {
                k = k ^ arr[j];
                if (k == 0)
                {
                    ans += (j - i);
                }
            }
        }

        return ans;
    }
};
