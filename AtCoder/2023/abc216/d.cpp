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
    int n, m; cin >> n >> m;
    vector<vector<int>> ve(m);
    vector<int> cnt(n+1), p(m);
    set<PII> st;
    for(int i = 0; i < m; i ++) {
        int k; cin >> k;
        ve[i].resize(k+1);
        for(int j = 0; j < k; j ++) {
            cin >> ve[i][j];
        }
    }
    int i = 0, ccnt = 0;
    function<void(int)> work = [&](int x) {
        if(cnt[x] == 2) {
            auto it = st.lower_bound({x, 0});
            int g = it->se, y = ve[g][p[g]+1];
            if(y) {
                st.insert({y, g});
                cnt[y]++;
                ccnt++;
                p[g]++;
                work(y);
            }
            it++;
            g = it->se, y = ve[g][p[g]+1];
            if(y) {
                st.insert({y, g});
                cnt[y]++;
                ccnt++;
                p[g]++;
                work(y);
            }
        }
    };
    while(true) {
        if(ccnt == n*2) break;
        int x = ve[i][p[i]];
        if(st.count({x, i})) {
            cout << "No\n";
            return;
        }
        st.insert({x, i});
        cnt[x]++;
        ccnt++;
        work(x);
        i++;
        if(i >= m) i = 0;
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
    // cout << "time: " << 1000.0 * (1.*(clock() - t1) / CLOCKS_PER_SEC) << "ms\n";
    return 0;
}