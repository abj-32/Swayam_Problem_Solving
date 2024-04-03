#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};
class nodeinfo
{
public:
    bool isbst;
    int min_elmnt;
    int max_elmnt;
    int size;

    nodeinfo() {}
    nodeinfo(bool isbst, int min_elmnt, int max_elmnt, int size)
    {
        this->isbst = isbst;
        this->min_elmnt = min_elmnt;
        this->max_elmnt = max_elmnt;
        this->size = size;
    }
};
class Solution
{
public:
    nodeinfo *lrgstbst(Node *root)
    {
        if (root == NULL)
        {
            // nodeinfo* temp=new nodeinfo();
            // temp.isbst=true;
            // temp->min_elmnt=INT_MAX;
            // temp->max_elmnt=INT_MIN;
            // temp->size=0;
            return new nodeinfo(true, INT_MAX, INT_MIN, 0);
        }

        nodeinfo *lftsubt = lrgstbst(root->left);
        nodeinfo *rghtsubt = lrgstbst(root->right);

        nodeinfo *root_info = new nodeinfo();

        root_info->isbst = (lftsubt->isbst && rghtsubt->isbst && (root->data > lftsubt->max_elmnt) && (root->data < rghtsubt->min_elmnt));

        root_info->min_elmnt = min(lftsubt->min_elmnt, root->data);
        root_info->max_elmnt = max(rghtsubt->max_elmnt, root->data);

        if (root_info->isbst)
        {
            root_info->size = lftsubt->size + rghtsubt->size + 1;
        }
        else
        {
            root_info->size = max(lftsubt->size, rghtsubt->size);
        }

        return root_info;
    }
    int largestBst(Node *root)
    {
        return (lrgstbst(root))->size;
    }
};