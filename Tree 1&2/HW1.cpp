#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root ==NULL){
            return 0;
        }

        int lft=maxDepth(root->left);
        int rght=maxDepth(root->right);

        int ans=max(lft,rght)+1;
        return ans;
        
    }
};