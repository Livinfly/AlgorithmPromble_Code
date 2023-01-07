#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstring>

using namespace std;

typedef long long LL;

const int N = 5e5 + 10;

int n, equal_cnt;
LL res;
int a[N], b[N];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	// freopen("i.txt", "r", stdin);
	// freopen("o.txt", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		b[a[i]] = i;
		if (a[i] == b[a[i]])
			equal_cnt++;
		else if (a[i] < i && a[a[i]] == i) // 我指向的数指向我的位置，而我的指向已经是它的位置了。
			res++;
	}
	res += (LL)equal_cnt * (LL)(equal_cnt - 1) / 2;
	cout << res << endl;
	return 0;
}