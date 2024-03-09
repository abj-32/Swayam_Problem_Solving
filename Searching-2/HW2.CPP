class Solution
{
public:
    int findPeakElement(vector<int> &nums)
    {
        int n = nums.size();
        int ans;
        int s, e, mid;
        if (n == 1)
            return 0;
        s = 0;
        e = n - 1;
        mid = s + (e - s) / 2;
        while (s <= e)
        {
            if ((mid == 0 || nums[mid - 1] < nums[mid]) && (mid == n - 1 || nums[mid] > nums[mid + 1]))
            {
                ans = mid;
                break;
            }
            else if (nums[mid] > nums[mid + 1])
            {
                e = mid - 1;
            }
            else
            {
                s = mid + 1;
            }
            mid = s + (e - s) / 2;
        }
        return ans;
    }
};