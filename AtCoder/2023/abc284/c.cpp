#pragma GCC optimize(2)

#include <bits/stdc++.h>

#define fi first
#define se second
#define mkp(x, y) make_pair((x), (y))
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 110;

int n, m;
int fa[N];

int GetFa(int x) {
    if(x == fa[x]) return x;
    return fa[x] = GetFa(fa[x]);
}
void solve() {
    cin >> n >> m;
    for(int i = 1; i <= n; i ++) 
        fa[i] = i;
    while(m --) {
        int a, b;
        cin >> a >> b;
        int fx = GetFa(a), fy = GetFa(b);
        if(fx != fy)
            fa[fy] = fx;
    }
    set<int> st;
    for(int i = 1; i <= n; i ++)
        st.insert(GetFa(i));
    cout << st.size() << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed;  // << setprecision(20); // double
    // freopen("i.txt", "r", stdin);
    // freopen("o.txt", "w", stdout);
    solve();
    return 0;
}