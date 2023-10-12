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
vector<int> a, belong, addTag, sum;

void Add(int l, int r, int c) {
	int bl = belong[l], br = belong[r];
	if(bl == br) {
		for(int i = l; i <= r; i ++) {
			a[i] += c;
			sum[bl] += c;
		}
	}
	else {
		for(int i = bl+1; i < br; i ++) {
			addTag[i] += c;
		}
		for(int i = l; i <= n && belong[i] == bl; i ++) {
			a[i] += c;
			sum[bl] += c;
		}
		for(int i = r; i > 0 && belong[i] == br; i --) {
			a[i] += c;
			sum[br] += c;
		}
	}
}
int Query(int l, int r, const int &MO) {
	int bl = belong[l], br = belong[r];
	int ret = 0;
	if(bl == br) {
		for(int i = l; i <= r; i ++) {
			int x = (1LL*a[i] + addTag[bl]) % MO;
			ret = (1LL*ret + x) % MO;
		}
	}
	else {
		for(int i = bl+1; i < br; i ++) {
			int x = (1LL*sum[i] + 1LL*addTag[i]*bSize%MO) % MO;
			ret = (1LL*ret + x) % MO;
		}
		for(int i = l; i <= n && belong[i] == bl; i ++) {
			int x = (1LL*a[i] + addTag[bl]) % MO;
			ret = (1LL*ret + x) % MO;
		}
		for(int i = r; i > 0 && belong[i] == br; i --) {
			int x = (1LL*a[i] + addTag[br]) % MO;
			ret = (1LL*ret + x) % MO;
		}
	}
	return ret;
}
void solve() {
    cin >> n;
    bSize = sqrt(n), bNum = (n-1)/bSize + 1;
    a.resize(n+1), belong.resize(n+1), addTag.resize(bNum+1), sum.resize(bNum+1);
    for(int i = 1; i <= n; i ++) {
    	cin >> a[i];
    	belong[i] = (i-1)/bSize + 1;
    	sum[belong[i]] += a[i];
    }
    for(int i = 0; i < n; i ++) {
    	int op, l, r, c;
    	cin >> op >> l >> r >> c;
    	if(op == 0) {
    		Add(l, r, c);
    	}
    	else {
    		int MO = c+1;
    		cout << (Query(l, r, c+1)%MO+MO) % MO << '\n';
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