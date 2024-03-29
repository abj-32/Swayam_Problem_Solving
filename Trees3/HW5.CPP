#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string s1 = "";
    string s2 = "";
    TreeNode* lowestCA(TreeNode* root, int x, int y){
        if(root==NULL) 
        return NULL;
        if(root->val == x || root->val == y) 
        return root;

        TreeNode* left = lowestCA(root->left,x,y);
        TreeNode* right = lowestCA(root->right,x,y);

        if(left && right) return root;
        return left ? left : right;
    }


    bool toLCA(TreeNode* root, string &curr, int x){
        if(root==NULL) 
        return false;

        if(root->val == x){
            s1 = curr;
            return true;
        }
        curr =curr+ "U";

        if(toLCA(root->left,curr,x)) 
        return true;

        if(toLCA(root->right,curr,x)) 
        return true;

        curr.pop_back();

        return false;
    }

    bool fromLCA(TreeNode* root, string &curr, int x){
        if(root==NULL) return false;
        if(root->val == x){
            s2 = curr;
            return true;
        }

        curr =curr+"L";
        if(fromLCA(root->left,curr,x)) 
        return true;

        curr.pop_back();

        curr+="R";
        if(fromLCA(root->right,curr,x)) 
        return true;

        curr.pop_back();

        return false;
    }
    string getDirections(TreeNode* root, int startValue, int destValue) {

        TreeNode* lca = lowestCA(root,startValue,destValue);

        string curr1 = "";
        string curr2 = "";

        toLCA(lca,curr1,startValue);
        fromLCA(lca,curr2,destValue);

        return s1 + s2;
    }
};