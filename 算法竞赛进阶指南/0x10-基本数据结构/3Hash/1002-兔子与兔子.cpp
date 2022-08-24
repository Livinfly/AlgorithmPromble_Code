#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

typedef unsigned long long ULL;

const int N = 1e6 + 10, P = 13331;

int hx[N], p[N];
int n;
char str[N];

inline int H(int l, int r)
{
    return hx[r] - hx[l - 1] * p[r - l + 1];
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> str + 1 >> n;
	int len = strlen(str + 1);
	p[0] = 1;
	for(int i = 1; i <= len; i ++)
	{
	    hx[i] = hx[i - 1] * P + (str[i] - 'a' + 1);
	    p[i] = p[i - 1] * P;
	}
	while(n --)
	{
	    int l1, r1, l2, r2;
	    cin >> l1 >> r1 >> l2 >> r2;
	    if(H(l1, r1) == H(l2, r2)) cout << "Yes" << endl;
	    else cout << "No" << endl;
	}
	
	return 0;
}
