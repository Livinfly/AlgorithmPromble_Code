#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

const int N = 256 * 256;

int n, res;
int a[12];
bool f[N + 10];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	f[0] = true;
	for(int i = 1; i <= n; i ++) cin >> a[i];
	for(int i = 1; i <= n; i ++)
	    for(int j = a[i]; j <= N; j ++)
	        f[j] |= f[j - a[i]];
	for(int i = N; i; i --) 
	    if(!f[i])
	    {
	        res = i;
	        break;
	    }
    if(res >= N - 256) res = 0;
    cout << res << endl;
	return 0;
}
