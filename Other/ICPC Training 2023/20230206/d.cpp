#include <bitsdc++.h>
using namespace std;

#define int long long
#define MAXN 10005
#define mo 998244353

int a[505][505];
int n;

int qwq(int n)
{
	int i,j,k,r = 1,fh = 0,l;
	for (i = 1; i <= n; i ++)
	{
		k = i;
		for (j = i ; j <= n; j ++) 
		if (a[j][i]) 
		{
			k = j;
			break;
		}
		if (a[k][i] == 0) 
			return 0;
		for (++j;j <= n; j ++) 
		if (a[j][i] && a[j][i] < a[k][i]) 
			k=j;
		if (i != k) 
		{
			swap(a[k],a[i]);
			fh ^= 1;
		}
		
		for (j = i+1; j <= n; j ++)
		{
			if (a[j][i] > a[i][i]) 
			{
				swap(a[j],a[i]);
				fh ^= 1;
			}
			while (a[j][i])
			{
				l = a[i][i] / a[j][i];
				for (k = i; k <= n; k ++) 
					a[i][k] = (a[i][k]+(mo-l)*a[j][k])%mo;
				swap(a[j],a[i]);
				fh ^= 1;
			}
		}
		r = r*a[i][i]%mo;
	}
	if (fh) return (mo-r)%mo;
	return r;
}

int c[MAXN],b[MAXN]; 

signed main()	{
	int T;
	cin >> T;
	while(T --) {
		memset(a,0,sizeof(a));
		int n;
		cin >> n;
		for(int i = 1; i <= n; i ++)
			cin >> b[i];
		for(int i = 1; i <= n; i ++)
			cin >> c[i];
		if(n >= 500) {
			cout<<0<<"\n";
			continue;
		}
		for(int i = 1; i <= n; i ++) {
			for(int j = 1; j <= n; j ++) {
				a[i][j] = b[i]^c[j];
			//	cout<<a[i][j]<<" ";
			}
		//	cout<<"\n";
		}
		cout<<qwq(n)<<"\n";
	}
	return 0;
}
/*
100
1000
2 5
4 1

2
6 3
1 4
*/