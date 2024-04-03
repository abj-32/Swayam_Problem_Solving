#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    TreeNode *blackbox(vector<int> &preorder, int &idx, int low, int high)
    {
        if (idx >= preorder.size())
        {
            return NULL;
        }

        if (preorder[idx] > high || preorder[idx] < low)
        {
            return NULL;
        }

        TreeNode *root = new TreeNode(preorder[idx++]);
        root->left = blackbox(preorder, idx, low, root->val);
        root->right = blackbox(preorder, idx, root->val, high);

        return root;
    }
    TreeNode *bstFromPreorder(vector<int> &preorder)
    {
        int idx = 0;
        int low = INT_MIN;
        int high = INT_MAX;

        return blackbox(preorder, idx, low, high);
    }
};