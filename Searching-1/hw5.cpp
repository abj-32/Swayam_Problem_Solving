#include<bits/stdc++.h>
using namespace std;

int find_rotation(vector<int> arr,int n){
    int s=0;
    int e=n-1;

    int ans=-1;

    while(s<=e){
        int mid=s+(e-s)/2;

        if(mid< e && arr[mid]>arr[mid+1]){
            ans=mid+1;
            break;
        }
        if(mid >s && arr[mid-1]>arr[mid]){
            ans=mid;
            break;
        }
        if(arr[s]>arr[mid]){
            e=mid-1;
        }
        else{
            s=mid+1;
        }

    }

    return ans;
}
