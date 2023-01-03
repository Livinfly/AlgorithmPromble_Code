#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

typedef long long LL;

const int N = 3e5 + 10;

int n, k;
int a[N];

int main()
{
    ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int T; cin >> T;
	while(T --)
	{
		cin >> n >> k;
		for(int i = 1; i <= n; i ++) cin >> a[i];
		LL res = -1e18;
		for(int i = max(n - 2 * k, 1); i <= n; i ++)
			for(int j = i + 1; j <= n; j ++)
				res = max(res, (LL)i * j - k * (a[i] | a[j]));
		cout << res << endl;
	}
    
    return 0;
}
/*
possible maxn's min -> (n - 1, n)'s min -> n(n - 1) - k(a[n] | a[n - 1]) <= n(n - 1) - 2kn
for every i, a possible maxn's max -> (i, n)' max -> in

want to update
so in > n(n - 1) - 2kn
so i > n - 2k - 1
*/
