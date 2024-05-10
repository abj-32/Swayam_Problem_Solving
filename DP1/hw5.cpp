#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // int robbery(vector<int> &nums, vector<int> &dp,int idx)
    // {
    //     if(idx==0) return dp[idx]=nums[idx];
    //     if(idx<0) return 0;

    //     if(dp[idx]!=-1)
    //     {
    //         return dp[idx];
    //     }

    //     int pick=nums[idx]+ robbery(nums,dp,idx-2);

    //     int not_pick=0+robbery(nums,dp,idx-1);

    //     return dp[idx]=max(pick,not_pick);
    // }
    int rob(vector<int>& nums) {
        int n=nums.size();
        //vector<int> dp(n+1,-1);
        //return robbery(nums,dp,n-1);

        int prev=nums[0];
        int prev2=0;
       
        for(int i=1;i<n;i++)
        {
            int tk=nums[i];
            if(i>1)
            tk=tk+prev2;

            int ntk=0+prev;

            int curr=max(tk,ntk);
            prev2=prev;
            prev=curr;
        }
        return prev;
    }
};
