// #pragma GCC optimize(2)

#include <bits/stdc++.h>

#define fi first
#define se second
#define pb push_back
#define mkp(x, y) make_pair((x), (y))
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;
typedef double db;
typedef pair<int, int> PII;

void solve() {
    int Q; cin >> Q;
    queue<int> q;
    priority_queue<int, vector<int>, greater<int>> heap;
    while(Q--) {
        int op, x; cin >> op;
        if(op == 1) {
            cin >> x;
            q.push(x);
        }
        else if(op == 2) {
            if(!heap.empty()) {
                cout << heap.top() << '\n';
                heap.pop();
            }
            else {
                cout << q.front() << '\n';
                q.pop();
            }
        }
        else {
            while(!q.empty()) {
                heap.push(q.front());
                q.pop();
            }
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
    // cout << "time: " << 1000.0 * (1.*(clock() - t1) / CLOCKS_PER_SEC) << "ms\n";
    return 0;
}