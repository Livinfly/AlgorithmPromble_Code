#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

int n, m;
string str;

int main()
{
	cin >> n >> m >> str;
	str = " " + str;
	
	while(m --)
	{
		int l, r;
		scanf("%d%d", &l, &r);
		str.erase(str.begin() + l, str.begin() + r + 1);
		int tmp = 1, t;
		for(int i = l; i <= r; i ++, t *= 2) tmp += (str[i] - 48) * t;
		str.insert(str.begin() + l, t - tmp - 1, '0');
		str.insert(str.begin() + l + t - tmp - 1, '1');
		str.insert(str.begin() + l + t - tmp, tmp, '0');
		
	}
	
	
	puts("");
	
	return 0;
}
