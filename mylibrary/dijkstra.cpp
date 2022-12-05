#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i,k,n) for(int i = k;i < (n);i++)
typedef long long ll;
const int INF = 1e9;
const ll lINF = 1e18;
template <class T> inline bool chmin(T &a, T b) {if (a > b) {a = b; return true;} return false;}
template <class T> inline bool chmax(T &a, T b) {if (a < b) {a = b; return true;} return false;}

struct Edge{
    int to;
    ll w;
    Edge(int to,ll w): to(to),w(w){}
};

using Graph = vector<vector<Edge>>;
//s,Gは0オリジンに直しておくこと
vector<ll> dijkstra(int s,Graph G){
    int n = G.size();
    vector<ll> dist(n,lINF);
    dist[s] = 0;

    priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>> que;
    que.push(make_pair(dist[s],s));

    while(!que.empty()){
        int v = que.top().second;
        ll d = que.top().first;
        que.pop();

        if(d > dist[v]) continue;

        for(auto e:G[v]){
            if(chmin(dist[e.to],dist[v]+e.w)) que.push(make_pair(dist[e.to],e.to));
        }
    }
    return dist;
}
