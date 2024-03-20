#include <bits/stdc++.h>
using namespace std;

int solve(vector<long long int> &arr, long long int k)
{

    int s = 0;
    int e = arr.size() - 1;
    int ans = 0;

    while (s <= e)
    {

        int mid = s + (e - s) / 2;

        if (arr[mid] >= k)
        {
            ans = mid;
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
    }

    if (ans == -1)
    {
        return 0;
    }

    return ans;
}

int main()
{
    int n, q;
    cin >> n;
    cin >> q;
    vector<long long int> students;
    vector<long long int> heights;
    for (int i = 0; i < n; i++)
    {
        long long int st;
        cin >> st;
        students.push_back(st);
    }

    for (int i = 0; i < q; i++)
    {
        long long int ht;
        cin >> ht;
        heights.push_back(ht);
    }

    sort(students.begin(), students.end());

    for (int i = 0; i < n; i++)
    {
        long long int v = heights[i];
        cout << solve(students, v) << endl;
    }
}