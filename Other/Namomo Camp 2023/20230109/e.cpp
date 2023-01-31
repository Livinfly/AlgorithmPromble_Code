#pragma GCC optimize(2)

#include <bits/stdc++.h>

#define fi first
#define se second
#define mkp(x, y) make_pair((x), (y))
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

bool is2(LL n) {
    while(n % 2 == 0) n /= 2;
    return n == 1;
}
void solve() {
    LL n;
    cin >> n;
    vector<vector<LL>> ans;
    if(n == 1 || is2(n)) {
        cout << "-1\n";
        return;
    }
    else {
        // cout << 1 << ' ' << n << '\n';
        vector<LL> t(1, n);
        ans.push_back(t);
    }
    LL t = (LL)(sqrt(n)+0.1);
    if(n == t*(t+1)) {
        // cout << 2 << ' ' << t << ' ' << t+1 << '\n';
        vector<LL> tt(1, t);
        tt.push_back(t+1);
        ans.push_back(tt);
    }
    else if(n == t*t) {
        // cout << 2 << ' ' << t << ' ' << t << '\n';
        vector<LL> tt(2, t);
        ans.push_back(tt);
    }
    for(LL i = 2; i*i*i <= n; i ++) {
        LL j = i+1, cnt0 = 0, cnt1 = 0;
        if(n % i == 0) {
            LL m = n;
            while(m % i == 0) m /= i, cnt0 ++;
            if(m == 1) {
                vector<LL> tt(cnt0, i);
                ans.push_back(tt);
            }
            j = i+1, cnt0 = 0, cnt1 = 0;
            if(n % (i*j) == 0) {
                LL m = n;
                while(m % i == 0) m /= i, cnt0 ++;
                while(m % j == 0) m /= j, cnt1 ++;
                if(m == 1) {
                    vector<LL> tt(cnt0, i);
                    for(int z = 0; z < cnt1; z ++)
                        tt.push_back(j);
                    ans.push_back(tt);
                }
            }
        }
    }
    cout << ans.size() << '\n';
    for(auto vec : ans) {
        cout << vec.size();
        for(auto x : vec) 
            cout << ' ' << x;
        cout << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed;  // << setprecision(20); // double
    freopen("little.in", "r", stdin);
    freopen("little.out", "w", stdout);
    // int Tcase;
    // cin >> Tcase; // scanf("%d", &Tcase);
    // while (Tcase--) 
    solve();
    return 0;
}
/*
对题目理解不完全，只要是任意数最多差1，且不存在元素和数目相同就是一个合法方案
2^k都是无限种方案。

解法的话，看到数据范围，三次开方的复杂度可以接受，就1次和2次的另外处理即可。
*/