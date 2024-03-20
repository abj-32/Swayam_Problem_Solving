int kthSmallest(int mat[MAX][MAX], int n, int k)
{
    int s = mat[0][0];
    int e = mat[n - 1][n - 1];

    int ans = 0;

    while (s < e)
    {
        int count = 0;
        int mid = s + (e - s) / 2;

        for (int i = 0; i < n; i++)
        {
            count = count + upper_bound(mat[i], mat[i] + n, mid) - mat[i];
        }

        if (count < k)
        {
            s = mid + 1;
        }
        else
        {
            e = mid;
        }
    }

    return s;
}