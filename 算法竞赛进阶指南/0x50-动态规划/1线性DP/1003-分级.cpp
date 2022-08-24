#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

typedef long long LL;
const int N = 2010;

int m, num[N];
int n;
int a[N], c[N];
LL f[N][N], g[N][N];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i ++)
	{
	  cin >> a[i];
	  num[++ m] = a[i];
	}
	sort(num+1, num+m+1);
	m = unique(num+1, num+m+1) - (num+1);
	memset(f, 0x3f, sizeof f);
	memset(g, 0x3f, sizeof g);
	f[0][0] = g[0][m+1] = 0;
	for(int i = 1; i <= n; i ++)
	{
	  LL S = f[i-1][0];
	  for(int j = 1; j <= m; j ++)
	  {
	    S = min(S, f[i-1][j]);
	    f[i][j] = min(f[i][j], S + abs(a[i]-num[j]));
	  }
	  S = g[i-1][m+1];
	  for(int j = m; j >= 1; j --)
	  {
	    S = min(S, g[i-1][j]);
	    g[i][j] = min(g[i][j], S + abs(a[i]-num[j]));
	  }
	}
	LL res = (1LL<<62);
	for(int j = 1; j <= m; j ++)
	  res = min(res, min(f[n][j], g[n][j]));
  cout << res << endl;
	return 0;
}
/*
思路
状态表示: f[i][j]表示A的钱i个数变成非严格单调递增,其中结尾变为了数值[j]的最小代价
f[i][j] = min{f[i-1,k]} 其中(k < j) + abs(a[i]-j)

做法1 O(n3)−>O(n2)O(n3)−>O(n2)
可以通过绝对值不等式(货仓选址)证明, 有一种满足条件的b[]的值都属于a[]
使得f[][]的状态数从2000∗1092000∗109 -> 2000220002
以非严格单调上升为例:
f[i][j]=minf[i−1][k](k<=j)f[i][j]=minf[i−1][k](k<=j)
发现因为我们j是从1->m的, 所以f[i][…]的候选集合是只增不减的,
考虑LCIS的优化方式, 按照候选集合增长的方式设置一个集合S, 放入候选集合.
下降的情况类似, 同样要注意第一个边界状态f[i-1][m+1]=0

(上文代码)

做法2 O(n4)−>O(n3)O(n4)−>O(n3) 超时
状态表示: f[i]表示构造1~i的b[]的最小代价

预处理的做不对不知道为什么
*/