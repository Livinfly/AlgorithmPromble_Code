#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <set>

using namespace std;

const int N = 1e5 + 10;

int n, m;
double ans;
set<string> S;
struct rec
{
	string s;
	operator < (const rec &o) const
	{
		return s.size() < o.s.size() || s.size() == o.s.size() && s < s;
	}
} s1[N];

inline double qpm(double a, int b)
{
	double ans = 1;
	while(b)
	{
		if(b & 1) ans = ans * a;
		a = a * a;
		b >>= 1;
	}
	return ans;
}

int main()
{
	cin >> n >> m;
	for(int i = 0; i < n; i ++) cin >> s1[i].s;
	sort(s1, s1 + n);
	for(int i = 0; i < n; i ++)
	{
		bool flag = false;
		string t = s1[i].s;
		for(int j = 1; j <= t.size(); j += 2)
			if(S.count(t.substr(0, j)))
			{
				flag = true;
				break;
			}
		if(flag) continue;
		S.insert(t);
		double a = m / qpm(2.0, (int)(t.size() - 1) / 2);
		ans += a * a;
	}
    printf("%.3lf\n", ans);
    return 0;
}
