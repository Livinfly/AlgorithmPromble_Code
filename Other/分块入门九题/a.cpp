#pragma GCC optimize(2)

#include <bits/stdc++.h>

#define fi first
#define se second
#define mkp(x, y) make_pair((x), (y))
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

int n, bSize, bNum;
vector<int> a, belong, addTag;

void Add(int l, int r, int c) {
    int bl = belong[l], br = belong[r];
    if(bl == br) {
        for(int i = l; i <= r; i ++)
            a[i] += c;
    }
    else {
        for(int i = bl+1; i < br; i ++) {
            addTag[i] += c;
        }
        for(int i = l; i <= n && belong[i] == bl; i ++) {
            a[i] += c;
        }
        for(int i = r; i > 0 && belong[i] == br; i --) {
            a[i] += c;
        }
    }
}
void solve() {
    cin >> n;
    bSize = sqrt(n), bNum = (n-1)/bSize+1;
    a.resize(n+1), belong.resize(n+1), addTag.resize(bNum+1);
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
    }
    while(n --) {
        int op, l, r, c;
        cin >> op >> l >> r >> c;
        if(op == 0) {
            Add(l, r, c);
        }
        else {
            cout << a[r] + addTag[belong[r]] << '\n';
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed;  // << setprecision(20); // double
    // freopen("i.txt", "r", stdin);
    // freopen("o.txt", "w", stdout);
    // time_t t1 = clock();
    int Tcase = 1;
    // cin >> Tcase; // scanf("%d", &Tcase);
    while (Tcase--) 
        solve();
    // cout << "time: " << 1000.0 * ((clock() - t1) / CLOCKS_PER_SEC) << "ms\n";
    return 0;
}