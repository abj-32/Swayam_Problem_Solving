class Solution
{
public:
    int singleNonDuplicate(vector<int> &nums)
    {
        int n = nums.size();
        int ans = 0;
        int e, s, mid;
        s = 0;
        e = n - 1;
        mid = s + (e - s) / 2;
        if (n == 1)
        {
            return nums[0];
        }
        if (nums[0] != nums[1])
            return nums[0];
        if (nums[n - 1] != nums[n - 2])
            return nums[n - 1];
        while (s <= e)
        {
            if (nums[mid] != nums[mid - 1] && nums[mid] != nums[mid + 1])
            {
                ans = mid;
                break;
            }
            else if (nums[mid] == nums[mid - 1] && ((mid - 1) % 2) != 0)
            {
                e = mid - 1;
            }
            else if (nums[mid] == nums[mid + 1] && (mid % 2) != 0)
            {
                e = mid - 1;
            }
            else if (nums[mid] == nums[mid - 1] && (mid - 1) % 2 == 0)
            {
                s = mid + 1;
            }
            else
            {
                s = mid + 1;
            }
            mid = s + (e - s) / 2;
        }
        return nums[ans];
    }
};