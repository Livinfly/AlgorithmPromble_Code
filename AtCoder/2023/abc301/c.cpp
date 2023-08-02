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
	set<char> st{'a', 't', 'c', 'o', 'd', 'e', 'r'};
	vector<array<int, 26>> cnt(2);
    int cnt1 = 0, cnt2 = 0;
    string s, t;
    cin >> s >> t;
    for(auto x : s) {
        if(x == '@') {
            cnt1 ++;
            continue;
        }
    	int xx = x - 'a';
    	cnt[0][xx] ++;
    }
    for(auto x : t) {
        if(x == '@') {
            cnt2 ++;
            continue;
        }
        int xx = x - 'a';
    	cnt[1][xx] ++;
    }
   	for(int i = 0; i < 26; i ++) {
        // cerr << cnt1 << ' ' << cnt2 << '\n';
        // cerr << (char)(i+'a') << ' ' << cnt[0][i] << ' ' << cnt[1][i] << '\n';
   		if(cnt[0][i] < cnt[1][i]) {
            if(st.count((char)(i+'a'))) {
                cnt1 -= cnt[1][i]-cnt[0][i];
            }
            else {
                cout << "No\n";
                return;
            }
   		}
        else if(cnt[0][i] > cnt[1][i]) {
            if(st.count((char)(i+'a'))) {
                cnt2 -= cnt[0][i]-cnt[1][i];
            }
            else {
                cout << "No\n";
                return;
            }
        }
        if(cnt1 < 0 || cnt2 < 0) {
            cout << "No\n";
            return; 
        }
   	}
    cout << "Yes\n";
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