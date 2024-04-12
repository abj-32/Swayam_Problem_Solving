#include <bits/stdc++.h>
using namespace std;

class Trienode
{
public:
    Trienode *children[26];
    int idx;
    Trienode()
    {
        idx = -1;
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
    }
};

class Solution
{
public:
    void insertTrie(Trienode *root, int i, vector<string> &wordsContainer)
    {
        Trienode *temp = root;
        string wrd = wordsContainer[i];
        int n = wrd.size();

        for (int j = n - 1; j >= 0; j--)
        {
            char ch = wrd[j];

            if (temp->children[ch - 'a'] == NULL)
            {
                temp->children[ch - 'a'] = new Trienode();
            }

            temp = temp->children[ch - 'a'];

            if (temp->idx == -1 || wordsContainer[temp->idx].size() > n)
            {
                temp->idx = i;
            }
        }
    }

    int indexTrie(string &wrd, Trienode *root)
    {
        Trienode *temp = root;
        int res = root->idx;
        int n = wrd.size();

        for (int i = n - 1; i >= 0; i--)
        {
            char ch = wrd[i];
            temp = temp->children[ch - 'a'];
            if (temp == NULL)
            {
                return res;
            }
            res = temp->idx;
        }

        return res;
    }

    vector<int> stringIndices(vector<string> &wordsContainer, vector<string> &wordsQuery)
    {
        int m = wordsContainer.size();
        int n = wordsQuery.size();

        vector<int> ans(n);
        Trienode *root = new Trienode();

        for (int i = 0; i < m; i++)
        {
            int x = root->idx;
            if (x == -1 || wordsContainer[x].size() > wordsContainer[i].size())
            {
                root->idx = i;
            }

            insertTrie(root, i, wordsContainer);
        }

        for (int i = 0; i < n; i++)
        {
            ans[i] = indexTrie(wordsQuery[i], root);
        }

        return ans;
    }
};