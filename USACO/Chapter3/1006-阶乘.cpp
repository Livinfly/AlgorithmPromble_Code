#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

int n;
int m2, m5; // only 2 and 5 can produce 0

inline int qpm(int a, int b)
{
    int ans = 1;
    while(b)
    {
        if(b & 1) ans = ans * a % 10;
        a = a * a % 10;
        b >>= 1;
    }
    return ans;
}

int main()
{
	cin >> n;
	int res = 1;
	for(int i = 1; i <= n; i ++)
	{
	    int t = i;
	    while((t & 1) == 0) t /= 2, m2 ++; // prior!!!
	    while(t % 5 == 0) t /= 5, m5 ++;
	    res = res * t % 10;
	}
	if(m2 > m5)
	{
	    res = res * qpm(2, m2 - m5) % 10;
	}
	else
	{
	    res = res * qpm(5, m5 - m2) % 10;
	}
	cout << res << endl;
	
	return 0;
}
