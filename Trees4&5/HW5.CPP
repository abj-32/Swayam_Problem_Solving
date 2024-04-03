#include <bits/stdc++.h>
using namespace std;

class nodeinfo
{
public:
    bool isbst;
    int min_elmnt;
    int max_elmnt;
    int sum;

    nodeinfo() {}
    nodeinfo(bool isbst, int min_elmnt, int max_elmnt, int sum)
    {
        this->isbst = isbst;
        this->min_elmnt = min_elmnt;
        this->max_elmnt = max_elmnt;
        this->sum = sum;
    }
};

class Solution
{
public:
    int ans = 0;
    nodeinfo *maxsumBST(TreeNode *root, int &ans)
    {
        if (root == NULL)
        {
            return new nodeinfo(true, INT_MAX, INT_MIN, 0);
        }

        nodeinfo *lftbst = maxsumBST(root->left, ans);
        nodeinfo *rghtbst = maxsumBST(root->right, ans);

        nodeinfo *root_info = new nodeinfo();

        root_info->isbst = (lftbst->isbst && rghtbst->isbst && (root->val > lftbst->max_elmnt) && (root->val < rghtbst->min_elmnt));

        root_info->min_elmnt = min(lftbst->min_elmnt, root->val);
        root_info->max_elmnt = max(rghtbst->max_elmnt, root->val);

        root_info->sum = lftbst->sum + rghtbst->sum + root->val;

        if (root_info->isbst)
        {
            ans = max(ans, root_info->sum);
        }
        // else{
        //     root_info->sum=max(lftbst->sum,rghtbst->sum);
        // }

        return root_info;
    }
    int maxSumBST(TreeNode *root)
    {
        int maxsum = 0;
        nodeinfo *temp = maxsumBST(root, maxsum);
        if (maxsum < 0)
        {
            return 0;
        }

        return maxsum;
    }
};