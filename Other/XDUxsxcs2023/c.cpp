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
	vector<LL> a(n+2), s(n+2), rs(n+2);
	for(int i = 1; i <= n; i ++)
		cin >> a[i];
	if(n == 2) {
		if(a[1]*a[2] == 0) 
			cout << "0/1\n";
		else 
			cout << "1/0\n";
		return;
	}
	for(int i = 1; i <= n; i ++)
		s[i] = s[i-1]+a[i];
	for(int i = 1; i <= n; i ++)
		s[i] += s[i-1];
	for(int i = n; i >= 1; i --)
		rs[i] = rs[i+1]+a[i];
	for(int i = n; i >= 1; i --)
		rs[i] += rs[i+1];
//	for(int i = 1; i <= n; i ++)
//		cout << s[i] << " \n"[i == n];
	LL ra = -1, rb = 1;
	if(rs[2] == 0) ra = 0, rb = 1;
	if(s[n-1] == 0) ra = 0, rb = 1;
	for(int mid = 2; mid < n; mid ++) {
//		cout << mid << '\n';
//		cout << s[mid-1] << ' ' << rs[mid+1] << '\n';
		if(s[mid-1] <= rs[mid+1]) {
			LL tra = rs[mid+1]-s[mid-1];
			LL trb = mid-1;
			if(!~ra || ra*trb > tra*rb) {
				ra = tra, rb = trb;
			}
		}
		else {
			LL tra = s[mid-1]-rs[mid+1];
			LL trb = n-mid;
			if(!~ra || ra*trb > tra*rb) {
				ra = tra, rb = trb;
			}
		}
	}
	if(!ra) rb = 1;
	else {
		int d = __gcd(ra, rb);
		ra /= d, rb /= d;
	}
	cout << ra << '/' << rb << '\n';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout << fixed;
	int Tcase = 1;
	while(Tcase --) 
		solve();
	return 0;
}