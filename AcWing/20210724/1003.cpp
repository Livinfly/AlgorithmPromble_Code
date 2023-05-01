#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

typedef long long LL;

const int N = 5e5 + 10;

int stk[N];
int n;
int m[N];
LL l[N], r[N]; 

int main()
{
    scanf("%d", &n);
    for(int i = 1; i <= n; i ++) scanf("%d", &m[i]);
    
//  stk[0] = 0;
    int tt = 0;
    for(int i = 1; i <= n; i ++)
	{
		while(tt && m[stk[tt]] >= m[i]) tt --;
		l[i] = l[stk[tt]] + (LL)m[i] * (i - stk[tt]);
		stk[++ tt] = i;
	}
	
	stk[0] = n + 1;
	tt = 0;
	for(int i = n; i > 0; i --)
	{
		while(tt && m[stk[tt]] >= m[i]) tt --;
		r[i] = r[stk[tt]] + (LL)m[i] * (stk[tt] - i);
		stk[++ tt] = i;
	}
	
	LL res = 0, t = 0; // LL!! 总合会爆int 
	int pos = 0;
	for(int i = 1; i <= n; i ++)
	{
//	    printf("i = %d, l = %d, r = %d\n", i, m[l[i]], m[r[i]]);
		t = l[i] + r[i] - m[i];
		if(t > res)
		{
			res = t;
			pos = i;
		}
	}
	
	for(int i = pos - 1; i > 0; i --) // 因为以pos为最高，左右两边为递减 
		m[i] = min(m[i], m[i + 1]);
	for(int i = pos + 1; i <= n; i ++)
		m[i] = min(m[i], m[i - 1]);
	
	for(int i = 1; i <= n; i ++)
		printf("%d ", m[i]);
	puts("");
	
    return 0;
}
/*
构造单峰函数 
l[i], r[i] 1~i /, i~n \

a[i] = m[i]
a[i - 1] = min(m[i - 1], a[i])
a[i - 2] = min(m[i - 2], a[i - 1])
...
会超时
单调栈：找到一个序列中 一个数左/右边离它最近比它小/大的数在哪里 存的值下标/元素值
这里是找左/右第一个比它大的数的位置 
      --
(---)/  \
----/    --
           \
            \
li = lj + (i - 1) * mi 

*/
