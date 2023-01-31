#pragma GCC optimize(2)

#include <bits/stdc++.h>

#define fi first
#define se second
#define mkp(x, y) make_pair((x), (y))
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 2e5+10;

int n, root;
int w[N];
bool rooted;
bool st[N];
vector<int> e[N], ans;

bool cmpw(int a, int b) {
    return w[a] < w[b];
}
void dfs1(int u) {
    st[u] = true;
    if(e[u].size() == 1) w[u] = u;
    for(auto v : e[u]) {
        if(!st[v]) {
            dfs1(v);
            if(!w[u]) w[u] = w[v];
            else w[u] = min(w[u], w[v]);
        }
    }
}
/*
前面遍历叶子小的子树里面一定不能有根，有根，要么是它的叶子作为第一个遍历，要么就是我们来的地方已经遍历完了，一定更劣
*/
void dfs2(int u, bool rootOk) {
    st[u] = false;
    if(e[u].size() == 1) {
        ans.push_back(u);
    }
    else if(e[u].size() > 1) {
        int t = e[u].size()-1;
        if(!st[e[u][t]]) t --; // !!!
        for(int i = 0; i < t; i ++) {
            int v = e[u][i];
            if(st[v]) {
                dfs2(v, false);
            }
        }
        int p = e[u][t];
        if(rootOk && w[p] > u) { // go to root
            ans.push_back(u);
            dfs2(p, true);
        }
        else { // u is root
            dfs2(p, false);
            ans.push_back(u);
        }
    }
}
void solve() {
    rooted = false;
    cin >> n;
    for(int i = 1; i <= n; i ++) 
        st[i] = false, w[i] = 0, e[i].clear();
    for(int i = 1; i < n; i ++) {
        int a, b;
        cin >> a >> b;
        e[a].push_back(b), e[b].push_back(a);
    }

    for(int i = 1; i <= n; i ++)
        if(e[i].size() == 1) {
            root = i;
            break;
        }
    
    ans.clear();
    dfs1(root);
    for(int i = 1; i <= n; i ++) 
        sort(all(e[i]), cmpw);
    
    ans.push_back(root);
    st[root] = false;
    dfs2(e[root][0], true);

    for(auto x : ans)
        cout << x << ' ';
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed;  // << setprecision(20); // double
    // freopen("i.txt", "r", stdin);
    // freopen("o.txt", "w", stdout);
    // time_t t1 = clock();
    int Tcase;
    cin >> Tcase; // scanf("%d", &Tcase);
    while (Tcase--) 
        solve();
    // cout << "time: " << 1000.0 * ((clock() - t1) / CLOCKS_PER_SEC) << "ms\n";
    return 0;
}