#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // if(n==k){
        //     return -1;
        // }
        vector<bool>visited(n+1,false);
        vector<int>dist(n+1,INT_MAX);
        vector<vector<pair<int,int>>>graph(n+1);
        priority_queue< pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> >pq;

        for(int i=0;i<times.size();i++){
            int u=times[i][0];
            int v=times[i][1];
            int tym=times[i][2];
            graph[u].push_back({v,tym});
        }

        int ans=-1;

        pq.push({0,k});
        dist[k]=0;

        while(!pq.empty()){
            int cnode=pq.top().second;
            int wt=pq.top().first;
            //ans=max(ans,wt);
            pq.pop();

            if(visited[cnode]==true){
                continue;
            }

            visited[cnode]=true;

            for(auto ngh:graph[cnode]){
                int newnode=ngh.first;
                int val=ngh.second;

                int newwt=val+wt;

                if(newwt<dist[newnode]){
                    dist[newnode]=newwt;
                    pq.push({newwt,newnode});
                }
            }
        }

        for(int i=1;i<=n;i++){
            ans=max(ans,dist[i]);
        }
        if(ans==INT_MAX){
            return -1;
        }

        return ans;
    }
};