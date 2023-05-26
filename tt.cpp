#pragma GCC optimize(2)

#include <bits/stdc++.h>

#define fi first
#define se second
#define mkp(x, y) make_pair((x), (y))
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

template<int P>
struct HashTable {
    struct Info {
        LL key, value;
        Info(LL key, LL value) : key(key), value(value) {}
    };
    vector<vector<Info>> data;
    void init() {
        data.assign(P+1, vector<Info>());
    }
    int hash(LL key) {
        return (key % P + P) % P; }
    int get(LL key) {
        int keyHash = hash(key);
        for(auto &[k, v] : data[keyHash]) {
            if(k == key) {
                return v;
            }
        }
        return -1;
    }
    LL modify(LL key, LL value) {
        int keyHash = hash(key);
        for(auto &[k, v] : data[keyHash]) {
            if(k == key) {
                return v = value;
            }
        }
        return -1;
    }
    LL add(LL key, LL value) {
        if(get(key) != -1) return -1;
        int keyHash = hash(key);
        data[keyHash].emplace_back(key, value);
        return 1;
    }
};
HashTable<13331> ht;

void solve() {
    ht.init();
    // unordered_map<int, int> ump;
    int n;
    cin >> n;
    for(int i = 0; i < n; i ++) {
        int x;
        cin >> x;
        // if(!ump.count(x)) {
        if(ht.add(x, 1) != -1) {
            // ump[x] = 1;
            cout << x << ' ';
        }
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
    int Tcase = 1;
    cin >> Tcase; // scanf("%d", &Tcase);
    while (Tcase--) 
        solve();
    // cout << "time: " << 1000.0 * ((clock() - t1) / CLOCKS_PER_SEC) << "ms\n";
    return 0;
}