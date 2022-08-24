#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

typedef long long LL;

const int N = 1e4 + 10, M = 3e6 + 10;

int l, r, cnt;
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
		for(int j = 0; primes[j] <= M / i; j ++) // <=!!!
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
	while(scanf("%d%d", &l, &r) == 2)
	{
		LL res = 0;
		for(int i = l; i <= r; i ++)
		{
			res += euler[i];
		}
		cout << res << endl;
	}
	
	return 0;
}
