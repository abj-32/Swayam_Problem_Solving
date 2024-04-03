#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    TreeNode *build(vector<int> nums, int l, int r)
    {
        if (l > r)
        {
            return NULL;
        }

        int mid = l + (r - l) / 2;

        TreeNode *root = new TreeNode(nums[mid]);

        root->left = build(nums, l, mid - 1);
        root->right = build(nums, mid + 1, r);

        return root;
    }
    TreeNode *sortedListToBST(ListNode *head)
    {
        ListNode *ptr = head;

        vector<int> nums;
        while (ptr != NULL)
        {
            nums.push_back(ptr->val);
            ptr = ptr->next;
        }

        int l = 0;
        int r = nums.size() - 1;
        return build(nums, l, r);
    }
};