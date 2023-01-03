#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

typedef long long LL;

LL n;
LL w[10] = {15, 20, 25}, c[10] = {6, 8, 10};
LL f[150];

int main()
{
	memset(f, 0x3f, sizeof f);
	f[0] = 0;
	for(int i = 0; i < 3; i ++)
		for(int j = c[i]; j <= 120; j ++)
			f[j] = min(f[j], f[j - c[i]] + w[i]);
	for(int i = 120; i; i --)
		f[i] = min(f[i], f[i + 1]);
//	for(int i = 0; i <= 120; i ++)
//		cout << i << ' ' << f[i] << endl;
	LL T; cin >> T;
	while(T --)
	{
		cin >> n;
		if(n & 1LL) n ++;
		LL a = n / 120LL, b = n % 120LL;
		LL res = (LL)a * 300LL + f[b];
		printf("%lld\n", res);
//		cout << (LL)(n / 120) * 300 + f[n % 120] << endl;
	}
    
    return 0;
}
/*
rate is the same.
waste less, better!
*/
