#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

int n, sum, cnt;

inline void dfs(const int &x, const int &tsum)
{
    if(tsum == sum) 
    {
        cnt ++;
        return;
    }
	for(register int i = x - 1; i; i --)
        if(tsum + i <= sum) dfs(i, tsum + i);
}
inline void solve()
{
	if((n & 1) == 0 && (n % 4) != 0) 
	{
		cout << 0 << endl;
		return;
	}
	for(register int i = 1; i <= n; i ++) sum += i;
	sum >>= 1;
	dfs(n, n);
	cout << cnt << endl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	cin >> n;
	solve();
	
	return 0;
}
