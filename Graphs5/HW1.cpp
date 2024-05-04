#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> minimumTime(int n, vector<vector<int>>& edges, vector<int>& disappear) {
        vector<vector<pair<int,int>>>graph(n);
        vector<int> dist(n,INT_MAX);
        vector<bool> visited(n,false);
        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>>pq;

        for(auto& it:edges){
            int u=it[0];
            int v=it[1];
            int len=it[2];
            graph[u].push_back({v,len});
            graph[v].push_back({u,len});
        }

        pq.push({0,0});
        dist[0]=0;

        while(!pq.empty()){
            int cnode=pq.top().second;
            int time=pq.top().first;
            pq.pop();

            if(visited[cnode]==true){
                continue;
            }

            if(time>=disappear[cnode]){
                continue;
            }
            visited[cnode]=true;

            for(auto ngh:graph[cnode]){
                int newnode=ngh.first;
                int newtime=ngh.second;
                if(time+newtime < dist[newnode] && time+newtime <= disappear[newnode]){
                    dist[newnode]=time+newtime;
                    pq.push({time+newtime,newnode});
                }
            }
        }

        for(int i=0;i<n;i++){
            if(dist[i]==INT_MAX || dist[i]>=disappear[i]){
                dist[i]=-1;
            }
        }



        return dist;
    }
};