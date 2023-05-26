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
T ExGcd(T a, T b, T &x, T &y) {
	if(!b) {
		x = 1, y = 0;
		return a;
	}
	T d = ExGcd(b, a%b, x, y);
	T t = x;
	x = y, y = t-a/b*y;
	return d;
}
template<typename T>
T CRT(vector<T>& r, vector<T>& mod) {
    T n = 1, ans = 0;
    int k = r.size();
    for (int i = 0; i < k; i++) n = n * mod[i];
    for (int i = 0; i < k; i++) {
        T m = n / mod[i], b, y;
        ExGcd(m, mod[i], b, y);  
        ans = (ans + r[i] * m * b % n) % n;
    }
    return (ans % n + n) % n;
}
void solve() {
    vector<LL> a {4, 9, 5, 7, 11, 13, 17, 19, 23};
    int sum = accumulate(all(a), 0);
    cout << sum << endl;
    int st = 1;
    vector<int> out;
    for(auto &x : a) {
    	int bg = st;
    	st ++;
    	for(int j = 1; j < x; j ++) {
    		out.push_back(st);
    		st ++;
    	}
    	out.push_back(bg);
    }
    for(auto &x : out) {
    	cout << x << ' ';
    }
    cout << endl;
    vector<int> b(sum);
    for(auto &x : b) {
    	cin >> x;
    }
    st = 0;
    vector<LL> r;
    for(auto &x : a) {
    	auto p = find(out.begin()+st, out.begin()+st+x, b[st]);
    	r.push_back(p - (out.begin()+st) + 1);
    	st += x;
    }
    cout << CRT(r, a) << endl;
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