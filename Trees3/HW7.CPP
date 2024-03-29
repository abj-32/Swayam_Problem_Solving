class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {

        if (root == NULL)
        {
            return NULL;
        }
        if (root == p || root == q)
        {
            return root;
        }

        TreeNode *lft = lowestCommonAncestor(root->left, p, q);
        TreeNode *rght = lowestCommonAncestor(root->right, p, q);

        if (lft && rght)
        {
            return root;
        }

        else if (lft != NULL)
            return lft;

        return rght;
    }
};