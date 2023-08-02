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
    LL n, k;
    cin >> n >> k;
    vector<LL> num;
    LL t = n;
    while(t) {
        num.push_back(t % 3);
        t /= 3;
    }
    LL sum = accumulate(all(num), 0);
    if(k < sum || k > n) {
        cout << "No\n";
        return;
    }
    k -= sum;
    for(int i = num.size()-1; i > 0; i --) {
        LL tt = min(num[i], (k / 2));
        k -= tt * 2;
        num[i-1] += tt * 3;
        // cerr << k << ' ' << tt << ' ' << num[i-1] << ' ' << num[i] << '\n';
    }
    // cout << k << '\n';
    if(!k) {
        cout << "Yes\n";
    }
    else {
        cout << "No\n";
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
    // cout << "time: " << 1000.0 * ((clock() - t1) / CLOCKS_PER_SEC) << "ms\n";
    return 0;
}