#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int memozn(int n,vector<long long int>&dp){
        
        if(n==2){
            return 2;
        }
        if(n==1){
            return 1;
        }
        
        if(dp[n]!=-1){
            return dp[n];
        }
        
        return dp[n]= memozn(n-1,dp)+ (n-1)*memozn(n-2,dp);
    }
    int countFriendsPairings(int n) 
    { 
        
        int div=1e9+7;
        vector<long long> dp (n+1,0);
        //return memozn(n,dp);
        if(n==2){
            return 2;
        }
        if(n==1){
            return 1;
        }
        
        dp[0]=1;
        dp[1]=1;
        dp[2]=2;
        
        for(int i=3;i<=n;i++){
            
            long long per1=dp[i-1]%div;
            long long per2=( (i-1) *(dp[i-2]%div))%div;
            
            dp[i]=(per1+per2)%div;
        }
        
        return dp[n];
        
    }
};