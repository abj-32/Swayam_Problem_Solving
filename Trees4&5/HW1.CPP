#include<bits/stdc++.h>
using namespace std;


struct TreeNode {
    int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    bool validation(TreeNode* root, long long int lb,long long int ub)
    {
        if(root==NULL)
        {
            return true;
        }

        bool cond=(root->val < ub && root->val > lb);
        bool lft=validation(root->left,lb,root->val);
        bool rght=validation(root->right,root->val,ub);

         if(lft && rght && cond)
        {
            return true;
        }

        return false;

    }
public:
    bool isValidBST(TreeNode* root) {
        long long int upperbound=2147483648;
        long long int lowerbound=-2147483649;

        return validation(root,lowerbound,upperbound);
    }
};