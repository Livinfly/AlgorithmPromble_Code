#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

const int P = 21252;

int x, y, d;
int a[4];
int m[4] = {0, 23, 28, 33};

void ex_gcd(int a, int b, int &x, int &y)
{
	if(!b)
	{
		x = 1, y = 0;
		return;
	}
	ex_gcd(b, a % b, x, y);
	int t = x;
	x = y, y = t - a / b * y;
	return;
}
int crt()
{
	int res = 0;
	for(int i = 1; i <= 3; i ++)
	{
		int w = P / m[i];
		ex_gcd(w, m[i], x, y); // x为w关于m[i]取模的逆 
//		res = (res + a[i] * w * ((x % m[i] + m[i]) % m[i])) % P;
		res = (res + a[i] * w * x % P) % P;
	}
	return (res % P + P) % P;
}

int main()
{
	int T;
	cin >> T; T = 0;
	while(scanf("%d%d%d%d", &a[1], &a[2], &a[3], &d) == 4)
	{
		if(a[1] == a[2] && a[2] == a[3] && a[3] == d && d == -1) break;
		
		int ans = crt();
		ans = ((ans - d) % P + P) % P;
		if(!ans) ans = P;
		printf("Case %d: the next triple peak occurs in %d days.\n", ++ T, ans);
	}
	
	return 0;
}
