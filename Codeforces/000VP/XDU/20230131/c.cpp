#pragma GCC optimize(2)

#include <bits/stdc++.h>

#define fi first
#define se second
#define mkp(x, y) make_pair((x), (y))
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

void solve() {
    
    // 顺序不同也算
    int cnt = 0;
    for(int i = 1; i <= 100; i ++)
        for(int j = i; j <= 100; j ++) 
            for(int k = j; k <= 100; k ++)
                for(int u = k; u <= 100; u ++)
                    for(int v = u; v <= 100; v ++)
                        for(int x = v; x <= 100; x ++)
                            for(int y = x; y <= 100; y ++)
                                if((LL)i*j*k*u*v*x*y == i+j+k+u+v+x+y) {
                                    cnt ++;
                                    printf("%d %d %d %d %d %d %d\n", i, j, k, u, v, x, y);
                                }
    printf("%d\n", cnt);
}

int main() {
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    // cout << fixed;  // << setprecision(20); // double
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
/*
f[2] = 2, 2
f[3] = 1, 2, 3
f[4] = 1, 1, 2, 4
f[5] = 1, 1, 1, 2, 5
       1, 1, 1, 3, 3
       1, 1, 2, 2, 2
f[6] = 1, 1, 1, 1, 2, 6
f[7] = 1, 1, 1, 1, 1, 2, 7
       1, 1, 1, 1, 1, 3, 4
*/