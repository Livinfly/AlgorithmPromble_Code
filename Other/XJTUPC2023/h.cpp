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
    vector<array<int, 26>> cnt(n);
    for(int i = 0; i < n; i ++) {
    	string s;
    	cin >> s;
    	for(auto x : s) {
    		cnt[i][x-'a'] ++;
    	}
    }
    int x = -1;
    for(int i = 0; i < 26; i ++) {
    	set<int> st;
    	for(int j = 0; j < n; j ++) {
    		if(st.count(cnt[j][i])) {
    			break;
    		}
    		st.insert(cnt[j][i]);
    	}
    	if(st.size() == n) {
    		x = i;
    	}
    }
    if(x == -1) {
    	cout << "No\n";
    	return;
    }
    cout << "Yes\n";
    for(int i = 0; i < 26; i ++) {
    	if(i != x) {
    		cout << (char)(i+'a');
    	}
    }
    cout << (char)(x+'a') << '\n';
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