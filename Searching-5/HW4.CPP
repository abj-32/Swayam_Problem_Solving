#include<bits/stdc++.h>
using namespace std;

int countSmallArray(vector<int> & nums,int k)
{
    int s=0;
    int e=nums.size()-1;
    while(s<=e)
    {
        int mid=s+(e-s)/2;
        if(nums[mid]<=k)
        {
            s=mid+1;
        }
        else
        {
            e=mid-1;
        }
    }
    return s;
}

int kthElement(vector<int> &arr1, vector<int>& arr2, int n, int m, int k){
    int s=min(arr1[0],arr2[0]);
    int e=max(arr1[n-1],arr2[m-1]);
    int ans=0;
    while(s<=e)
    {
        int mid=s+(e-s)/2;
        int ct=countSmallArray(arr1,mid);
        ct=ct+countSmallArray(arr2,mid);
        if(ct>=k)
        {
            ans=mid;
            e=mid-1;
        }
        else
        {
            s=mid+1;
        }
    }
    return ans;
}
