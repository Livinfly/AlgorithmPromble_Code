#pragma GCC optimize(2)

#include <bits/stdc++.h>

#define fi first
#define se second
#define mkp(x, y) make_pair((x), (y))
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

int n, bSize, bNum;
vector<int> a, belong, sum;
vector<bool> done;

void Modify(int l, int r) {
	int bl = belong[l], br = belong[r];
	if(bl == br) {
		for(int i = l; i <= r; i ++) {
			sum[bl] -= a[i];
			a[i] = sqrt(a[i]);
			sum[bl] += a[i];
		}
	}
	else {
		for(int i = bl+1; i < br; i ++) {
			if(done[i]) continue;
			done[i] = true;
            // 和n要取较小的值，循环里面i和j不要想错了qwq
			for(int j = (i-1)*bSize + 1; j <= min(i*bSize, n); j ++) {
				sum[i] -= a[j];
				a[j] = sqrt(a[j]);
				sum[i] += a[j];
				if(a[j] > 1) done[i] = false;
			}
		}
		for(int i = l; i <= n && belong[i] == bl; i ++) {
			sum[bl] -= a[i];
			a[i] = sqrt(a[i]);
			sum[bl] += a[i];
		}
		for(int i = r; i > 0 && belong[i] == br; i --) {
			sum[br] -= a[i];
			a[i] = sqrt(a[i]);
			sum[br] += a[i];
		}
	}
}
int Query(int l, int r) {
	int bl = belong[l], br = belong[r];
	int ret = 0;
	if(bl == br) {
		for(int i = l; i <= r; i ++) {
			ret += a[i];
		}
	}
	else {
		for(int i = bl+1; i < br; i ++) {
			ret += sum[i];
		}
		for(int i = l; i <= n && belong[i] == bl; i ++) {
			ret += a[i];
		}
		for(int i = r; i > 0 && belong[i] == br; i --) {
			ret += a[i];
		}
	}
	return ret;
}
void solve() {
    cin >> n;
    bSize = sqrt(n), bNum = (n-1)/bSize + 1;
    a.resize(n+1), belong.resize(n+1), done.resize(bNum+1), sum.resize(bNum+1);
    for(int i = 1; i <= n; i ++) {
    	cin >> a[i];
    	belong[i] = (i-1)/bSize + 1;
    	sum[belong[i]] += a[i];
    }
    for(int i = 0; i < n; i ++) {
		int op, l, r, c;
		cin >> op >> l >> r >> c;
		if(op == 0) {
			Modify(l, r);
		}
		else {
			cout << Query(l, r) << '\n';
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