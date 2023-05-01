#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

typedef unsigned long long ULL;

const int N = 1e6 + 10, P = 131;

int ans, len;
ULL hx[N], rhx[N], p[N];
string str;

inline void init()
{
    memset(hx, 0, sizeof hx);
    memset(rhx, 0, sizeof rhx);
    p[0] = 1, ans = 0, len = str.size();
    for(int i = 1; i <= len; i ++)
    {
        hx[i] = hx[i - 1] * P + (str[i-1] - 'a' + 1);
        p[i] = p[i - 1] * P;
    }
    for(int i = len; i; i --)
    {
        rhx[i] = rhx[i + 1] * P + (str[i-1] - 'a' + 1);
    }
}
inline ULL H1(int l, int r)
{
    return hx[r] - hx[l - 1] * p[r - l + 1];
}
inline ULL H2(int l, int r)
{
    return rhx[l] - rhx[r + 1] * p[r - l + 1];
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T = 0;
	while(cin >> str, str != "END")
	{
	    init();
	    for(int i = 1; i <= len; i ++)
	    {
	        int l = 0, r = len; // min(i - 1, len - i)
    	    while(l < r)
    	    {
    	        int mid = l + r + 1 >> 1;
    	        if(i - mid < 1 || i + mid > len) 
    	        {
    	            r = mid - 1;
    	            continue;
    	        }
    	        if(H1(i - mid, i) == H2(i, i + mid)) l = mid;
    	        else r = mid - 1;
    	    }
    	    ans = max(ans, r << 1 | 1);
    	    l = 0, r = len; // min(i - 1, len - i + 1)
    	    while(l < r)
    	    {
    	        int mid = l + r + 1 >> 1;
    	        if(i - mid < 1 || i + mid - 1 > len) 
    	        {
    	            r = mid - 1;
    	            continue;
    	        }
    	        if(H1(i - mid, i - 1) == H2(i, i + mid - 1)) l = mid;
    	        else r = mid - 1;
    	    }
    	    ans = max(ans, r << 1);
	    }
	    cout << "Case " << ++ T << ": " << ans << endl;
	}
	
	return 0;
}
