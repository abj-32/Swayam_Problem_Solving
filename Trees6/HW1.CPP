#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    TreeNode *prev = nullptr, *first = nullptr, *sec = nullptr;
    void inordertrav(TreeNode *cur)
    {
        if (cur == NULL)
        {
            return;
        }
        inordertrav(cur->left);
        if (prev != NULL && cur->val < prev->val)
        {
            if (first == nullptr)
            {
                first = prev;
            }
            sec = cur;
        }
        prev = cur;
        inordertrav(cur->right);
    }
    void recoverTree(TreeNode *root)
    {
        inordertrav(root);
        int temp1 = first->val;
        int temp2 = sec->val;
        first->val = temp2;
        sec->val = temp1;
    }
};