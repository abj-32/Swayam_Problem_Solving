class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        vector<int> arr;
        int ans1 = -1;
        int ans2 = -1;
        int s = 0;
        int e = nums.size() - 1;
        int mid = s + (e - s) / 2;
        while (s <= e)
        {
            if (nums[mid] == target)
            {
                ans1 = mid;
                e = mid - 1;
            }
            else if (nums[mid] < target)
            {
                s = mid + 1;
            }
            else if (nums[mid] > target)
            {
                e = mid - 1;
            }
            mid = s + (e - s) / 2;
        }
        s = 0;
        e = nums.size() - 1;
        mid = s + (e - s) / 2;
        while (s <= e)
        {
            if (nums[mid] == target)
            {
                ans2 = mid;
                s = mid + 1;
            }
            else if (nums[mid] < target)
            {
                s = mid + 1;
            }
            else if (nums[mid] > target)
            {
                e = mid - 1;
            }
            mid = s + (e - s) / 2;
        }

        arr.push_back(ans1);
        arr.push_back(ans2);
        return arr;
    }
};