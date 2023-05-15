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
    int n, q;
    cin >> n >> q;
    vector<int> cnt(n);
    while(q --) {
    	int op, x;
    	cin >> op >> x;
    	x --;
    	if(op == 1) {
            cnt[x] ++;
    	}
    	else if(op == 2) {
            cnt[x] += 2;
    	}
    	else {
            if(cnt[x] > 1) {
                cout << "Yes\n";
            }
            else {
    		  cout << "No\n";
            }
    	}
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