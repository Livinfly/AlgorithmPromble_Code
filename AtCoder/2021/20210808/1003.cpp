#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

#define fi first
#define se second

using namespace std;

typedef pair<int, int> PII;

const int N = 1e5 + 10;

int id[N], idn;
int h, w, n;
PII p[N];

int main()
{
    ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> h >> w >> n;
	for(int i = 0; i < n; i ++)
	{
		cin >> p[i].fi >> p[i].se;
		id[++ idn] = p[i].se;
	}
	sort(
    sort(p, p + n);
    
    return 0;
}
