#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void traverse(Node *root, vector<int> &arr)
    {
        if (root == NULL)
        {
            return;
        }

        traverse(root->left, arr);
        arr.push_back(root->data);
        traverse(root->right, arr);

        return;
    }
    vector<int> merge(Node *root1, Node *root2)
    {
        vector<int> arr1;
        vector<int> arr2;
        vector<int> ans;

        traverse(root1, arr1);
        traverse(root2, arr2);

        int i = 0;
        int j = 0;

        while (i < arr1.size() && j < arr2.size())
        {
            if (arr1[i] < arr2[j])
            {
                ans.push_back(arr1[i]);
                i++;
            }
            else if (arr2[j] < arr1[i])
            {
                ans.push_back(arr2[j]);
                j++;
            }
            else
            {
                ans.push_back(arr1[i]);
                ans.push_back(arr2[j]);
                i++;
                j++;
            }
        }

        while (i < arr1.size())
        {
            ans.push_back(arr1[i]);
            i++;
        }

        while (j < arr2.size())
        {
            ans.push_back(arr2[j]);
            j++;
        }

        return ans;
    }
};