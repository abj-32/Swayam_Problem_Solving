#include <bits/stdc++.h>
using namespace std;

class Trienode
{
public:
    Trienode *children[26];
    bool isEnd = false;
};

class Trie
{
    Trienode *root;

public:
    Trie()
    {
        root = new Trienode();
    }

    void insert(string word)
    {
        Trienode *temp = root;
        for (char ch : word)
        {
            if (temp->children[ch - 'a'] == NULL)
            {
                temp->children[ch - 'a'] = new Trienode();
            }
            temp = temp->children[ch - 'a'];
        }

        temp->isEnd = true;
    }

    bool search(string word)
    {
        Trienode *temp = root;
        for (char ch : word)
        {
            if (temp->children[ch - 'a'] == NULL)
            {
                return false;
            }
            else
            {
                temp = temp->children[ch - 'a'];
            }
        }

        return temp->isEnd;
    }

    bool startsWith(string prefix)
    {
        Trienode *temp = root;
        for (char ch : prefix)
        {
            if (temp->children[ch - 'a'] == NULL)
            {
                return false;
            }
            else
            {
                temp = temp->children[ch - 'a'];
            }
        }

        return true;
    }
};
