#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

typedef long long LL;

const int N = 1e5 + 10;

int n, m;
LL K;
int a[N], b[N];

bool check(int mid)
{
	LL cnt = 0;
	for(int i = 0, j = m - 1; i < n && j >= 0;) // ��i������i�ɶԵ�j�ĸ��� //j >= 0..
	{
		if(a[i] + b[j] <= mid) 
		{
			cnt += j + 1;
			i ++;
		}
		else j --;
	}
	return cnt >= K; // midҪ����ɵ��������棬һ�����mid�Լ�����ȥҲ����Ҫ>= K 
}

int main()
{
	int T; scanf("%d", &T);
	while(T --)
	{
		scanf("%d%d%lld", &n, &m, &K);
		for(int i = 0; i < n; i ++) scanf("%d", &a[i]);
		for(int i = 0; i < m; i ++) scanf("%d", &b[i]);
		sort(a, a + n); sort(b, b + m);
		
		int l = 1, r = 2e8;
		while(l < r)
		{
			int mid = l + r >> 1;
			if(check(mid)) r = mid; // �������� �޸�����ʹmid �������� 
			else l = mid + 1;
		}
		printf("%d\n", r);
	}
	
	return 0;
}
/*
Ѱ�ҵ�kС������ת��Ϊ���㡰k-1������ǰ�桱�����е���С����
�� <= x ���� >= k-1 ��������С����
����һ������f(x)����ʾ��f(x)����������a[i] + b[j] <= x
��ֱ�Ӷ���x�����kС������ֵqwq
000000000000111111111
            * 
*/
