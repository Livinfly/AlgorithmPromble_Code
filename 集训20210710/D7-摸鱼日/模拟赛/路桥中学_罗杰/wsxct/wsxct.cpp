#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

typedef long long LL;

const int N = 5e5 + 10;

int n;
int w[N];
int tr[N * 4], rh[N], hr[N];
LL res;


int read()
{
	int s=0,w=1;
	char ch=getchar();
	while(!isdigit(ch))
	{if(ch==' ')w=-1;ch=getchar();}
	while(isdigit(ch)){s=(s<<3)+(s<<1)+(ch^48);ch=getchar();}
	return s*w;
} //¿ì¶ÁÄ£°å
void dfs(int u)
{
	if(~rh[u << 1]) // ×ó 
	{
		dfs(u << 1);
	}
	// P
	if(w[rh[u]] <= w[rh[u << 1]] && ~rh[u << 1]) 
	{
		w[rh[u]] = w[rh[u << 1]] + 1;
		res ++;
	}
	else if(w[rh[u << 1 | 1]] <= w[rh[u]] && ~rh[u << 1 | 1])
	{
		w[rh[u << 1 | 1]] = w[rh[u]] + 1;
		res ++;
	}
	if(~rh[u << 1 | 1]) // ÓÒ
	{
		dfs(u << 1 | 1);
	}
}


int main()
{
	freopen("wsxct.in", "r", stdin);
	freopen("wsxct.out", "w", stdout);
	memset(rh, -1, sizeof rh);
	n = read();
	for(int i = 1; i <= n; i ++) w[i] = read();
	rh[1] = 1;
	for(int i = 2; i <= n; i ++) 
	{
		int b, ch;
		b = read(), ch = read();
		if(ch == 0) // left_son
		{
			rh[i] = rh[b] << 1;
		}
		else // right_son
		{
			rh[i] = rh[b] << 1 | 1;
		}
	}
	
	dfs(1);
	
	printf("%lld\n", res);
	
	return 0;
}
