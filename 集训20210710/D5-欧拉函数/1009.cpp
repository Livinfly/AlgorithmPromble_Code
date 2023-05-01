#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

typedef long long LL;

const int N = 1e4 + 10, M = 1e6 + 10;

int n, cnt;
int euler[M], primes[M];
bool st[M];

void get_eulers()
{
	euler[1] = 1;
	for(int i = 2; i < M; i ++)
	{
		if(!st[i])
		{
			primes[cnt ++] = i;
			euler[i] = i - 1;
		}
		for(int j = 0;primes[j] <= M / i; j ++) // <=!!!
		{
			int t = i * primes[j];
			st[t] = true;
			if(i % primes[j] == 0)
			{
				euler[t] = euler[i] * primes[j];
				break;
			}
			euler[t] = euler[i] * (primes[j] - 1);
		}
	}
}

int main()
{
	get_eulers();
	int T; cin >> T;
	while(T --)
	{
		scanf("%d", &n);
		for(int i = n; i < M; i ++)
			if(euler[i] >= n) 
			{
				printf("%d\n", i);
				break;
			}
	}
	
	return 0;
}
/*

n   1 2 3 4 5 6 7 
phi 1 1 2 2 4 2 6 
再加预处理后缀最小值 （每个phi值所对应的最小值）

*/
