#include<bits/stdc++.h>
using namespace std;

class TrieNode 
{
    public:
    TrieNode *child[2]; 
 
    int cnt; 
    
    TrieNode() 
    { 
        child[0] = child[1] = NULL; 
        cnt = 0; 
    } 
}; 

class Solution {
public:

void insertTrie(TrieNode *root, int N) 
   { 
    for (int i = 31; i >= 0; i--) 
    { 
    
        bool x = (N) & (1 << i); 
         
        if(!root->child[x]) 
        { 
            root->child[x] = new TrieNode(); 
        } 
          
        root->child[x]->cnt+= 1; 
        root= root->child[x]; 
    } 
} 


     int cntSmaller(TrieNode * root, int N, int K) 
{ 
    int cntPairs = 0; 
    
    for (int i = 31; i >= 0 && root; i--) 
    { 
                                                           
        bool x = N & (1 << i); 
     
        bool y = K & (1 << i); 
         
        if (y) 
        { 
             
            if(root->child[x])
            {
                    cntPairs  += root->child[x]->cnt; 
            }
         
            root = root->child[1 - x]; 
        } 
          
        else
        {  
            root = root->child[x]; 
        } 
    } 
    return cntPairs; 
} 


    int pairs(vector<int>arr, int n, int k)
    {
        TrieNode *root = new TrieNode(); 
    
        int cntPairs = 0; 
     
        for(int i = 0;i < n; i++)
        { 
         
            cntPairs += cntSmaller(root, arr[i], k); 

            insertTrie(root, arr[i]); 
        } 
        
       return cntPairs; 
    }
    

    int countPairs(vector<int>& nums, int low, int high) {
        int n = nums.size(); 
	   return pairs(nums, n, high + 1) - pairs(nums, n, low);
    }
};