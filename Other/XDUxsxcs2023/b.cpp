#include <bits/stdc++.h>

#define fi first
#define se second
#define all(a) (a).begin(), (a).end()

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;

void solve() {
	ULL n;
	cin >> n;
	ULL ans = (__int128)n*(n+1)*(2*n+1)/6-(__int128)(1+n)*n/2;
	cout << ans << '\n';
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