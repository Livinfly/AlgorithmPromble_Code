#include <bits/stdc++.h>

#define fi first
#define se second
#define all(a) (a).begin(), (a).end()

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 310, M = 15000;
const LL INF = 1e18;

int idx, h[N], ne[M], ver[M];
LL e[M], rec[M];
int n, m, S, T, C;
int d[N], cur[N];

void add(int a, int b, LL c) {
	ver[idx] = b, e[idx] = c, ne[idx] = h[a], h[a] = idx ++;
}
bool bfs() {
	queue<int> q;
	memset(d, -1, sizeof d);
	q.push(S);
	d[S] = 0, cur[S] = h[S];
	while(q.size()) {
		int t = q.front(); q.pop();
		for(int i = h[t]; ~i; i = ne[i]) {
			int v = ver[i];
			if(d[v] == -1 && e[i]) {
				d[v] = d[t]+1;
				cur[v] = h[v];
				if(v == T) {
					return true;
				}
				q.push(v);
			}
		}
	}
	return false;
}
LL update(int u, LL limit) {
	if(u == T) return limit;
	LL flow = 0;
	for(int i = cur[u]; ~i && flow < limit; i = ne[i]) {
		cur[u] = i;
		int v = ver[i];
		if(d[v] == d[u]+1 && e[i]) {
			LL t = update(v, min(e[i], limit-flow));
			if(!t) d[v] = -1;
			flow += t;
			e[i] -= t;
			e[i^1] += t;
		}
	}
	return flow;
}
LL dinic() {
	LL res = 0, flow;
	while(bfs())
		while(flow = update(S, INF)) 
			res += flow;
	return res;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout << fixed;
	memset(h, -1, sizeof h);
	cin >> n >> m >> C;
	S = 0, T = n;
	while(m --) {
		int a, b, c;
		cin >> a >> b >> c;
		rec[idx] = c;
		add(a, b, c), add(b, a, 0);
	}
	LL res = dinic(), r1 = ver[0^1], r2 = ver[0];
	vector<PII> vvv;
	for(int i = 0; i < idx; i += 2)
		if(e[i] == 0) 
			vvv.emplace_back(ver[i^1], ver[i]);
	for(auto [x, y] : vvv) {
//		int x = ver[zzz^1], y = ver[zzz];
		bool ok = false;
		for(int z = 0; z < idx; z += 2) { // .....
			e[z] = rec[z] + (!ok && ver[z] == y && ver[z^1] == x ? C : 0);
			e[z^1] = 0;
			if(ver[z] == y && ver[z^1] == x) ok = true;
		}
//		cout << endl;
//		cout << x << ' ' << y << endl;
//		for(int z = 2; z < idx; z += 2)
//			cout << ver[z^1] << ' ' << ver[z] << ' ' << e[z] << endl;
		LL tres = dinic();
		if(tres >= res) {
			res = tres;
			r1 = x, r2 = y;
		}
	}
	cout << r1 << ' ' << r2 << ' ' << res << '\n';
	return 0;
}