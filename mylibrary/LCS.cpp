#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i,k,n) for(int i = k;i < (n);i++)
typedef long long ll;
typedef pair <int,int> P;
typedef vector<vector<int>> Graph;
const ll MOD = 1e9 + 7;
const int INF = 1e8;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int lcs(string A,string B){
    int a = A.size(),b = B.size();
    vector<vector<int>> dp(a+1,vector<int>(b+1,0));
    rep(i,a){
        rep(j,b){
            if(A[i] == B[j]){
                dp[i+1][j+1] =dp[i][j]+1;
            }
            else{
                dp[i+1][j+1] = max(dp[i+1][j],dp[i][j+1]);
            }
        }
    }
    return dp[a][b];
}

string lcsmake(string A,string B){
    int a = A.size(),b = B.size();
    string res;
    vector<vector<int>> dp(a+1,vector<int>(b+1,0));
    rep(i,a){
        rep(j,b){
            if(A[i] == B[j]){
                dp[i+1][j+1] =dp[i][j]+1;
            }
            else{
                dp[i+1][j+1] = max(dp[i+1][j],dp[i][j+1]);
            }
        }
    }

    int i = A.length()-1,j = B.length()-1;

    while (i >= 0 && j >= 0){
        if(dp[i+1][j+1] == dp[i+1][j]) --j;
        else if(dp[i+1][j+1] == dp[i][j+1]) --i;
        else{
            res = A[i]+res;
            --i;--j;
        }
    
    }
    
    return res;
}