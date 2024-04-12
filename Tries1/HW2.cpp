#include <bits/stdc++.h>
using namespace std;

class Trienode
{
public:
    Trienode *children[26];
    int count = 0;
};

class Solution
{
public:
    void insertTrie(string wrd, Trienode *root)
    {
        Trienode *temp = root;
        for (char ch : wrd)
        {
            if (temp->children[ch - 'a'] == NULL)
            {
                temp->children[ch - 'a'] = new Trienode();
            }
            temp = temp->children[ch - 'a'];
            temp->count = temp->count + 1;
        }
    }

    int prefixScore(string wrd, Trienode *root)
    {
        Trienode *temp = root;
        int k = 0;
        for (char ch : wrd)
        {
            temp = temp->children[ch - 'a'];
            k += temp->count;
        }

        return k;
    }
    vector<int> sumPrefixScores(vector<string> &words)
    {
        Trienode *root = new Trienode();
        for (auto wd : words)
        {
            insertTrie(wd, root);
        }

        vector<int> ans;

        for (auto wd : words)
        {
            int val = 0;
            val = prefixScore(wd, root);
            ans.push_back(val);
        }

        return ans;
    }
};