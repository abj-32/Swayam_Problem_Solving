#include <bits/stdc++.h>
using namespace std;

bool hasOnlyOneChild(vector<int> pre, int size)
{
    int nxtdf, prevdf;

    for (int i = 0; i < size - 1; i++)
    {
        nxtdf = pre[i] - pre[i + 1];
        prevdf = pre[i] - pre[size - 1];
        if (nxtdf * prevdf < 0)
            return false;
        ;
    }
    return true;
}