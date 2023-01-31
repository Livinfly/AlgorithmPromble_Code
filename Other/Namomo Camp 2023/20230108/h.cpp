#pragma GCC optimize(2)

#include <bits/stdc++.h>

#define fi first
#define se second
#define mkp(x, y) make_pair((x), (y))
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed;  // << setprecision(20); // double
    // freopen("i.txt", "r", stdin);
    // freopen("o.txt", "w", stdout);
    int n;
    cin >> n;
    vector<LL> divs(n+1);
    for(int i = 1; i <= n; i ++)
        for(int j = i; j <= n; j += i) 
            divs[j] ++;
    LL res = 0;
    for(int i = 1; i <= n; i ++) 
        res += i*divs[i];
        
    cout << res << '\n';
    return 0;
}
/*
可以sqrt(n)


*/