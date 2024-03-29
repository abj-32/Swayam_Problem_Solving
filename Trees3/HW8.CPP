class Solution
{
public:
    void inversion(TreeNode *root)
    {
        if (root == NULL)
        {
            return;
        }

        swap(root->left, root->right);
        inversion(root->left);
        inversion(root->right);
    }
    TreeNode *invertTree(TreeNode *root)
    {
        inversion(root);
        return root;
    }
};