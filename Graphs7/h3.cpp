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

vector<bool> friendRequests(int n, vector<vector<int>>& restr, vector<vector<int>>& req) {
    int sz=req.size();

    DisjointSet dsu(n);


    vector<bool> ans(sz,false);
    //
    for(int i=0;i<sz;i++){
        
        int u=dsu.find(req[i][0]);
        int v=dsu.find(req[i][1]);

        bool k=true;

        for(int j=0;j<restr.size();j++){

            int nuu=dsu.find(restr[j][0]);
            int nvv=dsu.find(restr[j][1]);
            if((nuu==u && nvv==v) || (nuu==v && nvv==u)){
                k=false;
                break;
            }
        }

        if(k==true){
            dsu.unionRnk(req[i][0],req[i][1]);
            ans[i]=true;
        }

    }
    return ans;
}