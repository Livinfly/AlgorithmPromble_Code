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

int n, m, person;
vector<int> ve, cnt, ans, ccnt;

void dfs(int u) {
    if(u == n-1) {
        int mx = 0, mx_ = 0, p = -1, p_ = -1, tcnt = 0, tcnt_ = 0;
        for(int i = 1; i <= m; i ++) {
            if(cnt[i] > mx) {
                mx = cnt[i];
                p = i;
            }
            if(cnt[i] == mx) tcnt++;
        }
        mx_ = mx-1;
        if(mx_) {
            for(int i = 1; i <= m; i ++) {
                if(cnt[i] == mx_) {
                    if(tcnt_ == 0) p_ = i;
                    tcnt_++;
                }
            }
        }
        bool ok = false;
        if(p > 0 && p_ > 0) {
            if(tcnt == n-2 && tcnt_ == 1) {
                ans.push_back(p_);
                ok = true;
            }
            else if(tcnt == 1 && tcnt_ == n-2) {
                ans.push_back(p);
                ok = true;
            }
        }
        int tp = -1;
        for(int i = 1; i <= m; i ++) {
            if(cnt[i] == mx || mx_ && cnt[i] == mx_) {
                tp = i;
                break;
            }
        }
        if(!ok) ans.push_back(tp);
        return;
    }
    for(int i = 1; i <= m; i ++) {
        ve.push_back(i);
        cnt[i]++;
        dfs(u+1);
        ve.pop_back();
        cnt[i]--;
    }
}
void solve() {
    cin >> n >> m;
    cnt.resize(m+1);
    dfs(0);
    while(n--) {
        for(auto x: ans) {
            cout << x << ' ';
        }
        cout << '\n';
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