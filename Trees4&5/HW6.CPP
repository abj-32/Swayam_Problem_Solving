#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void traverse(Node *root, set<int> &st)
    {
        if (root == NULL)
        {
            return;
        }

        traverse(root->left, st);
        st.insert(root->data);
        traverse(root->right, st);

        return;
    }
    vector<int> findCommon(Node *root1, Node *root2)
    {
        set<int> bst1;
        set<int> bst2;

        traverse(root1, bst1);
        traverse(root2, bst2);

        vector<int> ans;
        for (auto it : bst1)
        {
            if (bst2.count(it) != 0)
            {
                ans.push_back(it);
            }
        }

        return ans;
    }
};