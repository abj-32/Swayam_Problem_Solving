#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int sum;
    void summation(TreeNode *root, int low, int high, int &sum)
    {
        if (root == NULL)
        {
            return;
        }

        summation(root->left, low, high, sum);

        if (root->val >= low && root->val <= high)
        {
            sum = sum + root->val;
        }

        summation(root->right, low, high, sum);

        return;
    }
    int rangeSumBST(TreeNode *root, int low, int high)
    {
        sum = 0;
        summation(root, low, high, sum);
        return sum;
    }
};