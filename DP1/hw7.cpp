#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long ans=0;
     long long solving(vector<vector<int>> &quest ,int idx,vector<long long>&dp){

        if(idx>=quest.size()){
            return 0;
        }

        if(dp[idx]!=-1){
            return dp[idx];
        }

        long long take=quest[idx][0]+solving(quest,idx+quest[idx][1]+1,dp);

        long long not_take=solving(quest,idx+1,dp);

        return dp[idx]=max(take , not_take);
    }
    long long mostPoints(vector<vector<int>>& questions) {

        int n=questions.size();
        vector<long long>dp(n+1,-1);
        //vector<vector<long long>> dp(n,vector<long long>(n,-1));
        
        return solving(questions,0,dp);
    }
};