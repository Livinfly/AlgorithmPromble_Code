#pragma GCC optimize(2)

#include <bits/stdc++.h>

#define fi first
#define se second
#define mkp(x, y) make_pair((x), (y))
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 4e6+10, MO = 998244353, G = 3, Gi = 332748118;

int n, m, limit, rr;
int R[N];
int a[N], b[N], aa[N], bb[N];

int qpm(int a, int b, const int &c = MO) {
    int ans = 1;
    while(b) {
        if(b & 1) ans = 1LL*ans*a%MO;
        a = 1LL*a*a%MO;
        b >>= 1;
    }
    return ans;
}
void NTT(int a[], int on) {
    for(int i = 0; i < limit; i ++)
        if(i < R[i]) swap(a[i], a[R[i]]);
    for(int mid = 1; mid < limit; mid <<= 1) {
        int Wn = qpm((on == 1 ? G : Gi), (MO-1)/(mid<<1));
        for(int j = 0, r = mid<<1; j < limit; j += r) {
            int w = 1;
            for(int k = 0; k < mid; k ++, w = 1LL*w*Wn%MO) {
                int x = a[j+k], y = 1LL*w*a[j+mid+k]%MO;
                a[j+k] = (1LL*x+y)%MO;
                a[j+mid+k] = (1LL*x-y)%MO;
            }
        }
    }
}
void Convolution(int a[], int b[]) {
    limit = 1, rr = 0;
    while(limit <= n+m) limit <<= 1, rr ++;
    for(int i = 0; i < limit; i ++)
        R[i] = (R[i>>1]>>1) | ((i&1)<<(rr-1));
    NTT(a, 1), NTT(b, 1);
    for(int i = 0; i <= limit; i ++)
        a[i] = 1LL*a[i]*b[i]%MO;
    NTT(a, -1);
    int inv = qpm(limit, MO-2);
    for(int i = 0; i <= n+m; i ++) {
        a[i] = (1LL*a[i]*inv%MO+MO)%MO;
        // cerr << a[i] << " \n"[i == n+m];
    }
}
void solve() {
    cin >> n;
    for(int i = 0; i < n; i ++) {
        cin >> a[i];
        a[i+n] = a[i];
    }
    for(int i = 0; i < n; i ++) {
        cin >> b[i];
    }
    m = n-1, n = 2*n-1;
   	vector<int> ans(m+1);
    for(int k = 0; k < 5; k ++) {
        memset(aa, 0, sizeof aa);
        memset(bb, 0, sizeof bb);
        for(int i = 0; i <= n; i ++) {
            aa[i] = ~a[n-i]>>k & 1;
            // cerr << aa[i] << " \n"[i == n];
        }
        for(int i = 0; i <= m; i ++) {
            bb[i] = ~b[i]>>k & 1;
            // cerr << bb[i] << " \n"[i == m];
        }
        Convolution(aa, bb);
        for(int i = m; i <= 2*m; i ++) {
            ans[i-m] += (m+1 - aa[i])<<k; // 取反
        }
    }
    cout << *max_element(all(ans)) << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed;  // << setprecision(20); // double
    // freopen("i.txt", "r", stdin);
    // freopen("o.txt", "w", stdout);
    // time_t t1 = clock();
    int Tcase = 1;
    // cin >> Tcase; // scanf("%d", &Tcase);
    while (Tcase--) 
        solve();
    // cout << "time: " << 1000.0 * ((clock() - t1) / CLOCKS_PER_SEC) << "ms\n";
    return 0;
}