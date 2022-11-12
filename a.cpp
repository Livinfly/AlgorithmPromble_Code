#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <set>

#define fi first
#define se second

using namespace std;

typedef pair<int, int> PII;
typedef long double LD;

const int N = 10;

int tot[5], sum[2];
int n[2];
PII a[2][N];
set<int> st[2];

void dfs(int u) {
	int v = 1-u;
	if(sum[0] == n[0] || sum[1] == n[1]) {
		if(sum[0] == n[0] && sum[1] == n[1]) tot[0] ++;
		else if(sum[0] == n[0]) tot[2] ++;
		else tot[1] ++;
		return;
	}

	for(int i = 1; i <= n[u]; i ++) {
		if(a[u][i].fi > 0) {
			for(int j = 1; j <= n[v]; j ++) {
				if(a[v][j].fi > 0) {
					a[v][j].fi -= a[u][i].se;
					a[u][i].fi -= a[v][j].se;
					if(a[u][i].fi <= 0) sum[u] ++;
					if(a[v][j].fi <= 0) sum[v] ++;
     				st[v].insert(j);
//					cout << u << ' ' << i << " A " << v << ' ' << j << '\n';
//					cout << sum[0] << ' ' << sum[1] << '\n';
     				dfs(v);
     				if(a[u][i].fi <= 0)  sum[u] --;
					if(a[v][j].fi <= 0) sum[v] --;
					a[v][j].fi += a[u][i].se;
					a[u][i].fi += a[v][j].se;
					st[v].erase(j);
				}
			}
			break;
		}
	}
}

int main() {
	scanf("%d%d", &n[0], &n[1]);
	for(int k = 0; k < 2; k ++)
		for(int i = 1; i <= n[k]; i ++) {
			scanf("%d", &a[k][i].fi);
			a[k][i].se = a[k][i].fi;
		}
	if(n[0] > n[1]) {
		dfs(0);
	}
	else if(n[0] == n[1]) {
		dfs(0);
		// tsum
		dfs(1);
	}
	else {
		dfs(1);
		int sum = tot[0]+tot[1]+tot[2];
		for(int i = 0; i < 3; i ++)
			cout << tot[i] << '\n';
		cout << '\n';
		LD res0 = (LD)tot[0]/sum, res1 = (LD)tot[1]/sum, res2 = (LD)tot[2]/sum;
		printf("%.10Lf\n%.10Lf\n%.10Lf\n", res1, res2, res0);
	}
	return 0;
}
/*
2 3
2 5
3 4 1
*/