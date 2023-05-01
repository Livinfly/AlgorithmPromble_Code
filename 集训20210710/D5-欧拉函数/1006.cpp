#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

const int N = 1e4 + 10, M = 32768;

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
	int T; cin >> T;
	while(T --)
	{
		cin >> n;
		cout << euler[n] << endl; 
	}
	
	return 0;
}
/*
求与n互质的数的个数 
*/
