#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // bool search(TreeNode* root,TreeNode* curr, int k){
    //     if(root==NULL){
    //         return false;
    //     }

    //     if(root->val==k && curr!=root){
    //         return true;
    //     }

    //     if(k > root->val){
    //         return search(root->right,curr,k);
    //     }

    //     if(k< root->val){
    //          return search(root->left,curr,k);
    //     }

    //     return false;

    // }

    bool findTarget(TreeNode *root, int k)
    {

        if (root == NULL)
        {
            return false;
        }
        set<int> st;
        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty())
        {

            TreeNode *temp = q.front();
            q.pop();

            if (st.count(k - temp->val))
            {
                return true;
            }

            st.insert(temp->val);

            if (temp->left != NULL)
            {
                q.push(temp->left);
            }

            if (temp->right != NULL)
            {
                q.push(temp->right);
            }
        }

        return false;
    }
};