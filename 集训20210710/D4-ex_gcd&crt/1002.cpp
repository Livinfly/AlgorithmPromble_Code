#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

typedef long long LL;

const int P = 9973;

int n, b;

int ex_gcd(int a, int b, int &x, int &y)
{
	if(!b)
	{
		x = 1, y = 0;
		return a;
	}
	int d = ex_gcd(b, a % b, x, y);
	int t = x;
	x = y;
	y = t - (int)(a / b) * y;
	return d;
}

int main()
{
	int T; cin >> T;
	while(T --)
	{
		cin >> n >> b;
		int x, y;
		ex_gcd(b, P, x, y);
		cout << (x % P * n % P + P) % P << endl;
	}
	
	return 0;
}
