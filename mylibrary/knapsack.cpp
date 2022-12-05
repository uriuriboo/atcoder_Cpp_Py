#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i,k,n) for(int i = k;i < (n);i++)


int knapsack(int N,int W,vector<int> &v,vector<int> &w){
    vector<vector<int>> dp(N+1,vector<int>(W+1,0));

    rep(i,N){
        rep(j,W+1){
            if(j < w[i]){
                dp[i+1][j] = dp[i][j];
            }
            else{
                dp[i+1][j] = max(dp[i][j],dp[i+1][j-w[i]]+v[i]);
            }
        }
    }
    return dp[N][W];
}