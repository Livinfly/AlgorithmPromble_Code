#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

typedef long long LL;

const int N = 4010, P = 2147483648;

int n;
int f[N];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	f[0] = 1;
	for(int i = 1; i < n; i ++)
	  for(int j = i; j <= n; j ++)
	    f[j] = ((LL)f[j] + f[j-i]) % P;
	cout << f[n] << endl;
	return 0;
}