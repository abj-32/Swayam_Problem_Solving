class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int m = nums1.size();
        int n = nums2.size();
        int arr[m + n];
        int i = 0, j = 0, k = 0;
        double med;
        while (i < m && j < n)
        {
            if (nums1[i] < nums2[j])
            {
                arr[k] = nums1[i];
                i++;
            }
            else if (nums1[i] == nums2[j])
            {
                arr[k] = nums1[i];
                k++;
                arr[k] = nums2[j];
                i++;
                j++;
            }
            else
            {
                arr[k] = nums2[j];
                j++;
            }
            k++;
        }
        while (i < m)
        {
            arr[k] = nums1[i];
            i++;
            k++;
        }
        while (j < n)
        {
            arr[k] = nums2[j];
            j++;
            k++;
        }

        if ((m + n) % 2 == 0)
        {
            int mid = (m + n) / 2;
            double p = arr[mid];
            double q = arr[mid - 1];
            med = (p + q) / 2;
        }
        else if ((m + n) % 2 != 0)
        {
            int mid = (m + n - 1) / 2;
            med = arr[mid];
        }

        return med;
    }
};
