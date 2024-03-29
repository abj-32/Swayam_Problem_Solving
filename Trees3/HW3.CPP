class Solution
{
public:
    vector<string> ans;
    void blackbox(TreeNode *root, string temp)
    {

        if (root == NULL)
        {
            return;
        }
        if (root->left == NULL && root->right == NULL)
        {
            temp = temp + to_string(root->val);
            ans.push_back(temp);
            return;
        }
        string d = to_string(root->val) + "->";
        blackbox(root->left, temp + d);
        blackbox(root->right, temp + d);

        return;
    }
    vector<string> binaryTreePaths(TreeNode *root)
    {
        if (root == NULL)
        {
            return ans;
        }

        string t = "";
        blackbox(root, t);

        return ans;
    }
};