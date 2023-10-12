// #pragma GCC optimize(2)

#include <bits/stdc++.h>

#define fi first
#define se second
#define pb push_back
#define mkp(x, y) make_pair((x), (y))
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;
typedef double db;
typedef pair<int, int> PII;

const int N = 2e5+10;

vector<int> e[N];
int n, a[N], in[N];
int st[N]; // 1 - circled
queue<int> q;

bool bfs() {
    bool ret = true;
    while(!q.empty()) {
        int u = q.front(); q.pop();
        if(!st[u]) st[u] = 1;
        bool ok = false;
        for(auto v: e[u]) {
            if(st[v] == 1) continue;
            ok = true;
            if(st[u] == 1) st[v] = 2;
            if(--in[v] == 0) q.push(v);
        }
        if(!ok && st[u] == 1) ret = false;
    }
    return ret;
}
void solve() {
    cin >> n;
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
        e[i].pb(a[i]);
        in[a[i]]++;
    }
    for(int i = 1; i <= n; i ++) {
        if(!in[i]) q.push(i);
    }
    // 基环树 -> 环（部分环环上被圈）
    bool ok = bfs();
    // 处理完环上被圈的环
    for(int i = 1; i <= n; i ++) {
        if(st[i] == 2 && in[i]) q.push(i);
        ok &= bfs();
    }
    // 处理未被圈的环
    for(int i = 1; i <= n; i ++) {
        if(in[i]) q.push(i);
        ok &= bfs();
    }
    if(!ok) {
        cout << "-1\n";
        return;
    }
    int cnt = 0;
    for(int i = 1; i <= n; i ++) {
        if(st[i] == 1) cnt++;
    }
    cout << cnt << '\n';
    for(int i = 1; i <= n; i ++) {
        if(st[i] == 1) {
            cout << a[i] << ' ';
        }
    }
    cout << '\n';
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
    // cout << "time: " << 1000.0 * (1.*(clock() - t1) / CLOCKS_PER_SEC) << "ms\n";
    return 0;
}
/*
基环树形状的都会直接在第一次就拆完了，然后第二次里面都是没访问的环。
*/