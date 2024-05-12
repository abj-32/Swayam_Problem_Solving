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

int minSwapsCouples(vector<int>& row) {
    int ans = 0;
    int n = row.size();
    DisjointSet dsu(n);
    for (int i = 0; i < n; i+=2) {
        dsu.unionRnk(i,i+1);
    }
    for (int i = 0; i < n; i += 2) {
        int lft=dsu.find(row[i]);
        int rght=dsu.find(row[i+1]);
        if(lft!=rght){
            dsu.unionRnk(lft,rght);
            ans++;
        }
    }
    return ans;
}