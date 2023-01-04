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
    LL n, m;
    cin >> n >> m;
    vector<LL> a(n);
    for(auto &x : a) cin >> x;
    LL cnt = 0, tsum = 0;
    priority_queue<LL, vector<LL>, greater<LL> > heap;
    for(int i = m; i < n; i ++) {
        if(a[i] < 0) heap.push(a[i]);
        tsum += a[i];
        while(tsum < 0) {
            int t = heap.top(); heap.pop();
            tsum -= 2*t;
            cnt ++;
        }
    }
    if(a[m-1]<=0) tsum = a[m-1];
    else if(m != 1) tsum = -a[m-1], cnt ++;

    priority_queue<int> hp;
    for(int i = m-2; i >= 1; i --) {
        if(a[i] > 0) hp.push(a[i]);
        tsum += a[i];
        while(tsum > 0) {
            int t = hp.top(); hp.pop();
            tsum -= 2*t;
            cnt ++;
        }
    }
    cout << cnt << '\n';
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