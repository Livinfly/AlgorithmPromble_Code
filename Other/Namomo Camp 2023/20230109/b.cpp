#pragma GCC optimize(2)

#include <bits/stdc++.h>

#define fi first
#define se second
#define mkp(x, y) make_pair((x), (y))
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 26;

int cnt[N][N], refc[N];

void solve() {
    string s;
    cin >> s;
    string dic = "bcdfghjklmnpqrstvxz";
    memset(refc, -1, sizeof refc);
    for(int i = 0; i < dic.size(); i ++) {
        char x = dic[i];
        int p = x-'a';
        refc[p] = i;
    }
    for(int i = 1; i < s.size(); i ++) {
        int a = refc[s[i-1]-'a'], b = refc[s[i]-'a'];
        if(!~a || !~b) continue;
        cnt[a][b] ++;
        cnt[b][a] ++; // 两个互相相邻
    }
    int res = 0, rec = 0;
    int T;
    for(T = 0; T < (1<<19); T ++) {
        int tres = 0;
        for(int i = 0; i < 19; i ++) {
            if(T>>i & 1) // upper
                for(int j = 0; j < 19; j ++)
                    if((T>>j & 1) == 0) { // lower
                        tres += cnt[i][j];
                    }
        }
        if(tres > res) {
            res = tres;
            rec = T;
        }
    }
    for(auto &x : s) {
        int p = refc[x-'a'];
        if(~p && (rec>>p & 1)) x = toupper(x);
    }
    cout << s << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed;  // << setprecision(20); // double
    freopen("consonant.in", "r", stdin);
    freopen("consonant.out", "w", stdout);
    // int Tcase;
    // cin >> Tcase; // scanf("%d", &Tcase);
    // while (Tcase--) 
    solve();
    return 0;
}
/*
没估计好复杂度+3秒限制，实际就枚举2^19次状态，每个check下它的pair数即可

一开始像确定前后关系来计cnt和tres，然后可以减少一般的枚举量，结果wa了
后面想到如果'z'为大写，小写和他相互结对的就不能记录个数了。
*/