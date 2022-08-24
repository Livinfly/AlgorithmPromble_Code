#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

typedef long long LL;

const int N = 1e6 + 10;


LL n, m;
char str[N];

int main()
{
	cin >> n >> m;
	m %= 26;
	scanf("%s", str + 1);
	for(int i = 1; i <= n; i ++)
	{
		str[i] = (char)( (str[i] - 96) - m + 96);
		if(str[i] < 'a') str[i] = (char)(str[i] + 26);
	}
	cout << str + 1 << endl;
	
	
	return 0;
}
