class Solution
{
public:
    bool checker(int diff, int cow, vector<int> stalls)
    {
        int lastCow = stalls[0];
        int placed = 1;
        for (int i = 1; i < stalls.size(); i++)
        {
            if (stalls[i] - lastCow >= diff)
            {
                lastCow = stalls[i];
                placed++;
            }

            if (placed >= cow)
            {
                return true;
            }
        }

        return false;
    }
    int solve(int n, int k, vector<int> &stalls)
    {
        int s = 1;
        sort(stalls.begin(), stalls.end());
        int e = stalls[n - 1] - stalls[0];
        int ans = 1;
        int mid = s + (e - s) / 2;

        while (s <= e)
        {
            if (checker(mid, k, stalls))
            {
                ans = mid;
                s = mid + 1;
            }
            else
            {
                e = mid - 1;
            }

            mid = s + (e - s) / 2;
        }

        return ans;
    }
};