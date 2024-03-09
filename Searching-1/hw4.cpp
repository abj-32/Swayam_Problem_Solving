class Solution
{
public:
    bool search(vector<int> &nums, int target)
    {
        bool ans = false;
        int n = nums.size();
        if (n == 1 && nums[0] == target)
        {
            return true;
        }
        int s, e, mid;
        s = 0;
        e = n - 1;
        mid = s + (e - s) / 2;
        while (s <= e)
        {
            if (nums[mid] == target)
            {
                ans = true;
                break;
            }
            if (nums[mid] == nums[s] && nums[mid] == nums[e])
            {
                s = s + 1;
                e = e - 1;
            }
            else if (nums[s] <= nums[mid])
            {
                if (nums[s] <= target && target < nums[mid])
                    e = mid - 1;
                else
                    s = mid + 1;
            }
            else
            {
                if ((nums[mid] < target) && (nums[e] >= target))
                    s = mid + 1;
                else
                    e = mid - 1;
            }

            mid = s + (e - s) / 2;
        }
        return ans;
    }
};