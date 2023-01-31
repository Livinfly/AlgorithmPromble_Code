#pragma GCC optimize(2)

#include <bits/stdc++.h>

#define fi first
#define se second
#define mkp(x, y) make_pair((x), (y))
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, int> PLI;

const int G = 410, N = 1e4+10;

int n, m;
int fa[N], siz[N], id[G][G], deg[N];
string g[G];
vector<int> degBy[N];

int GetFa(int x) {
    return ((x == fa[x]) ? x : fa[x] = GetFa(fa[x]));
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed;  // << setprecision(20); // double
    // freopen("i.txt", "r", stdin);
    // freopen("o.txt", "w", stdout);
    int Tcase;
    cin >> Tcase;
    for(int TTT = 1; TTT <= Tcase; TTT ++) {
        LL cnt = 0;
        cin >> n >> m;
        getline(cin, g[0]);
        for(int i = 0; i < n*4+3; i ++)
            getline(cin, g[i]);
        for(int i = 2; i < n*4+3; i += 2)
            for(int j = 4; j < g[i].size(); j += 6) {
                if(g[i][j] == '*') id[i][j] = ++ cnt;
                else id[i][j] = 0;
            }

        for(int i = 1; i <= cnt; i ++)
            fa[i] = i, siz[i] = 1, deg[i] = 0, degBy[i].clear();
        for(int i = 2; i < n*4+3; i += 2)
            for(int j = 4; j < g[i].size(); j += 6)
                if(id[i][j]) {
                    // cout << i << ' ' << j << '\n';
                    int a = i-2, b = j+6;
                    if(b < g[a].size()) {
                        if(id[a][b] && g[i-1][j+3] == ' ') {
                            deg[id[i][j]] ++, deg[id[a][b]] ++;
                            degBy[id[i][j]].push_back(id[a][b]);
                            degBy[id[a][b]].push_back(id[i][j]);
                            int fx = GetFa(id[i][j]), fy = GetFa(id[a][b]);
                            if(fx != fy) {
                                siz[fx] += siz[fy];
                                fa[fy] = fx;
                            }
                        }
                    }
                    a = i+2;
                    if(b < g[a].size()) {
                        if(id[a][b] && g[i+1][j+3] == ' ') {
                            deg[id[i][j]] ++, deg[id[a][b]] ++;
                            degBy[id[i][j]].push_back(id[a][b]);
                            degBy[id[a][b]].push_back(id[i][j]);
                            int fx = GetFa(id[i][j]), fy = GetFa(id[a][b]);
                            if(fx != fy) {
                                siz[fx] += siz[fy];
                                fa[fy] = fx;
                            }
                        }
                    }
                    a = i+4, b = j;
                    if(a < n*4+3 && b < g[a].size()) {
                        if(id[a][b] && g[i+2][j] == ' ') {
                            deg[id[i][j]] ++, deg[id[a][b]] ++;
                            degBy[id[i][j]].push_back(id[a][b]);
                            degBy[id[a][b]].push_back(id[i][j]);
                            int fx = GetFa(id[i][j]), fy = GetFa(id[a][b]);
                            if(fx != fy) {
                                siz[fx] += siz[fy];
                                fa[fy] = fx;
                            }
                        }
                    }
                }
        LL res = 0;
        priority_queue<PII, vector<PII>, greater<PII>> heap;
        for(int i = 1; i <= cnt; i ++) {
            heap.push({deg[i], i});
        }
        while(heap.size()) {
            auto t = heap.top(); heap.pop();
            auto i = t.se;
            if(t.fi != deg[i]) continue;
            int fx = GetFa(i);
            siz[fx] --;
            res += t.fi*siz[fx];
            if(deg[i] == 1)
                for(auto x : degBy[i]) 
                    deg[x] --;
        }
        cout << "Case #" << TTT << ": " << res << '\n';
    }
    return 0;
}
/*
同一排 x+2, y+6, x, y+12
x+4, y+6

*/