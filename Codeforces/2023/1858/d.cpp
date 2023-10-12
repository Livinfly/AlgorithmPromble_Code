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

void solve() {
    const int INF = 1e9;
    int n, k;
    string s;
    cin >> n >> k >> s;
    s = " " + s;
    vector<int> mx0(n+1, -INF);
    vector<vector<int>> pre(n+2, vector<int>(k+1));
    vector<vector<int>> suf(n+2, vector<int>(k+1));
    for(int i = 1; i <= n; i ++) {
        for(int j = 0; j <= k; j ++) {
            pre[i][j] = 0;
            if(s[i] == '0') pre[i][j] = pre[i-1][j] + 1;
            else if(j > 0) pre[i][j] = pre[i-1][j-1] + 1;
        }
    }
    for(int i = 1; i <= n; i ++) {
        pre[i][0] = max(pre[i][0], pre[i-1][0]); // miss
        for(int j = 1; j <= k; j ++) {
            pre[i][j] = max({pre[i][j], pre[i][j-1], pre[i-1][j]});
        }
    }
    for(int i = n; i >= 1; i --) {
        for(int j = 0; j <= k; j ++) {
            suf[i][j] = 0;
            if(s[i] == '0') suf[i][j] = suf[i+1][j] + 1;
            else if(j > 0) suf[i][j] = suf[i+1][j-1] + 1;
        }
    }
    for(int i = n; i >= 1; i --) {
        suf[i][0] = max(suf[i][0], suf[i+1][0]); // miss
        for(int j = 1; j <= k; j ++) {
            suf[i][j] = max({suf[i][j], suf[i][j-1], suf[i+1][j]});
        }
    }
    for(int l = 1; l <= n; l ++) { // [l, r] -> 1
        int cnt0 = 0;
        for(int r = l; r <= n; r ++) {
            cnt0 += (s[r] == '0');
            if(cnt0 > k) break;
            mx0[r-l+1] = max({mx0[r-l+1], pre[l-1][k-cnt0], suf[r+1][k-cnt0]});
        }
    }
    mx0[0] = pre[n][k];

    for(int a = 1; a <= n; a ++) {
        int ans = 0;
        for(int i = 0; i <= n; i ++) {
            // if(a==1) cerr << mx0[i] << ' ' << i << '\n';
            if(mx0[i] == -INF) continue;
            ans = max(ans, a*mx0[i] + i);
        }
        cout << ans << " \n"[a==n];
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
    cin >> Tcase; // scanf("%d", &Tcase);
    while (Tcase--) 
        solve();
    // cout << "time: " << 1000.0 * (1.*(clock() - t1) / CLOCKS_PER_SEC) << "ms\n";
    return 0;
}