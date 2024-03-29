#include <bits/stdc++.h>
using namespace std;

int heightOfBinaryTree(TreeNode<int> *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int left = heightOfBinaryTree(root->left);
    int right = heightOfBinaryTree(root->right);

    int ans = max(left, right) + 1;
    return ans;
}