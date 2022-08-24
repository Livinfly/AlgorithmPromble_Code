#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

int a[5][5], b[3];

inline int gcd(int a, int b)
{
    return b ? gcd(b, a % b) : a;
}
inline bool check()
{
    int d = gcd(gcd(b[0], b[1]), b[2]);
    if(!d) return false;
    for(int i = 0; i < 3; i ++)
    {
        b[i] /= d;
        if(b[i] != a[0][i]) return false;
    }
    return true;
}

int main()
{
	for(int i = 0; i < 4; i ++)
	{
	    for(int j = 0; j < 3; j ++)
	        cin >> a[i][j];
	}
	int d = gcd(gcd(a[0][0], a[0][1]), a[0][2]);
    for(int j = 0; j < 3; j ++)
        a[0][j] /= d;
    for(int i = 0; i < 100; i ++)
        for(int j = 0; j < 100; j ++)
            for(int k = 0; k < 100; k ++)
            {
                for(int u = 0; u < 3; u ++)
                {
                    b[u] = a[1][u] * i + a[2][u] * j + a[3][u] * k;
                    if(b[u] < a[0][u] * d) break;
                }
                if(check())
                {
                    cout << i << ' ' << j << ' ' << k << ' ';
                    for(int u = 0; u < 3; u ++)
                    {
                        if((a[1][u] * i + a[2][u] * j + a[3][u] * k) / (a[0][u] * d))
                        {
                            cout << (a[1][u] * i + a[2][u] * j + a[3][u] * k) / (a[0][u] * d) << endl;
                            break;
                        }
                    }
                    return 0;
                }
            }
	cout << "NONE" << endl;
	
	return 0;
}
