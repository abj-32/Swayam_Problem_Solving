class Solution
{
public:
    vector<int> ans;
    void rightTraverse(TreeNode *root, int level)
    {
        if (root == NULL)
        {
            return;
        }

        if (level == ans.size())
        {
            ans.push_back(root->val);
        }
        rightTraverse(root->right, level + 1);
        rightTraverse(root->left, level + 1);
    }
    vector<int> rightSideView(TreeNode *root)
    {

        if (root == NULL)
        {
            return ans;
        }

        rightTraverse(root, 0);

        // for(auto it:st)
        // {
        //     ans.push_back(it);
        // }

        return ans;
    }
};