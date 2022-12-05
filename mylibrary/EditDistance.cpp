#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i,k,n) for(int i = k;i < (n);i++)
typedef long long ll;
typedef pair <int,int> P;
typedef vector<vector<int>> Graph;
const ll MOD = 1e9 + 7;
const int INF = 1e9;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};


int editdistance(string s1,string s2){
    int a = s1.size(),b = s2.size(),cost;
    vector<vector<int>> dp(a+1,vector<int>(b+1,0));
    rep(i,a+1) dp[i][0] = i;
    rep(i,b+1) dp[0][i] = i;

    rep(i,a){
        rep(j,b){
            if(s1[i] == s2[j]) cost = 0;
            else cost = 1;
            dp[i+1][j+1] = min({dp[i+1][j]+1,dp[i][j+1]+1,dp[i][j]+cost});
        }
    }
    return dp[a][b];
}