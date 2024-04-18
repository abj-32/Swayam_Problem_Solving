#include <bits/stdc++.h>
using namespace std;

class Trienode
{
public:
    Trienode *children[26];
    vector<string> str;
    // Trienode(){
    // }
};
class Solution
{
public:
    void insert(Trienode *&root, string wrd)
    {
        Trienode *temp = root;
        for (char ch : wrd)
        {
            if (temp->children[ch - 'a'] == NULL)
            {
                temp->children[ch - 'a'] = new Trienode();
            }

            temp = temp->children[ch - 'a'];
            temp->str.push_back(wrd);
        }

        return;
    }

    void blackbox(Trienode *root, string s, vector<vector<string>> &ans)
    {
        Trienode *temp = root;
        int i = 0;
        while (i < s.size())
        {
            if (temp->children[s[i] - 'a'] != NULL)
            {
                temp = temp->children[s[i] - 'a'];
                // vector<string> st=temp->str;
                ans.push_back(temp->str);
                i++;
            }
            else
            {
                while (i < s.size())
                {
                    ans.push_back({"0"});
                    i++;
                }
            }
        }

        return;
    }
    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
        vector<vector<string>> ans;
        sort(contact, contact + n);
        Trienode *root = new Trienode();

        int j = 0;
        for (int i = 0; i < n - 1; i++)
        {
            if (contact[i] != contact[i + 1])
            {
                contact[j++] = contact[i];
            }
        }

        contact[j++] = contact[n - 1];

        for (int i = 0; i < j; i++)
        {
            insert(root, contact[i]);
        }

        blackbox(root, s, ans);

        return ans;
    }
};