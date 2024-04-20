#include<bits/stdc++.h>
using namespace std;

int dfs(int node,vector<vector<int>>&adj,int &ans){
    int maxi=0;
    for(auto it:adj[node]){
        int val=dfs(it,adj,ans);
        ans=max(ans,maxi+val);
        maxi=max(maxi,val);
    }
    
    return maxi+1;
}

int Solution::solve(vector<int> &A) {
    int n=A.size();
    vector<vector<int>> adj(n,vector<int>(0));
    vector<bool>visited(n,false);
    int root=-1;
    
    for(int i=0;i<n;i++){
        if(A[i]== -1){
            root=i;
            continue;
        }
        
        adj[A[i]].push_back(i);
    }
    
    int ans=0;
    int k=dfs(root,adj,ans);
    
    return ans;
    
}
