#pragma GCC optimize(2)

#include <bits/stdc++.h>

#define fi first
#define se second
#define mkp(x, y) make_pair((x), (y))
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 2010;

vector<int> e[N];
int n, m;
int p[N], d[N];

void solve() {
    cin >> n >> m;
    vector<bool> st(n+1);
    while(m --) {
    	int a, b;
    	cin >> a >> b;
    	e[a].push_back(b);
    	e[b].push_back(a);
    }
    int k;
    cin >> k;
    for(int i = 0; i < k; i ++) {
    	cin >> p[i] >> d[i];
    	queue<int> q;
    	vector<int> dis(n+1, -1);
    	q.push(p[i]);
    	dis[p[i]] = 0;
        if(dis[p[i]] < d[i]) st[p[i]] = true;
    	while(q.size()) {
    		int u = q.front();
    		q.pop();
    		for(auto v : e[u]) {
    			if(!~dis[v]) {
                    dis[v] = dis[u]+1;
        			if(dis[v] < d[i]) {
        				st[v] = true;
        				q.push(v);
        			}
                }
    		}
    	}
    }
    bool ok = true;
    for(int i = 0; i < k; i ++) {
        bool tok = false;
        queue<int> q;
        vector<int> dis(n+1, -1);
        q.push(p[i]);
        dis[p[i]] = 0;
        
        while(q.size()) {
            int u = q.front();
            // cout << u << endl;
            q.pop();
            if(!st[u] && dis[u] == d[i]) {
                tok = true;
                break;
            }
            for(auto v : e[u]) {
                if(!~dis[v]) {
                    dis[v] = dis[u]+1;
                    if(dis[v] <= d[i])
                        q.push(v);
                }
            }
        }
        if(!tok) {
            ok = false;
            break;
        }
    }

    vector<int> ans;
    for(int i = 1; i <= n; i ++)
    	if(!st[i]) {
    		ans.push_back(i);
        }
    if(!ok || ans.size() == 0) cout << "No\n";
    else {
        cout << "Yes\n";
        for(int i = 1; i <= n; i ++)
            cout << !st[i];
        cout << '\n';
    }
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