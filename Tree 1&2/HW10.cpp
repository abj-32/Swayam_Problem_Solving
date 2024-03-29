#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // map<int,int> mpp;
    // void traverse(Node* root,int level){
    //     if(root==NULL) return;

    //     mpp[level]=root->data;
    //     traverse(root->left,level-1);
    //     traverse(root->right,level+1);

    //     return;
    // }
    vector<int> bottomView(Node *root)
    {
        vector<int> ans;
        if (root == NULL)
            return ans;
        map<int, int> mpp;
        traverse(root, 0);
        queue<pair<Node *, int>> q;
        q.push({root, 0});
        while (!q.empty())
        {
            auto it = q.front();
            q.pop();
            Node *temp = it.first;
            int line = it.second;
            mpp[line] = node->data;

            if (node->left != NULL)
            {
                q.push({node->left, line - 1});
            }
            if (node->right != NULL)
            {
                q.push({node->right, line + 1});
            }
        }

        for (auto it : mpp)
        {
            ans.push_back(it.second);
        }
        return ans;
    }
};