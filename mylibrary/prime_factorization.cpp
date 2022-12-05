#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (n); i++)
using P = pair<ll,ll>;

//(素因数,素因数の数)のペア
vector<pair<ll,int>> prime_fac(ll n){
    vector<pair<ll,int>> res;
    for(ll i = 2;i*i <= n;i++){
        int cnt = 0;
        while(n%i == 0){
            cnt++;
            n /= i;
        }
        if(cnt != 0) res.emplace_back(make_pair(i,cnt));
    }
    if(n != 1) res.emplace_back(n,1);

    return res;
}
