#pragma GCC optimize(2)

#include <bits/stdc++.h>

#define fi first
#define se second
#define mkp(x, y) make_pair((x), (y))
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

template<typename T>
struct FenwickTree {
    int n;
    vector<T> a;
    void init(int n) {
        this->n = n;
        a.assign(n+1, 0);
    }
    int lowbit(int x) {
        return x & -x;
    }
    void add(int x, T v) {
        for( ; x <= n; x += lowbit(x))
            a[x] += v;
    }
    T sum(int x) {
        auto ans = T();
        for( ; x; x -= lowbit(x))
            ans += a[x];
        return ans;
    }
    T rangeSum(int l, int r) {
        return sum(r) - sum(l-1);
    }
    int kth(T k) {
        assert(k > 0);
        int x = 1;
        for (int i = 1<<__lg(n); i; i /= 2) {
            if(x+i <= n && k > a[x+i-1]) {
                x += i;
                k -= a[x-1];
            }
        }
        return x;
    }
};
vector<FenwickTree<int>> fens(26);

bool check(vector<int> a, int l) {
	for(int i = 0; i < 26; i ++) {
		if(fens[i].rangeSum(l, l+a[i]-1) != a[i]) {
			return false;
		}
		l += a[i];
	}
	return true;
}
void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    s = " " + s;
    for(auto &fen : fens) {
    	fen.init(n);
    }
    vector<int> cnt(26);
  	for(int i = 1; i <= n; i ++) {
  		int x = s[i]-'a';
		fens[x].add(i, 1);
		cnt[x] ++;
  	}
    int Q;
    cin >> Q;
    while(Q --) {
    	int op;
    	cin >> op;
    	if(op == 1) {
    		int x;
            char c;
    		cin >> x >> c;
    		int tx = s[x]-'a', ty = c-'a';
    		fens[tx].add(x, -1);
    		fens[ty].add(x, 1);
    		cnt[tx] --, cnt[ty] ++;
            s[x] = c;
    	}
    	else {
    		int l, r;
    		cin >> l >> r;
    		vector<int> tcnt(26);
    		for(int i = 0; i < 26; i ++) {
    			tcnt[i] = fens[i].rangeSum(l, r);
    		}
    		int ll = 0, rr = 25;
    		while(!tcnt[ll]) ll ++;
    		while(!tcnt[rr]) rr --;
    		bool ok = true;
    		for(int i = ll+1; i < rr; i ++) {
    			if(cnt[i] != tcnt[i]) {
    				ok = false;
    				break;
    			}
    		}
    		ok &= check(tcnt, l);
            
            cout << (ok ? "Yes" : "No") << '\n';
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