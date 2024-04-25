#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> findOrder(int numCr, vector<vector<int>>& prereq) {
        vector<int> ans;
        vector<int> indegree(numCr+1,0);

        vector<vector<int>> adj(numCr+1,vector<int>());
        for(auto it: prereq){
            int k1=it[0];
            int k2=it[1];
            adj[k2].push_back(k1);
            indegree[k1]++;
        }

        queue<int> q;
        for(int i=0;i<numCr; i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }


        while(!q.empty()){
            int x=q.front();
            q.pop();
            ans.push_back(x);

            for(int ngh:adj[x]){
                indegree[ngh]--;
                if(indegree[ngh]==0){
                    q.push(ngh);
                }
            }
        }

        if(ans.size()==numCr){
            return ans;
        }

        return {};
    }
};