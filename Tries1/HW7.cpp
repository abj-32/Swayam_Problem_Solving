#include <bits/stdc++.h>
using namespace std;


class Trienode
{
public:
    Trienode *children[26];
    bool isWordEnd;
    Trienode()
    {

        isWordEnd = false;

        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
    }
};

class solution
{
    void insert(Trienode *root, string key)
    {
        Trienode *temp = root;

        for (int i = 0; i < key.length(); i++)
        {
            int index = key[i] - 'a';
            if (!temp->children[index])
                temp->children[index] = new Trienode();

            temp = temp->children[index];
        }
        temp->isWordEnd = true;
    }


    bool isLastNode(Trienode *root)
    {
        for (int i = 0; i < 26; i++)
            if (root->children[i])
                return 0;
        return 1;
    }



    void sgst(Trienode *root,string currPrefix){
       
        if (root->isWordEnd)
            cout << currPrefix << endl;

        for (int i = 0; i < 26; i++)
            if (root->children[i])
            {
                char child = 'a' + i;
                sgst(root->children[i],
                     currPrefix + child);
            }
    }


    int printAutoSuggestions(Trienode *root, string query)
    {
        struct Trienode *temp = root;
        for (char c : query)
        {
            int ind = c-'a';

            if (!temp->children[ind])
                return 0;

            temp = temp->children[ind];
        }


        if (isLastNode(temp))
        {
            cout << query << endl;
            return -1;
        }
        sgst(temp, query);
        return 1;
    }


    
    int main()
    {
        Trienode *root = new Trienode();
        insert(root, "hello");
        insert(root, "dog");
        insert(root, "hell");
        insert(root, "cat");
        insert(root, "a");
        insert(root, "hel");
        insert(root, "help");
        insert(root, "helps");
        insert(root, "helping");
        int comp = printAutoSuggestions(root, "hel");

        if (comp == -1)
            cout << "No other strings found with this prefix\n";

        else if (comp == 0)
            cout << "No string found with this prefix\n";

        return 0;
    }
};
