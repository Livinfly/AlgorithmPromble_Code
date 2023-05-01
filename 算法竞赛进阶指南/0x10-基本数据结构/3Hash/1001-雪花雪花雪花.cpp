#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

typedef long long LL;

const int N = 1e5 + 10, P = 99991;

int idx, h[N], ne[N], snow[N][6];
int n;
int a[6];

inline int H(int *a)
{
    int sum = 0, mul = 1;
    for(int i = 0; i < 6; i ++)
    {
        sum = (sum + a[i]) % P;
        mul = (LL)mul * a[i] % P;
    }
    return (sum + mul) % P;
}
inline bool equal(int *a, int *b)
{
    for(int i = 0; i < 6; i ++) // begin
        for(int j = 0; j < 6; j ++) // begin
        {
            bool eq = true;
            for(int k = 0; k < 6; k ++)
                if(a[(i + k) % 6] != b[(j + k) % 6]) eq = false;
            if(eq) return true;
            eq = true;
            for(int k = 0; k < 6; k ++)
                if(a[(i + k) % 6] != b[(j - k + 6) % 6]) eq = false;
            if(eq) return true;
        }
    return false;
}
inline bool insert(int *a)
{
    int val = H(a);
    for(int i = h[val]; ~i; i = ne[i])
        if(equal(snow[i], a)) return true;
    memcpy(snow[idx], a, 6 * sizeof(int));
    ne[idx] = h[val];
    h[val] = idx ++;
    return false;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	memset(h, -1, sizeof h);
	cin >> n;
	while(n --)
	{
	    for(int i = 0; i < 6; i ++) cin >> a[i];
	    if(insert(a))
	    {
	        cout << "Twin snowflakes found." << endl;
	        return 0;
	    }
	}
	cout << "No two snowflakes are alike." << endl;
	return 0;
}
