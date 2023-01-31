#pragma GCC optimize(2)

#include <bits/stdc++.h>

#define fi first
#define se second
#define mkp(x, y) make_pair((x), (y))
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 510;
int n, m;
int a[N];

int Gather(int p) {
    vector<int> ans;
    for(int i = 0; i < n; i ++) {
        if(a[i] < p) ans.push_back(p-a[i]);
        else if(a[i] > p) {
            int x = a[i], xx = a[i], cnt = 0;
            while(x > p) xx = x, x >>= 1, cnt ++;
            int t = p-x;
            if(x != a[i]) t = min(t, xx-p-1);
            cnt += t;
            ans.push_back(cnt);
        }
    }
    sort(all(ans));
    // puts("----");
    // cout << p << '\n';
    // for(auto x : ans) 
    //     printf("%d\n", x);
    LL sum = 0;
    for(int i = 0; i+m < ans.size(); i ++) 
        sum += ans[i];
    // printf("sum = %d\n", sum);
    return min((LL)1e9, sum); // !!!!!
}
void solve() {
    scanf("%d%d", &n, &m);
    set<int> st;
    for(int i = 0; i < n; i ++) {
        scanf("%d", &a[i]);
        for(int x = a[i]; x > 0; x >>= 1) 
            st.insert(x);
    }
    int res = 1e9;
    for(auto x : st) 
        res = min(res, Gather(x));
    printf("%d\n", res);
}

int main() {
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    // cout << fixed;  // << setprecision(20); // double
    // freopen("i.txt", "r", stdin);
    // freopen("o.txt", "w", stdout);
    int Tcase;
    scanf("%d", &Tcase); // cin >> Tcase;
    while (Tcase--) 
        solve();
    return 0;
}