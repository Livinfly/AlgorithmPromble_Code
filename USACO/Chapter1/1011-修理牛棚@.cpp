#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

const int N = 210;

int n, m, sum;
int w[N], d[N];


int main()
{
	cin >> m >> sum >> n;
	for(int i = 0; i < n; i ++) cin >> w[i];
	sort(w, w + n);
	
	for(int i = 0; i < n - 1; i ++) d[i] = w[i + 1] - w[i] - 1;
	
	sort(d, d + n - 1);
	
	int res = n;
	for(int i = 0; i < n - m; i ++)
	{
	    res += d[i];
	}
	
	cout << res << endl;
	
	return 0;
}
/*
��û��֤����̰�� 

��������һ��ľ��ǵ�����Ҫ�໨��ľ�峤��
���ֻ����m��壬������С���� n - m ���ϲ��ķ���
�������뵽ѡ�� n - m��С�ķ���

Ȼ���Һ����֤���ˣ��� 
*/
