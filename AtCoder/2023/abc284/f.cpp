#pragma GCC optimize(2)

#include <bits/stdc++.h>

#define fi first
#define se second
#define mkp(x, y) make_pair((x), (y))
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<int,int> hashv;
const LL mod1=1000000007;
const LL mod2=1000000009;
 
hashv operator + (hashv a,hashv b) {
	int c1=a.fi+b.fi,c2=a.se+b.se;
	if (c1>=mod1) c1-=mod1;
	if (c2>=mod2) c2-=mod2;
	return mkp(c1,c2);
}
 
hashv operator - (hashv a,hashv b) {
	int c1=a.fi-b.fi,c2=a.se-b.se;
	if (c1<0) c1+=mod1;
	if (c2<0) c2+=mod2;
	return mkp(c1,c2);
}
 
hashv operator * (hashv a,hashv b) {
	return mkp(1ll*a.fi*b.fi%mod1,1ll*a.se*b.se%mod2);
}

const int N = 2e6+10;

int n;
char s[N];
hashv pw[N], Hx[N], rHx[N], base=mkp(13331,23333);

int main() {
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    // cout << fixed;  // << setprecision(20); // double
    // freopen("i.txt", "r", stdin);
    // freopen("o.txt", "w", stdout);
    scanf("%d", &n);
    n *= 2;
    scanf("%s", s+1);
    pw[0]=mkp(1,1);
    for (int i=1;i<=n;i++) 
        pw[i]=pw[i-1]*base, Hx[i] = Hx[i-1]*base+mkp(s[i],s[i]);
    for(int i = n; i >= 1; i --) 
        rHx[i] = rHx[i+1]*base+mkp(s[i], s[i]);
    for(int i = 0; i <= n/2; i ++) {
        hashv hx1 = Hx[i]*pw[n/2-i]+(Hx[n]-Hx[n/2+i]*pw[n/2-i]);
        hashv hx2 = rHx[i+1]-rHx[n/2+i+1]*pw[n/2];
        if(hx1 == hx2) {
            for(int j = n/2+i; j > i; j --)
                printf("%c", s[j]);
            puts("");
            printf("%d\n", i);
            return 0;
        }
    }
    puts("-1");
    return 0;
}
/*
No自然溢出，双哈希
*/