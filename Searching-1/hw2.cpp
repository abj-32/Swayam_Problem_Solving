class Solution
{
public:
    int findMin(vector<int> &nums)
    {
        int n = nums.size();
        int s, e, mid;
        int ans;
        if (n == 1)
        {
            return nums[0];
        }
        s = 0;
        e = n - 1;
        mid = s + (e - s) / 2;
        while (s < e)
        {
            if (nums[mid] >= nums[0])
            {
                s = mid + 1;
            }
            else
            {
                e = mid;
            }
            mid = s + (e - s) / 2;
        }
        if (nums[s] < nums[s - 1])
        {
            ans = nums[s];
        }
        else
        {
            ans = nums[0];
        }

        return ans;
    }
};