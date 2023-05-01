#include <bits/stdc++.h>

#define fi first
#define se second
#define all(a) (a).begin(), (a).end()

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

int g[10][10] = {
	{},
	{200, 100, 50, 25, 15},
	{100, 75, 25, 15},
	{75, 25, 15},
	{20, 15, 10, 5},
};

void solve() {
	vector<int> f(31);
	int n;
	cin >> n;
	while(n --) {
		int a, b, c;
		cin >> a >> b >> c;
		f[a] = max(f[a], g[b][c]);
	}
	int res = 0;
	for(auto x : f) 
		res += x;
	cout << res << '\n';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout << fixed;
	
	int Tcase = 1;
	cin >> Tcase;
	while(Tcase --) 
		solve();
	
	return 0;
}