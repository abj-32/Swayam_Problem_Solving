class Solution
{
public:
    bool blackbox(vector<int> &nums, int mid, int maxop)
    {
        int cnt = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] % mid == 0)
            {
                cnt = cnt + (nums[i] / mid) - 1;
            }
            else
            {
                cnt = cnt + (nums[i] / mid);
            }

            if (cnt > maxop)
            {
                return false;
            }
        }

        if (cnt > maxop)
        {
            return false;
        }

        return true;
    }
    int minimumSize(vector<int> &nums, int maxOperations)
    {
        int e = INT_MIN;
        for (int i = 0; i < nums.size(); i++)
        {
            e = max(e, nums[i]);
        }

        e = e;
        int s = 1;
        long long int ans = 1;
        while (s <= e)
        {
            long long int mid = s + (e - s) / 2;
            if (blackbox(nums, mid, maxOperations))
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