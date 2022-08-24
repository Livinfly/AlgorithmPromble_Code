#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

const int N = 210, D = 110, P = 9901;

int n, d;
int f[N][D]; // i nodes, depth <= j cnt

int main()
{
	cin >> n >> d;
	for(int i = 1; i <= d; i ++) f[1][i] = 1;
	for(int i = 2; i <= n; i ++)
		for(int j = 1; j <= d; j ++)
			for(int k = 1; k <= i - 2; k ++)
				f[i][j] = (f[i][j] + f[i - k - 1][j - 1] * f[k][j - 1] % P) % P;
	
	cout << ((f[n][d] - f[n][d - 1]) % P + P) % P << endl; // depth == d cnt
	
	return 0;
}
