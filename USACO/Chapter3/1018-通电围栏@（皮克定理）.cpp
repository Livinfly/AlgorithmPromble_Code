#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>

#define fi first
#define se second
#define mkp(x, y) make_pair(x, y)

using namespace std;

typedef pair<int, int> PII;

int n, m, p;
PII q[3];

inline int gcd(int a, int b)
{
    return b ? gcd(b, a % b) : a;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m >> p;
	int s = p * m;
	int b = 0;
	q[0] = mkp(0, 0), q[1] = mkp(p, 0), q[2] = mkp(n, m);
	for(int i = 0; i < 3; i ++)
	    for(int j = i + 1; j < 3; j ++)
	        b += abs(gcd(q[j].fi - q[i].fi, q[j].se - q[i].se));
    cout << (s - b + 2) / 2 << endl;
	return 0;
}
/* 
* S：多边形面积， a：内部整点数，b：边上整点数 
* S = a + b / 2 - 1 
* b = gcd(x, y)（把这条边一段移到原点）
*/ 
