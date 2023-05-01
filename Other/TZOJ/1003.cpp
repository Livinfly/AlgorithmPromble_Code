#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

typedef long long LL;

const int N = 1e6 + 10, P = 1e9 + 7;

int n, m;
LL fa[N], sum[N], siz[N];

inline int get_fa(int x)
{
	if(x == fa[x]) return x;
	return fa[x] = get_fa(fa[x]);
}
inline int qpm(LL a, int b)
{
	LL ans = 1;
	while(b)
	{
		if(b & 1) ans = (ans * a) % P;
		a = a * a % P;
		b >>= 1;
	}
	return ans;
}

int main()
{
    ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i ++)
	{
		cin >> sum[i];
		fa[i] = i;
		siz[i] = 1;
	}
	while(m --)
	{
		int op, x, y, k;
		cin >> op;
		if(op == 1)
		{
			cin >> x >> y;
			int a = get_fa(x), b = get_fa(y);
			if(a != b) // ???
			{
				sum[b] = (sum[b] + sum[a]) % P;
				siz[b] += siz[a];
				fa[a] = b;
			}
		}
		else if(op == 2)
		{
			cin >> x >> k;
			int a = get_fa(x);
			sum[a] = (sum[a] + k) % P;
		}
		else
		{
			cin >> x;
			int a = get_fa(x);
			LL res = sum[a] * qpm(2, siz[a] - 1) % P;
			cout << (res + P) % P << endl;
		}
	}
    
    return 0;
}
