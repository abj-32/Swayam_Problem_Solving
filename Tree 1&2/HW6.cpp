#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        if (p == NULL && q == NULL)
        {
            return true;
        }

        if (p != NULL && q == NULL)
        {
            return false;
        }

        if (p == NULL && q != NULL)
        {
            return false;
        }

        bool left = isSameTree(p->left, q->left);
        bool rght = isSameTree(p->right, q->right);

        bool diff = (p->val == q->val);

        if (left && rght && diff)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};