#include<bits/stdc++.h>
using namespace std;

#define int long long
#define mo 998244353
#define MAXN 1000005
#define ni(x) ksm(x,mo-2)

int n,m;
int a[MAXN];
int p[MAXN];

int read() {
	int x = 0; char ch = getchar();
	while(ch > '9' || ch < '0') ch = getchar();
	while('0' <= ch && ch <= '9') {
		x = x*10+ch-'0';
		ch = getchar();
	}
	return x; 
}

int ksm(int x,int y) {
	int ans = 1;
	for(; y > 0; y >>= 1,x = x*x%mo)
	if(y&1) ans = ans*x%mo;
	return ans;
}

void rd() {
	n = read();  m = read();
	for(int i = 1; i <= n; i ++) {
		a[i] = read();
		p[a[i]] = i;
	}
}

int jc[MAXN];
int C(int n,int m) {
	return  jc[n]*ni(jc[n-m])%mo*ni(jc[m])%mo; 
}


signed main() {
	rd();
	jc[0] = 1;
	for(int i = 1; i <= n; i ++)
		jc[i] = jc[i-1]*i%mo;
		 
	int nn = 0,x = 0;
	for(int i = 1; i <= n; i ++)
	if(p[i] > x) {
		x = p[i];
		nn ++;
	}
	if(m > nn) {
		cout<<0;
		return 0;
	}
	if(m&1) printf("%lld",mo-C(nn,m));
	else cout<<C(nn,m);
	return 0;
}
/*
5 1 
2 5 4 1 3

5 1
5 4 3 2 1 
*/