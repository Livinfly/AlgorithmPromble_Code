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
vector<int> a, belong, addTag;
vector<multiset<int>> va;

void Add(int l, int r, int c) {
	int bl = belong[l], br = belong[r];
	if(bl == br) {
		for(int i = l; i <= r; i ++) {
			va[bl].erase(va[bl].find(a[i]));
			a[i] += c;
			va[bl].insert(a[i]);
		}
	}
	else {
		for(int i = bl+1; i < br; i ++) {
			addTag[i] += c;
		}
		for(int i = l; i <= n && belong[i] == bl; i ++) {
			va[bl].erase(va[bl].find(a[i]));
			a[i] += c;
			va[bl].insert(a[i]);
		}
		for(int i = r; i > 0 && belong[i] == br; i --) {
			va[br].erase(va[br].find(a[i]));
			a[i] += c;
			va[br].insert(a[i]);
		}
	}
}
int Query(int l, int r, int c) {
	int bl = belong[l], br = belong[r];
	int ret = -1;
	if(bl == br) {
		for(int i = l; i <= r; i ++) {
			if(a[i]+addTag[bl] < c) {
				ret = max(ret, a[i]+addTag[bl]);
			}
		}
	}
	else {
		for(int i = bl+1; i < br; i ++) {
			int t = c-addTag[i];
			auto iter = va[i].lower_bound(t);
			if(iter != va[i].begin()) {
				// + addTag[i]
				ret = max(ret, *(-- iter) + addTag[i]);
			}
		}
		for(int i = l; i <= n && belong[i] == bl; i ++) {
			if(a[i]+addTag[bl] < c) {
				ret = max(ret, a[i]+addTag[bl]);
			}
		}
		for(int i = r; i > 0 && belong[i] == br; i --) {
			if(a[i]+addTag[br] < c) {
				ret = max(ret, a[i]+addTag[br]);
			}
		}
	}
	return ret;
}
void solve() {
    cin >> n;
    bSize = sqrt(n), bNum = (n-1)/bSize+1;
    a.resize(n+1), va.resize(bNum+1), belong.resize(n+1), addTag.resize(bNum+1);
    for(int i = 1; i <= n; i ++) {
    	cin >> a[i];
    	belong[i] = (i-1)/bSize+1;
    	va[(i-1)/bSize+1].insert(a[i]);
    }
    for(int i = 0; i < n; i ++) {
    	int op, l, r, c;
    	cin >> op >> l >> r >> c;
    	if(op == 0) {
    		Add(l, r, c);
    	}
    	else {
    		cout << Query(l, r, c) << '\n';
    	}
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed;  // << setprecision(20); // double
    // freopen("a2.in", "r", stdin);
    // freopen("o.txt", "w", stdout);
    // time_t t1 = clock();
    int Tcase = 1;
    // cin >> Tcase; // scanf("%d", &Tcase);
    while (Tcase--) 
        solve();
    // cout << "time: " << 1000.0 * ((clock() - t1) / CLOCKS_PER_SEC) << "ms\n";
    return 0;
}