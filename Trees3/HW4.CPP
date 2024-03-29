#include <bits/stdc++.h>
using namespace std;

bool blackbox(TreeNode *root, int b, std::vector<int> &ans)
{

    if (root == NULL)
    {
        return false;
    }

    ans.push_back(root->val);

    if (root->val == b)
    {
        return true;
    }

    if (blackbox(root->left, b, ans) || blackbox(root->right, b, ans))
    {
        return true;
    }

    ans.pop_back();

    return false;
}
vector<int> Solution::solve(TreeNode *A, int B)
{
    std::vector<int> ans;
    blackbox(A, B, ans);

    return ans;
}