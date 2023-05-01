#include <bits/stdc++.h>

#define fi first
#define se second
#define all(a) (a).begin(), (a).end()

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

void solve() {
	LL n;
	cin >> n;
	vector<int> a(n+1), s(n+1);
	for(int i = 1; i <= n; i ++) {
		cin >> a[i];
		s[i] = s[i-1] + (a[i]%2 ? 1 : -1);
	}
	LL res = 0;
	if(n & 1) res = (n+1)/2*(n+1)/2;
	else res = (n+2)/2*n/2;
//	cout << res << '\n';
//	for(int i = 1; i <= n; i ++)
//		cout << s[i] << " \n"[i == n];
	
	for(int i = 1; i <= n; i ++) {
		for(int j = i; j <= n; j ++) {
			res = res + abs(s[j]-s[i-1]+1)/2;
		}
	}
	cout << res << '\n';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
//	freopen("o.txt", "r", stdin);
	cout << fixed;
	
	int Tcase = 1;
//	cin >> Tcase;
	while(Tcase --) 
		solve();
	
	return 0;
}