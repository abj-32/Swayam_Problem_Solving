#include <bits/stdc++.h>
using namespace std;

class Codec
{
public:
    void preorder(TreeNode *root, string &code)
    {
        if (root == NULL)
        {
            code = code + "#,";
            return;
        }

        code = code + to_string(root->val);
        code = code + ",";
        preorder(root->left, code);
        preorder(root->right, code);

        return;
    }
    string serialize(TreeNode *root)
    {
        string code = "";
        preorder(root, code);

        return code;
    }

    TreeNode *treee(queue<string> &q)
    {
        string st = q.front();
        q.pop();

        if (st == "#")
        {
            return NULL;
        }

        int k = stoi(st);
        TreeNode *root = new TreeNode(k);
        root->left = treee(q);
        root->right = treee(q);

        return root;
    }

    TreeNode *deserialize(string data)
    {
        string temp = "";

        queue<string> q;

        for (auto it : data)
        {
            if (it == ',')
            {
                q.push(temp);
                temp = "";
            }
            else
            {
                temp = temp + it;
            }
        }

        TreeNode *ans = treee(q);

        return ans;
    }
};