#pragma GCC optimize(2)

#include <bits/stdc++.h>

#define fi first
#define se second
#define mkp(x, y) make_pair((x), (y))
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

struct DSU {// int / LL
    vector<int> fa, siz;

    void Init(int n) {
        fa.resize(n+1);
        siz.resize(n+1);
        for(int i = 1; i <= n; i ++) 
            fa[i] = i, siz[i] = 1;
    }
    int GetFa(int x) {
        if(x == fa[x]) return x;
        return fa[x] = GetFa(fa[x]);
    }
    bool Same(int x, int y) {
        return GetFa(x) == GetFa(y);
    }
    bool Merge(int x, int y) {
        x = GetFa(x), y = GetFa(y);
        if(x == y) return false;
        siz[x] += siz[y];
        fa[y] = x;
        return true;
    }
    int Size(int x) {
        return siz[GetFa(x)];
    }
}dsu;

void solve() {
    int n;
    cin >> n;
    dsu.Init(n);
    vector<int> p(n+1);
   	for(int i = 2; i <= n; i ++) {
   		cin >> p[i];
   	}
   	int q;
   	cin >> q;
   	while(q --) {
   		int op;
   		cin >> op;
   		if(op == 1) {
   			int u, v;
   			cin >> u >> v;
   			u = dsu.GetFa(u), v = dsu.GetFa(v);
   			while(u != v) { 
   				dsu.Merge(p[u], u);
   				u = dsu.GetFa(p[u]);
   			}
   		}
   		else {
   			int x;
   			cin >> x;
   			cout << dsu.GetFa(x) << '\n';;
   		}
   	}
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
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