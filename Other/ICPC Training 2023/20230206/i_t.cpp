#pragma GCC optimize(2)

#include <bits/stdc++.h>

#define fi first
#define se second
#define mkp(x, y) make_pair((x), (y))
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 1e6+10;

int n;
int a[N], b[N];

void solve() {
    cin >> n;
    for(int i = 1; i <= n; i ++)
        a[i] = i;
    do {
        int res = n;
        for(int i = 0; i < (1<<res); i ++) {
            memcpy(b, a, sizeof b);
            for(int j = 0; j < res; j ++) {
                if(i>>j & 1) 
                    sort(b+1, b+j+1+1);
                else 
                    sort(b+n-j, b+n+1);
                if(is_sorted(b+1, b+n+1)) {
                    res = min(res, j+1);
                    break;
                }
            }
        }
        int suml = 0, sumr = 0, ans = 0;
        memcpy(b, a, sizeof b);
        do {
            ans ++;
            // cout << l << ' ' << r << '\n';
            suml = sumr = 0;
            for(int i = 1; i <= n; i ++) {
                if(b[i] <= n/2) suml += i+n-b[i];
                else sumr = n-i+1+b[i];
            }
            
            if(suml < sumr) {
                // cout << "P";
                sort(b+1, b+ans+1);
            }
            else {
                // cout << "S";
                sort(b+n-ans+1, b+n+1);
            }
        } while(!is_sorted(b+1, b+n+1));
        // cout << '\n';
        // cout << res << ' ' << ans << endl;
        if(res != ans) {
            for(int i = 1; i <= n; i ++)
                cout << a[i] << " \n"[i == n];
            cout << res << ' ' << ans << endl;
            break;
        }
    }while(next_permutation(a+1, a+n+1));
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