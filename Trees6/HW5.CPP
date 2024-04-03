#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (root == NULL)
        {
            return root;
        }

        if (root == p || root == q)
        {
            return root;
        }

        if (root != NULL && (root->val < p->val && root->val < q->val))
        {
            return lowestCommonAncestor(root->right, p, q);
        }

        else if (root != NULL && (root->val > p->val && root->val > q->val))
        {
            return lowestCommonAncestor(root->left, p, q);
        }
        else
        {
            return root;
        }
    }
};