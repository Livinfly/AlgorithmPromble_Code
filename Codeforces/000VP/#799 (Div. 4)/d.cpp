#pragma GCC optimize(2)

#include <bits/stdc++.h>

#define fi first
#define se second
#define mkp(x, y) make_pair((x), (y))
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

bool st[1440];

void solve() {
    memset(st, 0, sizeof st);
    int hh, mm, inv;
    scanf("%d:%d %d", &hh, &mm, &inv);
    int cnt = 0;
    while(!st[hh*60+mm]) {
        st[hh*60+mm] = true;
        mm += inv;
        hh += mm/60;
        mm %= 60;
        hh %= 24;
        if(hh%10 == mm/10 && hh/10 == mm%10) cnt ++;
    }
    printf("%d\n", cnt);
}

int main() {
    // freopen("i.txt", "r", stdin);
    // freopen("o.txt", "w", stdout);
    int Tcase;
    scanf("%d", &Tcase);
    while (Tcase--) solve();
    return 0;
}