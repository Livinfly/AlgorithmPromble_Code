#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

typedef long long LL;

const int N = 1e5 + 10, P = 9973;

int n, len, l, r;
int s[N];
char str[N];

int qpm(int a, int b)
{
	int ans = 1;
	while(b)
	{
		if(b & 1) ans = ans * a % P;
		a = a * a % P;
		b >>= 1;
	}
	return ans;
}

int main()
{
	s[0] = 1;
	while(cin >> n)
	{
		scanf("%s", str + 1);
		len = strlen(str + 1);
		for(int i = 1; i <= len; i ++) s[i] = s[i - 1] * ((int)str[i] - 28) % P;
//		for(int i = 0; i <= len; i ++)
//			cout << s[i] << endl;
//		cout << endl;
		
		while(n --)
		{
			cin >> l >> r;
			cout << ((s[r] + P) * qpm(s[l - 1], P - 2)) % P << endl; 
		} 
	}
	
	return 0;
}
