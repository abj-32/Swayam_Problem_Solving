#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> value;
    void inorder(TreeNode *root)
    {
        if (root == NULL)
        {
            return;
        }

        inorder(root->left);

        value.push_back(root->val);

        inorder(root->right);
    }

    void solve(TreeNode *root, int &count, int &k, int &ans)
    {
        if (root == NULL)
        {
            return;
        }

        solve(root->left, count, k, ans);
        count++;
        if (count == k)
        {
            ans = root->val;
            return;
        }

        solve(root->right, count, k, ans);
    }
    int kthSmallest(TreeNode *root, int k)
    {
        // inorder(root);
        // return value[k-1];

        int count = 0;
        int ans = 0;
        solve(root, count, k, ans);

        return ans;
    }
};