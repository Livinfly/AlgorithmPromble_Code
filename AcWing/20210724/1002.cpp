#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <map>

using namespace std;

typedef pair<int, int> PII;

const int N = 2e5 + 10;

int T, n, idx, sum;
int a[N];
bool st[N];
map<int, PII> ans;

int main()
{
    ios::sync_with_stdio(0);
    cin >> T;
	for(int i = 1; i <= T; i ++)
	{
		memset(st, 0, sizeof st);
		sum = 0;
		cin >> n;
		for(int j = 1; j <= n; j ++)
		{
			cin >> a[j];
			sum += a[j];
		}
		for(int j = 1; j <= n; j ++)
		{
			int t = sum - a[j];
			if(ans.count(t) == 0) ans[t] = make_pair(i, j);
			else if(ans.count(t) != 0 && ans[t].first != i)
			{
				cout << "YES" << endl;
				cout << ans[t].first << ' ' << ans[t].second << endl;
				cout << i << ' ' << j << endl;
				return 0;
			}
		}
	}
	
	cout << "NO" << endl;
    
    return 0;
}
