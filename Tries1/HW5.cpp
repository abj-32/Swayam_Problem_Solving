#include <bits/stdc++.h>
using namespace std;

class Trienode
{
public:
    Trienode *children[26];
    bool isEnd = false;
    string root = "";
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
        }
        temp->isEnd = true;
        temp->root = wrd;
    }

    string rootWord(string wrd, Trienode *root)
    {
        Trienode *temp = root;
        char kc = wrd[0];

        if (temp->children[kc - 'a'] == NULL)
        {
            return "";
        }
        for (char ch : wrd)
        {
            if (temp->isEnd == true)
            {
                return temp->root;
            }

            if (temp->children[ch - 'a'] == nullptr)
            {
                return wrd;
            }

            temp = temp->children[ch - 'a'];
        }

        return "";
    }

    string replaceWords(vector<string> &dictionary, string sentence)
    {
        Trienode *root = new Trienode();

        for (auto wd : dictionary)
        {
            insertTrie(wd, root);
        }

        //---------------------------------------------------------------------------------//

        vector<string> senc;
        string str = "";

        for (char ch : sentence)
        {
            if (ch == ' ')
            {
                senc.push_back(str);
                str = "";
            }
            else
            {
                str += ch;
            }
        }
        senc.push_back(str);

        //--------------------------------------------------------------------------------//
        string ans = "";
        for (auto it : senc)
        {
            string ptr = rootWord(it, root);
            if (ptr.empty())
            {
                ans += it;
            }
            else
            {
                ans += ptr;
            }

            ans.push_back(' ');
        }

        ans.pop_back();

        return ans;
    }
};