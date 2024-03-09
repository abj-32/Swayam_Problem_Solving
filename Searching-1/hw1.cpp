#include <stdio.h>
using namespace std;

class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int s = 0;
        int n = nums.size();
        int e = nums.size() - 1;
        int mid = s + (e - s) / 2;
        int ans = -1;
        int piv;
        if (nums.size() == 1 && nums[0] == target)
        {
            return 0;
        }
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
        piv = s;
        cout << piv << endl;
        if (nums[piv] <= target && target <= nums[n - 1])
        {
            s = piv;
            e = n - 1;
            mid = s + (e - s) / 2;
            while (s <= e)
            {
                if (nums[mid] == target)
                {
                    ans = mid;
                    break;
                }
                else if (nums[mid] < target)
                {
                    s = mid + 1;
                }
                else
                {
                    e = mid - 1;
                }
                mid = s + (e - s) / 2;
            }
        }
        else
        {
            s = 0;
            e = piv - 1;
            mid = s + (e - s) / 2;
            while (s <= e)
            {
                if (nums[mid] == target)
                {
                    ans = mid;
                    break;
                }
                else if (nums[mid] < target)
                {
                    s = mid + 1;
                }
                else
                {
                    e = mid - 1;
                }
                mid = s + (e - s) / 2;
            }
        }
        return ans;
    }
};