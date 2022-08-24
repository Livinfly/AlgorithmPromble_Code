#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

int n, l;
unsigned int k; // unsigned
int f[33][33]; // front i bits no more than j 1 counts
string ans;

int main()
{
	cin >> n >> l >> k;
	for(int i = 0; i <= n; i ++) f[i][0] = f[0][i] = 1;
	for(int i = 1; i <= n; i ++)
	    for(int j = 1; j <= n; j ++)
	        f[i][j] = f[i - 1][j] + f[i - 1][j - 1];
	for(int i = n; i; i --)
	{
	   // cout << k << ' ' << f[i - 1][l] << endl;
	    if(k > f[i - 1][l]) 
	    {
	        cout << 1;
	        k -= f[i - 1][l];
	        l --;
	    }
	    else
	    {
	        cout << 0;
	    }
	}
	cout << endl;
	return 0;
}
