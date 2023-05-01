#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <bitset>

using namespace std;

const int N = 2e6 + 10;

int n, s;
int f[N]; // reach val_i needs how many

int main()
{
    memset(f, 0x3f, sizeof f);
    f[0] = 0;
	cin >> s >> n;
	for(int i = 0; i < n; i ++)
	{
	    int w; cin >> w;
	    for(int j = w; j < s * 10000; j ++)
	        f[j] = min(f[j], f[j - w] + 1);
	}
	for(int i = 0; i < s * 10000; i ++)
	    if(f[i] > s)
	    {
	        cout << i - 1 << endl;
	        return 0;
	    }
	
	return 0;
}
