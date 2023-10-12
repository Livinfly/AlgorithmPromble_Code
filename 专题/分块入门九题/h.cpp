#pragma GCC optimize(2)

#include <bits/stdc++.h>

#define fi first
#define se second
#define mkp(x, y) make_pair((x), (y))
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

int n, bSize, bNum;
vector<int> a, belong, tag;

void Reset(int x) {
	if(tag[x] == -1) return;
	for(int i = (x-1)*bSize + 1; i <= min(n, x*bSize); i ++) {
		a[i] = tag[x];
	}
	tag[x] = -1;
}
int Query(int l, int r, int c) {
	int bl = belong[l], br = belong[r], ret = 0;
	if(bl == br) {
		Reset(bl);
		for(int i = l; i <= r; i ++) {
			if(a[i] == c) {
				ret ++;
			}
			else {
				a[i] = c;
			}
		}
	}
	else {
		for(int i = bl+1; i < br; i ++) {
			if(tag[i] == c) {
				ret += bSize;
			}
			else if(tag[i] == -1) {
				// i和j分清楚。。
				for(int j = (i-1)*bSize + 1; j <= min(n, i*bSize); j ++) {
					if(a[j] == c) {
						ret ++;
					}
				}
			}
			tag[i] = c;
		}
		Reset(bl);
		for(int i = l; i <= n && belong[i] == bl; i ++) {
			if(a[i] == c) {
				ret ++;
			}
			else {
				a[i] = c;
			}
		}
		Reset(br);
		for(int i = r; i > 0 && belong[i] == br; i --) {
			if(a[i] == c) {
				ret ++;
			}
			else {
				a[i] = c;
			}
		}
	}
	return ret;
}
void solve() {
    cin >> n;
    bSize = sqrt(n), bNum = (n-1)/bSize + 1;
    a.resize(n+1), belong.resize(n+1), tag.assign(bNum+1, -1);
    for(int i = 1; i <= n; i ++) {
    	cin >> a[i];
    	belong[i] = (i-1)/bSize + 1;
    }
    for(int i = 0; i < n; i ++) {
    	int l, r, c;
    	cin >> l >> r >> c;
    	cout << Query(l, r, c) << '\n';
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