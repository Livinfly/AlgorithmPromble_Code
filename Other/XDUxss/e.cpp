#pragma GCC optimize(2)

#include <bits/stdc++.h>

#define fi first
#define se second
#define mkp(x, y) make_pair(x, y)
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

struct rec {
    LL l, r, x, c2;
};
LL id, num[2010], color[2010], p_color[2010];

LL count(LL c) {
    LL res = 0;
    LL l = -1;
    for(int i = 0; i < id; i ++) {
        if(p_color[i] == c) res ++;
        if(color[i] == c) res += num[i+1]-num[i]-1;
    }
    return res;
} 
void solve() {
    LL n, q, k;
    cin >> n >> q >> k;
    const LL P = k;
    vector<rec> Query;
    num[id ++] = 1, num[id ++] = n;
    for(int i = 0; i < q; i ++) {
        LL l, r, x, c2;
        cin >> l >> r >> x >> c2;
        Query.push_back({l, r, x, c2});
        num[id ++] = l, num[id ++] = r;
    }
    sort(num, num+id);
    id = unique(num, num+id)-num;
    num[id] = num[id-1]+1;
    for(int i = 0; i < id; i ++)
        color[i] = 1, p_color[i] = 1;
    // for(int i = 0; i < id; i ++) 
    //     cout << num[i] << ' ';
    // cout << '\n';
    for(int i = 0; i < q; i ++) {
        rec &nq = Query[i];
        LL l = lower_bound(num, num+id, nq.l)-num;
        LL r = lower_bound(num, num+id, nq.r)-num;
        for(int i = l; i < r; i ++)
            color[i] = (nq.x ^ color[i])%P+1;
        for(int i = l; i <= r; i ++) 
            p_color[i] = (nq.x ^ p_color[i])%P+1;
        // for(int i = 0; i < id; i ++)
        //     cout << color[i] << ' ';
        // cout << '\n';
        cout << count(nq.c2) << '\n';
    }
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