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

char s[N];
bool st[N];
vector<PII> ans;
vector<int> ll, bb, rr;

void solve() {
    int n;
    cin >> n;
    cin >> s+1;
    for(int i = 1; i <= n*2; i ++) {
        if(s[i] == 'A') ll.push_back(i);
        else if(s[i] == 'B') bb.push_back(i);
        else rr.push_back(i);
    }
    int dx = n-ll.size();
    if(dx >= 0) {
        for(int i = 0; i < dx; i ++) {
            auto iter = upper_bound(all(rr), bb[i]);
            if(iter == rr.end()) {
                cout << "NO\n";
                return;
            }
            int p = *iter;
            rr.erase(iter);
            ans.push_back({bb[i], p});
            // cout << bb[i] << ' ' << p << '\n';
        }
        for(int i = dx; i < bb.size(); i ++)
            rr.push_back(bb[i]);
    }
    else {
        cout << "NO\n";
        return;
    }
    sort(all(rr));
    for(int i = 0; i < ll.size(); i ++) {
        if(ll[i] < rr[i]) {
            ans.push_back({ll[i], rr[i]});
            // cout << ll[i] << ' ' << rr[i] << '\n';
        }
        else {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
    for(auto x : ans) 
        cout << x.fi << ' ' << x.se << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed;  // << setprecision(20); // double
    // freopen("i.txt", "r", stdin);
    // freopen("o.txt", "w", stdout);
    // time_t t1 = clock();
    // int Tcase;
    // cin >> Tcase; // scanf("%d", &Tcase);
    // while (Tcase--) 
    solve();
    // cout << "time: " << 1000.0 * ((clock() - t1) / CLOCKS_PER_SEC) << "ms\n";
    return 0;
}