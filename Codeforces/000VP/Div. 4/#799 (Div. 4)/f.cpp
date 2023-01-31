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
    int n;
    cin >> n;
    vector<int> a(n), cnt(10);
    for(auto &x : a) cin >> x, cnt[x%10] ++;
    for(int i = 0; i < 10; i ++)
        for(int j = 0; j < 10; j ++)
            for(int k = 0; k < 10; k ++)
                if((i+j+k)%10 == 3) {
                    cnt[i] --, cnt[j] --, cnt[k] --;
                    if(cnt[i] >= 0 && cnt[j] >= 0 && cnt[k] >= 0) {
                        cout << "YES\n";
                        return;
                    }
                    else {
                        cnt[i] ++, cnt[j] ++, cnt[k] ++;
                    }
                }
    cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed;  // << setprecision(20); // double
    // freopen("i.txt", "r", stdin);
    // freopen("o.txt", "w", stdout);
    int Tcase;
    cin >> Tcase;  // scanf("%d", &Tcase);
    while (Tcase--) solve();
    return 0;
}