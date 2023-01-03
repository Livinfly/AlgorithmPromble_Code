#pragma GCC optimize(2)

#include <bits/stdc++.h>

#define fi first
#define se second
#define mkp(x, y) make_pair(x, y)
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

int get_cnt(int x, int c) {
    int cnt = 0;
    while(x % c == 0) {
        x /= c;
        cnt ++;
    }
    return cnt;
}
void solve() {
    LL n, m;
    cin >> n >> m;
    int cnt2 = get_cnt(n, 2), cnt5 = get_cnt(n, 5);
    LL k = 1;
    if(cnt2 == cnt5) {
        while(k * 10 <= m)
            k *= 10;
        k = m/k*k;
        cout << n*k << '\n';
    }
    else if(cnt2 > cnt5) {
        int t2 = cnt2 - cnt5;
        while(t2 && k*5 <= m)
            k *= 5, t2 --;
        while(k*10 <= m) 
            k *= 10;
        k = m/k*k;
        // cout << "?????\n";
        cout << n*k << '\n';
    }
    else {
        int t5 = cnt5 - cnt2;
        while(t5 && k*2 <= m)
            k *= 2, t5 --;
        while(k*10 <= m) 
            k *= 10;
        k = m/k*k;
        cout << n*k << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed;  // << setprecision(20); // double
    // freopen("i.txt", "r", stdin);
    // freopen("o.txt", "w", stdout);
    int T;
    cin >> T;  // scanf("%d", &T);
    while (T--) solve();
    return 0;
}