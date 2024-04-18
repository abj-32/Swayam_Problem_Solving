#include <bits/stdc++.h>
using namespace std;

class Trienode
{
public:
    unordered_map<char, Trienode *> children;
    unordered_map<string, int> frequencies;
};

class AutoCompleteSystem
{
public:
    Trienode *root;
    Trienode *current;
    string currentQuery;

    static bool compare(pair<string, int> &a, pair<string, int> &b)
    {
        return a.second > b.second || (a.second == b.second && a.first < b.first);
    }

    void insert(string senc, int time)
    {
        Trienode *temp = root;
        for (char ch : senc)
        {
            if (!temp->children[ch])
            {
                temp->children[ch] = new Trienode();
            }
            temp = temp->children[ch];
            temp->frequencies[senc] += time;
        }
    }
    AutoCompleteSystem(vector<string> &sentences, vector<int> &times)
    {
        root = new Trienode();
        current = root;
        currentQuery = "";

        for (int i = 0; i < sentences.size(); i++)
        {
            insert(sentences[i], times[i]);
        }
    }
    vector<string> input(char c)
    {
        if (c == '#')
        {
            insert(currentQuery, 1);
            currentQuery = "";
            current = root;
            return {};
        }

        currentQuery += c;
        if (!current->children[c])
        {
            current->children[c] = new Trienode();
            current = current->children[c];
            return {};
        }

        current = current->children[c];
        vector<pair<string, int>> suggestions(current->frequencies.begin(), current->frequencies.end());
        sort(suggestions.begin(), suggestions.end(), compare);

        vector<string> result;
        for (int i = 0; i < min(3, (int)suggestions.size()); ++i)
        {
            result.push_back(suggestions[i].first);
        }

        return result;
    }
};