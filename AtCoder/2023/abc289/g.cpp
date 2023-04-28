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

int n, m;
int b[N];
double xx[N];
vector<int> stk;

// 按运算顺序加转类型，先算的都要加
double CrossX(int i, int j) {
    return ((double)j*b[j]-(double)i*b[i])/(i-j);
}

void solve() {
    cin >> n >> m;
    for(int i = 1; i <= n; i ++) 
        cin >> b[i];
    sort(b+1, b+n+1, greater<int>());
    for(int i = 1; i <= n; i ++) {
        while(stk.size() > 1 && CrossX(stk.rbegin()[1], i) <= CrossX(stk.rbegin()[1], stk.back()))
            stk.pop_back();
        stk.push_back(i);
    }
    for(int i = 0; i+1 < stk.size(); i ++) 
        xx[i] = CrossX(stk[i], stk[i+1]);
    while(m --) {
        int c;
        cin >> c;
        int l = 0, r = stk.size()-1;
        // equal last
        while(l < r) {
            int mid = l+r >> 1;
            if(xx[mid] >= c) r = mid;
            else l = mid+1;
        }
        cout << (LL)stk[r]*(b[stk[r]]+c) << ' ';
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed;  // << setprecision(20); // double
    // freopen("i.txt", "r", stdin);
    // freopen("o.txt", "w", stdout);
    // time_t t1 = clock();
    // int Tcase;
    // cin >> Tcase; // scanf("%d", &Tcase);
    // while (Tcase--) 
    solve();
    // cout << "time: " << 1000.0 * ((clock() - t1) / CLOCKS_PER_SEC) << "ms\n";
    return 0;
}