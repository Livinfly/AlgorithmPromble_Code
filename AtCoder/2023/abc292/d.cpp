#pragma GCC optimize(2)

#include <bits/stdc++.h>

#define fi first
#define se second
#define mkp(x, y) make_pair((x), (y))
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

struct DSU {
    vector<int> fa, siz, sizE;

    void Init(int n) {
        fa.resize(n+1);
        siz.resize(n+1);
        sizE.resize(n+1);
        for(int i = 1; i <= n; i ++) 
            fa[i] = i, siz[i] = 1, sizE[i] = 0;
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
        sizE[x] += sizE[y];
        sizE[x] ++;
        fa[y] = x;
        return true;
    }
    int Size(int x) {
        return siz[GetFa(x)];
    }
}dsu;

void solve() {
    int n, m;
    cin >> n >> m;
    dsu.Init(n);
    while(m --) {
    	int a, b;
    	cin >> a >> b;
    	if(dsu.Same(a, b)) {
    		dsu.sizE[dsu.GetFa(a)] ++;
    	}
    	else {
    		dsu.Merge(a, b);
    	}
    }
    for(int i = 1; i <= n; i ++) {
    	if(dsu.Size(i) != dsu.sizE[dsu.GetFa(i)]) {
    		cout << "No\n";
    		return;
    	}
    }
    cout << "Yes\n"; 
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