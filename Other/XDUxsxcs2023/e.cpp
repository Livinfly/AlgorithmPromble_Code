#include <bits/stdc++.h>

#define fi first
#define se second
#define all(a) (a).begin(), (a).end()

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, int> PLI;

void solve() {
	int n, m;
	cin >> n >> m;
	vector<LL> a(n), v(m), belong(n), cnt(m), t(m);
	for(auto &x : v) cin >> x;
	for(auto &x : a) cin >> x;
	sort(all(a));
	set<PII> st; // cnt, id
	set<PLI> done; // time, id
	for(int i = 0; i < m; i ++) 
		st.insert({0, i});
	for(int i = 0; i < n; i ++) {
		while(done.size() && done.begin()->fi <= a[i]) {
			int gid = belong[done.begin()->se];
			done.erase(done.begin());
			st.erase(st.find({cnt[gid], gid}));
			cnt[gid] --;
			st.insert({cnt[gid], gid});
		}
		auto [nn, gid] = *st.begin();
//		cout << nn << ' ' << gid << '\n';
		st.erase(st.begin());
		cnt[gid] ++;
		st.insert({cnt[gid], gid});
		done.insert({max(a[i], t[gid])+v[gid], i});
		belong[i] = gid;
//		cout << t[gid] << '\n';
		
		t[gid] = max(t[gid], a[i])+v[gid];
	}
	cout << (done.rbegin()->fi) << '\n';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout << fixed;
	
	int Tcase = 1;
//	cin >> Tcase;
	while(Tcase --) 
		solve();
	
	return 0;
}
/*
3 1
100
1 10 301
*/