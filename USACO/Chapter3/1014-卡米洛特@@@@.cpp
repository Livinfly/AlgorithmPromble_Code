#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>

#define fi first
#define se second
#define mkp(x, y) make_pair(x, y)

using namespace std;

typedef pair<int, int> PII;

const int N = 35, INF = 0x3f3f3f3f;

int dx[8] = {-2, -1, 1, 2, 2, 1, -1, -2},
    dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int n, m;
int dist_sum[N][N], dist_min[N][N], dist[N][N][2];
bool st[N][N][2];
PII king;
struct Node
{
    int x, y, z;
};
queue<Node> q;

inline void spfa(int sx, int sy)
{
    memset(dist, 0x3f, sizeof dist);
    dist[sx][sy][0] = 0;
    q.push((Node) {sx, sy, 0});
    st[sx][sy][0] = true;
    while(q.size())
    {
        Node t = q.front(); q.pop();
        st[t.x][t.y][t.z] = false;
        for(int i = 0; i < 8; i ++)
        {
            int a = t.x + dx[i], b = t.y + dy[i];
            if(a < 1 || a > n || b < 1 || b > m) continue;
            if(dist[a][b][t.z] > dist[t.x][t.y][t.z] + 1) 
            {
                dist[a][b][t.z] = dist[t.x][t.y][t.z] + 1;
                if(!st[a][b][t.z])
                {
                    q.push((Node) {a, b, t.z});
                    st[a][b][t.z] = true;
                }
            }
        }
        if(!t.z)
        {
            if(dist[t.x][t.y][1] > dist[t.x][t.y][0] + max(abs(t.x - king.fi), abs(t.y - king.se)))
            {
                dist[t.x][t.y][1] = dist[t.x][t.y][0] + max(abs(t.x - king.fi), abs(t.y - king.se));
                if(!st[t.x][t.y][1])
                {
                    q.push((Node) {t.x, t.y, 1});
                    st[t.x][t.y][1] = true;
                }
            }
        }
    }
    for(int i = 1; i <= n; i ++)
        for(int j = 1; j <= m; j ++)
            if(dist[i][j][0] == INF)
                dist_sum[i][j] = INF;
            else
                dist_sum[i][j] += dist[i][j][0];
    for(int i = 1; i <= n; i ++)
        for(int j = 1; j <= m; j ++)
            dist_min[i][j] = min(dist_min[i][j], dist[i][j][1] - dist[i][j][0]);
    return;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    char y; int x;
    cin >> y >> x;
    y = y - 'A' + 1;
    king = mkp(x, y);
    for(int i = 1; i <= n; i ++)
        for(int j = 1; j <= m; j ++)
            dist_min[i][j] = max(abs(i - king.fi), abs(j - king.se));
    while(cin >> y >> x)
    {
        y = y - 'A' + 1;
        spfa(x, y);
    }
    int res = INF;
    for(int i = 1; i <= n; i ++)
        for(int j = 1; j <= m; j ++)
            res = min(res, dist_sum[i][j] + dist_min[i][j]);
    cout << res << endl;
    return 0;
}
