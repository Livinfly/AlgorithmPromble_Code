#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

const int N = 1e5 + 10;

int n;
int a[N];

int gcd(int a, int b)
{
	return b == 0 ? a : gcd(b, a % b);
}

int main()
{
	int T; cin >> T;
	while(T --)
	{
		bool flag = true;
		scanf("%d", &n);
		for(int i = 1; i <= n; i ++) 
		{
			scanf("%d", &a[i]);
			if(a[i] < 0) a[i] = -a[i];
		}
		if(!flag) continue;
		sort(a + 1, a + n + 1);
		if(a[1] == 1 || a[n] > 1e6) 
		{
			cout << "Yes" << endl;
			continue;
		}
		for(int i = 1; i <= n; i ++)
		{
			for(int j = i + 1; j <= n; j ++)
				if(gcd(a[i], a[j]) == 1) 
				{
					flag = false;
					break;
				}
			if(!flag) break;
		}
		if(flag) puts("No");
		else puts("Yes");
	}
	
	return 0;
}
