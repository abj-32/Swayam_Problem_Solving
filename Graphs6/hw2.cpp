#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {

        int n=points.size();

        vector<vector<pair<int, int>>> adj(n, vector<pair<int, int>>());
        for(int i = 0 ; i < n; i++) {
            vector<int> temp = points[i];
            for(int j = 0; j < points.size(); j++) {
                if(j == i) continue;
                adj[i].push_back({abs(temp[0] - points[j][0]) + abs(temp[1] - points[j][1]), j});
            }
        }


		priority_queue< pair<int, int> , vector<pair<int, int> > , greater<pair<int, int>>  > pq;

        vector<bool> visited(n, false);
        pq.push({0, 0});


        int ans = 0;


        while(!pq.empty()) {
            int curr = pq.top().second;
            int wt = pq.top().first;
            pq.pop();


            if(visited[curr]) {
                continue;
            }

            visited[curr] = true;
            ans += wt;


            for(auto ngh: adj[curr]) {
                if(visited[ngh.second]) {
                  continue;
                }
                pq.push(ngh);
            }
        }


        return ans;
    }
};