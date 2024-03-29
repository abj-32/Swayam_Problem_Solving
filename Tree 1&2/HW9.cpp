#include <bits/stdc++.h>
usimg namespace std;

class Solution
{
public:
    int findBottomLeftValue(TreeNode *root)
    {

        queue<TreeNode *> q;

        q.push(root);
        TreeNode *node = root;

        while (!q.empty())
        {
            node = q.front();
            q.pop();

            if (node->right != NULL)
            {
                q.push(node->right);
            }
            if (node->left != NULL)
            {
                q.push(node->left);
            }
        }

        return node->val;
    }
};