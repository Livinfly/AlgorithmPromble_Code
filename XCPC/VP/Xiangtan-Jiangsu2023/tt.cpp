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

int n, m;
int a[N];

int BinarySearch(int a[], int x) {
	int l = 0, r = n;
    
    // 写法一：
	while(l < r) {
		int mid = l+r >> 1;
		if(a[mid] < x) l = mid+1;
		else r = mid;
	}

    // 写法二：
    // r = lower_bound(a, a+n, x)-a;

	if(a[r] != x) return -1;
	return r+1;
}
void solve() {
    cin >> n >> m;
    for(int i = 0; i < n; i ++) cin >> a[i];
    while(m --) {
    	int x;
    	cin >> x;
    	cout << BinarySearch(a, x) << ' ';
    }
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