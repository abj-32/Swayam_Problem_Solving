#include<bits/stdc++.h>
using namespace std;

int blackbox(vector<int>& arr,int val)
{
    int s=0,e=arr.size();
    while(s<=e)
    {
        int mid=s+(e-s)/2;
        if(arr[mid]<=val)
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

int findMedian(vector<vector<int>>& arr)
{
    int n=arr.size();
    int m=arr[0].size();
    int s=arr[0][0];
    int e=arr[n-1][m-1];
    int ans=-1;
    for(int i=0;i<n;i++)
    {
        s=min(low,arr[i][0]);
        e=max(high,arr[i][m-1]);
    }
    int half=(n*m)/2;
    while(s<=e)
    {
        int mid=s+(e-s)/2;
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            cnt += blackbox(arr[i], mid);
        }
        if(count>half)
        {
            e=mid-1;
        }
        else
            s=mid+1;
    }
    return  s;

}
