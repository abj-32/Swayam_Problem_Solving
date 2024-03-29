#include<bits/stdc++.h>
using namespace std;


vector<int> ans;
void leftview(BinaryTreeNode<int>* root,int level){
    if(root==NULL) return;

    if(level==ans.size()){
        ans.push_back(root->data);
    }

    leftview(root->left,level+1);
    leftview(root->right,level+1);

    return ;
}


vector<int> printLeftView(BinaryTreeNode<int>* root) {
   leftview(root,0);
   return ans;
}