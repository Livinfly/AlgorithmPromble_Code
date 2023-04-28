#pragma GCC optimize(2)

#include <bits/stdc++.h>

#define fi first
#define se second
#define mkp(x, y) make_pair((x), (y))
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 2e5+10;

int n, q;
map<int, int> box[N];
set<int> card[N];

void solve() {
    cin >> n >> q;
    while(q --) {
    	int op;
    	cin >> op;
    	if(op == 1) {
    		int i, j;
    		cin >> i >> j;
    		box[j][i] ++;
    		card[i].insert(j);
    	}
    	else if(op == 2) {
    		int i; 
    		cin >> i;
    		for(auto iter : box[i])
    			for(int k = 0; k < iter.se; k ++)
    				cout << iter.fi << ' ';
            cout << '\n';
    	}
    	else {
    		int i;
    		cin >> i;
    		for(auto x : card[i])
    			cout << x << ' ';
    		cout << '\n';
    	}
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
    // cin >> Tcase; // scanf("%d", &Tcase);
    while (Tcase--) 
        solve();
    // cout << "time: " << 1000.0 * ((clock() - t1) / CLOCKS_PER_SEC) << "ms\n";
    return 0;
}