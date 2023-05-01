#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

typedef unsigned long long ULL;

const int N = 3e5 + 10, P = 131;

int n;
int sa[N], hight[N];
ULL hx[N], p[N];
char str[N];

inline ULL H(int l, int r)
{
    return hx[r] - hx[l - 1] * p[r - l + 1];
}
inline int lcp(int x, int y)
{
    int l = 0, r = min(n-x+1, n-y+1);
    while(l < r)
    {
        int mid = l + r + 1 >> 1;
        if(H(x, x+mid-1) == H(y, y+mid-1)) l = mid;
        else r = mid - 1;
    }
    return r;
}
inline bool cmp(int a, int b)
{
    int len = lcp(a, b);
    return str[a+len] < str[b+len];
}
inline void calu_hight()
{
    for(int i = 2; i <= n; i ++)
        hight[i] = lcp(sa[i-1], sa[i]);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> str + 1;
	n = strlen(str + 1);
	p[0] = 1;
	for(int i = 1; i <= n; i ++)
	{
	    sa[i] = i;
	    hx[i] = hx[i - 1] * P + str[i] - 'a' + 1;
	    p[i] = p[i - 1] * P;
	}
	sort(sa + 1, sa + n + 1, cmp);
	calu_hight();
	for(int i = 1; i <= n; i ++) 
	    cout << sa[i] - 1 << ' '; cout << endl;
	for(int i = 1; i <= n; i ++) 
	    cout << hight[i] << ' '; cout << endl;
	return 0;
}
