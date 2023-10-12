// #pragma GCC optimize(2)

#include <bits/stdc++.h>

#define fi first
#define se second
#define mkp(x, y) make_pair((x), (y))
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;
typedef double db;
typedef pair<int, int> PII;

const int N = 1e6+10;

int idx, cur;
vector<int> son[N], query[N];
int n, qry, ans[N], w[N], f[N][20], cnt[N];
int sum;

void dfs(int u) {
    if(u != 1 && ++cnt[w[u]] == 1) sum++;
    for(auto v: query[u]) ans[v] = sum;
    for(auto v: son[u]) dfs(v);
    if(u != 1 && --cnt[w[u]] == 0) sum--; 
}
void solve() {
    idx = cur = 1;
    cin >> n;
    vector<int> stk;
    stk.reserve(n);
    stk.push_back(1);
    while(n--) {
        int x; char op;
        cin >> op;
        if(op == '+') {
            cin >> x;
            w[++idx] = x;
            son[cur].push_back(idx);
            f[idx][0] = cur;
            for(int k = 1; k < 20; k ++) {
                f[idx][k] = f[f[idx][k-1]][k-1];
            }
            cur = idx;
            stk.push_back(cur);
        }
        else if(op == '-') {
            cin >> x;
            for(int k = 0; k < 20; k ++) {
                if(x>>k & 1) {
                    cur = f[cur][k];
                }
            }
            stk.push_back(cur);
        }
        else if(op == '!') {
            stk.pop_back();
            cur = stk.back();
        }
        else {
            query[cur].push_back(qry++);
        }
    }
    dfs(1);
    for(int i = 0; i < qry; i ++) {
        cout << ans[i] << '\n';
    }
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