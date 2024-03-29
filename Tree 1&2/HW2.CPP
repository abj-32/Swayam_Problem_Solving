#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    map<pair<int, int>, vector<int>> mpp;
    void blackbox(TreeNode *root, int x, int y)
    {
        if (root == NULL)
            return;

        mpp[{y, x}].push_back(root->val);

        blackbox(root->left, x + 1, y - 1);
        blackbox(root->right, x + 1, y + 1);
    }
    vector<vector<int>> verticalTraversal(TreeNode *root)
    {
        // if(root==NULL) return;

        blackbox(root, 0, 0);
        vector<vector<int>> ans;
        int cordinate = INT_MIN;
        int size = 0;
        for (auto it : mpp)
        {
            sort(it.second.begin(), it.second.end());
            if (it.first.first == cordinate)
            {
                ans[size - 1].insert(ans[size - 1].end(), it.second.begin(), it.second.end());
            }
            else
            {
                ans.push_back(it.second);
                cordinate = it.first.first;
                size++;
            }
        }

        return ans;
    }
};