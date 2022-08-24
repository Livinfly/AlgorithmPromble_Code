#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

#define fi first
#define se second

using namespace std;

typedef pair<int, int> PII;

const int N = 1010;

int n;
PII a[N];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T; cin >> T;
	while(T --)
	{
	  cin >> n;
	  for(int i = 0; i < n; i ++) cin >> a[i].fi >> a[i].se;
	  int cur = 0;
	  for(int i = 0; i < n; i ++)
	  {
	   // cout << a[i].fi << ' ' << a[i].se << ' ' << cur << endl;
	    if(a[i].se < cur) cout << 0 << ' ';
	    else
	    {
	      cur = max(cur, a[i].fi);
	      cout << cur << ' ';
	      cur ++;
	    }
	  }
	  cout << endl;
	}
	return 0;
}