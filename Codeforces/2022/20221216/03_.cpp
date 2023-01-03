#pragma GCC optimize(2)

#include <bits/stdc++.h>

#define fi first
#define se second
#define mkp(x, y) make_pair(x, y)
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 110, P = 998244353;

LL res = 1;
int fa[N];

int GetFa(int x) {
    if(x == fa[x]) return x;
    return fa[x] = GetFa(fa[x]);
}
void merge(int x, int y) {
    int fx = GetFa(x), fy = GetFa(y);
    if(fx != fy) 
        fa[fy] = fx;
}

void solve() {
    int n;
    cin >> n;
    for(int i = 1; i <= n; i ++) fa[i] = i;
    vector<PII> seg;
    for(int i = 1; i <= n; i ++)
        for(int j = i; j <= n; j ++) {
            int x;
            cin >> x;
            if(x == 1) {
                for(int k = i; k <= j; k ++) 
                    merge(i, j);
            }
            else if(x == 2)
                seg.push_back(mkp(i, j));
        }
    sort(all(seg));
    res = 1;
    
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