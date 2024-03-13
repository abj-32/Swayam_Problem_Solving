class Solution
{
public:
    bool blackbox(vector<int> &bloom, int day, int m, int k)
    {
        int n = bloom.size();
        int cnt = 0;
        int bouq = 0;
        int i = 0;

        while (i < n)
        {
            if (bloom[i] <= day)
            {
                cnt = 0;
                while (i < n && bloom[i] <= day && cnt < k)
                {
                    cnt++;
                    i++;
                }

                if (cnt == k)
                {
                    bouq++;
                }
            }

            else
            {
                i++;
            }
        }

        if (bouq >= m)
        {
            return true;
        }

        return false;
    }
    int minDays(vector<int> &bloomDay, int m, int k)
    {
        long long n = bloomDay.size();

        int finalDay = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            finalDay = max(finalDay, bloomDay[i]);
        }

        int s = 1;
        int e = finalDay;
        int ans = -1;
        while (s <= e)
        {
            int mid = s + (e - s) / 2;
            if (blackbox(bloomDay, mid, m, k))
            {
                ans = mid;
                e = mid - 1;
            }
            else
            {
                s = mid + 1;
            }
        }
        return ans;
    }
};