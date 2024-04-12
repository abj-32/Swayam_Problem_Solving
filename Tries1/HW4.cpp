#include <bits/stdc++.h>
using namespace std;

class Trienode
{
public:
    Trienode *children[2];
    Trienode()
    {
        children[0] = NULL;
        children[1] = NULL;
    }
};

class Solution
{
public:
    void insertTrie(Trienode *&root, int num)
    {
        Trienode *temp = root;
        for (int i = 31; i >= 0; i--)
        {

            int bt = (num >> i) & 1;

            if (temp->children[bt] == NULL)
            {
                temp->children[bt] = new Trienode();
            }
            temp = temp->children[bt];
        }
    }

    int MaxXOR(Trienode *&root, int num)
    {
        Trienode *temp = root;
        int ans = 0;

        for (int i = 31; i >= 0; i--)
        {
            int bt = (num >> i) & 1;

            if (temp->children[!bt] != NULL)
            {
                ans += (1 << i);
                temp = temp->children[!bt];
            }
            else
            {
                temp = temp->children[bt];
            }
        }

        return ans;
    }

    int findMaximumXOR(vector<int> &nums)
    {
        int n = nums.size();
        int maxi = 0;

        Trienode *root = new Trienode();

        for (int i = 0; i < n; i++)
        {

            insertTrie(root, nums[i]);
        }

        for (int i = 0; i < n; i++)
        {
            int tan = MaxXOR(root, nums[i]);
            maxi = max(maxi, tan);
        }

        return maxi;
    }
};