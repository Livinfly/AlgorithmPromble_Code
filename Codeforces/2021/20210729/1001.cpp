#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

typedef long long LL;

const int N = 3e5 + 10;

int n;
int a[N];

int main()
{
    ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int T; cin >> T;
	while(T --)
	{
		cin >> n;
		for(int i = 0; i < n; i ++) cin >> a[i];
		LL res = 0;
		for(int i = 1; i < n; i ++)
			res = max(res, (LL)a[i] * a[i - 1]);
		cout << res << endl;
	}
    
    return 0;
}
/*
think some special ans = max(a[i] * a[i - 1])
*/
