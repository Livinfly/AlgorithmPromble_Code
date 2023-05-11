#pragma GCC optimize(2)

#include <bits/stdc++.h>

#define fi first
#define se second
#define mkp(x, y) make_pair((x), (y))
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int MO = 10007;

int n, bSize, bNum;
vector<int> a, belong, addTag, mulTag;

void Reset(int x) {
	for(int i = (x-1)*bSize+1; i <= min(n, x*bSize); i ++)
		a[i] = (1LL*a[i]*mulTag[x] % MO + addTag[x]) % MO;
	mulTag[x] = 1, addTag[x] = 0;
}
void Modify(int op, int l, int r, int c) {
	int bl = belong[l], br = belong[r];
	if(bl == br) {
		Reset(bl);
		for(int i = l; i <= r; i ++) {
			if(op == 0) {
				a[i] = (1LL*a[i] + c) % MO;
			}
			else {
				a[i] = 1LL*a[i]*c % MO;
			}
		}
	}
	else {
		for(int i = bl+1; i < br; i ++) {
			if(op == 0) {
				addTag[i] = (1LL*addTag[i] + c) % MO;
			}
			else {
				addTag[i] = 1LL*addTag[i] * c % MO;
				mulTag[i] = 1LL*mulTag[i] * c % MO;
			}
		}
		Reset(bl);
		for(int i = l; i <= n && belong[i] == bl; i ++) {
			if(op == 0) {
				a[i] = (1LL*a[i] + c) % MO;
			}
			else {
				a[i] = 1LL*a[i]*c % MO;
			}
		}
		Reset(br);
		for(int i = r; i > 0 && belong[i] == br; i --) {
			if(op == 0) {
				a[i] = (1LL*a[i] + c) % MO;
			}
			else {
				a[i] = 1LL*a[i]*c % MO;
			}
		}
	}
}
int Query(int x) {
	int bx = belong[x];
	return (1LL*a[x] * mulTag[bx] % MO + addTag[bx]) % MO;
}
void solve() {
    cin >> n;
    bSize = sqrt(n), bNum = (n-1)/bSize + 1;
    a.resize(n+1), belong.resize(n+1), addTag.resize(bNum+1), mulTag.resize(bNum+1);
    for(int i = 1; i <= n; i ++) {
    	cin >> a[i];
    	belong[i] = (i-1)/bSize + 1;
    }
    for(int i = 1; i <= bNum; i ++) {
    	mulTag[i] = 1;
    }
    for(int i = 0; i < n; i ++) {
    	int op, l, r, c;
    	cin >> op >> l >> r >> c;
    	if(op == 2) {
    		cout << Query(r) << '\n';
    	}
    	else {
    		Modify(op, l, r, c);
    	}
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