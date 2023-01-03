#pragma GCC optimize(2)

#include <bits/stdc++.h>

#define fi first
#define se second
#define mkp(x, y) make_pair((x), (y))
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

set<char> st[300010];

void solve() {
    string s;
    cin >> s;
    stack<int> stk;
    for(int i = 0; i < s.size(); i ++) {
        if(s[i] == '(') stk.push(i);
        else if(s[i] == ')') {
            for(auto x : st[stk.size()]) {
                st[0].erase(x);
            }
            st[stk.size()].clear();
            stk.pop();
        }
        else {
            if(st[0].find(s[i]) != st[0].end()) {
                cout << "No\n";
                return;
            }
            st[stk.size()].insert(s[i]);
            st[0].insert(s[i]);
        }
    }
    cout << "Yes\n";
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