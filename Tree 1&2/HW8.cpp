#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> topView(Node *root)
    {
        vector<int> ans;
        if (root == NULL)
        {
            return ans;
        }

        queue<pair<Node *, int>> q;
        map<int, int> mpp;

        q.push({root, 0});

        while (!q.empty())
        {
            auto it = q.front();
            q.pop();

            Node *temp = it.first;
            int line = it.second;

            if (mpp.count(line) == 0)
            {
                mpp[line] = temp->data;
            }

            if (temp->left != NULL)
            {
                q.push({temp->left, line - 1});
            }

            if (temp->right != NULL)
            {
                q.push({temp->right, line + 1});
            }
        }

        for (auto it : mpp)
        {
            ans.push_back(it.second);
        }

        return ans;
    }
};