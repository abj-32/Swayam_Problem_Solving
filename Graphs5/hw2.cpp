#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        // vector<double> cost;
        // for (double prob : succProb) {
        //     cost.push_back(log(prob));
        // }
        vector<bool> visited(n, false);
        vector<double> dist(n, 0.0);
        //priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> pq;
        priority_queue<pair<double, int>>pq;
        vector<vector<pair<int, double>>> graph(n);

        for (int i = 0; i < edges.size(); ++i) { 
            int u = edges[i][0];
            int v = edges[i][1];
            double cst = succProb[i]; // Use cost[i] instead of n

            graph[u].push_back({v, cst});
            graph[v].push_back({u, cst});
        }

        pq.push({1.0, start_node});
        dist[start_node] = 1;

        while (!pq.empty()) {
            int cnode = pq.top().second;
            double prb = pq.top().first;
            pq.pop();

            if (visited[cnode]) {
                continue;
            }

            visited[cnode] = true;

            for (auto it : graph[cnode]) {
                int ngnode = it.first;
                double ngprb = it.second;
                double newprb=ngprb*prb;

                if (newprb > dist[ngnode]) {
                    dist[ngnode] = newprb;
                    pq.push({newprb, ngnode});
                }
            }
        }

        if (dist[end_node] == DBL_MAX) {
            return 0.0;
        }

        //return pow(2.71828,dist[end_node]);
        return dist[end_node];
    }
};

