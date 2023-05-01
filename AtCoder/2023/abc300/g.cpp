#pragma GCC optimize(2)

#include <bits/stdc++.h>

#define fi first
#define se second
#define mkp(x, y) make_pair((x), (y))
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

vector<int> primes, minp;

void Sieve(int n) {
    primes.clear();
    minp.assign(n+1, 0);
    for(int i = 2; i <= n; i ++) {
        if(!minp[i]) {
            minp[i] = i;
            primes.push_back(i);
        }
        for(auto p : primes) {
            if(p > n/i) {
                break;
            }
            minp[i*p] = p;
            if(p == minp[i]) {
                break;
            }
        }
    }
}

void solve() {
    LL n;
    int p;
    cin >> n >> p;
    Sieve(p);
    function<void(int, int, LL, vector<LL> &)> dfs = [&](int cur, int goal, LL x, vector<LL> &ans) {
        if(cur == goal) {
            ans.push_back(x);
            return;
        }
        while(x <= n) {
            dfs(cur+1, goal, x, ans);
            x *= primes[cur];
        }
    };
    int c = primes.size();
    int c1 = min(c, 8);
    vector<LL> ans1, ans2;
    dfs(0, c1, 1, ans1);
    dfs(c1, c, 1, ans2);
    // cout << ans1.size() << ' ' << ans2.size() << '\n';
    sort(all(ans1)), sort(all(ans2));

    LL res = 0;
    for(int i = 0, j = ans2.size()-1; i < ans1.size(); i ++) {
        while(j >= 0 && ans2[j] > n/ans1[i]) {
            j --;
        }
        if(j < 0) break;
        res += j+1;
    }
    cout << res << '\n';
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