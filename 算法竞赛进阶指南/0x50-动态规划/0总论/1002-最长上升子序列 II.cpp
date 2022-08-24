#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

const int N = 1e5 + 10;

int top, stk[N]; // stk[i] 想要构成i+1长度的最长上升子序列, 需要的最小代价
int n;
int a[N], f[N];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i ++) cin >> a[i];
	stk[++ top] = a[1];
	for(int i = 1; i <= n; i ++)
	{
	  if(stk[top] < a[i]) stk[++ top] = a[i];
	  else *lower_bound(stk+1, stk+top+1, a[i]) = a[i];
	  // 更新最小的>=a[i]位置的最小代价(与1~pos-1可以构成长度为pos的序列)
	}
	cout << top << endl;
	
	return 0;
}