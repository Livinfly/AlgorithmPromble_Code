#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

typedef long long LL;

const int N = 40;

int n, sum;
LL f[N][400]; // 用不超过i的数来划分j的方案数 

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i ++) sum += i;
    if(sum & 1 != 0) 
	{
		cout << 0 << endl;
		return 0;
	}
	sum >>= 1;
	for(int i = 1; i <= n; i ++)
		for(int j = 1; j <= sum; j ++)
			if(j > i) f[i][j] = f[i - 1][j] + f[i - 1][j - i];
			else if(j < i) f[i][j] = f[i - 1][j];
			else f[i][j] = f[i - 1][j] + 1;
	
	cout << (f[n][sum] >> 1) << endl;
	
	return 0;
}
