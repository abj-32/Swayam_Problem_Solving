#include<bits/stdc++.h>
using namespace std;
int main(){
    
    int div=1e9+7;

    int n;
    cin>>n;
    //cout<<endl;
    vector<vector<int>> dp(n + 1, vector<int>(n * 6 + 1, 0));
    dp[0][0] = 1;

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n * 6; ++j) {
            for (int k = 1; k <= 6; ++k) {
                if (k <= j) {
                    dp[i][j] = ( (dp[i][j]% div) + (dp[i - 1][j - k]% div) ) % div;
                }
            }
        }
    }

    int ans= dp[n][n];
    cout<<ans<<endl;

    return 0;
}

// int dice(int n,int idx,vector<int> & nums, vector<vector<int>>&dp){
//     if(n==0){
//         return 1;
//     }

//     int take=0;
//     if(nums[idx]<=n){
//         take=dice(n-nums[idx],idx,nums,dp);
//     }
    
//     int not_take=dice(n,idx+1,nums,dp);

//     return take+not_take;
// }