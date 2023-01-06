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
    int n;
    cin >> n;
    vector<int> a(n);
    for(auto &x : a) cin >> x;
    vector<int> s(2), t(2);
    int l = 0, r = n-1, cnt = 0, p = 0;
    while(l <= r) {
        // cout << l << ' ' << r << endl;
        t[p] = 0;
        while(l <= r && t[p] <= t[1-p]) {
            if(!p) 
                t[p] += a[l ++];
            else 
                t[p] += a[r --];
        }
        s[p] += t[p];
        // if(!p)  
        //     cout << "A : " << s[p] << '\n';
        // else 
        //     cout << "B : " << s[p] << '\n';
        cnt ++;
        p = 1-p;
    }
    cout << cnt << ' ' << s[0] << ' ' << s[1] << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed;  // << setprecision(20); // double
    // freopen("i.txt", "r", stdin);
    // freopen("o.txt", "w", stdout);
    int Tcase;
    cin >> Tcase;  // scanf("%d", &Tcase);
    while (Tcase--) solve();
    return 0;
}