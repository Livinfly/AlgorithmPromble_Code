#pragma GCC optimize(2)

#include <bits/stdc++.h>

#define fi first
#define se second
#define mkp(x, y) make_pair(x, y)
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 1010, M = 35;

int idx, h[N], ne[M], ver[M];
int n, m, q, res, nn;
int v[N], w[N];
int ans[M], idd;
vector<PII> all;
vector<int> f(10001);
bool used[N];
bitset<1001> choose_no;

void add(int a, int b) {
    ver[idx] = b, ne[idx] = h[a], h[a] = idx ++;
    ver[idx] = a, ne[idx] = h[b], h[b] = idx ++;
}
void dfs0(const int& p, int V, int W) {
    if(V > m) return;
    if(p == q) {
        // vector<int> t = f;
        res = max(res, f[m-V]+W);
        // for(int x : ans)
        //     cout << x << ' ';
        // cout << '\n';
        // cout << "f[m] " << f[m] << '\n';
        return;
    }

    int x = all[p].fi;

    // cout << "now : " << x << '\n';
    // for(int i : all) 
    //     cout << i << " : " << choose_no[i] << '\n';

    if(!choose_no[x]) {
        // cout << "111 ";
        bitset<1001> t = choose_no;
        choose_no[x] = true;
        for(int i = h[x]; ~i; i = ne[i]) {
            int v = ver[i];
            choose_no[v] = true;
        }
        ans[idd ++] = x;
        // cout << '\n';
        dfs0(p+1, V+v[x], W+w[x]);
        idd --;
        choose_no = t;
    }
    x = all[p].se;
    if(!choose_no[x]) {
        // cout << "111 ";
        bitset<1001> t = choose_no;
        choose_no[x] = true;
        for(int i = h[x]; ~i; i = ne[i]) {
            int v = ver[i];
            choose_no[v] = true;
        }
        ans[idd ++] = x;
        // cout << '\n';
        dfs0(p+1, V+v[x], W+w[x]);
        idd --;
        choose_no = t;
    }
    dfs0(p+1, V, W);
    // cout << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed;  // << setprecision(20); // double
    // freopen("i.txt", "r", stdin);
    // freopen("o.txt", "w", stdout);
    memset(h, -1, sizeof h);
    cin >> n >> m >> q;
    for(int i = 0; i < q; i ++) {
        int a, b;
        cin >> a >> b;
        all.push_back(mkp(a,b));
        used[a] = used[b] = true;
        add(a, b);
    }
    for(int i = 1; i <= n; i ++) 
        cin >> v[i] >> w[i];
    for(int i = 1; i <= n; i ++) {
        if(used[i]) continue;
        for(int j = m; j >= v[i]; j --)
            f[j] = max(f[j], f[j-v[i]]+w[i]);
    }
    // cout << "****\n";
    // memset(used, 0, sizeof used);
    dfs0(0, 0, 0);
    cout << res << '\n';
    return 0;
}
/*
3 7 1
1 2
4 5
5 999
3 5

4 3 3
1 2
2 3
3 4
1 1
1 2
1 3
1 4

3 3 3
1 2
2 3
3 1
1 1
1 2
1 3
*/