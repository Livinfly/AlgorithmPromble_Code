#pragma GCC optimize(2)

#include <bits/stdc++.h>

#define fi first
#define se second
#define mkp(x, y) make_pair((x), (y))
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

struct Rec {
    char ch;
    int rot, p;
    Rec(char _ch, int _rot, int _p) { ch = _ch, rot = _rot, p = _p; }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed;  // << setprecision(20); // double
    int w, n;
    cin >> w >> n;
    vector<string> g(n);
    for(auto &s : g) cin >> s;
    int p = -1;
    for(auto s : g) {
        for(int j = 0; j < w; j ++) {
            if(s[j] == '#') {
                p = j+1;
                break;
            }
        }
    }
    vector<Rec> ans;
    p = max(p, 2), p = min(p, w-1);
    ans.emplace_back('T', 2, p-1);
    if(p & 1) {
        if(w & 1) {
            for(int i = p-3; i >= 2; i -= 2) {
                ans.emplace_back('S', 0, i);
            }
            ans.emplace_back('T', 3, 1);
            for(int i = p+1; i <= w-3; i += 2) {
                ans.emplace_back('Z', 0, i);
            }
            for(int i = 1; i <= w-4; i += 2) {
                ans.emplace_back('Z', 0, i);
            }
            ans.emplace_back('T', 1, w-1);
            ans.emplace_back('T', 0, w-2);
        }
        else {
            for(int i = p-3; i >= 2; i -= 2) {
                ans.emplace_back('S', 0, i);
            }
            ans.emplace_back('T', 3, 1);
            for(int i = p+1; i <= w-2; i += 2) {
                ans.emplace_back('Z', 0, i);
            }
            for(int i = 1; i <= w-3; i += 2) {
                ans.emplace_back('Z', 0, i);
            }
            ans.emplace_back('L', 2, w-1);
        }
    }
    else {
        if(w & 1) {
            for(int i = p-3; i >= 1; i -= 2) {
                ans.emplace_back('S', 0, i);
            }
            ans.emplace_back('T', 3, 1);
            for(int i = p+1; i <= w-2; i += 2) {
                ans.emplace_back('Z', 0, i);
            }
            for(int i = 2; i <= w-3; i += 2) {
                ans.emplace_back('Z', 0, i);
            }
            ans.emplace_back('L', 2, w-1);
        }
        else {
            for(int i = p-3; i >= 1; i -= 2) {
                ans.emplace_back('S', 0, i);
            }
            ans.emplace_back('T', 3, 1);
            for(int i = p+1; i <= w-3; i += 2) {
                ans.emplace_back('Z', 0, i);
            }
            for(int i = 2; i <= w-4; i += 2) {
                ans.emplace_back('Z', 0, i);
            }
            ans.emplace_back('T', 1, w-1);
            ans.emplace_back('T', 0, w-2);
        }
    }

    cout << ans.size() << '\n';
    for(auto [ch, a, b] : ans) {
        cout << ch << ' ' << a << ' ' << b << '\n';
    }

    return 0;
}