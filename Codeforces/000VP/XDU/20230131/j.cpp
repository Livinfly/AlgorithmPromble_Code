#pragma GCC optimize(2)

#include <bits/stdc++.h>

#define fi first
#define se second
#define mkp(x, y) make_pair((x), (y))
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 9e5+10;

int n, m;
int cnt[3][N];
char s[N];

void solve() {
    cin >> n;
    m = n*3;
    cin >> s+1;
    for(int i = 1; i <= m; i ++) {
        for(int j = 0; j < 3; j ++)
            cnt[j][i] = cnt[j][i-1];
        cnt[s[i]-'A'][i] ++;
    }
    if(cnt[0][m] == cnt[1][m] && cnt[1][m] == cnt[2][m]) {
        cout << "0\n";
        return;
    }
    int p = 0, tcnt = 0;
    for(int i = 0; i < 3; i ++) {
        if(cnt[i][m] < cnt[p][m]) p = i;
        if(cnt[i][m] >= n) tcnt ++;
    }
    // 1
    if(tcnt == 2) {
        for(int l = 1, r = 1; r <= m; r ++) {
            bool ok = true;
            if(r-l+1-(cnt[p][r]-cnt[p][l-1]) != n-cnt[p][m]) ok = false;
            
            for(int i = 0; i < 3; i ++) {
                if(i == p) continue;
                if(cnt[i][r]-cnt[i][l-1] != cnt[i][m]-n) {
                    ok = false;
                    if(cnt[i][r]-cnt[i][l-1] > cnt[i][m]-n) {
                        l ++;
                        // r --;
                        break;
                    }
                }
            }
            // cout << l << ' ' << r << '\n';
            // cout << r-l+1-(cnt[p][r]-cnt[p][l-1]) << '\n';
            if(l > r) continue;
            if(ok) {
                cout << "1\n";
                cout << l << ' ' << r << ' ' << (char)('A'+p) << '\n';
                return;
            }
        }
    }
    // 2
    int pos = 1;
    for(int i = n; i <= m; i ++) {
        bool ok = false;
        for(int j = 0; j < 3; j ++) {
            if(cnt[j][i] == n) {
                pos = i;
                p = s[i]-'A';
                ok = true;
                break;
            }
        }
        if(ok) break;
    }
    int t = pos+1;
    cout << "2\n";
    for(int i = 0; i < 3; i ++)
        if(i != p) {
            cout << t << ' ' << t+n-cnt[i][pos]-1 << ' ' << (char)('A'+i) << '\n';
            t = t+n-cnt[i][pos];
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