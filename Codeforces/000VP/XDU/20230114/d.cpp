#pragma GCC optimize(2)

#include <bits/stdc++.h>

#define fi first
#define se second
#define mkp(x, y) make_pair((x), (y))
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

const int N = 1e6+10;

struct rec {
    LL x, y, w;
    bool operator < (const rec &o) const {
        return x < o.x;
    }
} a[N];

LL n, m;
LL yy[N], tt[N];
priority_queue<PLL> heap;

bool cmp(LL x, LL y) {
    return x > y;
}
LL GetMax() {
    while(heap.size()) {
        auto t = heap.top();
        if(yy[t.se] != t.fi) heap.pop();
        else return t.fi;
    }
    return 0;
}
LL work() {
    sort(a+1, a+n+1);
    memset(yy, 0, sizeof yy);
    for(int i = 1; i <= n; i ++) 
        yy[a[i].y] += a[i].w;
    memcpy(tt, yy, sizeof tt);
    sort(tt, tt+m+1, cmp);
    LL ans = tt[0]+tt[1]+tt[2];

    while(heap.size()) heap.pop();

    for(int i = 0; i <= m; i ++)
        heap.push({yy[i], i});
    for(int i = 1, j = 0; i <= n; i = j+1) {
        j = i;
        while(j < n && a[j+1].x == a[i].x) j ++;
        LL sx = 0, sy = 0;
        for(int k = i; k <= j; k ++) {
            int y = a[k].y;
            yy[y] -= a[k].w;
            heap.push({yy[y], y});
            sx += a[k].w;
        }

        // Ynoi orz
        sy += GetMax();
        auto t1 = heap.top();
        // 不能选 t1.se 这一行了，都要删去，设为不合法
        yy[t1.se] = 0;

        sy += GetMax();

        yy[t1.se] = t1.fi;
        
        ans = max(ans, sx+sy);

        for(int k = i; k <= j; k ++) {
            int y = a[k].y;
            yy[y] += a[k].w;
            heap.push({yy[y], y});
        }
    }
    return ans;
}
void solve() {
    // m = 3
    cin >> n;
    for(int i = 1; i <= n; i ++) {
        LL x, y, z;
        cin >> x >> y >> z;
        a[i] = {x, y, z};
        m = max({x, y, m});
    }
    LL res = work();
    for(int i = 1; i <= n; i ++)
        swap(a[i].x, a[i].y);
    res = max(res, work());
    cout << res << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed;  // << setprecision(20); // double
    // freopen("i.txt", "r", stdin);
    // freopen("o.txt", "w", stdout);
    // int Tcase;
    // cin >> Tcase; // scanf("%d", &Tcase);
    // while (Tcase--) 
    solve();
    return 0;
}
/*
7
0 0 100000
0 1 100000
2 2 10000
2 6 1000
3 3 100
3 4 10
3 5 1
*/