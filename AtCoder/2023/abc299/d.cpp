#pragma GCC optimize(2)

#include <bits/stdc++.h>

#define fi first
#define se second
#define mkp(x, y) make_pair((x), (y))
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

string Ask(int mid) {
	cout << "? " << mid << endl;
	string r;
	cin >> r;
	return r;
}
void solve() {
    int n;
    cin >> n;
    int l = 1, r = n-1;
    while(l < r) {
    	int mid = l+r+1 >> 1;
    	if(Ask(mid) == "0") l = mid;
    	else r = mid-1;
    }
    cout << "! " << r << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
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