#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

#define fi first
#define se second

using namespace std;

typedef pair<int, int> PII;

const int N = 2e5 + 10;

int n;
PII a[N];

int main()
{
    ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i ++) 
	{
		cin >> a[i].fi;
		a[i].se = i;
	}
    sort(a + 1, a + n + 1);
    
    cout << a[n - 1].se << endl;
    
    return 0;
}
