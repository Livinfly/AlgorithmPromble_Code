#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

int n, res;

int main()
{
	while(cin >> n)
	{
		res = 0;
		while(n > 1) res += n / 2, n /= 2;
		cout << res << endl;
	}
	
	return 0;
}
