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
vector<int> a, belong;
vector<vector<int>> va;

PII Find(int x) {
	int ret = 1;
	while(x > va[ret].size()) {
		x -= va[ret].size();
		ret ++;
	}
	return {ret, x-1};
}
void Rebuild() {
	a.assign(1, 0);
	for(int i = 1; i <= bNum; i ++) {
		a.insert(a.end(), va[i].begin(), va[i].end());
		va[i].clear();
	}
	n = a.size()-1;
	bSize = sqrt(n), bNum = (n-1)/bSize + 1;
	// 理论上只要更新bSize和va，但为了一致性，这里还是都更新了
	belong.resize(n+1), va.resize(bNum+1);
	for(int i = 1; i <= n; i ++) {
		belong[i] = (i-1)/bSize + 1;
		va[belong[i]].push_back(a[i]);
	}
}
void Insert(int x, int c) {
	auto [i, b] = Find(x);
	va[i].insert(va[i].begin() + b, c);
	// if(va[i].size() > 20*bSize) {
	// 	Rebuild();
	// }
}
int Query(int x) {
	auto [i, b] = Find(x);
	return va[i][b];
}
void solve() {
    cin >> n;
    bSize = sqrt(n), bNum = (n-1)/bSize + 1;
    a.resize(n+1), belong.resize(n+1), va.resize(bNum+1);
    for(int i = 1; i <= n; i ++) {
    	cin >> a[i];
    	belong[i] = (i-1)/bSize + 1;
    	va[belong[i]].push_back(a[i]);
    }
    int t = sqrt(n);
    // 由于n在重新分块时更新了，所以，这里循环询问的n要存到别的变量里面
    int nn = n;
    for(int i = 0; i < nn; i ++) {
    	int op, l, r, c;
    	cin >> op >> l >> r >> c;
    	if(op == 0) {
    		Insert(l, r);
    		// if(i % t == 0) {
    		// 	Rebuild();
    		// }
    	}
    	else {
    		cout << Query(r) << '\n';
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