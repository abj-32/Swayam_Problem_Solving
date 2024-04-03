#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    Node *prev = NULL;
    Node *head = NULL;

    void inorderLL(Node *root)
    {
        if (root == NULL)
        {
            return;
        }

        inorderLL(root->left);
        if (head == NULL)
        {
            head = root;
        }
        else
        {
            root->left = prev;
            prev->right = root;
        }
        prev = root;
        inorderLL(root->right);

        return;
    }

    Node *bTreeToCList(Node *root)
    {
        // if(root==NULL){
        //     return root;
        // }

        inorderLL(root);

        head->left = prev;
        prev->right = head;

        return head;
    }
};