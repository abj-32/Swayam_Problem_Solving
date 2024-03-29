#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int getLevelDiff(Node *root)
    {
        queue<Node *> q;
        int level = 1;
        q.push(root);

        int oddsum = 0;
        int evensum = 0;

        while (!q.empty())
        {
            int n = q.size();

            for (int i = 0; i < n; i++)
            {
                Node *temp = q.front();
                q.pop();

                if (level % 2 != 0)
                {
                    oddsum = oddsum + temp->data;
                }
                else
                {
                    evensum = evensum + temp->data;
                }

                if (temp->left != NULL)
                {
                    q.push(temp->left);
                }

                if (temp->right != NULL)
                {
                    q.push(temp->right);
                }
            }

            level++;
        }

        return oddsum - evensum;
    }
};