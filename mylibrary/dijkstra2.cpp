#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i,k,n) for(int i = k;i < (n);i++)
typedef long long ll;
const int INF = 1e9;
const ll lINF = 1e18;
template <class T> inline bool chmin(T &a, T b) {if (a > b) {a = b; return true;} return false;}
template <class T> inline bool chmax(T &a, T b) {if (a < b) {a = b; return true;} return false;}

using TU = tuple<int,ll>;

using Graph = vector<vector<TU>>;
//s,Gは0オリジンに直しておくこと
vector<ll> dijkstra(int s,Graph &G){
    int n = G.size();
    vector<ll> dist(n,lINF);
    dist[s] = 0;

    priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>> que;
    que.push(make_pair(dist[s],s));

    while(!que.empty()){
        int v;
        ll d;
        tie(d,v) = que.top();
        que.pop();

        if(d > dist[v]) continue;

        for(auto nxt:G[v]){
            int nv;
            ll w;
            tie(nv,w) = nxt;
            if(chmin(dist[nv],dist[v]+w))
                que.push(make_pair(dist[nv], nv));
        }
    }
    return dist;
}
