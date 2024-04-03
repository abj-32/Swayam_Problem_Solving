#include <bits/stdc++.h>
using namespace std;

set<int> st;
vector<int> ans;

void leftmost(TreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }

    if (root->left == NULL && root->right == NULL)
    {
        return;
    }

    if (st.count(root->data) == 0)
    {
        ans.push_back(root->data);
        st.insert(root->data);
    }
    if (root->left != NULL)
        leftmost(root->left);
    else if (root->right != NULL)
        leftmost(root->right);

    return;
}

void rightmost(TreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }

    if (root->left == NULL && root->right == NULL)
    {
        return;
    }

    if (root->right != NULL)
        rightmost(root->right);
    else if (root->left != NULL)
        rightmost(root->left);

    if (st.count(root->data) == 0)
    {
        ans.push_back(root->data);
        st.insert(root->data);
    }
}

void leafs(TreeNode<int> *root)
{
    if (root == NULL)
        return;

    if (root->left == NULL && root->right == NULL)
    {
        if (st.count(root->data) == 0)
        {
            ans.push_back(root->data);
            st.insert(root->data);
        }
    }

    leafs(root->left);
    leafs(root->right);
}

vector<int> traverseBoundary(TreeNode<int> *root)
{

    if (root == NULL)
        return {};

    ans.push_back(root->data);

    leftmost(root->left);
    leafs(root);
    rightmost(root->right);

    // for (int i = 0; i < lft.size(); ++i) {
    //     if (st.count(lft[i]) == 0) {
    //         ans.push_back(lft[i]);
    //         st.insert(lft[i]);
    //     }
    // }
    // for (int i = rht.size()-1; i >=0; i--) {
    //     if (st.count(rht[i]) == 0) {
    //         ans.push_back(rht[i]);
    //         st.insert(rht[i]);
    //     }
    // }

    return ans;
}
