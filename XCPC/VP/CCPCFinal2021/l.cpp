#include<bits/stdc++.h>
using namespace std;

#define MAXN 20005
#define int long long
const int mo = 1145141919827;

int n,m;
int r[MAXN],c[MAXN];
string s[MAXN];
map<int,int>p;
int ans;

void qk() {
	for(int i = 1; i <= n; i ++) r[i] = 0;
	p.clear();
	ans = 0;
}

void dfs(int x,int ow) {
	if(x == 6) {
		if(ow == 0) {
			int hx = 0;
			for(int i = 1; i <= n; i ++) {
				hx = (hx*13+r[i])%mo;
				if(r[i] > c[i]) return;
			}
			p[hx] ++;
		} else {
			int hx = 0;
			for(int i = 1; i <= n; i ++) {
				hx = (hx*13+c[i]-r[i])%mo;
				if(r[i] > c[i]) return;
			}
			ans += p[hx];			
		}
		return;
	}
	for(char i = 'A'; i <= 'D'; i ++) {
		for(int j = 1; j <= n; j ++) {
			if(s[j][x+ow*5-1] == i)
				r[j] ++;
		}
		dfs(x+1,ow);
		for(int j = 1; j <= n; j ++) {
			if(s[j][x+ow*5-1] == i)
				r[j] --;
		}
	}
	
}

int zhi(int x) {
	for(int i = 2; i*i <= x; i ++)
	if(x%i == 0) return 0;
	return 1;
}

signed main() {
	/*for(int i = (int)1145141919810; ; i ++) {
		if(zhi(i)) {
			cout<<i;
			return 0;
		}
	}*/
	int T;
	cin >> T;
	while(T --) {
		cin >> n;
		for(int i = 1; i <= n; i ++) {
			cin >> s[i];
			cin >> c[i];
			c[i] /= 10;
		}
		dfs(1,0);
		for(int i = 1; i <= n; i ++) r[i] = 0;
		dfs(1,1);
		cout<<ans<<"\n";
		qk();
	}
	return 0;
}
/*
3
1
CCCCCCCCCC 90
2
AAAAAAAAAA 10
ABCDABCDAB 20
3
AAAAAAAAAA 0
BBBBBBBBBB 0
CCCCCCCCCC 0

*/