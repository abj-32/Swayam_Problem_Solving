#include<bits/stdc++.h>
using namespace std;

class DisjointSet {
public:
    vector<int> rank, parent, size;
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int find(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = find(parent[node]);
    }

    void unionRnk(int u, int v) {
        int pu = find(u);
        int pv = find(v);
        if (pu == pv) return;
        if (rank[pu] < rank[pv]) {
            parent[pu] = pv;
        }
        else if (rank[pv] < rank[pu]) {
            parent[pv] = pu;
        }
        else {
            parent[pv] = pu;
            rank[pu]++;
        }
    }

};

class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        DisjointSet alice(n+1);
        DisjointSet bob(n+1);
        int k = 0;
        for(int i=0;i<edges.size();i++){
            int u = edges[i][1];
            int v = edges[i][2];
            if(edges[i][0]==3){
                if(alice.find(u)!=alice.find(v)){
                    alice.unionRnk(u,v);
                }
                if(bob.find(u)!=bob.find(v)){
                    bob.unionRnk(u,v);
                }
                else k++;
            }
        }
        for(int i=0;i<edges.size();i++){
            if(edges[i][0]==1){
                int u = edges[i][1];
                int v = edges[i][2];
                if(alice.find(u)!=alice.find(v)){
                    alice.unionRnk(u,v);
                }
                else{
                    k++;
                }
            }
            else if(edges[i][0]==2){
                int u = edges[i][1];
                int v = edges[i][2];
                if(bob.find(u)!=bob.find(v)){
                    bob.unionRnk(u,v);
                }
                else{
                    k++;
                }
            }
        }
        for(int i=1; i<=n; i++){
            if(alice.find(i) != alice.find(n)  || bob.find(i) != bob.find(n) ){
                return -1;
            }
        }
        return k;

    }
};