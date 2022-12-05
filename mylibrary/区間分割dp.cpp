#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define rep2(i,k,n) for(ll i = k;i < (n);i++)
#define ALL(a) (a).begin(),(a).end()
#define ALLR(a) (a).rbegin(),(a).rend()
using P = pair<ll,ll>;
const ll MOD = 1e9 + 7;
const int INF = 1e9;
const ll lINF = 1e18;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
template <class T> inline bool chmin(T &a, T b) {if (a > b) {a = b; return true;} return false;}
template <class T> inline bool chmax(T &a, T b) {if (a < b) {a = b; return true;} return false;}

//vector<vector<ll>> c(n+1,vector<ll>(n+1))を渡す
ll dp(vector<vector<ll>> &c){
    int n = c.size()-1;
    vector<ll> dp(n+1,lINF);
    dp[0] = 0;

    for(int i = 0;i <= n;i++){
        for(int j = 0;j < i;j++)
            chmin(dp[i],dp[j]+c[i][j]);
    }
    return dp[n];
}
