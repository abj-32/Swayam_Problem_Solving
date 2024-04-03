#include <bits/stdc++.h>
using namespace std;

void blackbox(Node *root, int input, int &ans)
{
    if (root == NULL)
    {
        return;
    }

    if (root->data == input)
    {
        ans = root->data;
        return;
    }
    else if (root->data > input)
    {
        ans = root->data;
        blackbox(root->left, input, ans);
    }
    else
    {
        blackbox(root->right, input, ans);
    }

    return;
}
int findCeil(Node *root, int input)
{
    if (root == NULL)
        return -1;
    int ans = -1;
    blackbox(root, input, ans);

    return ans;
}