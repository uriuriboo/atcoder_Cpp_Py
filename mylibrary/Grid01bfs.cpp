#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i,k,n) for(int i = k;i < (n);i++)
typedef long long ll;
typedef pair <int,int> P;
const ll MOD = 1e9 + 7;
const int INF = 1e9;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
/*0-1幅優先探索
(スタート,ゴール,迷路)
first が行 secondが列
4方向のみ
'.'または'g'がコストのない通路
'#'がコストのある通路*/

int bfs01(P s, P g, vector<string> &c)
{
    int H = c.size();
    int W = c[0].size();
    vector<vector<int>> d(H, vector<int>(W, -1)); //探索で通ったか、コストを記録
    deque<P> que;
    que.push_front(s);
    d[s.first][s.second] = 0;

    while (que.size())
    {
        P p = que.front();
        que.pop_front();

        rep(i, 4)
        {
            int x = p.first + dx[i], y = p.second + dy[i];

            if (x < 0 || x >= H || y < 0 || y >= W)
                continue;
            if (d[x][y] != -1)
                continue;
            if (c[x][y] == '.' || c[x][y] == 'g'){
                d[x][y] = d[p.first][p.second];
                que.push_front(make_pair(x,y));
                }
            else if(c[x][y] == '#'){
                d[x][y] = d[p.first][p.second]+1;
                que.push_back(make_pair(x,y));
            }        
        }
    }
    return d[g.first][g.second];
}