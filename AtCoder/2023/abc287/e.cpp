#pragma GCC optimize(2)

#include <bits/stdc++.h>

#define fi first
#define se second
#define mkp(x, y) make_pair((x), (y))
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 5e5 + 10;
int idx, tr[N][26], cnt[N*26 + 10];

void insert(string s) {
	int p = 0;
	for(auto x : s) {
		x -= 'a';
		auto &id = tr[p][x];
		if(id) cnt[id] ++;
		else id = ++ idx, cnt[id] = 1;
		p = id;
	}
}
int query(string s) {
	int p = 0, ret = 0;
	for(auto x : s) {
		x -= 'a';
		auto &id = tr[p][x];
		if(cnt[id] > 1) {
			ret ++;
		}
		else {
			break;
		}
		p = id;
	}
	return ret;
}
void solve() {
	int n;
    cin >> n;
    vector<string> a(n);
    for(auto &s : a) {
    	cin >> s;
    	insert(s);
    }
    for(auto s : a) {
    	cout << query(s) << '\n';
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