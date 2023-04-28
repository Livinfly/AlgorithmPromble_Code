#pragma GCC optimize(2)

#include <bits/stdc++.h>

#define fi first
#define se second
#define mkp(x, y) make_pair((x), (y))
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

struct HP {
    int num[4010];
    int len;
}tmp;
HP ToHP(const string &str) {
    memset(&tmp, 0, sizeof(HP));
    tmp.len = str.size();
    for(int i = tmp.len-1; i >= 0; i --)
        tmp.num[i] = str[tmp.len-i-1]-'0';
    return tmp;
}
int HHCmp(const HP &a, const HP &b) {
    if(a.len > b.len) return 1;
    else if(a.len < b.len) return -1;
    else {
        for(int i = a.len-1; i >= 0; i --) {
            if(a.num[i] > b.num[i]) return 1;
            else if(a.num[i] < b.num[i]) return -1;
        }
    }
    return 0;
}
HP HHSub(const HP &a, const HP &b, bool &is_posi) {
    memset(&tmp, 0, sizeof(HP));
    int t = HHCmp(a, b);
    if(t < 0) {
        HP res = HHSub(b, a, is_posi);
        is_posi = false;
        return res;
    }
    else is_posi = true;

    int r = 0;
    for(int i = 0; i < a.len; i ++){
        r = a.num[i]-r;
        if(i < b.len) r -= b.num[i];
        tmp.num[tmp.len ++] = (r+10)%10;
        if(r < 0) r = 1;
        else r = 0;
    }
    while(tmp.len > 1 && tmp.num[tmp.len-1] == 0) tmp.len --;
    return tmp;
}
void HPrint(const HP &a) {
    for(int i = a.len-1; i >= 0; i --)
        cout << a.num[i];
}

string n;

void solve() {
    cin >> n;
    HP nn = ToHP(n);
    for(int i = 1; i < 10; i ++) {
        HP a = {};
        for(int j = 0; j < nn.len-1; j ++)
            a.num[a.len ++] = i;
        bool is_posi = true;
        HP b = HHSub(nn, a, is_posi);
        
        if(a.len > 0 && is_posi && b.num[0] != 0) {
            bool ok = true;
            for(int j = 1; j < b.len; j ++) {
                if(b.num[j] != b.num[j-1]) {
                    ok = false;
                    break;
                }
            }
            if(ok) {
                HPrint(a);
                cout << ' ';
                HPrint(b);
                cout << '\n';
                return;
            }
        }

        a.num[a.len ++] = i;
        is_posi = true;
        b = HHSub(nn, a, is_posi);
        if(a.len > 0 && is_posi && b.num[0] != 0) {
            bool ok = true;
            for(int j = 1; j < b.len; j ++) {
                if(b.num[j] != b.num[j-1]) {
                    ok = false;
                    break;
                }
            }
            if(ok) {
                HPrint(a);
                cout << ' ';
                HPrint(b);
                cout << '\n';
                return;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed;  // << setprecision(20); // double
    // freopen("i.txt", "r", stdin);
    // freopen("o.txt", "w", stdout);
    // time_t t1 = clock();
    int Tcase;
    cin >> Tcase; // scanf("%d", &Tcase);
    while (Tcase--) 
        solve();
    // cout << "time: " << 1000.0 * ((clock() - t1) / CLOCKS_PER_SEC) << "ms\n";
    return 0;
}