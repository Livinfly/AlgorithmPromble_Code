#pragma GCC optimize(2)

#include <bits/stdc++.h>

#define fi first
#define se second
#define mkp(x, y) make_pair((x), (y))
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 1e5+10;

int n, m, x;
int a[N];
bool st[N];
set<int> trap;

void solve() {
    cin >> n;
    for(int i = 0; i < n; i ++)
        cin >> a[i];
    cin >> m;
    for(int i = 0; i < m; i ++) {
        int a;
        cin >> a;
        trap.insert(a);
    }

    cin >> x;
    st[0] = true;

    for(int i = 1; i <= x; i ++) {
        if(!trap.count(i)) {
            for(int j = 0; j < n; j ++) {
                if(st[i] || i < a[j]) break;
                if(!st[i]) st[i] = st[i-a[j]];
            }
        }
    }
    if(st[x]) {
        cout << "Yes\n";
    }
    else {
        cout << "No\n";
    }
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