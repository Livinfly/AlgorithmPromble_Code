#pragma GCC optimize(2)

#include <bits/stdc++.h>

#define fi first
#define se second
#define mkp(x, y) make_pair((x), (y))
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 2e5+10;

int n, m;
LL k, a[N], b[N];

int GetBooks(LL rest) {
    int l = 0, r = m;
    while(l < r) {
        int mid = l+r+1>>1;
        if(b[mid] <= rest) l = mid;
        else r = mid-1;
    }
    return r;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed;  // << setprecision(20); // double
    
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i ++)
        cin >> a[i], a[i] += a[i-1];
    for(int i = 1; i <= m; i ++)
        cin >> b[i], b[i] += b[i-1];
    int res = 0;
    for(int i = 0; i <= n; i ++) {
        if(k >= a[i])
            res = max(res, i+GetBooks(k-a[i]));
    }
    cout << res << '\n';
    return 0;
}
/*
也可以双指针
一个从大到小，一个从小到大，一定O(n)
*/