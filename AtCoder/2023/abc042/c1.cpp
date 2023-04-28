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
    string n;
    int k;
    cin >> n >> k;
    set<int> num;
    for(int i = 0; i < 10; i ++) 
        num.insert(i);
    while(k --) {
        int x;
        cin >> x;
        num.erase(num.find(x));
    }
    for(auto x : num) 
        cout << x << ' ';
    cout << '\n';
    // maybe longer
    bool ok = false;
    if(n[0]-'0' > *num.rbegin()) {
        auto it = num.begin();
        if(*it == 0) it ++;
        cout << *it;
        ok = true;
    }
    
    for(int i = 0; i < n.size(); i ++) {
        int x = n[i]-'0';
        if(ok) {
            cout << *num.begin();
        }
        else {
            int t = *num.lower_bound(x);
            cout << t;
            if(t > x) ok = true;
        }
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
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