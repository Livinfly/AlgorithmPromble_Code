#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;

typedef long long LL;

int n, m, p;
double k1, k2, b2;

inline int get_cnt(double x)
{
    if(p > n)
    {
        if(x < n) return (int)(k1 * x - 1e-8);
        return (int)(k2 * x + b2 - 1e-8);
    }
    if(x < p) return (int)(k1 * x - 1e-8);
    return (int)(k1 * x - 1e-8) - (int)(k2 * x + b2 + 1e-8); // l2: (+ 1e-8) wucha ((- 1e-8)x)
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m >> p;
	k1 = 1.0 * m / n, k2 = 1.0 * m / (n - p), b2 = - k2 * p;
// 	cout << k1 << ' ' << k2 << ' ' << b2 << endl;
	LL res = 0;
	for(int i = 1; i < max(p, n); i ++)
	{
	    res += get_cnt(i);
	   // cout << get_cnt(i) << endl;
	}
	cout << res << endl;
	return 0;
}
