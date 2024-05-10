#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    int memozn(int n,vector<vector<int>>&mat,vector<vector<int>>&dp,int row,int col){
        if(col>=n){
            return 0;
        }
        
        if(dp[row][col]!=-1){
            return dp[row][col];
        }
        
        int t1=mat[row][col]+max(memozn(n,mat,dp,0,col+2), memozn(n,mat,dp,1,col+2));
        
        int t2=memozn(n,mat,dp,1,col+1);
        int t3=memozn(n,mat,dp,0,col+1);
        
        return dp[row][col]=max(t1,max(t2,t3));
    }
    
    
    int maxSum(int N, vector<vector<int>> mat)
    {
        vector<vector<int>> dp(3,vector<int>(N+1,-1));
        return max(memozn(N,mat,dp,0,0),memozn(N,mat,dp,1,0));
    }
};