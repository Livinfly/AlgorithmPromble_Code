#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

typedef long long LL;

LL n; 

void work()
{
	n --;
	if(n <= 2) 
	{
		cout << n + 1 << endl;
		return;
	}
	LL ans = 2, s = 3, rate = 3;
	while(s + rate * 3 + rate <= n)
	{
		s = s + rate * 3 + rate;
		rate = rate * 3;
		ans += 2;
	}
	LL rest = n - s;
	while(rate >= 1)
	{
		ans += rest / rate;
		rest %= rate;
		rate /= 3;
	}
	
	cout << ans << endl;
	
	return;
}

int main()
{
	cin >> n;
	
	work();
	
	return 0;
}
