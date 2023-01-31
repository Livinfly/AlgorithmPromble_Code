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
    int n, T;
    cin >> n >> T;
    T = min(n, T);
    string s;
    cin >> s;
    for(int i = 0; i < T; i ++)
        for(int j = 0; j < n-1; j ++)
            if(s[j] == 'S' && s[j+1] == 'P' ||
                s[j] == 'P' && s[j+1] == 'R' ||
                s[j] == 'R' && s[j+1] == 'S' )
                swap(s[j], s[j+1]);
    cout << s << '\n';
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