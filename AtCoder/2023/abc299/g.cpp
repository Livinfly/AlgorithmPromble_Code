#pragma GCC optimize(2)

#include <bits/stdc++.h>

#define fi first
#define se second
#define mkp(x, y) make_pair((x), (y))
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), lst(m+1);
    for(int i = 0; i < n; i ++) {
        cin >> a[i];
        lst[a[i]] = i;
    }
    int l = 0, r = -1;
    set<int> lstp;
    set<PII> st;
    vector<int> ans;
    vector<bool> vis(m+1);

    for(int i = 1; i <= m; i ++) 
        lstp.insert(lst[i]);

    for(int i = 0; i < m; i ++) {
        while(r < *lstp.begin()) {
            r ++;
            st.insert({a[r], r});
        }
        while(true) {
            auto [x, id] = *st.begin();
            st.erase(st.begin());
            if(vis[x]) 
                continue;
            ans.push_back(x);
            vis[x] = true;
            lstp.erase(lst[x]);
            while(l <= id) {
                st.erase({a[l], l});
                l ++;
            }
            break;
        }
    }
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
    int Tcase = 1;
    // cin >> Tcase; // scanf("%d", &Tcase);
    while (Tcase--) 
        solve();
    // cout << "time: " << 1000.0 * ((clock() - t1) / CLOCKS_PER_SEC) << "ms\n";
    return 0;
}