#pragma GCC optimize(2)

#include <bits/stdc++.h>

#define fi first
#define se second
#define mkp(x, y) make_pair((x), (y))
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 110;

int n, m;
int a[N], fa[N];

void solve() {
    cin >> n >> m;
    for(int i = 1; i <= n; i ++)
        a[i] = i, fa[i] = i;
    while(m --) {
        int x;
        cin >> x;
        fa[x] = x+1;
    }
    for(int i = n-1; i > 0; i --) {
        fa[i] = fa[fa[i]];
    }
    // for(int i = 1; i <= n; i ++)
    //     cout << fa[i] << " ";
    // cout << endl;
    for(int i = 1, j; i <= n; i = j) {
        reverse(a+i, a+fa[i]+1);
        j = fa[i]+1;
        // cout << i << endl;
    }
    for(int i = 1; i <= n; i ++)
        cout << a[i] << " \n"[i == n];
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