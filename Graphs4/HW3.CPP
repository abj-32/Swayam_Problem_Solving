#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    unordered_map<Node*,Node*>mpp;
    Node* cloneGraph(Node* node) {
        if(node==NULL){
            return NULL;
        }
        if(mpp.count(node)==0){
            mpp[node]=new Node(node->val,{});

            for(auto ngh:node->neighbors){
                mpp[node]->neighbors.push_back(cloneGraph(ngh));
            }
        }

        return mpp[node];


    }
};