#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int ans = 0;
    int blackbox(TreeNode *root, int targetSum, long long curr)
    {
        if (root == NULL)
        {
            return 0;
        }

        curr = curr + root->val;

        if (curr == targetSum)
        {
            return 1 + blackbox(root->left, targetSum, curr) + blackbox(root->right, targetSum, curr);
        }
        return blackbox(root->left, targetSum, curr) + blackbox(root->right, targetSum, curr);
    }

    void traverse(TreeNode *root, int targetSum)
    {
        if (root == NULL)
            return;
        ans = ans + blackbox(root, targetSum, 0);
        pathSum(root->left, targetSum);
        pathSum(root->right, targetSum);
    }

    int pathSum(TreeNode *root, int targetSum)
    {
        if (root == NULL)
            return 0;
        traverse(root, targetSum);
        return ans;
    }
};