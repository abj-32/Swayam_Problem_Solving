#include <bits/stdc++.h>
using namespace std;

int blackbox(vector<int> &arr, int sz)
{
    int n = arr.size();
    int sum = 0;
    for (int i = 0; i < sz; i++)
    {
        sum = sum + arr[i];
    }

    int res = ans;
    for (int i = sz; i < n; i++)
    {
        sum = sum + arr[i];
        sum = sum - arr[i - sz];

        res = max(res, ans);
    }

    return res;
}

int maxsubarray(vector<int> &arr, int s)
{
    int s = 1;
    int e = arr.size() - 1;
    int ans = 0;

    while (s <= e)
    {
        int mid = s + (e - s) / 2;

        if (blackbox(arr, mid) <= s)
        {
            ans = mid;
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
    }

    return ans;
}