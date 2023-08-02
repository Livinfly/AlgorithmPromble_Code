#pragma GCC optimize(2)

#include <bits/stdc++.h>

#define fi first
#define se second
#define mkp(x, y) make_pair((x), (y))
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;
typedef double db;
typedef pair<int, int> PII;

const int N = 1e3+10;

PII dxy[] = {
    {0, 1}, {1, 0}, {0, -1}, {-1, 0},
};
string g[N];

void solve() {
    int h, w, S, T;
    cin >> h >> w;
    int x, y;
    cin >> x >> y;
    x--, y--;
    S = x*w + y;
    cin >> x >> y;
    x--, y--;
    T = x*w + y;
    for(int i = 0; i < h; i ++) cin >> g[i];
    deque<PII> deq;
    deq.emplace_back(S, 0);
    vector<int> dis(h*w, -1);
    while(deq.size()) {
        auto [p, d] = deq.front();
        deq.pop_front();
        if(dis[p] != -1) continue;
        dis[p] = d;
        int x = p/w, y = p%w;
        for(auto [dx, dy]: dxy) {
            int a = x+dx, b = y+dy;
            if(a < 0 || a >= h || b < 0 || b >= w || g[a][b] == '#') continue;
            deq.emplace_front(a*w+b, d);
        }
        for(int dx = -2; dx <= 2; dx ++) {
            for(int dy = -2; dy <= 2; dy ++) {
                int a = x+dx, b = y+dy;
                if(a < 0 || a >= h || b < 0 || b >= w || g[a][b] == '#') continue;
                deq.emplace_back(a*w+b, d+1);
            }
        }
    }
    cout << dis[T] << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed;  // << setprecision(20); // double
    // freopen("i.txt", "r", stdin);
    // freopen("o.txt", "w", stdout);
    // time_t t1 = clock();
    int Tcase = 1;
    // cin >> Tcase; // scanf("%d", &Tcase);
    while (Tcase--) 
        solve();
    // cout << "time: " << 1000.0 * ((clock() - t1) / CLOCKS_PER_SEC) << "ms\n";
    return 0;
}