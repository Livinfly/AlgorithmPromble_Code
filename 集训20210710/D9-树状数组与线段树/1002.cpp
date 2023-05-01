#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

typedef long long LL;

const int N = 1e5 + 10;

int n;
int w[N], tr[N];

int lowbit(int x)
{
	return x & -x;
}
void add(int x, int c)
{
	for(; x <= n; x += lowbit(x)) tr[x] += c; 
}
int query(int x)
{
	int res = 0;
	for(; x; x -= lowbit(x)) res += tr[x];
	return res;
}

int main()
{
	ios::sync_with_stdio(0);
	while(cin >> n)
	{
		memset(tr, 0, sizeof tr);
		for(int i = 1; i <= n; i ++) cin >> w[i];
		
		LL res = 0;
		for(int i = n; i >= 1; i --) // find maxer
		{
			res += query(w[i] - 1);
			add(w[i], 1);
		}
		
		cout << res << endl;
	}
	
	return 0;
}
