#pragma GCC optimize(2)

#include <bits/stdc++.h>

#define fi first
#define se second
#define mkp(x, y) make_pair((x), (y))
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

constexpr int tot = (1<<26)-1;

int n, dn;
map<int, int> lg2;

vector<int> GetDivisors(int n)
{
    vector<int> ret;
    for(int i = 1; i <= n/i; i ++)
        if(n % i == 0) {
            ret.push_back(i);
            if(n/i != i) {
                ret.push_back(n/i);
            }
        }
    sort(all(ret));
    return ret;
}
void solve() {
    cin >> n;
    set<int> st;
    vector<int> divs = GetDivisors(n);
    for(auto div : divs) {
        st.insert(div);
    }
    int p = 0;
    for(int i = 2; i <= n; i ++) {
        if(!st.count(i)) {
            p = i;
            break;
        }
    }
    if(!p) p = n;
    for(int i = 0; i < n; i ++) {
        cout << (char)('a' + i%p);
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed;  // << setprecision(20); // double
    // freopen("i.txt", "r", stdin);
    // freopen("o.txt", "w", stdout);
    // time_t t1 = clock();
    for(int i = 0; i < 26; i ++) {
        lg2[1<<i] = i;
    }
    int Tcase = 1;
    cin >> Tcase; // scanf("%d", &Tcase);
    while (Tcase--) 
        solve();
    // cout << "time: " << 1000.0 * ((clock() - t1) / CLOCKS_PER_SEC) << "ms\n";
    return 0;
}