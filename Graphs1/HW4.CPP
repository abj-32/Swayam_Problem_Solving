#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>> &edges)
    {
        set<int> st;
        int sz = edges.size();

        for (int i = 0; i < sz; i++)
        {
            st.insert(edges[i][1]);
        }

        vector<int> ans;

        for (int i = 0; i < n; i++)
        {
            if (st.count(i) == 0)
            {
                ans.push_back(i);
            }
        }

        return ans;
    }
};