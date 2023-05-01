#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

int n, d;
int gcd(int a, int b)
{
	return b ? gcd(b, a % b) : a;
}

int main()
{
	int T; cin >> T;
	while(T --)
	{
		cin >> n;
		cin >> d;
		if(d < 0) d = -d; // SJ
		for(int i = 2; i <= n; i ++) 
		{
			int a;
			cin >> a;
			if(a < 0) a = -a; // SJ
			d = gcd(d, a);
		}
		if(d == 1) puts("Yes");
		else puts("No");
	} 
	
	return 0;
}
