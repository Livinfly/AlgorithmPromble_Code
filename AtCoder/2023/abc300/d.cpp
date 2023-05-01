#pragma GCC optimize(2)

#include <bits/stdc++.h>

#define fi first
#define se second
#define mkp(x, y) make_pair((x), (y))
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 1e6+10;
const LL M = 1e12;

int idp, prime[N];
bool vis[N];
vector<LL> rec;

void GetPrimes(int n) {
	for(int i = 2; i <= n; i ++) {
		if(!vis[i]) prime[idp ++] = i;
		for(int j = 0; prime[j] <= n/i; j ++) {
			vis[i*prime[j]] = true;
			if(i % prime[j] == 0) break;
		}
	}
	for(int i = 0; i < idp; i ++) {
		int x = prime[i];
		if(1LL*x*x > M) break;
		for(int j = i+1; j < idp; j ++) {
			int y = prime[j];
			if(1LL*x*x > M/y) break;
			for(int k = j+1; k < idp; k ++) {
				int z = prime[k];
				if(1LL*x*x*y > M/z/z) break;
				// cout << 1LL*x*x*y*z*z << '\n';
				rec.push_back(1LL*x*x*y*z*z);
			}
		}
	}
	// cout << rec.size() << '\n';
	sort(all(rec));
}

void solve() {
	GetPrimes(N-10);
    LL n;
    cin >> n;
    cout << (upper_bound(all(rec), n)-rec.begin()) << '\n';
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