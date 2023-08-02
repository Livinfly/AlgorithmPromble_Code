#pragma GCC optimize(2)

#include <bits/stdc++.h>

#define fi first
#define se second
#define mkp(x, y) make_pair((x), (y))
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

LL s, k, p, ans;

LL f(LL mid) {
    LL t = (mid-p) / 4, tts = s, ttp = p;
    tts += t*20;
    ttp += t*4;
    while(ttp < mid) {
        tts += tts%10;
        ttp++;
    }
    return tts * (k-mid);
}
void solve() {
    cin >> s >> k;
    ans = p = 0;
    LL ts = s;
    if(!s) {
        cout << "0\n";
        return;
    }
    // 2 4 8 6, 2 4 8 6, 1->(), 3->6(), 0 5
    for(p = 0; p < k; p ++) {
        ans = max(ans, s * (k-p));
        if(s + s%10 == 2*s) {
            s += s%10;
        }
        else {
            break;
        }
    }
    s = ts;
    if(s % 5) {
        p = 0;
        while(s%10 != 2 && p < k) {
            ans = max(ans, s * (k-p));
            s += s%10;
            p++;
        }
        LL mid = k/2, len = k/10;
        for(int i = mid-len; i <= mid+len; i ++) {
            // if(i == 355758828) {
            //     cerr << f(i) << '\n';
            // }
            ans = max(ans, f(i));
        }
    }
    cout << ans << '\n';
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