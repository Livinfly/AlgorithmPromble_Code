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
	int n;
    cin >> n;
    vector<string> g(n);
    for(auto &s : g) cin >> s;
    int cnt0 = 0;
   	int win = 0;
  	for(int i = 0; i < n; i ++)
  		for(int j = 0; j < n; j ++)
  			if(g[i][j] == '1') win ++;
  			else if(g[i][j] == '2') win --;
  			else cnt0 ++;
  	// cout << win << '\n';
  	if(win == 1) win = 1;
  	else if(win == 0) win = 2;
  	else {
  		cout << "NO\n";
  		return;
  	}
  	auto check1 = [&](char c) {
		for(int i = 0; i < n; i ++) {
			int cnt = 0;
			for(int j = 0; j < n; j ++) {
				if(g[i][j] == c) 
					cnt ++;
				else 
					cnt = 0;
				if(cnt == 5) return true;
			}
		}
		for(int i = 0; i < n; i ++) {
			int cnt = 0;
			for(int j = 0; j < n; j ++) {
				if(g[j][i] == c) 
					cnt ++;
				else 
					cnt = 0;
				if(cnt == 5) return true;
			}
		}
		for(int i = 0; i < n; i ++) {
			int cnt = 0, j = i, k = 0;
			while(j >= 0 && k < n) {
				if(g[j][k] == c) 
					cnt ++;
				else 
					cnt = 0;
				if(cnt == 5) return true;
				j --, k ++;
			}
			cnt = 0, j = n-1, k = i+1;
			while(j >= 0 && k < n) {
				if(g[j][k] == c) 
					cnt ++;
				else 
					cnt = 0;
				if(cnt == 5) return true;
				j --, k ++;
			}
			cnt = 0, j = 0, k = i;
			while(j < n && k < n) {
				if(g[j][k] == c) 
					cnt ++;
				else 
					cnt = 0;
				if(cnt == 5) return true;
				j ++, k ++;
			}
			cnt = 0, j = i+1, k = 0;
			while(j < n && k < n) {
				if(g[j][k] == c) 
					cnt ++;
				else 
					cnt = 0;
				if(cnt == 5) return true;
				j ++, k ++;
			}
		}
		return false;
	};
	auto check2 = [&](char c) {
		int tot = 0;
		vector<vector<int>> cnt(n);
		for(auto &v : cnt) v.resize(n);
		for(int i = 0; i < n; i ++) {
			int tcnt = 0;
			for(int j = 0; j < n; j ++) {
				if(g[i][j] == c) 
					tcnt ++;
				else 
					tcnt = 0;
				if(tcnt >= 5) {
					tot ++;
					for(int z = 0; z < 5; z ++) 
						cnt[i][j-z] ++;
				}
			}
		}
		for(int i = 0; i < n; i ++) {
			int tcnt = 0;
			for(int j = 0; j < n; j ++) {
				if(g[j][i] == c) 
					tcnt ++;
				else 
					tcnt = 0;
				if(tcnt >= 5) {
					tot ++;
					for(int z = 0; z < 5; z ++) 
						cnt[j-z][i] ++;
				}
			}
		}
		for(int i = 0; i < n; i ++) {
			int tcnt = 0, j = i, k = 0;
			while(j >= 0 && k < n) {
				if(g[j][k] == c) 
					tcnt ++;
				else 
					tcnt = 0;
				if(tcnt >= 5) {
					tot ++;
					for(int z = 0; z < 5; z ++) 
						cnt[j+z][k-z] ++;
				}
				j --, k ++;
			}
			tcnt = 0, j = n-1, k = i+1;
			while(j >= 0 && k < n) {
				if(g[j][k] == c) 
					tcnt ++;
				else 
					tcnt = 0;
				if(tcnt >= 5) {
					tot ++;
					for(int z = 0; z < 5; z ++) 
						cnt[j+z][k-z] ++;
				}
				j --, k ++;
			}
			tcnt = 0, j = 0, k = i;
			while(j < n && k < n) {
				if(g[j][k] == c) 
					tcnt ++;
				else 
					tcnt = 0;
				if(tcnt >= 5) {
					tot ++;
					for(int z = 0; z < 5; z ++) 
						cnt[j-z][k-z] ++;
				}
				j ++, k ++;
			}
			tcnt = 0, j = i+1, k = 0;
			while(j < n && k < n) {
				if(g[j][k] == c) 
					tcnt ++;
				else 
					tcnt = 0;
				if(tcnt >= 5) {
					tot ++;
					for(int z = 0; z < 5; z ++) 
						cnt[j-z][k-z] ++;
				}
				j ++, k ++;
			}
		}
		vector<PII> res;
		for(int i = 0; i < n; i ++)
			for(int j = 0; j < n; j ++)
				if(cnt[i][j] == tot)
					res.emplace_back(i, j);
		// cout << res.size() << ' ' << tot << '\n';
		if(res.size() > 5 || res.size() == 0) return false;
		sort(all(res));
		vector<int> recc(4);
		for(int i = 0; i < res.size(); i ++) {
			if(res[i].fi-i == res[0].fi && res[i].se == res[0].se) recc[0] ++;
			else recc[0] = 0;
			if(res[i].fi == res[0].fi && res[i].se-i == res[0].se) recc[1] ++;
			else recc[1] = 0;
			if(res[i].fi-i == res[0].fi && res[i].se-i == res[0].se) recc[2] ++;
			else recc[2] = 0;
			if(res[i].fi-i == res[0].fi && res[i].se+i == res[0].se) recc[3] ++;
			else recc[3] = 0;
		}
		for(auto x : recc)
			if(x == res.size())
				return true;
		return false;
	};
	// cout << cnt0 << ' ' << win << '\n';
	// cout << check1((char)('0'+3-win)) << ' ' << check1((char)('0'+win)) << ' ' << check2((char)('0'+win)) << '\n';
	bool f1 = check1((char)('0'+3-win)), f2 = check1((char)('0'+win)), f3 = check2((char)('0'+win));
  	if(!f1 && (!cnt0 && !f2 || f2 && f3)) {
  		cout << "YES\n";
  	}
  	else {
  		cout << "NO\n";
  	}
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed;  // << setprecision(20); // double
    // freopen("i.txt", "r", stdin);
    // freopen("o.txt", "w", stdout);
    // time_t t1 = clock();
    int Tcase = 1;
    cin >> Tcase; // scanf("%d", &Tcase);
    while (Tcase--) 
        solve();
    // cout << "time: " << 1000.0 * ((clock() - t1) / CLOCKS_PER_SEC) << "ms\n";
    return 0;
}