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

/*(スタート,ゴール,迷路)
first が行 secondが列
'#'の時通れない。それ以外の時に通れる。
4方向のみ*/
int bfs(P s, P g, vector<string> &c)
{
    int H = c.size();
    int W = c[0].size();
    vector<vector<int>> d(H, vector<int>(W, -1)); //探索で通ったか、コストを記録
    queue<P> que;
    que.push(s);
    d[s.first][s.second] = 0;

    while (que.size())
    {
        P p = que.front();
        que.pop();

        rep(i, 4)
        {
            int x = p.first + dx[i], y = p.second + dy[i];

            if (x < 0 || x >= H || y < 0 || y >= W)
                continue;
            if (c[x][y] == '#')
                continue;
            if (d[x][y] != -1)
                continue;
            if (x == g.first && y == g.second)
            {
                d[x][y] = d[p.first][p.second] + 1;
                break;
            }
            que.push(P(x, y));
            d[x][y] = d[p.first][p.second] + 1;
        }
    }
    return d[g.first][g.second];
}